void __cdecl __noreturn __crtExitProcess(int status)
{
  __crtCorExitProcess(status);
  ExitProcess(status);
}
