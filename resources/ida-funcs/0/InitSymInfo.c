int __cdecl InitSymInfo()
{
  unsigned int Options; // eax
  HANDLE CurrentProcess; // eax
  char v3[8192]; // [esp+0h] [ebp-2000h] BYREF

  Options = s_SymGetOptions();
  s_SymSetOptions(Options & 0xFFFFDFE9 | 0x2014);
  InitSymbolPath(v3);
  CurrentProcess = GetCurrentProcess();
  return s_SymInitialize(CurrentProcess, v3, 1);
}
