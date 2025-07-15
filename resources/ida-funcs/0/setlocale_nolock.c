char *__fastcall setlocale_nolock(char *_locale, threadlocaleinfostruct *ploci, int _category)
{
  int v3; // ebx
  threadlocaleinfostruct *v4; // esi
  char *result; // eax
  unsigned __int8 *v6; // edi
  _BYTE *v7; // eax
  _BYTE *v8; // ebx
  unsigned int v9; // eax
  const $6811DD5A8A1C5085C56CC46F8CE42219 *v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // ebx
  unsigned int v13; // eax
  int v14; // edi
  unsigned __int8 *v15; // edi
  unsigned __int8 **lc_category; // edi
  int v17; // eax
  int v19; // [esp+10h] [ebp-94h]
  int v20; // [esp+14h] [ebp-90h]
  unsigned int v21; // [esp+14h] [ebp-90h]
  int v22; // [esp+18h] [ebp-8Ch]
  char _Dst[132]; // [esp+1Ch] [ebp-88h] BYREF

  v3 = 0;
  v4 = ploci;
  if ( _category )
  {
    if ( _locale )
      return setlocale_set_cat(ploci, _locale, _category);
    else
      return ploci->lc_category[_category].locale;
  }
  v20 = 1;
  v22 = 0;
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
      v21 = v9;
      if ( !v9 || *v8 == 59 )
        return 0;
      v19 = 1;
      v10 = &__lc_category[1];
      while ( 1 )
      {
        if ( !strncmp(v10->catname, (const char *)v6, v9) )
        {
          strlen((unsigned __int8 *)v10->catname);
          if ( v21 == v11 )
            break;
        }
        ++v19;
        if ( (int)++v10 > (int)&__lc_category[5] )
          break;
        v9 = v21;
      }
      v12 = v8 + 1;
      strcspn(v12, ";");
      v14 = v13;
      if ( !v13 && *v12 != 59 )
        return 0;
      if ( v19 <= 5 )
      {
        if ( strncpy_s(v13, _Dst, 131, (const char *)v12, v13) )
          _invoke_watson((int)v12, v14, 0);
        _Dst[v14] = 0;
        if ( setlocale_set_cat(ploci, _Dst, v19) )
          ++v22;
      }
      v15 = &v12[v14];
      if ( !*v15 )
        break;
      v6 = v15 + 1;
    }
    while ( *v6 );
    result = 0;
    if ( !v22 )
      return result;
    v4 = ploci;
    return setlocale_get_all(v4);
  }
  result = _expandlocale(_locale, _Dst, 0x83u, 0, 0);
  if ( result )
  {
    lc_category = (unsigned __int8 **)v4->lc_category;
    do
    {
      if ( v3 )
      {
        strcmp((unsigned __int8 *)_Dst, *lc_category);
        if ( !v17 || setlocale_set_cat(v4, _Dst, v3) )
          ++v22;
        else
          v20 = 0;
      }
      ++v3;
      lc_category += 4;
    }
    while ( v3 <= 5 );
    result = 0;
    if ( v20 || v22 )
      return setlocale_get_all(v4);
  }
  return result;
}
