int __usercall GetModuleNameFromAddress@<eax>(
        unsigned int a1@<ebx>,
        unsigned __int64 address,
        char *lpszModule,
        unsigned int lpszModuleSize)
{
  HANDLE CurrentProcess; // eax
  _IMAGEHLP_MODULE64 moduleInfo; // [esp+0h] [ebp-690h] BYREF
  int ret; // [esp+68Ch] [ebp-4h]

  ret = 0;
  memset((int)&moduleInfo, 0, sizeof(moduleInfo));
  moduleInfo.SizeOfStruct = 1672;
  CurrentProcess = GetCurrentProcess();
  if ( s_SymGetModuleInfo64(CurrentProcess, (unsigned int)address, &moduleInfo) )
  {
    PCSTR2LPTSTR(a1, moduleInfo.ModuleName, lpszModule, lpszModuleSize);
    return 1;
  }
  else
  {
    strcpy_s(lpszModule, lpszModuleSize, "?");
  }
  return ret;
}
