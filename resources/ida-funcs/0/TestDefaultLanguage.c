BOOL __cdecl TestDefaultLanguage(unsigned int lcid, int bTestPrimary)
{
  char **v2; // ecx
  char **v3; // esi
  int v4; // ecx
  BOOL result; // eax
  int v6; // ecx
  char *v7; // esi
  int PrimaryLen; // edi
  int v9; // eax
  char LCData[120]; // [esp+4h] [ebp-7Ch] BYREF

  v3 = v2;
  result = 0;
  if ( GetLocaleInfoA(lcid & 0x3FF | 0x400, 1u, LCData, 120) )
  {
    if ( lcid == LcidFromHexString(v4, LCData) )
      return 1;
    if ( !bTestPrimary )
      return 1;
    v7 = *v3;
    PrimaryLen = GetPrimaryLen(v6, v7);
    strlen((unsigned __int8 *)v7);
    if ( PrimaryLen != v9 )
      return 1;
  }
  return result;
}
