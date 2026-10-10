// SPDX-License-Identifier: GPL-3.0-or-later
fn main() {
    unsafe { boot_server() }
}

#[inline(never)]
#[expect(unsafe_op_in_unsafe_fn)]
unsafe fn boot_server() {
    const PATH: &[u8] =
        b"E:\\Projects\\srp\\target\\i686-pc-windows-msvc\\debug\\match_server.dll\0";

    windows_link::link!("kernel32.dll" "system" fn LoadLibraryA(lplibfilename: *const u8) -> windows::Win32::Foundation::HMODULE);
    windows_link::link!("kernel32.dll" "system" fn Sleep(dwmilliseconds : u32));

    let _handle = LoadLibraryA(PATH.as_ptr());

    loop {
        Sleep(120_000);
    }
}
