int __cdecl __init_ctype(threadlocaleinfostruct *ploci)
{
  int v1; // ebx
  unsigned __int8 *v2; // eax
  int j; // eax
  unsigned __int8 *v4; // eax
  int v5; // ecx
  int v6; // edi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // edi
  unsigned __int16 *v9; // ecx
  bool v10; // cc
  unsigned __int8 *v11; // edx
  unsigned __int16 *v12; // ecx
  unsigned __int8 v13; // dl
  int v14; // ecx
  unsigned __int8 *k; // ecx
  int *v16; // eax
  unsigned int lc_codepage; // [esp-Ch] [ebp-64h]
  localeinfo_struct locinfo; // [esp+Ch] [ebp-4Ch] BYREF
  const unsigned __int8 *v20; // [esp+14h] [ebp-44h]
  const unsigned __int16 *v21; // [esp+18h] [ebp-40h]
  unsigned __int16 *v22; // [esp+1Ch] [ebp-3Ch]
  const unsigned __int8 *v23; // [esp+20h] [ebp-38h]
  unsigned __int8 *v24; // [esp+24h] [ebp-34h]
  int mb_cur_max; // [esp+28h] [ebp-30h]
  int *refcount; // [esp+2Ch] [ebp-2Ch]
  unsigned __int8 *newcumap; // [esp+30h] [ebp-28h]
  unsigned __int8 *cbuffer; // [esp+34h] [ebp-24h]
  int i; // [esp+38h] [ebp-20h]
  unsigned __int16 *newctype1; // [esp+3Ch] [ebp-1Ch]
  _cpinfo lpCPInfo; // [esp+40h] [ebp-18h] BYREF

  v1 = 0;
  refcount = 0;
  newctype1 = 0;
  i = 0;
  newcumap = 0;
  cbuffer = 0;
  locinfo.locinfo = ploci;
  locinfo.mbcinfo = 0;
  if ( ploci->lc_handle[2] )
  {
    if ( !ploci->lc_codepage
      && __getlocaleinfo(&locinfo, 0, ploci->lc_id[2].wLanguage, 0x1004u, (char **)&ploci->lc_codepage) )
    {
      goto error_cleanup_0;
    }
    refcount = (int *)_malloc_crt(4u);
    newctype1 = (unsigned __int16 *)_calloc_crt(0x180u, 2u);
    i = (int)_calloc_crt(0x180u, 1u);
    newcumap = (unsigned __int8 *)_calloc_crt(0x180u, 1u);
    v2 = (unsigned __int8 *)_calloc_crt(0x101u, 1u);
    cbuffer = v2;
    if ( !refcount )
      goto error_cleanup_0;
    if ( !newctype1 )
      goto error_cleanup_0;
    if ( !v2 )
      goto error_cleanup_0;
    if ( !i )
      goto error_cleanup_0;
    if ( !newcumap )
      goto error_cleanup_0;
    *refcount = 0;
    for ( j = 0; j < 256; ++j )
      cbuffer[j] = j;
    if ( !GetCPInfo(ploci->lc_codepage, &lpCPInfo) || lpCPInfo.MaxCharSize > 5 )
      goto error_cleanup_0;
    mb_cur_max = LOWORD(lpCPInfo.MaxCharSize);
    if ( LOWORD(lpCPInfo.MaxCharSize) > 1u && lpCPInfo.LeadByte[0] )
    {
      v4 = &lpCPInfo.LeadByte[1];
      do
      {
        LOBYTE(v5) = *v4;
        if ( !*v4 )
          break;
        v6 = *(v4 - 1);
        v5 = (unsigned __int8)v5;
        while ( v6 <= v5 )
        {
          cbuffer[v6] = 32;
          v5 = *v4;
          ++v6;
        }
        v4 += 2;
      }
      while ( *(v4 - 1) );
    }
    lc_codepage = ploci->lc_codepage;
    v21 = newctype1 + 128;
    if ( __crtGetStringTypeA(0, 1u, (const char *)cbuffer, 256, newctype1 + 128, lc_codepage, 0, 0)
      && __crtLCMapStringA(
           0,
           ploci->lc_handle[2],
           0x100u,
           (const char *)cbuffer + 1,
           255,
           (char *)(i + 129),
           255,
           ploci->lc_codepage,
           0)
      && __crtLCMapStringA(
           0,
           ploci->lc_handle[2],
           0x200u,
           (const char *)cbuffer + 1,
           255,
           (char *)newcumap + 129,
           255,
           ploci->lc_codepage,
           0) )
    {
      v7 = (unsigned __int8 *)newctype1;
      v8 = (unsigned __int8 *)i;
      v9 = newctype1 + 127;
      v10 = mb_cur_max <= 1;
      newctype1[127] = 0;
      v11 = newcumap;
      v22 = v9;
      v8[127] = 0;
      v11[127] = 0;
      v8[128] = 0;
      v20 = v8 + 128;
      v23 = v11 + 128;
      v11[128] = 0;
      if ( !v10 && lpCPInfo.LeadByte[0] )
      {
        v12 = (unsigned __int16 *)&lpCPInfo.LeadByte[1];
        newctype1 = (unsigned __int16 *)&lpCPInfo.LeadByte[1];
        do
        {
          v13 = *(_BYTE *)v12;
          if ( !*(_BYTE *)v12 )
            break;
          v14 = *((unsigned __int8 *)v12 - 1);
          i = v14;
          if ( v14 <= v13 )
          {
            for ( k = &v7[2 * v14 + 256]; ; k = v24 )
            {
              ++i;
              *(_WORD *)k = 0x8000;
              v24 = k + 2;
              if ( i > *(unsigned __int8 *)newctype1 )
                break;
            }
          }
          v12 = newctype1 + 1;
          newctype1 = v12;
        }
        while ( *((_BYTE *)v12 - 1) );
      }
      memcpy(v7, v7 + 512, 0xFEu);
      memcpy(v8, v8 + 256, 0x7Fu);
      memcpy(newcumap, newcumap + 256, 0x7Fu);
      if ( ploci->ctype1_refcount )
      {
        if ( !InterlockedDecrement(ploci->ctype1_refcount) )
        {
          free(ploci->ctype1 - 127);
          free((void *)(ploci->pclmap - 128));
          free((void *)(ploci->pcumap - 128));
          free(ploci->ctype1_refcount);
        }
      }
      v16 = refcount;
      *refcount = 1;
      ploci->ctype1_refcount = v16;
      ploci->pctype = v21;
      ploci->ctype1 = v22;
      ploci->pclmap = v20;
      ploci->pcumap = v23;
      ploci->mb_cur_max = mb_cur_max;
    }
    else
    {
error_cleanup_0:
      free(refcount);
      free(newctype1);
      free((void *)i);
      free(newcumap);
      v1 = 1;
    }
    free(cbuffer);
    return v1;
  }
  else
  {
    if ( ploci->ctype1_refcount )
      InterlockedDecrement(ploci->ctype1_refcount);
    ploci->ctype1_refcount = 0;
    ploci->ctype1 = 0;
    ploci->pctype = asc_81F380;
    ploci->pclmap = &__newclmap[128];
    ploci->pcumap = &__newcumap[128];
    ploci->mb_cur_max = 1;
    return 0;
  }
}
