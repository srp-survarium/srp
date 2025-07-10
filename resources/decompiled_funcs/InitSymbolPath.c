void __cdecl InitSymbolPath(char *lpszSymbolPath, unsigned int symPathSize, char *lpszIniPath)
{
  char Buffer[8192]; // [esp+0h] [ebp-2000h] BYREF

  strcpy_s(
    lpszSymbolPath,
    symPathSize,
    (const char *)&stru_957BE0.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags);
  if ( GetEnvironmentVariableA("_NT_SYMBOL_PATH", Buffer, 0x2000u) )
  {
    strcat_s(lpszSymbolPath, symPathSize, ";");
    strcat_s(lpszSymbolPath, symPathSize, Buffer);
  }
  if ( GetEnvironmentVariableA("_NT_ALTERNATE_SYMBOL_PATH", Buffer, 0x2000u) )
  {
    strcat_s(lpszSymbolPath, symPathSize, ";");
    strcat_s(lpszSymbolPath, symPathSize, Buffer);
  }
  if ( GetEnvironmentVariableA("SYSTEMROOT", Buffer, 0x2000u) )
  {
    strcat_s(lpszSymbolPath, symPathSize, ";");
    strcat_s(lpszSymbolPath, symPathSize, Buffer);
    strcat_s(lpszSymbolPath, symPathSize, ";");
    strcat_s(lpszSymbolPath, symPathSize, Buffer);
    strcat_s(lpszSymbolPath, symPathSize, "\\System32");
  }
  if ( lpszIniPath )
  {
    if ( *lpszIniPath )
    {
      strcat_s(lpszSymbolPath, symPathSize, ";");
      strcat_s(lpszSymbolPath, symPathSize, lpszIniPath);
    }
  }
}
