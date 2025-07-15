void __cdecl __crtCorExitProcess(int status)
{
  HMODULE ModuleHandleW; // eax
  FARPROC CorExitProcess; // eax

  ModuleHandleW = GetModuleHandleW(L"mscoree.dll");
  if ( ModuleHandleW )
  {
    CorExitProcess = GetProcAddress(ModuleHandleW, "CorExitProcess");
    if ( CorExitProcess )
      ((void (__stdcall *)(int))CorExitProcess)(status);
  }
}
