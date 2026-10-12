// SPDX-License-Identifier: GPL-3.0-or-later

#![no_std]
#![deny(unsafe_op_in_unsafe_fn)]

//! C adapter. All input pointers must describe live, initialized memory of the
//! stated size; writable buffers/contexts/outputs must not alias any input or
//! each other. Callbacks must obey the same rules, not unwind, and not mutate
//! validated bytes. Opaque contexts must be initialized and exclusively held.
//! Null is accepted only for zero-length byte slices or optional callbacks.

use core::{ffi::c_void, mem, ptr, slice};
use srp_packet_guard::{
    self as guard, Error, Players, Result, application, login, state, transport,
};

#[cfg(not(test))]
mod runtime {
    use core::{
        alloc::{GlobalAlloc, Layout},
        panic::PanicInfo,
    };
    unsafe extern "C" {
        fn pg_host_alloc(size: usize, alignment: usize) -> *mut u8;
        fn pg_host_free(memory: *mut u8, size: usize, alignment: usize);
        fn pg_host_abort() -> !;
    }
    struct HostAllocator;
    // SAFETY: The integrating host must implement the documented allocator contract.
    unsafe impl GlobalAlloc for HostAllocator {
        unsafe fn alloc(&self, layout: Layout) -> *mut u8 {
            // SAFETY: Forward the allocation contract unchanged to the host.
            unsafe { pg_host_alloc(layout.size(), layout.align()) }
        }
        unsafe fn dealloc(&self, memory: *mut u8, layout: Layout) {
            // SAFETY: memory/layout are supplied by Rust's allocator machinery.
            unsafe { pg_host_free(memory, layout.size(), layout.align()) }
        }
    }
    #[global_allocator]
    static ALLOCATOR: HostAllocator = HostAllocator;
    #[panic_handler]
    fn panic(_: &PanicInfo<'_>) -> ! {
        // SAFETY: The host abort function must terminate and never unwind/return.
        unsafe { pg_host_abort() }
    }
}

