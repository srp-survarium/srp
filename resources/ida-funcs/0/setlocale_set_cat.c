char *__usercall setlocale_set_cat@<eax>(threadlocaleinfostruct *ploci@<esi>, char *locale@<ecx>, int category)
{
  _is_ctype_compatible *Lcid_c; // edi
  char *v6; // ebx
  int v7; // eax
  int v8; // eax
  unsigned int *v9; // ecx
  unsigned int id; // ecx
  _is_ctype_compatible *v11; // eax
  unsigned int v12; // edx
  unsigned __int8 *v13; // edx
  _is_ctype_compatible *v14; // eax
  unsigned int i; // eax
  void **p_refcount; // edi
  int *v17; // eax
  void *v18; // [esp-4h] [ebp-1D0h]
  unsigned __int8 dst[6]; // [esp+8h] [ebp-1C4h] BYREF
  unsigned int v20; // [esp+10h] [ebp-1BCh]
  unsigned int lc_codepage; // [esp+18h] [ebp-1B4h]
  tagLC_ID src; // [esp+1Ch] [ebp-1B0h] BYREF
  unsigned int v23; // [esp+24h] [ebp-1A8h]
  char *v24; // [esp+28h] [ebp-1A4h]
  unsigned __int8 *is_clike; // [esp+30h] [ebp-19Ch]
  unsigned int v26; // [esp+34h] [ebp-198h] BYREF
  unsigned int *v27; // [esp+38h] [ebp-194h]
  void *pointer; // [esp+3Ch] [ebp-190h]
  int v29; // [esp+40h] [ebp-18Ch]
  unsigned __int16 CharType[128]; // [esp+44h] [ebp-188h] BYREF
  unsigned __int8 str1[132]; // [esp+144h] [ebp-88h] BYREF

  Lcid_c = _getptd()->_setloc_data._Lcid_c;
  if ( !_expandlocale(locale, (char *)str1, 0x83u, &src, (unsigned __int8 *)&v26) )
    return 0;
  v6 = (char *)ploci + 16 * category;
  strcmp(str1, *((unsigned __int8 **)v6 + 18));
  if ( v7 )
  {
    strlen(str1);
    v29 = v8 + 5;
    pointer = _malloc_crt(v8 + 5);
    if ( !pointer )
      return 0;
    v24 = (char *)*((_DWORD *)v6 + 18);
    v27 = &ploci->lc_handle[category];
    v23 = *v27;
    is_clike = (unsigned __int8 *)&ploci->lc_id[category];
    memcpy((int)dst, (const __m128i *)is_clike, sizeof(dst));
    lc_codepage = ploci->lc_codepage;
    if ( strcpy_s((int)Lcid_c, (char *)pointer + 4, v29 - 4, (const char *)str1) )
      _invoke_watson((int)v6, (int)Lcid_c, (int)ploci);
    v9 = v27;
    *((_DWORD *)v6 + 18) = (char *)pointer + 4;
    *v9 = src.wLanguage;
    memcpy((int)is_clike, (const __m128i *)&src, 6u);
    if ( category == 2 )
    {
      v29 = 0;
      ploci->lc_codepage = v26;
      id = Lcid_c[4].id;
      is_clike = (unsigned __int8 *)Lcid_c[4].is_clike;
      v11 = Lcid_c;
      while ( ploci->lc_codepage != v11->id )
      {
        v12 = v11->id;
        ++v29;
        v11->id = id;
        v20 = v12;
        v13 = (unsigned __int8 *)v11->is_clike;
        v11->is_clike = (int)is_clike;
        id = v20;
        ++v11;
        is_clike = v13;
        if ( v29 >= 5 )
          goto LABEL_14;
      }
      if ( v29 )
      {
        v14 = &Lcid_c[v29];
        Lcid_c->id = v14->id;
        Lcid_c->is_clike = v14->is_clike;
        v14->id = id;
        v14->is_clike = (int)is_clike;
      }
LABEL_14:
      if ( v29 == 5 )
      {
        if ( __crtGetStringTypeA(0, 1u, first_127char, 127, CharType, ploci->lc_codepage, ploci->lc_handle[2], 1) )
        {
          for ( i = 0; i < 0x7F; ++i )
            CharType[i] &= 0x1FFu;
          Lcid_c->is_clike = memcmp((unsigned __int8 *)CharType, (unsigned __int8 *)ctype_loc_style, 0xFEu) == 0;
        }
        else
        {
          Lcid_c->is_clike = 0;
        }
        Lcid_c->id = ploci->lc_codepage;
      }
      ploci->lc_clike = Lcid_c->is_clike;
    }
    if ( category == 1 )
      ploci->lc_collate_cp = v26;
    if ( ((int (__cdecl *)())__lc_category[category].init)() )
    {
      v18 = pointer;
      *((_DWORD *)v6 + 18) = v24;
      free(v18);
      *v27 = v23;
      ploci->lc_codepage = lc_codepage;
      return 0;
    }
    if ( v24 != __clocalestr )
    {
      p_refcount = (void **)&ploci->lc_category[category].refcount;
      if ( !InterlockedDecrement((volatile LONG *)*p_refcount) )
      {
        free(*p_refcount);
        free(*((void **)v6 + 21));
        *((_DWORD *)v6 + 19) = 0;
      }
    }
    v17 = (int *)pointer;
    *(_DWORD *)pointer = 1;
    ploci->lc_category[category].refcount = v17;
  }
  return (char *)*((_DWORD *)v6 + 18);
}
