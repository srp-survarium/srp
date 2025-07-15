int __cdecl __getlocaleinfo(
        localeinfo_struct *plocinfo,
        int lc_type,
        LCID localehandle,
        LCTYPE fieldtype,
        unsigned __int8 **address)
{
  char *v5; // edi
  int LocaleInfoA; // esi
  unsigned int v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // eax
  wchar_t *v11; // edi
  char v12; // bl
  int cchData; // [esp+10h] [ebp-90h]
  int v14; // [esp+18h] [ebp-88h]
  char LCData[128]; // [esp+1Ch] [ebp-84h] BYREF

  if ( lc_type == 1 )
  {
    v5 = LCData;
    v14 = 0;
    LocaleInfoA = __crtGetLocaleInfoA(plocinfo, localehandle, fieldtype, LCData, 128, 0);
    if ( !LocaleInfoA )
    {
      if ( GetLastError() != 122 )
        return -1;
      v7 = __crtGetLocaleInfoA(plocinfo, localehandle, fieldtype, 0, 0, 0);
      cchData = v7;
      if ( !v7 )
        return -1;
      v8 = _calloc_crt(v7, 1u);
      v5 = (char *)v8;
      if ( !v8 )
        return -1;
      v14 = 1;
      LocaleInfoA = __crtGetLocaleInfoA(plocinfo, localehandle, fieldtype, (char *)v8, cchData, 0);
      if ( !LocaleInfoA )
        goto LABEL_9;
    }
    v9 = _calloc_crt(LocaleInfoA, 1u);
    *address = v9;
    if ( !v9 )
    {
      if ( !v14 )
        return -1;
LABEL_9:
      free(v5);
      return -1;
    }
    if ( strncpy_s((int)v5, (char *)v9, LocaleInfoA, v5, LocaleInfoA - 1) )
      _invoke_watson(0, (int)v5, LocaleInfoA);
    if ( v14 )
      free(v5);
  }
  else
  {
    if ( lc_type )
      return -1;
    v11 = wcbuffer;
    if ( !__crtGetLocaleInfoW(plocinfo, localehandle, fieldtype, wcbuffer, 4) )
      return -1;
    *(_BYTE *)address = 0;
    do
    {
      v12 = *(_BYTE *)v11;
      if ( !isdigit(*(unsigned __int8 *)v11) )
        break;
      ++v11;
      *(_BYTE *)address = v12 + 10 * *(_BYTE *)address - 48;
    }
    while ( (int)v11 < (int)&__pPurecall );
  }
  return 0;
}