type ItemCallback = unsafe extern "C" fn(*mut c_void, u32) -> u32;
type MessageCallback = unsafe extern "C" fn(*mut c_void, u32, *const u8, u32) -> i32;
type StateCallback = unsafe extern "C" fn(*mut c_void, u32, *const u8, u32, u32, u32) -> i32;
#[repr(C)]
#[derive(Clone, Copy, Default)]
pub struct Callbacks {
    context: *mut c_void,
    item_kind: Option<ItemCallback>,
    map_exists: Option<ItemCallback>,
    lobby_schema: Option<MessageCallback>,
    match_schema: Option<MessageCallback>,
    state_schema: Option<StateCallback>,
}
struct Bridge(Callbacks);
fn approved(code: i32) -> Result<()> {
    if code == 0 {
        Ok(())
    } else {
        Err(Error::Unsupported)
    }
}
impl application::Metadata for Bridge {
    fn item_kind(&self, id: u16) -> Option<application::ItemKind> {
        let callback = self.0.item_kind?;
        // SAFETY: Callbacks and context are valid for the enclosing C call.
        match unsafe { callback(self.0.context, u32::from(id)) } {
            1 => Some(application::ItemKind::Stackable),
            2 => Some(application::ItemKind::NonStackable),
            _ => None,
        }
    }
    fn map_exists(&self, id: u8) -> bool {
        // SAFETY: Callback contract as above; accept only canonical true.
        self.0
            .map_exists
            .is_some_and(|f| unsafe { f(self.0.context, u32::from(id)) == 1 })
    }
}
impl application::MessageSchema for Bridge {
    fn lobby(&self, op: transport::Opcode, bytes: &[u8]) -> Result<()> {
        let f = self.0.lobby_schema.ok_or(Error::Unsupported)?;
        // SAFETY: bytes remain live and immutable for the synchronous callback.
        approved(unsafe {
            f(
                self.0.context,
                u32::from(op.get()),
                bytes.as_ptr(),
                bytes.len() as u32,
            )
        })
    }
    fn match_action(&self, op: transport::Opcode, bytes: &[u8]) -> Result<()> {
        let f = self.0.match_schema.ok_or(Error::Unsupported)?;
        // SAFETY: Same synchronous callback contract.
        approved(unsafe {
            f(
                self.0.context,
                u32::from(op.get()),
                bytes.as_ptr(),
                bytes.len() as u32,
            )
        })
    }
}
impl state::Schema for Bridge {
    fn check(&self, part: state::Part, bytes: &[u8], bits: usize, slot: Option<u8>) -> Result<()> {
        let f = self.0.state_schema.ok_or(Error::Unsupported)?;
        // SAFETY: Slice and bit count have already been bounded by the core.
        approved(unsafe {
            f(
                self.0.context,
                part as u32,
                bytes.as_ptr(),
                bytes.len() as u32,
                bits as u32,
                slot.map_or(20, u32::from),
            )
        })
    }
}
fn status(value: Result<()>) -> i32 {
    value.map_or_else(|e| e as i32, |()| 0)
}
fn checked_region(p: usize, n: usize, alignment: usize) -> Result<()> {
    if p == 0
        || !p.is_multiple_of(alignment)
        || n > isize::MAX as usize
        || p.checked_add(n).is_none()
    {
        Err(Error::Invalid)
    } else {
        Ok(())
    }
}
unsafe fn input<'a>(p: *const u8, n: u32) -> Result<&'a [u8]> {
    if n == 0 {
        return Ok(&[]);
    }
    checked_region(p as usize, n as usize, 1)?;
    // SAFETY: Caller promises initialized readable memory; shape checked above.
    Ok(unsafe { slice::from_raw_parts(p, n as usize) })
}
unsafe fn output<'a>(p: *mut u8, n: u32) -> Result<&'a mut [u8]> {
    if n == 0 {
        return Ok(&mut []);
    }
    checked_region(p as usize, n as usize, 1)?;
    // SAFETY: Caller promises exclusive writable memory of this size.
    Ok(unsafe { slice::from_raw_parts_mut(p, n as usize) })
}
unsafe fn read_callbacks(p: *const Callbacks) -> Result<Bridge> {
    if p.is_null() {
        return Ok(Bridge(Callbacks::default()));
    }
    checked_region(
        p as usize,
        mem::size_of::<Callbacks>(),
        mem::align_of::<Callbacks>(),
    )?;
    // SAFETY: C caller supplies an initialized matching callbacks structure.
    Ok(Bridge(unsafe { p.read() }))
}
unsafe fn write_value<T>(p: *mut T, value: T) -> Result<()> {
    checked_region(p as usize, mem::size_of::<T>(), mem::align_of::<T>())?;
    // SAFETY: Caller promises writable output memory with no aliasing.
    unsafe { p.write(value) };
    Ok(())
}
unsafe fn context<'a, T>(p: *mut c_void, n: u32) -> Result<&'a mut T> {
    if (n as usize) < mem::size_of::<T>() {
        return Err(Error::Limit);
    }
    checked_region(p as usize, mem::size_of::<T>(), mem::align_of::<T>())?;
    // SAFETY: Caller used the matching initializer and holds exclusive access.
    Ok(unsafe { &mut *p.cast::<T>() })
}
fn stage(n: u32) -> Result<login::Stage> {
    match n {
        1 => Ok(login::Stage::Name),
        2 => Ok(login::Stage::Password),
        _ => Err(Error::Invalid),
    }
}
fn channel(n: u32) -> Result<transport::Channel> {
    match n {
        1 => Ok(transport::Channel::Lobby),
        2 => Ok(transport::Channel::Match),
        _ => Err(Error::Invalid),
    }
}
fn byte(n: u32) -> Result<u8> {
    u8::try_from(n).map_err(|_| Error::Invalid)
}
fn players(n: u32) -> Result<Option<Players>> {
    if n == 0 {
        Ok(None)
    } else {
        Players::new(byte(n)?).map(Some)
    }
}

#[repr(C)]
#[derive(Clone, Copy)]
pub struct Frame {
    opcode: u32,
    delivery: u32,
    index: u32,
    count: u32,
    body: *const u8,
    size: u32,
}
impl From<transport::Frame<'_>> for Frame {
    fn from(f: transport::Frame<'_>) -> Self {
        Self {
            opcode: u32::from(f.opcode.get()),
            delivery: f.delivery.map_or(256, u32::from),
            index: f.fragment.map_or(256, |f| u32::from(f.index)),
            count: f.fragment.and_then(|f| f.count).map_or(0, u32::from),
            body: f.body.as_ptr(),
            size: f.body.len() as u32,
        }
    }
}

