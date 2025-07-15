int __cdecl __init_ctype(threadlocaleinfostruct *ploci)
{
  int v1; // ebx
  unsigned __int8 *v2; // eax
  int i; // eax
  unsigned __int8 *v4; // eax
  int v5; // ecx
  int v6; // edi
  const __m128i *v7; // eax
  const __m128i *v8; // edi
  unsigned __int8 *v9; // ecx
  bool v10; // cc
  unsigned __int8 *v11; // edx
  unsigned __int8 *v12; // ecx
  unsigned __int8 v13; // dl
  unsigned __int8 *v14; // ecx
  __int16 *j; // ecx
  int *v16; // eax
  UINT lc_codepage; // [esp-Ch] [ebp-64h]
  localeinfo_struct v19; // [esp+Ch] [ebp-4Ch] BYREF
  const unsigned __int8 *v20; // [esp+14h] [ebp-44h]
  const unsigned __int16 *v21; // [esp+18h] [ebp-40h]
  unsigned __int16 *v22; // [esp+1Ch] [ebp-3Ch]
  const unsigned __int8 *v23; // [esp+20h] [ebp-38h]
  __int16 *v24; // [esp+24h] [ebp-34h]
  int MaxCharSize_low; // [esp+28h] [ebp-30h]
  void *pointer; // [esp+2Ch] [ebp-2Ch]
  unsigned __int8 *v27; // [esp+30h] [ebp-28h]
  char *lpSrcStr; // [esp+34h] [ebp-24h]
  unsigned __int8 *v29; // [esp+38h] [ebp-20h]
  unsigned __int8 *dst; // [esp+3Ch] [ebp-1Ch]
  _cpinfo CPInfo; // [esp+40h] [ebp-18h] BYREF

  v1 = 0;
  pointer = 0;
  dst = 0;
  v29 = 0;
  v27 = 0;
  lpSrcStr = 0;
  v19.locinfo = ploci;
  v19.mbcinfo = 0;
  if ( ploci->lc_handle[2] )
  {
    if ( !ploci->lc_codepage
      && __getlocaleinfo(&v19, 0, ploci->lc_id[2].wLanguage, 0x1004u, (unsigned __int8 **)&ploci->lc_codepage) )
    {
      goto error_cleanup_0;
    }
    pointer = _malloc_crt(4u);
    dst = _calloc_crt(0x180u, 2u);
    v29 = _calloc_crt(0x180u, 1u);
    v27 = _calloc_crt(0x180u, 1u);
    v2 = _calloc_crt(0x101u, 1u);
    lpSrcStr = (char *)v2;
    if ( !pointer )
      goto error_cleanup_0;
    if ( !dst )
      goto error_cleanup_0;
    if ( !v2 )
      goto error_cleanup_0;
    if ( !v29 )
      goto error_cleanup_0;
    if ( !v27 )
      goto error_cleanup_0;
    *(_DWORD *)pointer = 0;
    for ( i = 0; i < 256; ++i )
      lpSrcStr[i] = i;
    if ( !GetCPInfo(ploci->lc_codepage, &CPInfo) || CPInfo.MaxCharSize > 5 )
      goto error_cleanup_0;
    MaxCharSize_low = LOWORD(CPInfo.MaxCharSize);
    if ( LOWORD(CPInfo.MaxCharSize) > 1u && CPInfo.LeadByte[0] )
    {
      v4 = &CPInfo.LeadByte[1];
      do
      {
        LOBYTE(v5) = *v4;
        if ( !*v4 )
          break;
        v6 = *(v4 - 1);
        v5 = (unsigned __int8)v5;
        while ( v6 <= v5 )
        {
          lpSrcStr[v6] = 32;
          v5 = *v4;
          ++v6;
        }
        v4 += 2;
      }
      while ( *(v4 - 1) );
    }
    lc_codepage = ploci->lc_codepage;
    v21 = (const unsigned __int16 *)(dst + 256);
    if ( __crtGetStringTypeA(0, 1u, lpSrcStr, 256, (unsigned __int16 *)dst + 128, lc_codepage, 0, 0)
      && __crtLCMapStringA(
           0,
           ploci->lc_handle[2],
           0x100u,
           lpSrcStr + 1,
           255,
           (wchar_t *)(v29 + 129),
           255,
           ploci->lc_codepage,
           0)
      && __crtLCMapStringA(
           0,
           ploci->lc_handle[2],
           0x200u,
           lpSrcStr + 1,
           255,
           (wchar_t *)(v27 + 129),
           255,
           ploci->lc_codepage,
           0) )
    {
      v7 = (const __m128i *)dst;
      v8 = (const __m128i *)v29;
      v9 = dst + 254;
      v10 = MaxCharSize_low <= 1;
      *((_WORD *)dst + 127) = 0;
      v11 = v27;
      v22 = (unsigned __int16 *)v9;
      v8[7].m128i_i8[15] = 0;
      v11[127] = 0;
      v8[8].m128i_i8[0] = 0;
      v20 = (const unsigned __int8 *)&v8[8];
      v23 = v11 + 128;
      v11[128] = 0;
      if ( !v10 && CPInfo.LeadByte[0] )
      {
        v12 = &CPInfo.LeadByte[1];
        dst = &CPInfo.LeadByte[1];
        do
        {
          v13 = *v12;
          if ( !*v12 )
            break;
          v14 = (unsigned __int8 *)*(v12 - 1);
          v29 = v14;
          if ( (int)v14 <= v13 )
          {
            for ( j = &v7[16].m128i_i16[(_DWORD)v14]; ; j = v24 )
            {
              ++v29;
              *j = 0x8000;
              v24 = j + 1;
              if ( (int)v29 > *dst )
                break;
            }
          }
          v12 = dst + 2;
          dst = v12;
        }
        while ( *(v12 - 1) );
      }
      memcpy((int)v7, v7 + 32, 0xFEu);
      memcpy((int)v8, v8 + 16, 0x7Fu);
      memcpy((int)v27, (const __m128i *)v27 + 16, 0x7Fu);
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
      v16 = (int *)pointer;
      *(_DWORD *)pointer = 1;
      ploci->ctype1_refcount = v16;
      ploci->pctype = v21;
      ploci->ctype1 = v22;
      ploci->pclmap = v20;
      ploci->pcumap = v23;
      ploci->mb_cur_max = MaxCharSize_low;
    }
    else
    {
error_cleanup_0:
      free(pointer);
      free(dst);
      free(v29);
      free(v27);
      v1 = 1;
    }
    free(lpSrcStr);
    return v1;
  }
  else
  {
    if ( ploci->ctype1_refcount )
      InterlockedDecrement(ploci->ctype1_refcount);
    ploci->ctype1_refcount = 0;
    ploci->ctype1 = 0;
    ploci->pctype = asc_6B79D8;
    ploci->pclmap = &__newclmap[128];
    ploci->pcumap = &__newcumap[128];
    ploci->mb_cur_max = 1;
    return 0;
  }
}
