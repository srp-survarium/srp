int __usercall GetSourceInfoFromAddress@<eax>(
        unsigned int a1@<ebx>,
        unsigned __int64 address,
        char *lpszModuleInfo,
        unsigned int lpszModuleInfoSize,
        char *lpszSourceInfo,
        unsigned int lpszSourceInfoSize,
        int *line,
        unsigned int *address_out)
{
  HANDLE CurrentProcess; // eax
  HANDLE v9; // eax
  HANDLE v10; // eax
  HANDLE v11; // eax
  HINSTANCE__ *ModuleBase64; // [esp-Ch] [ebp-44h]
  HINSTANCE__ *v14; // [esp-Ch] [ebp-44h]
  HANDLE v15; // [esp+4h] [ebp-34h]
  _IMAGEHLP_LINE64 lineInfo; // [esp+18h] [ebp-20h] BYREF
  unsigned int dwDisp; // [esp+34h] [ebp-4h] BYREF

  strcpy_s(lpszSourceInfo, lpszSourceInfoSize, "?");
  strcpy_s(lpszModuleInfo, lpszModuleInfoSize, "?");
  *line = -1;
  *address_out = 0;
  memset(&lineInfo.Key, 0, 20);
  lineInfo.SizeOfStruct = 24;
  CurrentProcess = GetCurrentProcess();
  if ( s_SymGetLineFromAddr64(CurrentProcess, address, &dwDisp, &lineInfo) )
  {
    PCSTR2LPTSTR(a1, lineInfo.FileName, lpszSourceInfo, lpszSourceInfoSize);
    *line = lineInfo.LineNumber;
    *address_out = lineInfo.Address;
    if ( s_GetModuleBaseName )
    {
      v15 = GetCurrentProcess();
      ModuleBase64 = (HINSTANCE__ *)s_SymGetModuleBase64(v15, lineInfo.Address);
      v9 = GetCurrentProcess();
      s_GetModuleBaseName(v9, ModuleBase64, lpszModuleInfo, lpszModuleInfoSize);
      if ( !*lpszModuleInfo )
        GetModuleNameFromAddress(a1, address, lpszModuleInfo, lpszModuleInfoSize);
    }
    else
    {
      GetModuleNameFromAddress(a1, address, lpszModuleInfo, lpszModuleInfoSize);
    }
    return 1;
  }
  else
  {
    if ( s_GetModuleBaseName )
    {
      v10 = GetCurrentProcess();
      v14 = (HINSTANCE__ *)s_SymGetModuleBase64(v10, address);
      v11 = GetCurrentProcess();
      s_GetModuleBaseName(v11, v14, lpszModuleInfo, lpszModuleInfoSize);
      if ( !*lpszModuleInfo )
        GetModuleNameFromAddress(a1, address, lpszModuleInfo, lpszModuleInfoSize);
    }
    else
    {
      GetModuleNameFromAddress(a1, address, lpszModuleInfo, lpszModuleInfoSize);
    }
    *address_out = address;
    return 0;
  }
}