/// # Safety
/// Follow the module-level C pointer/lifetime contract.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn pg_login(stage_id: u32, p: *const u8, n: u32) -> i32 {
    // SAFETY: Raw accesses are covered by this exported function's contract.
    status((|| unsafe {
        login::verify(stage(stage_id)?, input(p, n)?)
    })())
}
#[unsafe(no_mangle)]
pub extern "C" fn pg_login_size() -> u32 {
    mem::size_of::<login::Accumulator>() as u32
}
#[unsafe(no_mangle)]
pub extern "C" fn pg_login_align() -> u32 {
    mem::align_of::<login::Accumulator>() as u32
}
/// # Safety
/// p is exclusively writable, aligned storage of at least pg_login_size bytes.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn pg_login_init(p: *mut c_void, n: u32) -> i32 {
    status((|| {
        if n < pg_login_size() {
            return Err(Error::Limit);
        }
        // SAFETY: Initialize storage without creating a reference to old bytes.
        unsafe { write_value(p.cast(), login::Accumulator::new()) }
    })())
}
/// # Safety
/// Initialized exclusive context; input/output pointers follow module contract.
/// Response borrows context until the next call; on failure close/reset it.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn pg_login_feed(
    ctx: *mut c_void,
    size: u32,
    stage_id: u32,
    p: *const u8,
    n: u32,
    consumed: *mut u32,
    response: *mut *const u8,
    response_size: *mut u32,
) -> i32 {
    let result: Result<bool> = (|| unsafe {
        write_value(consumed, 0)?;
        write_value(response, ptr::null())?;
        write_value(response_size, 0)?;
        let progress =
            context::<login::Accumulator>(ctx, size)?.feed(stage(stage_id)?, input(p, n)?)?;
        write_value(consumed, progress.consumed as u32)?;
        if let Some(bytes) = progress.response {
            write_value(response, bytes.as_ptr())?;
            write_value(response_size, bytes.len() as u32)?;
            Ok(true)
        } else {
            Ok(false)
        }
    })();
    match result {
        Ok(true) => 0,
        Ok(false) => 9,
        Err(e) => e as i32,
    }
}

/// Transport only: never dispatch based solely on this result.
/// # Safety
/// out points to capacity initialized-or-uninitialized Frame slots; all other
/// pointers follow the module contract. Output bodies borrow the input datagram.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn pg_udp(
    channel_id: u32,
    roster: u32,
    p: *const u8,
    n: u32,
    out: *mut Frame,
    capacity: u32,
    written: *mut u32,
) -> i32 {
    status((|| unsafe {
        write_value(written, 0)?;
        if n as usize > guard::MAX_DATAGRAM {
            return Err(Error::Limit);
        }
        let header = transport::header(input(p, n)?)?;
        let frames = transport::frames(
            header.payload,
            header.single,
            channel(channel_id)?,
            players(roster)?,
        )?;
        let count = frames.count_remaining();
        if count > capacity as usize {
            return Err(Error::Limit);
        }
        checked_region(
            out as usize,
            count * mem::size_of::<Frame>(),
            mem::align_of::<Frame>(),
        )?;
        for (i, frame) in frames.enumerate() {
            out.add(i).write(frame.into());
        }
        write_value(written, count as u32)
    })())
}
#[unsafe(no_mangle)]
pub extern "C" fn pg_reassembly_size() -> u32 {
    mem::size_of::<transport::Reassembly>() as u32
}
#[unsafe(no_mangle)]
pub extern "C" fn pg_reassembly_align() -> u32 {
    mem::align_of::<transport::Reassembly>() as u32
}
/// # Safety
/// p is exclusively writable aligned storage of at least pg_reassembly_size.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn pg_reassembly_init(p: *mut c_void, n: u32) -> i32 {
    status((|| {
        if n < pg_reassembly_size() {
            return Err(Error::Limit);
        }
        checked_region(
            p as usize,
            pg_reassembly_size() as usize,
            pg_reassembly_align() as usize,
        )?;
        // SAFETY: Reassembly documents all-zero as a valid representation.
        // Initialize in place to avoid a 128 KiB temporary on the native stack.
        unsafe { p.cast::<u8>().write_bytes(0, pg_reassembly_size() as usize) };
        Ok(())
    })())
}
/// # Safety
/// Initialized exclusive context, readable Frame/input, writable result. Result
/// body borrows ctx; do not reset/feed ctx until the consumer is finished.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn pg_reassemble(
    ctx: *mut c_void,
    size: u32,
    channel_id: u32,
    source: *const Frame,
    now: u32,
    out: *mut Frame,
) -> i32 {
    let result: Result<bool> = (|| unsafe {
        checked_region(
            source as usize,
            mem::size_of::<Frame>(),
            mem::align_of::<Frame>(),
        )?;
        let f = source.read();
        let channel = channel(channel_id)?;
        let op = transport::Opcode::new(byte(f.opcode)?, channel)?;
        if !op.has_delivery(channel) || f.index >= 255 || f.count > 255 {
            return Err(Error::Invalid);
        }
        let frame = transport::Frame {
            opcode: op,
            delivery: Some(byte(f.delivery)?),
            fragment: Some(transport::Fragment {
                index: f.index as u8,
                count: if f.count == 0 {
                    None
                } else {
                    Some(f.count as u8)
                },
            }),
            body: input(f.body, f.size)?,
        };
        let value = context::<transport::Reassembly>(ctx, size)?.feed(frame, now)?;
        if let Some(complete) = value {
            write_value(out, complete.into())?;
            Ok(true)
        } else {
            Ok(false)
        }
    })();
    match result {
        Ok(true) => 0,
        Ok(false) => 5,
        Err(e) => e as i32,
    }
}

