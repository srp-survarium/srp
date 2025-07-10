BOOL __cdecl TestDefaultLanguage(unsigned int lcid, int bTestPrimary)
{
  setloc_struct *_psetloc_data; // ecx
  setloc_struct *v3; // esi
  int v4; // ecx
  BOOL result; // eax
  int v6; // ecx
  char *pchLanguage; // esi
  int PrimaryLen; // edi
  int v9; // eax
  char rgcInfo[120]; // [esp+4h] [ebp-7Ch] BYREF

  v3 = _psetloc_data;
  result = 0;
  if ( GetLocaleInfoA(lcid & 0x3FF | 0x400, 1u, rgcInfo, 120) )
  {
    if ( lcid == LcidFromHexString(v4, rgcInfo) )
      return 1;
    if ( !bTestPrimary )
      return 1;
    pchLanguage = v3->pchLanguage;
    PrimaryLen = GetPrimaryLen(v6, pchLanguage);
    strlen((unsigned __int8 *)pchLanguage);
    if ( PrimaryLen != v9 )
      return 1;
  }
  return result;
}
