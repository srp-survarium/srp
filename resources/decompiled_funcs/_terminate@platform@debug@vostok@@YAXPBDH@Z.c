void __cdecl __noreturn vostok::debug::platform::terminate(const char *message, int error_code)
{
  HANDLE CurrentProcess; // eax

  if ( *message )
    MessageBoxA(0, message, "Error", 0x1010u);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(CurrentProcess, error_code);
  exit(error_code);
}
