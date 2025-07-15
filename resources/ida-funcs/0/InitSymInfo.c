int __cdecl InitSymInfo(char *lpszInitialSymbolPath)
{
  HANDLE CurrentProcess; // [esp+0h] [ebp-200Ch]
  char szSymbolPath[8196]; // [esp+4h] [ebp-2008h] BYREF
  unsigned int v4; // [esp+2008h] [ebp-4h]

  v4 = s_SymGetOptions() & 0xFFFFDFE9 | 0x2014;
  s_SymSetOptions(v4);
  InitSymbolPath(szSymbolPath, 0x2000u, lpszInitialSymbolPath);
  CurrentProcess = GetCurrentProcess();
  return s_SymInitialize(CurrentProcess, szSymbolPath, 1);
}
