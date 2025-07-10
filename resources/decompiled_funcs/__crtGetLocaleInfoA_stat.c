int __cdecl _crtGetLocaleInfoA_stat(
        localeinfo_struct *plocinfo,
        LCID Locale,
        LCTYPE LCType,
        char *lpLCData,
        int cchData,
        UINT code_page)
{
  int v6; // eax
  int v7; // esi
  int LocaleInfoW; // eax
  int v9; // ecx
  unsigned int v11; // eax
  void *v12; // esp
  wchar_t *v13; // edi
  wchar_t *v14; // eax
  int v15; // eax
  int v16; // [esp+0h] [ebp-14h] BYREF
  int v17; // [esp+8h] [ebp-Ch] BYREF
  int buff_size; // [esp+Ch] [ebp-8h]

  v6 = f_use_2;
  v7 = 0;
  if ( !f_use_2 )
  {
    if ( GetLocaleInfoW(0, 1u, 0, 0) )
    {
      f_use_2 = 1;
      goto LABEL_10;
    }
    if ( GetLastError() == 120 )
    {
      v6 = 2;
      f_use_2 = 2;
    }
    else
    {
      v6 = f_use_2;
    }
  }
  if ( v6 == 2 || !v6 )
    return GetLocaleInfoA(Locale, LCType, lpLCData, cchData);
  if ( v6 != 1 )
    return 0;
LABEL_10:
  if ( !code_page )
    code_page = plocinfo->locinfo->lc_codepage;
  LocaleInfoW = GetLocaleInfoW(Locale, LCType, 0, 0);
  v9 = LocaleInfoW;
  buff_size = LocaleInfoW;
  if ( !LocaleInfoW )
    return 0;
  if ( LocaleInfoW <= 0 || 0xFFFFFFE0 / LocaleInfoW < 2 )
  {
    v13 = 0;
  }
  else
  {
    v11 = 2 * LocaleInfoW + 8;
    if ( v11 <= 0x400 )
    {
      v12 = alloca(v11);
      if ( &v16 )
      {
        v16 = 52428;
        v13 = (wchar_t *)&v17;
        goto LABEL_23;
      }
      return 0;
    }
    v14 = (wchar_t *)malloc(2 * v9 + 8);
    if ( v14 )
    {
      *(_DWORD *)v14 = 56797;
      v14 += 4;
    }
    v13 = v14;
  }
LABEL_23:
  if ( !v13 )
    return 0;
  if ( GetLocaleInfoW(Locale, LCType, v13, buff_size) )
  {
    if ( cchData )
      v15 = WideCharToMultiByte(code_page, 0, v13, -1, lpLCData, cchData, 0, 0);
    else
      v15 = WideCharToMultiByte(code_page, 0, v13, -1, 0, 0, 0, 0);
    v7 = v15;
  }
  _freea(v13);
  return v7;
}
