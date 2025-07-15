int __cdecl __get_qualified_locale(tagLC_STRINGS *const lpInStr, tagLC_ID *lpOutId, tagLC_STRINGS *lpOutStr)
{
  _tiddata *v3; // eax
  int p_setloc_data; // esi
  unsigned __int8 **p_pchCountry; // edi
  _BYTE *v6; // eax
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // edi
  int v9; // eax
  LCID UserDefaultLCID; // eax
  UINT v11; // eax
  unsigned __int16 v12; // di
  int val; // [esp+14h] [ebp+8h]

  v3 = _getptd();
  p_setloc_data = (int)&v3->_setloc_data;
  if ( !lpInStr )
  {
    v3->_setloc_data.iLcidState |= 0x104u;
LABEL_23:
    UserDefaultLCID = GetUserDefaultLCID();
    *(_DWORD *)(p_setloc_data + 24) = UserDefaultLCID;
    *(_DWORD *)(p_setloc_data + 28) = UserDefaultLCID;
    goto LABEL_24;
  }
  p_pchCountry = (unsigned __int8 **)&v3->_setloc_data.pchCountry;
  *(_DWORD *)p_setloc_data = lpInStr;
  v3->_setloc_data.pchCountry = lpInStr->szCountry;
  if ( lpInStr != (tagLC_STRINGS *const)-64 && lpInStr->szCountry[0] )
    TranslateName(__rg_country, 22, &v3->_setloc_data.pchCountry);
  v6 = *(_BYTE **)p_setloc_data;
  *(_DWORD *)(p_setloc_data + 8) = 0;
  if ( !v6 || !*v6 )
  {
    v8 = *p_pchCountry;
    if ( !v8 || !*v8 )
    {
      *(_DWORD *)(p_setloc_data + 8) = 260;
      goto LABEL_23;
    }
    strlen(v8);
    *(_DWORD *)(p_setloc_data + 20) = v9 == 3;
    EnumSystemLocalesA((LOCALE_ENUMPROCA)CountryEnumProc, 1u);
    if ( (*(_BYTE *)(p_setloc_data + 8) & 4) == 0 )
      *(_DWORD *)(p_setloc_data + 8) = 0;
LABEL_24:
    if ( !*(_DWORD *)(p_setloc_data + 8) )
      return 0;
    goto LABEL_25;
  }
  if ( *p_pchCountry && **p_pchCountry )
    GetLcidFromLangCountry((setloc_struct *)p_setloc_data);
  else
    GetLcidFromLanguage((setloc_struct *)p_setloc_data);
  if ( !*(_DWORD *)(p_setloc_data + 8) )
  {
    if ( TranslateName(__rg_language, 64, (char **)p_setloc_data) )
    {
      v7 = *p_pchCountry;
      if ( v7 && *v7 )
        GetLcidFromLangCountry((setloc_struct *)p_setloc_data);
      else
        GetLcidFromLanguage((setloc_struct *)p_setloc_data);
    }
    goto LABEL_24;
  }
LABEL_25:
  v11 = ProcessCodePage(
          lpInStr != 0 ? lpInStr->szCodePage : 0,
          (setloc_struct *)p_setloc_data,
          (int)lpInStr->szCodePage);
  v12 = v11;
  val = v11;
  if ( !v11
    || v11 == 65000
    || v11 == 65001
    || !IsValidCodePage((unsigned __int16)v11)
    || !IsValidLocale(*(_DWORD *)(p_setloc_data + 24), 1u) )
  {
    return 0;
  }
  if ( lpOutId )
  {
    lpOutId->wLanguage = *(_WORD *)(p_setloc_data + 24);
    lpOutId->wCountry = *(_WORD *)(p_setloc_data + 28);
    lpOutId->wCodePage = v12;
  }
  if ( !lpOutStr )
    return 1;
  if ( lpOutId->wLanguage == 2068 )
  {
    if ( strcpy_s((int)GetLocaleInfoA, lpOutStr->szLanguage, 64, "Norwegian-Nynorsk") )
      _invoke_watson((int)lpOutStr, (int)GetLocaleInfoA, p_setloc_data);
  }
  else if ( !GetLocaleInfoA(*(_DWORD *)(p_setloc_data + 24), 0x1001u, lpOutStr->szLanguage, 64) )
  {
    return 0;
  }
  if ( GetLocaleInfoA(*(_DWORD *)(p_setloc_data + 28), 0x1002u, lpOutStr->szCountry, 64) )
  {
    _itoa_s((char *)GetLocaleInfoA, val, lpOutStr->szCodePage, 0x10u, 0xAu);
    return 1;
  }
  return 0;
}
