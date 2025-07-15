char *__usercall setlocale_get_all@<eax>(threadlocaleinfostruct *ploci@<esi>)
{
  char *result; // eax
  char *v2; // edi
  unsigned int *v3; // ebx
  int v4; // eax
  char *pointer; // [esp+4h] [ebp-14h]
  int v6; // [esp+8h] [ebp-10h]
  threadlocaleinfostruct::<unnamed_type_lc_category> *v7; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h]
  const $6811DD5A8A1C5085C56CC46F8CE42219 *v9; // [esp+14h] [ebp-4h]

  v6 = 1;
  result = (char *)_malloc_crt(0x355u);
  pointer = result;
  if ( result )
  {
    v2 = result + 4;
    result[4] = 0;
    *(_DWORD *)result = 1;
    v8 = 1;
    v3 = &ploci->lc_handle[1];
    v7 = &ploci->lc_category[1];
    _strcats(result + 4, 0x351u, 3, __lc_category[1].catname, "=", ploci->lc_category[1].locale);
    v9 = &__lc_category[1];
    do
    {
      if ( strcat_s((int)v2, v2, 849, ";") )
        _invoke_watson((int)v3, (int)v2, (int)ploci);
      strcmp((unsigned __int8 *)v7->locale, (unsigned __int8 *)v3[22]);
      if ( v4 )
        v6 = 0;
      ++v8;
      ++v9;
      v3 = (unsigned int *)((char *)ploci + 16 * v8);
      v7 = (threadlocaleinfostruct::<unnamed_type_lc_category> *)(v3 + 18);
      _strcats(v2, 0x351u, 3, v9->catname, "=", v3[18]);
    }
    while ( (int)v9 < (int)&__lc_category[5] );
    if ( v6 )
    {
      free(pointer);
      if ( ploci->lc_category[0].refcount && !InterlockedDecrement(ploci->lc_category[0].refcount) )
        free(ploci->lc_category[0].refcount);
      if ( ploci->lc_category[0].wrefcount && !InterlockedDecrement(ploci->lc_category[0].wrefcount) )
        free(ploci->lc_category[0].wrefcount);
      result = ploci->lc_category[2].locale;
      ploci->lc_category[0].wrefcount = 0;
      ploci->lc_category[0].wlocale = 0;
      ploci->lc_category[0].refcount = 0;
      ploci->lc_category[0].locale = 0;
    }
    else
    {
      if ( ploci->lc_category[0].refcount && !InterlockedDecrement(ploci->lc_category[0].refcount) )
        free(ploci->lc_category[0].refcount);
      if ( ploci->lc_category[0].wrefcount )
      {
        if ( !InterlockedDecrement(ploci->lc_category[0].wrefcount) )
          free(ploci->lc_category[0].wrefcount);
      }
      ploci->lc_category[0].wrefcount = 0;
      ploci->lc_category[0].wlocale = 0;
      ploci->lc_category[0].refcount = (int *)pointer;
      ploci->lc_category[0].locale = v2;
      return v2;
    }
  }
  return result;
}
