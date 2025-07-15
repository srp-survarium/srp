int __cdecl __init_monetary(threadlocaleinfostruct *ploci)
{
  threadlocaleinfostruct *v1; // esi
  lconv *v2; // ebx
  int *v4; // eax
  int *v5; // eax
  unsigned int wCountry; // esi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // edi
  int v19; // edi
  int v20; // edi
  char *mon_grouping; // eax
  char v22; // cl
  char *v23; // esi
  int *v24; // ecx
  localeinfo_struct locinfo; // [esp+Ch] [ebp-10h] BYREF
  int *lc_refcount; // [esp+14h] [ebp-8h]
  int *lconv_mon_refcount; // [esp+18h] [ebp-4h]

  v1 = ploci;
  lconv_mon_refcount = 0;
  locinfo.locinfo = ploci;
  locinfo.mbcinfo = 0;
  if ( ploci->lc_handle[3] || ploci->lc_handle[4] )
  {
    v2 = (lconv *)_calloc_crt(1u, 0x30u);
    if ( !v2 )
      return 1;
    v4 = (int *)_malloc_crt(4u);
    lc_refcount = v4;
    if ( !v4 )
    {
      free(v2);
      return 1;
    }
    *v4 = 0;
    if ( !ploci->lc_handle[3] )
    {
      qmemcpy(v2, &__lconv_c, sizeof(lconv));
LABEL_25:
      v1 = ploci;
      v2->decimal_point = ploci->lconv->decimal_point;
      v2->thousands_sep = ploci->lconv->thousands_sep;
      v24 = lc_refcount;
      v2->grouping = ploci->lconv->grouping;
      *v24 = 1;
      if ( lconv_mon_refcount )
        *lconv_mon_refcount = 1;
      goto LABEL_27;
    }
    v5 = (int *)_malloc_crt(4u);
    lconv_mon_refcount = v5;
    if ( !v5 )
    {
      free(v2);
      free(lc_refcount);
      return 1;
    }
    *v5 = 0;
    wCountry = ploci->lc_id[3].wCountry;
    v7 = __getlocaleinfo(&locinfo, 1, wCountry, 0x15u, &v2->int_curr_symbol);
    v8 = __getlocaleinfo(&locinfo, 1, wCountry, 0x14u, &v2->currency_symbol) | v7;
    v9 = __getlocaleinfo(&locinfo, 1, wCountry, 0x16u, &v2->mon_decimal_point) | v8;
    v10 = __getlocaleinfo(&locinfo, 1, wCountry, 0x17u, &v2->mon_thousands_sep) | v9;
    v11 = __getlocaleinfo(&locinfo, 1, wCountry, 0x18u, &v2->mon_grouping) | v10;
    v12 = __getlocaleinfo(&locinfo, 1, wCountry, 0x50u, &v2->positive_sign) | v11;
    v13 = __getlocaleinfo(&locinfo, 1, wCountry, 0x51u, &v2->negative_sign) | v12;
    v14 = __getlocaleinfo(&locinfo, 0, wCountry, 0x1Au, (char **)&v2->int_frac_digits) | v13;
    v15 = __getlocaleinfo(&locinfo, 0, wCountry, 0x19u, (char **)&v2->frac_digits) | v14;
    v16 = __getlocaleinfo(&locinfo, 0, wCountry, 0x54u, (char **)&v2->p_cs_precedes) | v15;
    v17 = __getlocaleinfo(&locinfo, 0, wCountry, 0x55u, (char **)&v2->p_sep_by_space) | v16;
    v18 = __getlocaleinfo(&locinfo, 0, wCountry, 0x56u, (char **)&v2->n_cs_precedes) | v17;
    v19 = __getlocaleinfo(&locinfo, 0, wCountry, 0x57u, (char **)&v2->n_sep_by_space) | v18;
    v20 = __getlocaleinfo(&locinfo, 0, wCountry, 0x52u, (char **)&v2->p_sign_posn) | v19;
    if ( v20 | __getlocaleinfo(&locinfo, 0, wCountry, 0x53u, (char **)&v2->n_sign_posn) )
    {
      __free_lconv_mon(v2);
      free(v2);
      free(lc_refcount);
      free(lconv_mon_refcount);
      return 1;
    }
    mon_grouping = v2->mon_grouping;
    while ( 1 )
    {
      if ( !*mon_grouping )
        goto LABEL_25;
      v22 = *mon_grouping;
      if ( *mon_grouping >= 48 && v22 <= 57 )
        break;
      if ( v22 == 59 )
      {
        v23 = mon_grouping;
        do
        {
          *v23 = v23[1];
          ++v23;
        }
        while ( *v23 );
      }
      else
      {
LABEL_17:
        ++mon_grouping;
      }
    }
    *mon_grouping = v22 - 48;
    goto LABEL_17;
  }
  lconv_mon_refcount = 0;
  lc_refcount = 0;
  v2 = &__lconv_c;
LABEL_27:
  if ( v1->lconv_mon_refcount )
    InterlockedDecrement(v1->lconv_mon_refcount);
  if ( v1->lconv_intl_refcount )
  {
    if ( !InterlockedDecrement(v1->lconv_intl_refcount) )
    {
      free(v1->lconv);
      free(v1->lconv_intl_refcount);
    }
  }
  v1->lconv_mon_refcount = lconv_mon_refcount;
  v1->lconv_intl_refcount = lc_refcount;
  v1->lconv = v2;
  return 0;
}
