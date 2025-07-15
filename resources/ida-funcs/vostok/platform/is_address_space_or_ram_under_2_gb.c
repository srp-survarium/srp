bool __cdecl vostok::platform::is_address_space_or_ram_under_2_gb()
{
  HMODULE ModuleHandleA; // eax
  HANDLE CurrentProcess; // eax
  _MEMORYSTATUSEX dst; // [esp+0h] [ebp-48h] BYREF
  int v4; // [esp+44h] [ebp-4h] BYREF

  if ( !s_is_wow64_process )
  {
    ModuleHandleA = GetModuleHandleA("kernel32");
    s_is_wow64_process = (int (__stdcall *)(void *, int *))GetProcAddress(ModuleHandleA, "IsWow64Process");
    if ( !s_is_wow64_process )
      return 1;
  }
  v4 = 0;
  CurrentProcess = GetCurrentProcess();
  if ( !s_is_wow64_process(CurrentProcess, &v4) || v4 != 1 )
    return 1;
  memset((int)&dst, 0, sizeof(dst));
  dst.dwLength = 64;
  GlobalMemoryStatusEx(&dst);
  return dst.ullTotalPhys <= 0x80000000;
}
