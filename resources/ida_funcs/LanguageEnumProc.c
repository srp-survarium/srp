BOOL __stdcall LanguageEnumProc(char *lpLcidString)
{
  setloc_struct *p_setloc_data; // esi
  int v2; // ecx
  LCID v3; // edi
  BOOL v5; // eax
  char rgcInfo[120]; // [esp+8h] [ebp-7Ch] BYREF

  p_setloc_data = &_getptd()->_setloc_data;
  v3 = LcidFromHexString(v2, lpLcidString);
  if ( !GetLocaleInfoA(v3, p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097, rgcInfo, 120) )
  {
    p_setloc_data->iLcidState = 0;
    return 1;
  }
  if ( !_stricmp(p_setloc_data->pchLanguage, rgcInfo) )
  {
    if ( p_setloc_data->bAbbrevLanguage )
    {
LABEL_11:
      p_setloc_data->iLcidState |= 4u;
      p_setloc_data->lcidLanguage = v3;
      p_setloc_data->lcidCountry = v3;
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v5 = TestDefaultLanguage(v3, 1);
  }
  else
  {
    if ( p_setloc_data->bAbbrevLanguage || !p_setloc_data->iPrimaryLen || _stricmp(p_setloc_data->pchLanguage, rgcInfo) )
      return (p_setloc_data->iLcidState & 4) == 0;
    v5 = TestDefaultLanguage(v3, 0);
  }
  if ( v5 )
    goto LABEL_11;
  return (p_setloc_data->iLcidState & 4) == 0;
}
