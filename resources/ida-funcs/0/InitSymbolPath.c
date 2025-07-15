void __cdecl InitSymbolPath(char *lpszSymbolPath)
{
  char Buffer[8192]; // [esp+Ch] [ebp-2000h] BYREF

  strcpy_s(lpszSymbolPath, 0x2000u, ".");
  if ( GetEnvironmentVariableA("_NT_SYMBOL_PATH", Buffer, 0x2000u) )
  {
    strcat_s(lpszSymbolPath, 0x2000u, ";");
    strcat_s(lpszSymbolPath, 0x2000u, Buffer);
  }
  if ( GetEnvironmentVariableA("_NT_ALTERNATE_SYMBOL_PATH", Buffer, 0x2000u) )
  {
    strcat_s(lpszSymbolPath, 0x2000u, ";");
    strcat_s(lpszSymbolPath, 0x2000u, Buffer);
  }
  if ( GetEnvironmentVariableA("SYSTEMROOT", Buffer, 0x2000u) )
  {
    strcat_s(lpszSymbolPath, 0x2000u, ";");
    strcat_s(lpszSymbolPath, 0x2000u, Buffer);
    strcat_s(lpszSymbolPath, 0x2000u, ";");
    strcat_s(lpszSymbolPath, 0x2000u, Buffer);
    strcat_s(lpszSymbolPath, 0x2000u, "\\System32");
  }
}
