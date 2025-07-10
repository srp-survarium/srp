BOOL __stdcall CountryEnumProc(char *lpLcidString)
{
  setloc_struct *p_setloc_data; // esi
  int v2; // ecx
  int v3; // edi
  char rgcInfo[120]; // [esp+8h] [ebp-7Ch] BYREF

  p_setloc_data = &_getptd()->_setloc_data;
  v3 = LcidFromHexString(v2, lpLcidString);
  if ( GetLocaleInfoA(v3, p_setloc_data->bAbbrevCountry != 0 ? 7 : 4098, rgcInfo, 120) )
  {
    if ( !_stricmp(p_setloc_data->pchCountry, rgcInfo) )
    {
      if ( TestDefaultCountry(v3) )
      {
        p_setloc_data->iLcidState |= 4u;
        p_setloc_data->lcidCountry = v3;
        p_setloc_data->lcidLanguage = v3;
      }
    }
    return (p_setloc_data->iLcidState & 4) == 0;
  }
  else
  {
    p_setloc_data->iLcidState = 0;
    return 1;
  }
}
