int __cdecl __init_monetary(threadlocaleinfostruct *ploci)
{
  threadlocaleinfostruct *v1; // esi
  unsigned __int8 *v2; // ebx
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  LCID wCountry; // esi
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
  char *v21; // eax
  char v22; // cl
  char *v23; // esi
  _DWORD *v24; // ecx
  localeinfo_struct v25; // [esp+Ch] [ebp-10h] BYREF
  void *pointer; // [esp+14h] [ebp-8h]
  void *v27; // [esp+18h] [ebp-4h]

  v1 = ploci;
  v27 = 0;
  v25.locinfo = ploci;
  v25.mbcinfo = 0;
  if ( ploci->lc_handle[3] || ploci->lc_handle[4] )
  {
    v2 = _calloc_crt(1u, 0x30u);
    if ( !v2 )
      return 1;
    v4 = _malloc_crt(4u);
    pointer = v4;
    if ( !v4 )
    {
      free(v2);
      return 1;
    }
    *v4 = 0;
    if ( !ploci->lc_handle[3] )
    {
      qmemcpy(v2, &__lconv_c, 0x30u);
LABEL_25:
      v1 = ploci;
      *(_DWORD *)v2 = ploci->lconv->decimal_point;
      *((_DWORD *)v2 + 1) = ploci->lconv->thousands_sep;
      v24 = pointer;
      *((_DWORD *)v2 + 2) = ploci->lconv->grouping;
      *v24 = 1;
      if ( v27 )
        *(_DWORD *)v27 = 1;
      goto LABEL_27;
    }
    v5 = _malloc_crt(4u);
    v27 = v5;
    if ( !v5 )
    {
      free(v2);
      free(pointer);
      return 1;
    }
    *v5 = 0;
    wCountry = ploci->lc_id[3].wCountry;
    v7 = __getlocaleinfo(&v25, 1, wCountry, 0x15u, (unsigned __int8 **)v2 + 3);
    v8 = __getlocaleinfo(&v25, 1, wCountry, 0x14u, (unsigned __int8 **)v2 + 4) | v7;
    v9 = __getlocaleinfo(&v25, 1, wCountry, 0x16u, (unsigned __int8 **)v2 + 5) | v8;
    v10 = __getlocaleinfo(&v25, 1, wCountry, 0x17u, (unsigned __int8 **)v2 + 6) | v9;
    v11 = __getlocaleinfo(&v25, 1, wCountry, 0x18u, (unsigned __int8 **)v2 + 7) | v10;
    v12 = __getlocaleinfo(&v25, 1, wCountry, 0x50u, (unsigned __int8 **)v2 + 8) | v11;
    v13 = __getlocaleinfo(&v25, 1, wCountry, 0x51u, (unsigned __int8 **)v2 + 9) | v12;
    v14 = __getlocaleinfo(&v25, 0, wCountry, 0x1Au, (unsigned __int8 **)v2 + 10) | v13;
    v15 = __getlocaleinfo(&v25, 0, wCountry, 0x19u, (unsigned __int8 **)(v2 + 41)) | v14;
    v16 = __getlocaleinfo(&v25, 0, wCountry, 0x54u, (unsigned __int8 **)(v2 + 42)) | v15;
    v17 = __getlocaleinfo(&v25, 0, wCountry, 0x55u, (unsigned __int8 **)(v2 + 43)) | v16;
    v18 = __getlocaleinfo(&v25, 0, wCountry, 0x56u, (unsigned __int8 **)v2 + 11) | v17;
    v19 = __getlocaleinfo(&v25, 0, wCountry, 0x57u, (unsigned __int8 **)(v2 + 45)) | v18;
    v20 = __getlocaleinfo(&v25, 0, wCountry, 0x52u, (unsigned __int8 **)(v2 + 46)) | v19;
    if ( v20 | __getlocaleinfo(&v25, 0, wCountry, 0x53u, (unsigned __int8 **)(v2 + 47)) )
    {
      __free_lconv_mon((lconv *)v2);
      free(v2);
      free(pointer);
      free(v27);
      return 1;
    }
    v21 = (char *)*((_DWORD *)v2 + 7);
    while ( 1 )
    {
      if ( !*v21 )
        goto LABEL_25;
      v22 = *v21;
      if ( *v21 >= 48 && v22 <= 57 )
        break;
      if ( v22 == 59 )
      {
        v23 = v21;
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
        ++v21;
      }
    }
    *v21 = v22 - 48;
    goto LABEL_17;
  }
  v27 = 0;
  pointer = 0;
  v2 = (unsigned __int8 *)&__lconv_c;
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
  v1->lconv_mon_refcount = (int *)v27;
  v1->lconv_intl_refcount = (int *)pointer;
  v1->lconv = (lconv *)v2;
  return 0;
}
