char *__usercall setlocale_set_cat@<eax>(threadlocaleinfostruct *ploci@<esi>, char *locale@<ecx>, int category)
{
  _is_ctype_compatible *Lcid_c; // edi
  char *v6; // ebx
  int v7; // eax
  int v8; // eax
  unsigned int *v9; // ecx
  unsigned int id; // ecx
  unsigned int *p_id; // eax
  unsigned int v12; // edx
  int v13; // edx
  _is_ctype_compatible *v14; // eax
  unsigned int j; // eax
  void **p_refcount; // edi
  int *v17; // eax
  char *v18; // [esp-4h] [ebp-1D0h]
  tagLC_ID oldid; // [esp+8h] [ebp-1C4h] BYREF
  _is_ctype_compatible buf2; // [esp+10h] [ebp-1BCh]
  unsigned int oldcodepage; // [esp+18h] [ebp-1B4h]
  tagLC_ID idtemp; // [esp+1Ch] [ebp-1B0h] BYREF
  unsigned int oldhandle; // [esp+24h] [ebp-1A8h]
  char *oldlocale; // [esp+28h] [ebp-1A4h]
  _is_ctype_compatible buf1; // [esp+2Ch] [ebp-1A0h]
  unsigned int cptemp; // [esp+34h] [ebp-198h] BYREF
  unsigned int *v27; // [esp+38h] [ebp-194h]
  char *pch; // [esp+3Ch] [ebp-190h]
  int i; // [esp+40h] [ebp-18Ch]
  unsigned __int16 out[128]; // [esp+44h] [ebp-188h] BYREF
  char lctemp[132]; // [esp+144h] [ebp-88h] BYREF

  Lcid_c = _getptd()->_setloc_data._Lcid_c;
  if ( !_expandlocale(locale, lctemp, 0x83u, &idtemp, (unsigned __int8 *)&cptemp) )
    return 0;
  v6 = (char *)ploci + 16 * category;
  strcmp((unsigned __int8 *)lctemp, *((unsigned __int8 **)v6 + 18));
  if ( v7 )
  {
    strlen((unsigned __int8 *)lctemp);
    i = v8 + 5;
    pch = (char *)_malloc_crt(v8 + 5);
    if ( !pch )
      return 0;
    oldlocale = (char *)*((_DWORD *)v6 + 18);
    v27 = &ploci->lc_handle[category];
    oldhandle = *v27;
    buf1.is_clike = (int)&ploci->lc_id[category];
    memcpy((unsigned __int8 *)&oldid, (unsigned __int8 *)buf1.is_clike, sizeof(oldid));
    oldcodepage = ploci->lc_codepage;
    if ( strcpy_s(pch + 4, i - 4, lctemp) )
      _invoke_watson(0, 0, 0, 0, 0);
    v9 = v27;
    *((_DWORD *)v6 + 18) = pch + 4;
    *v9 = idtemp.wLanguage;
    memcpy((unsigned __int8 *)buf1.is_clike, (unsigned __int8 *)&idtemp, 6u);
    if ( category == 2 )
    {
      i = 0;
      ploci->lc_codepage = cptemp;
      id = Lcid_c[4].id;
      buf1.is_clike = Lcid_c[4].is_clike;
      p_id = &Lcid_c->id;
      while ( ploci->lc_codepage != *p_id )
      {
        v12 = *p_id;
        ++i;
        *p_id = id;
        buf2.id = v12;
        v13 = p_id[1];
        p_id[1] = buf1.is_clike;
        id = buf2.id;
        p_id += 2;
        buf1.is_clike = v13;
        if ( i >= 5 )
          goto LABEL_14;
      }
      if ( i )
      {
        v14 = &Lcid_c[i];
        Lcid_c->id = v14->id;
        Lcid_c->is_clike = v14->is_clike;
        v14->id = id;
        v14->is_clike = buf1.is_clike;
      }
LABEL_14:
      if ( i == 5 )
      {
        if ( __crtGetStringTypeA(0, 1u, first_127char, 127, out, ploci->lc_codepage, ploci->lc_handle[2], 1) )
        {
          for ( j = 0; j < 0x7F; ++j )
            out[j] &= 0x1FFu;
          Lcid_c->is_clike = memcmp(out, ctype_loc_style, 0xFEu) == 0;
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
      ploci->lc_collate_cp = cptemp;
    if ( ((int (__cdecl *)())__lc_category[category].init)() )
    {
      v18 = pch;
      *((_DWORD *)v6 + 18) = oldlocale;
      free(v18);
      *v27 = oldhandle;
      ploci->lc_codepage = oldcodepage;
      return 0;
    }
    if ( oldlocale != __clocalestr )
    {
      p_refcount = (void **)&ploci->lc_category[category].refcount;
      if ( !InterlockedDecrement((volatile LONG *)*p_refcount) )
      {
        free(*p_refcount);
        free(*((void **)v6 + 21));
        *((_DWORD *)v6 + 19) = 0;
      }
    }
    v17 = (int *)pch;
    *(_DWORD *)pch = 1;
    ploci->lc_category[category].refcount = v17;
  }
  return (char *)*((_DWORD *)v6 + 18);
}
