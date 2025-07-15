char *__fastcall setlocale_nolock(char *_locale, threadlocaleinfostruct *ploci, int _category)
{
  int v3; // ebx
  threadlocaleinfostruct *v4; // esi
  char *result; // eax
  unsigned __int8 *v6; // edi
  _BYTE *v7; // eax
  _BYTE *v8; // ebx
  unsigned int v9; // eax
  const $9F2E80260589685076FEBAEA1C0B7C54 *v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // ebx
  unsigned int v13; // eax
  unsigned int v14; // edi
  unsigned __int8 *v15; // edi
  unsigned __int8 **lc_category; // edi
  int v17; // eax
  int i; // [esp+10h] [ebp-94h]
  unsigned int len; // [esp+14h] [ebp-90h]
  unsigned int lena; // [esp+14h] [ebp-90h]
  int fLocaleSet; // [esp+18h] [ebp-8Ch]
  char lctemp[132]; // [esp+1Ch] [ebp-88h] BYREF

  v3 = 0;
  v4 = ploci;
  if ( _category )
  {
    if ( _locale )
      return setlocale_set_cat(ploci, _locale, _category);
    else
      return ploci->lc_category[_category].locale;
  }
  len = 1;
  fLocaleSet = 0;
  if ( !_locale )
    return setlocale_get_all(v4);
  if ( *_locale == 76 && _locale[1] == 67 && _locale[2] == 95 )
  {
    v6 = (unsigned __int8 *)_locale;
    do
    {
      strpbrk(v6, "=;");
      v8 = v7;
      if ( !v7 )
        return 0;
      v9 = v7 - v6;
      lena = v9;
      if ( !v9 || *v8 == 59 )
        return 0;
      i = 1;
      v10 = &__lc_category[1];
      while ( 1 )
      {
        if ( !strncmp(v10->catname, (const char *)v6, v9) )
        {
          strlen((unsigned __int8 *)v10->catname);
          if ( lena == v11 )
            break;
        }
        ++i;
        if ( (int)++v10 > (int)&__lc_category[5] )
          break;
        v9 = lena;
      }
      v12 = v8 + 1;
      strcspn(v12, ";");
      v14 = v13;
      if ( !v13 && *v12 != 59 )
        return 0;
      if ( i <= 5 )
      {
        if ( strncpy_s(lctemp, 0x83u, (const char *)v12, v13) )
          _invoke_watson(0, 0, 0, 0, 0);
        lctemp[v14] = 0;
        if ( setlocale_set_cat(ploci, lctemp, i) )
          ++fLocaleSet;
      }
      v15 = &v12[v14];
      if ( !*v15 )
        break;
      v6 = v15 + 1;
    }
    while ( *v6 );
    result = 0;
    if ( !fLocaleSet )
      return result;
    v4 = ploci;
    return setlocale_get_all(v4);
  }
  result = _expandlocale(_locale, lctemp, 0x83u, 0, 0);
  if ( result )
  {
    lc_category = (unsigned __int8 **)v4->lc_category;
    do
    {
      if ( v3 )
      {
        strcmp((unsigned __int8 *)lctemp, *lc_category);
        if ( !v17 || setlocale_set_cat(v4, lctemp, v3) )
          ++fLocaleSet;
        else
          len = 0;
      }
      ++v3;
      lc_category += 4;
    }
    while ( v3 <= 5 );
    result = 0;
    if ( len || fLocaleSet )
      return setlocale_get_all(v4);
  }
  return result;
}
