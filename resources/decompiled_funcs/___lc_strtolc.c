int __cdecl __lc_strtolc(tagLC_STRINGS *names, char *locale)
{
  const char *v2; // esi
  unsigned int v4; // eax
  bool j; // zf
  const char *v6; // edi
  char v7; // bl
  int v8; // eax
  char *szCountry; // eax
  unsigned int v10; // [esp-Ch] [ebp-18h]
  const char *v12; // [esp-8h] [ebp-14h]
  unsigned int v13; // [esp-4h] [ebp-10h]
  int i; // [esp+18h] [ebp+Ch]

  memset((int)names, 0, sizeof(tagLC_STRINGS));
  v2 = locale;
  if ( !*locale )
    return 0;
  if ( *locale == 46 && locale[1] )
  {
    if ( strncpy_s(names->szCodePage, 0x10u, locale + 1, 0xFu) )
      _invoke_watson(0, 0, 0, 0, 0);
    names->szCodePage[15] = 0;
    return 0;
  }
  i = 0;
  strcspn((unsigned __int8 *)locale, "_.,");
  for ( j = v4 == 0; !j; j = v4 == 0 )
  {
    v6 = &v2[v4];
    v7 = v2[v4];
    if ( i )
    {
      if ( i == 1 )
      {
        if ( v4 >= 0x40 || v7 == 95 )
          return -1;
        v13 = v4;
        v12 = v2;
        v10 = 64;
        szCountry = names->szCountry;
      }
      else
      {
        if ( i != 2 || v4 >= 0x10 || v7 && v7 != 44 )
          return -1;
        v13 = v4;
        v12 = v2;
        v10 = 16;
        szCountry = names->szCodePage;
      }
      v8 = strncpy_s(szCountry, v10, v12, v13);
    }
    else
    {
      if ( v4 >= 0x40 || v7 == 46 )
        return -1;
      v8 = strncpy_s(names->szLanguage, 0x40u, v2, v4);
    }
    if ( v8 )
      _invoke_watson(0, 0, 0, 0, 0);
    if ( v7 == 44 || !v7 )
      return 0;
    ++i;
    v2 = v6 + 1;
    strcspn((unsigned __int8 *)v6 + 1, "_.,");
  }
  return -1;
}
