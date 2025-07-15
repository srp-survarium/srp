int __cdecl __init_numeric(threadlocaleinfostruct *ploci)
{
  unsigned __int8 *v2; // eax
  _DWORD *v4; // eax
  int *v5; // eax
  int v6; // esi
  LCID wCountry; // edi
  int v8; // eax
  int v9; // eax
  char *v10; // eax
  char v11; // cl
  char *v12; // esi
  localeinfo_struct v13; // [esp+Ch] [ebp-18h] BYREF
  char **p_grouping; // [esp+14h] [ebp-10h]
  int v15; // [esp+18h] [ebp-Ch]
  void *v16; // [esp+1Ch] [ebp-8h]
  int *v17; // [esp+20h] [ebp-4h]
  lconv *pointer; // [esp+2Ch] [ebp+8h]

  v13.locinfo = ploci;
  v13.mbcinfo = 0;
  if ( ploci->lc_handle[4] || ploci->lc_handle[3] )
  {
    v2 = _calloc_crt(1u, 0x30u);
    pointer = (lconv *)v2;
    if ( !v2 )
      return 1;
    qmemcpy(v2, ploci->lconv, 0x30u);
    v4 = _malloc_crt(4u);
    v16 = v4;
    if ( !v4 )
    {
      free(pointer);
      return 1;
    }
    *v4 = 0;
    if ( !ploci->lc_handle[4] )
    {
      pointer->decimal_point = __lconv_c.decimal_point;
      pointer->thousands_sep = __lconv_c.thousands_sep;
      v17 = 0;
      pointer->grouping = __lconv_c.grouping;
LABEL_26:
      *(_DWORD *)v16 = 1;
      if ( v17 )
        *v17 = 1;
      goto LABEL_28;
    }
    v5 = (int *)_malloc_crt(4u);
    v17 = v5;
    if ( !v5 )
    {
      v6 = 1;
LABEL_11:
      free(pointer);
      free(v16);
      return v6;
    }
    *v5 = 0;
    wCountry = ploci->lc_id[4].wCountry;
    v15 = __getlocaleinfo(&v13, 1, wCountry, 0xEu, (unsigned __int8 **)pointer);
    v8 = __getlocaleinfo(&v13, 1, wCountry, 0xFu, (unsigned __int8 **)&pointer->thousands_sep);
    v15 |= v8;
    p_grouping = &pointer->grouping;
    v9 = __getlocaleinfo(&v13, 1, wCountry, 0x10u, (unsigned __int8 **)&pointer->grouping);
    if ( v15 | v9 )
    {
      __free_lconv_num(pointer);
      v6 = -1;
      goto LABEL_11;
    }
    v10 = *p_grouping;
    while ( 1 )
    {
      if ( !*v10 )
        goto LABEL_26;
      v11 = *v10;
      if ( *v10 >= 48 && v11 <= 57 )
        break;
      if ( v11 == 59 )
      {
        v12 = v10;
        do
        {
          *v12 = v12[1];
          ++v12;
        }
        while ( *v12 );
      }
      else
      {
LABEL_18:
        ++v10;
      }
    }
    *v10 = v11 - 48;
    goto LABEL_18;
  }
  v17 = 0;
  v16 = 0;
  pointer = &__lconv_c;
LABEL_28:
  if ( ploci->lconv_num_refcount )
    InterlockedDecrement(ploci->lconv_num_refcount);
  if ( ploci->lconv_intl_refcount )
  {
    if ( !InterlockedDecrement(ploci->lconv_intl_refcount) )
    {
      free(ploci->lconv_intl_refcount);
      free(ploci->lconv);
    }
  }
  ploci->lconv_num_refcount = v17;
  ploci->lconv_intl_refcount = (int *)v16;
  ploci->lconv = pointer;
  return 0;
}
