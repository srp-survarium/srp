void __cdecl __noreturn epilogue(_EXCEPTION_POINTERS *const exception_information)
{
  HANDLE CurrentProcess; // eax

  if ( s_SymCleanup )
  {
    CurrentProcess = GetCurrentProcess();
    s_SymCleanup(CurrentProcess);
  }
  if ( s_previous_handler )
    s_previous_handler(exception_information);
  vostok::debug::platform::terminate(2, uri);
}
