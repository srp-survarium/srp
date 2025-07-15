int __cdecl __lc_strtolc(tagLC_STRINGS *names, char *locale)
{
  int v2; // ebx
  const char *v3; // esi
  unsigned int v5; // eax
  bool i; // zf
  int v7; // edi
  int v8; // eax
  char *szCountry; // eax
  int v10; // [esp-Ch] [ebp-18h]
  const char *v12; // [esp-8h] [ebp-14h]
  unsigned int v13; // [esp-4h] [ebp-10h]
  unsigned __int8 *string; // [esp+18h] [ebp+Ch]

  v2 = 0;
  memset((int)names, 0, sizeof(tagLC_STRINGS));
  v3 = locale;
  if ( !*locale )
    return 0;
  if ( *locale == 46 && locale[1] )
  {
    if ( strncpy_s((int)names, names->szCodePage, 16, locale + 1, 0xFu) )
      _invoke_watson(0, (int)names, (int)locale);
    names->szCodePage[15] = 0;
    return 0;
  }
  string = 0;
  strcspn((unsigned __int8 *)locale, "_.,");
  for ( i = v5 == 0; !i; i = v5 == 0 )
  {
    v7 = (int)&v3[v5];
    LOBYTE(v2) = v3[v5];
    if ( string )
    {
      if ( string == (unsigned __int8 *)1 )
      {
        if ( v5 >= 0x40 || (_BYTE)v2 == 95 )
          return -1;
        v13 = v5;
        v12 = v3;
        v10 = 64;
        szCountry = names->szCountry;
      }
      else
      {
        if ( string != (unsigned __int8 *)2 || v5 >= 0x10 || (_BYTE)v2 && (_BYTE)v2 != 44 )
          return -1;
        v13 = v5;
        v12 = v3;
        v10 = 16;
        szCountry = names->szCodePage;
      }
      v8 = strncpy_s(v7, szCountry, v10, v12, v13);
    }
    else
    {
      if ( v5 >= 0x40 || (_BYTE)v2 == 46 )
        return -1;
      v8 = strncpy_s(v7, names->szLanguage, 64, v3, v5);
    }
    if ( v8 )
      _invoke_watson(v2, v7, (int)v3);
    if ( (_BYTE)v2 == 44 || !(_BYTE)v2 )
      return 0;
    ++string;
    v3 = (const char *)(v7 + 1);
    strcspn((unsigned __int8 *)(v7 + 1), "_.,");
  }
  return -1;
}
