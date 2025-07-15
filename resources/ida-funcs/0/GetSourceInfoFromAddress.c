int __cdecl GetSourceInfoFromAddress(
        unsigned __int64 address,
        char *lpszModuleInfo,
        char *lpszModuleInfoSize,
        char *lpszSourceInfo,
        _DWORD *lpszSourceInfoSize)
{
  HANDLE CurrentProcess; // eax
  bool v6; // zf
  HANDLE v7; // eax
  HANDLE v8; // eax
  HANDLE v10; // eax
  HANDLE v11; // eax
  HINSTANCE__ *ModuleBase64; // [esp-Ch] [ebp-3Ch]
  HINSTANCE__ *v13; // [esp-Ch] [ebp-3Ch]
  _IMAGEHLP_LINE64 v14; // [esp+10h] [ebp-20h] BYREF
  unsigned int v15; // [esp+2Ch] [ebp-4h] BYREF

  strcpy_s(lpszModuleInfoSize, 0x208u, "?");
  strcpy_s(lpszModuleInfo, 0x100u, "?");
  *(_DWORD *)lpszSourceInfo = -1;
  *lpszSourceInfoSize = 0;
  memset(&v14, 0, sizeof(v14));
  v14.SizeOfStruct = 24;
  CurrentProcess = GetCurrentProcess();
  if ( s_SymGetLineFromAddr64(CurrentProcess, address, &v15, &v14) )
  {
    PCSTR2LPTSTR(256, v14.FileName, lpszModuleInfoSize, 0x208u);
    *(_DWORD *)lpszSourceInfo = v14.LineNumber;
    v6 = s_GetModuleBaseName == 0;
    *lpszSourceInfoSize = v14.Address;
    if ( v6 )
    {
      GetModuleNameFromAddress(256, address, lpszModuleInfo);
    }
    else
    {
      v7 = GetCurrentProcess();
      ModuleBase64 = (HINSTANCE__ *)s_SymGetModuleBase64(v7, v14.Address);
      v8 = GetCurrentProcess();
      s_GetModuleBaseName(v8, ModuleBase64, lpszModuleInfo, 0x100u);
      if ( !*lpszModuleInfo )
        GetModuleNameFromAddress((int)lpszModuleInfo, address, lpszModuleInfo);
    }
    return 1;
  }
  else
  {
    if ( s_GetModuleBaseName )
    {
      v10 = GetCurrentProcess();
      v13 = (HINSTANCE__ *)s_SymGetModuleBase64(v10, address);
      v11 = GetCurrentProcess();
      s_GetModuleBaseName(v11, v13, lpszModuleInfo, 0x100u);
      if ( !*lpszModuleInfo )
        GetModuleNameFromAddress((int)lpszModuleInfo, address, lpszModuleInfo);
    }
    else
    {
      GetModuleNameFromAddress(256, address, lpszModuleInfo);
    }
    *lpszSourceInfoSize = address;
    return 0;
  }
}