/// # Safety
/// Follow module contract, including validity and purity of optional callbacks.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn pg_lobby(
    op: u32,
    p: *const u8,
    n: u32,
    callbacks: *const Callbacks,
) -> i32 {
    status((|| unsafe {
        application::lobby(byte(op)?, input(p, n)?, &read_callbacks(callbacks)?)
    })())
}
/// # Safety
/// Module contract; scratch is exclusive and does not alias input or callbacks.
/// roster_out is only nonzero for a successfully verified E4 setup.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn pg_match(
    op: u32,
    p: *const u8,
    n: u32,
    roster: u32,
    callbacks: *const Callbacks,
    scratch: *mut u8,
    scratch_size: u32,
    roster_out: *mut u32,
) -> i32 {
    status((|| unsafe {
        write_value(roster_out, 0)?;
        if scratch_size as usize > guard::MAX_OPTIONS {
            return Err(Error::Limit);
        }
        let bridge = read_callbacks(callbacks)?;
        let policy = application::Policy {
            players: players(roster)?,
            metadata: &bridge,
            messages: &bridge,
            state: &bridge,
            decoder: &application::Lzma2,
        };
        let value = application::match_message(
            byte(op)?,
            input(p, n)?,
            &policy,
            output(scratch, scratch_size)?,
        )?;
        write_value(roster_out, value.map_or(0, |p| u32::from(p.get())))
    })())
}
/// # Safety
/// Follow the module-level C pointer/lifetime contract.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn pg_options(
    p: *const u8,
    n: u32,
    callbacks: *const Callbacks,
    roster_out: *mut u32,
) -> i32 {
    status((|| unsafe {
        write_value(roster_out, 0)?;
        let roster = application::options(input(p, n)?, &read_callbacks(callbacks)?)?;
        write_value(roster_out, u32::from(roster.get()))
    })())
}
/// Diagnostic boundaries only, NEVER permission to dispatch.
/// # Safety
/// Input points to readable memory of n bytes, as required by the module contract.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn pg_state_envelope(p: *const u8, n: u32, roster: u32) -> i32 {
    status((|| unsafe {
        state::envelope(input(p, n)?, players(roster)?.ok_or(Error::Invalid)?)
    })())
}
/// # Safety
/// Module contract, with pure schema callbacks that check the whole supplied slice.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn pg_state_deep(
    p: *const u8,
    n: u32,
    roster: u32,
    callbacks: *const Callbacks,
) -> i32 {
    status((|| unsafe {
        state::deep(
            input(p, n)?,
            players(roster)?.ok_or(Error::Invalid)?,
            &read_callbacks(callbacks)?,
        )
    })())
}
/// # Safety
/// Input/output are live disjoint regions. written is an exclusive u32 output.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn pg_decode(
    p: *const u8,
    n: u32,
    out: *mut u8,
    capacity: u32,
    written: *mut u32,
) -> i32 {
    status((|| unsafe {
        write_value(written, 0)?;
        if n as usize > guard::MAX_MESSAGE || capacity as usize > guard::MAX_OPTIONS {
            return Err(Error::Limit);
        }
        let value = guard::compression::decode(input(p, n)?, output(out, capacity)?)?;
        write_value(written, value as u32)
    })())
}
