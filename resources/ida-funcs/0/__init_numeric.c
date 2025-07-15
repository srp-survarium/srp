int __cdecl __init_numeric(lconv *ploci)
{
  lconv *v2; // eax
  int *v4; // eax
  int *v5; // eax
  int v6; // esi
  unsigned int int_curr_symbol_high; // edi
  int v8; // eax
  int v9; // eax
  char *v10; // eax
  char v11; // cl
  char *v12; // esi
  localeinfo_struct locinfo; // [esp+Ch] [ebp-18h] BYREF
  char **p_grouping; // [esp+14h] [ebp-10h]
  int ret; // [esp+18h] [ebp-Ch]
  int *lc_refcount; // [esp+1Ch] [ebp-8h]
  int *lconv_num_refcount; // [esp+20h] [ebp-4h]
  lconv *lc; // [esp+2Ch] [ebp+8h]

  locinfo.locinfo = (threadlocaleinfostruct *)ploci;
  locinfo.mbcinfo = 0;
  if ( ploci->mon_grouping || ploci->mon_thousands_sep )
  {
    v2 = (lconv *)_calloc_crt(1u, 0x30u);
    lc = v2;
    if ( !v2 )
      return 1;
    qmemcpy(v2, *(const void **)&ploci[3].n_cs_precedes, sizeof(lconv));
    v4 = (int *)_malloc_crt(4u);
    lc_refcount = v4;
    if ( !v4 )
    {
      free(lc);
      return 1;
    }
    *v4 = 0;
    if ( !ploci->mon_grouping )
    {
      lc->decimal_point = __lconv_c.decimal_point;
      lc->thousands_sep = __lconv_c.thousands_sep;
      lconv_num_refcount = 0;
      lc->grouping = __lconv_c.grouping;
LABEL_26:
      *lc_refcount = 1;
      if ( lconv_num_refcount )
        *lconv_num_refcount = 1;
      goto LABEL_28;
    }
    v5 = (int *)_malloc_crt(4u);
    lconv_num_refcount = v5;
    if ( !v5 )
    {
      v6 = 1;
LABEL_11:
      free(lc);
      free(lc_refcount);
      return v6;
    }
    *v5 = 0;
    int_curr_symbol_high = HIWORD(ploci[1].int_curr_symbol);
    ret = __getlocaleinfo(&locinfo, 1, int_curr_symbol_high, 0xEu, &lc->decimal_point);
    v8 = __getlocaleinfo(&locinfo, 1, int_curr_symbol_high, 0xFu, &lc->thousands_sep);
    ret |= v8;
    p_grouping = &lc->grouping;
    v9 = __getlocaleinfo(&locinfo, 1, int_curr_symbol_high, 0x10u, &lc->grouping);
    if ( ret | v9 )
    {
      __free_lconv_num(lc);
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
  lconv_num_refcount = 0;
  lc_refcount = 0;
  lc = &__lconv_c;
LABEL_28:
  if ( ploci[3].negative_sign )
    InterlockedDecrement((volatile LONG *)ploci[3].negative_sign);
  if ( ploci[3].positive_sign )
  {
    if ( !InterlockedDecrement((volatile LONG *)ploci[3].positive_sign) )
    {
      free(ploci[3].positive_sign);
      free(*(void **)&ploci[3].n_cs_precedes);
    }
  }
  ploci[3].negative_sign = (char *)lconv_num_refcount;
  ploci[3].positive_sign = (char *)lc_refcount;
  *(_DWORD *)&ploci[3].n_cs_precedes = lc;
  return 0;
}
