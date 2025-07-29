#![feature(iter_intersperse)]
#![feature(generic_atomic)]

mod game;
mod match_connection;
mod message;
mod run;
mod sequence_number;
mod utils;

use windows::Win32::Foundation::HANDLE;
use windows::Win32::System::SystemServices::DLL_PROCESS_ATTACH;

#[unsafe(no_mangle)]
pub extern "system" fn DllMain(
    _h_dll: HANDLE,
    dw_reason: u32,
    _lp_reserved: *mut std::ffi::c_void,
) -> bool {
    match dw_reason {
        DLL_PROCESS_ATTACH => _ = std::thread::spawn(run::run),
        _ => (),
    }
    return true;
}
