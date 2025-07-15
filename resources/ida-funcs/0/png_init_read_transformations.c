int __cdecl png_init_read_transformations(int a1)
{
  unsigned int v1; // edx
  BOOL v2; // eax
  int v3; // eax
  BOOL v4; // eax
  int v5; // edx
  int result; // eax
  char v7; // [esp+4h] [ebp-88h]
  char v8; // [esp+8h] [ebp-84h]
  int v9; // [esp+18h] [ebp-74h]
  int v10; // [esp+18h] [ebp-74h]
  int v11; // [esp+18h] [ebp-74h]
  int v12; // [esp+1Ch] [ebp-70h]
  int m; // [esp+20h] [ebp-6Ch]
  int n; // [esp+20h] [ebp-6Ch]
  int ii; // [esp+20h] [ebp-6Ch]
  unsigned __int16 v16; // [esp+24h] [ebp-68h]
  unsigned __int16 v17; // [esp+28h] [ebp-64h]
  unsigned __int16 v18; // [esp+2Ch] [ebp-60h]
  int v19; // [esp+30h] [ebp-5Ch]
  __int16 v20; // [esp+34h] [ebp-58h]
  unsigned __int8 v21; // [esp+36h] [ebp-56h]
  int v22; // [esp+38h] [ebp-54h]
  int k; // [esp+3Ch] [ebp-50h]
  int v24; // [esp+40h] [ebp-4Ch]
  int j; // [esp+44h] [ebp-48h]
  int v26; // [esp+48h] [ebp-44h]
  BOOL v27; // [esp+4Ch] [ebp-40h]
  int v28; // [esp+50h] [ebp-3Ch]
  BOOL v29; // [esp+54h] [ebp-38h]
  int v30; // [esp+58h] [ebp-34h]
  unsigned __int16 v31; // [esp+5Ch] [ebp-30h]
  unsigned __int16 v32; // [esp+60h] [ebp-2Ch]
  unsigned __int16 v33; // [esp+64h] [ebp-28h]
  int v34; // [esp+6Ch] [ebp-20h]
  int v35; // [esp+70h] [ebp-1Ch]
  unsigned __int8 v36; // [esp+74h] [ebp-18h]
  unsigned __int8 v37; // [esp+75h] [ebp-17h]
  unsigned __int8 v38; // [esp+76h] [ebp-16h]
  __int16 v39; // [esp+78h] [ebp-14h]
  char v40; // [esp+7Ah] [ebp-12h]
  int v41; // [esp+7Ch] [ebp-10h]
  int i; // [esp+80h] [ebp-Ch]
  int v43; // [esp+84h] [ebp-8h]
  int v44; // [esp+88h] [ebp-4h]

  v44 = 0;
  if ( *(_DWORD *)(a1 + 376) )
  {
    if ( *(_DWORD *)(a1 + 380) )
      v44 = sub_467DB0(*(_DWORD *)(a1 + 376), *(_DWORD *)(a1 + 380));
    else
      *(_DWORD *)(a1 + 380) = png_reciprocal(*(_DWORD *)(a1 + 376));
  }
  else if ( *(_DWORD *)(a1 + 380) )
  {
    *(_DWORD *)(a1 + 376) = png_reciprocal(*(_DWORD *)(a1 + 380));
  }
  else
  {
    *(_DWORD *)(a1 + 376) = 100000;
    *(_DWORD *)(a1 + 380) = 100000;
  }
  if ( v44 )
    v1 = *(_DWORD *)(a1 + 116) | 0x2000;
  else
    v1 = *(_DWORD *)(a1 + 116) & 0xFFFFDFFF;
  *(_DWORD *)(a1 + 116) = v1;
  if ( (*(_DWORD *)(a1 + 116) & 0x40000) != 0 && (*(_DWORD *)(a1 + 116) & 0x80) == 0 )
  {
    *(_DWORD *)(a1 + 116) &= 0xFD7FFEFF;
    *(_DWORD *)(a1 + 112) &= ~0x2000u;
    *(_WORD *)(a1 + 308) = 0;
  }
  if ( !png_gamma_significant(*(_DWORD *)(a1 + 380)) )
  {
    *(_DWORD *)(a1 + 116) &= ~0x800000u;
    *(_DWORD *)(a1 + 112) &= ~0x2000u;
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x100) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 315) & 2) == 0 )
      *(_DWORD *)(a1 + 108) |= 0x800u;
  }
  else if ( (*(_DWORD *)(a1 + 116) & 0x80) != 0
         && (*(_DWORD *)(a1 + 116) & 0x4000) != 0
         && *(unsigned __int16 *)(a1 + 342) == *(unsigned __int16 *)(a1 + 344)
         && *(unsigned __int16 *)(a1 + 342) == *(unsigned __int16 *)(a1 + 346) )
  {
    *(_DWORD *)(a1 + 108) |= 0x800u;
    *(_WORD *)(a1 + 348) = *(_WORD *)(a1 + 342);
  }
  if ( *(_BYTE *)(a1 + 315) == 3 )
    sub_467E00(a1);
  else
    sub_467FD0(a1);
  if ( (*(_DWORD *)(a1 + 116) & 0x200) != 0
    && (*(_DWORD *)(a1 + 116) & 0x80) != 0
    && (*(_DWORD *)(a1 + 116) & 0x100) == 0
    && *(_BYTE *)(a1 + 316) != 16 )
  {
    *(_WORD *)(a1 + 342) = (255 * (unsigned int)*(unsigned __int16 *)(a1 + 342) + 32895) >> 16;
    *(_WORD *)(a1 + 344) = (255 * (unsigned int)*(unsigned __int16 *)(a1 + 344) + 32895) >> 16;
    *(_WORD *)(a1 + 346) = (255 * (unsigned int)*(unsigned __int16 *)(a1 + 346) + 32895) >> 16;
    *(_WORD *)(a1 + 348) = (255 * (unsigned int)*(unsigned __int16 *)(a1 + 348) + 32895) >> 16;
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x4000400) != 0
    && (*(_DWORD *)(a1 + 116) & 0x80) != 0
    && (*(_DWORD *)(a1 + 116) & 0x100) == 0
    && *(_BYTE *)(a1 + 316) == 16 )
  {
    *(_WORD *)(a1 + 342) *= 257;
    *(_WORD *)(a1 + 344) *= 257;
    *(_WORD *)(a1 + 346) *= 257;
    *(_WORD *)(a1 + 348) *= 257;
  }
  *(_DWORD *)(a1 + 350) = *(_DWORD *)(a1 + 340);
  *(_DWORD *)(a1 + 354) = *(_DWORD *)(a1 + 344);
  *(_WORD *)(a1 + 358) = *(_WORD *)(a1 + 348);
  if ( (*(_DWORD *)(a1 + 116) & 0x2000) != 0
    || ((unsigned int)&loc_600000 & *(_DWORD *)(a1 + 116)) != 0
    && (png_gamma_significant(*(_DWORD *)(a1 + 376)) || png_gamma_significant(*(_DWORD *)(a1 + 380)))
    || (*(_DWORD *)(a1 + 116) & 0x80) != 0
    && (png_gamma_significant(*(_DWORD *)(a1 + 376))
     || png_gamma_significant(*(_DWORD *)(a1 + 380))
     || *(_BYTE *)(a1 + 332) == 3 && png_gamma_significant(*(_DWORD *)(a1 + 336)))
    || (*(_DWORD *)(a1 + 116) & 0x800000) != 0 && png_gamma_significant(*(_DWORD *)(a1 + 380)) )
  {
    png_build_gamma_table(a1, *(unsigned __int8 *)(a1 + 316));
    if ( (*(_DWORD *)(a1 + 116) & 0x80) != 0 )
    {
      if ( ((unsigned int)&loc_600000 & *(_DWORD *)(a1 + 116)) != 0 )
        png_warning(a1, "libpng does not support gamma+background+rgb_to_gray");
      if ( *(_BYTE *)(a1 + 315) == 3 )
      {
        v41 = *(_DWORD *)(a1 + 296);
        v43 = *(unsigned __int16 *)(a1 + 300);
        if ( *(_BYTE *)(a1 + 332) == 2 )
        {
          LOBYTE(v39) = *(_BYTE *)(*(unsigned __int16 *)(a1 + 342) + *(_DWORD *)(a1 + 384));
          HIBYTE(v39) = *(_BYTE *)(*(unsigned __int16 *)(a1 + 344) + *(_DWORD *)(a1 + 384));
          v40 = *(_BYTE *)(*(unsigned __int16 *)(a1 + 346) + *(_DWORD *)(a1 + 384));
          v36 = *(_BYTE *)(*(unsigned __int16 *)(a1 + 342) + *(_DWORD *)(a1 + 396));
          v37 = *(_BYTE *)(*(unsigned __int16 *)(a1 + 344) + *(_DWORD *)(a1 + 396));
          v38 = *(_BYTE *)(*(unsigned __int16 *)(a1 + 346) + *(_DWORD *)(a1 + 396));
        }
        else
        {
          v8 = *(_BYTE *)(a1 + 332);
          switch ( v8 )
          {
            case 1:
              v35 = *(_DWORD *)(a1 + 380);
              v34 = 100000;
              v2 = png_gamma_significant(100000);
              break;
            case 2:
              v35 = png_reciprocal(*(_DWORD *)(a1 + 376));
              v34 = png_reciprocal2(*(_DWORD *)(a1 + 376), *(_DWORD *)(a1 + 380));
              v2 = png_gamma_significant(v34);
              break;
            case 3:
              v35 = png_reciprocal(*(_DWORD *)(a1 + 336));
              v34 = png_reciprocal2(*(_DWORD *)(a1 + 336), *(_DWORD *)(a1 + 380));
              v2 = png_gamma_significant(v34);
              break;
            default:
              v35 = 100000;
              v34 = 100000;
              v2 = png_gamma_significant(100000);
              break;
          }
          if ( v2 )
          {
            LOBYTE(v39) = png_gamma_8bit_correct(*(unsigned __int16 *)(a1 + 342), v34);
            HIBYTE(v39) = png_gamma_8bit_correct(*(unsigned __int16 *)(a1 + 344), v34);
            v40 = png_gamma_8bit_correct(*(unsigned __int16 *)(a1 + 346), v34);
          }
          else
          {
            LOBYTE(v39) = *(_BYTE *)(a1 + 342);
            HIBYTE(v39) = *(_BYTE *)(a1 + 344);
            v40 = *(_BYTE *)(a1 + 346);
          }
          if ( png_gamma_significant(v35) )
          {
            v36 = png_gamma_8bit_correct(*(unsigned __int16 *)(a1 + 342), v35);
            v37 = png_gamma_8bit_correct(*(unsigned __int16 *)(a1 + 344), v35);
            v38 = png_gamma_8bit_correct(*(unsigned __int16 *)(a1 + 346), v35);
          }
          else
          {
            v36 = *(_BYTE *)(a1 + 342);
            v37 = *(_BYTE *)(a1 + 344);
            v38 = *(_BYTE *)(a1 + 346);
          }
        }
        for ( i = 0; i < v43; ++i )
        {
          if ( i >= *(unsigned __int16 *)(a1 + 308) || *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + i) == 255 )
          {
            *(_BYTE *)(v41 + 3 * i) = *(_BYTE *)(*(unsigned __int8 *)(v41 + 3 * i) + *(_DWORD *)(a1 + 384));
            *(_BYTE *)(v41 + 3 * i + 1) = *(_BYTE *)(*(unsigned __int8 *)(v41 + 3 * i + 1) + *(_DWORD *)(a1 + 384));
            *(_BYTE *)(v41 + 3 * i + 2) = *(_BYTE *)(*(unsigned __int8 *)(v41 + 3 * i + 2) + *(_DWORD *)(a1 + 384));
          }
          else if ( *(_BYTE *)(*(_DWORD *)(a1 + 420) + i) )
          {
            v33 = *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + i)
                * *(unsigned __int8 *)(*(unsigned __int8 *)(v41 + 3 * i) + *(_DWORD *)(a1 + 396))
                + (255 - *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + i)) * v36
                + 128;
            *(_BYTE *)(v41 + 3 * i) = *(_BYTE *)((unsigned __int8)((unsigned __int16)(((int)v33 >> 8) + v33) >> 8)
                                               + *(_DWORD *)(a1 + 392));
            v32 = *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + i)
                * *(unsigned __int8 *)(*(unsigned __int8 *)(v41 + 3 * i + 1) + *(_DWORD *)(a1 + 396))
                + (255 - *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + i)) * v37
                + 128;
            *(_BYTE *)(v41 + 3 * i + 1) = *(_BYTE *)((unsigned __int8)((unsigned __int16)(((int)v32 >> 8) + v32) >> 8)
                                                   + *(_DWORD *)(a1 + 392));
            v31 = *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + i)
                * *(unsigned __int8 *)(*(unsigned __int8 *)(v41 + 3 * i + 2) + *(_DWORD *)(a1 + 396))
                + (255 - *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + i)) * v38
                + 128;
            *(_BYTE *)(v41 + 3 * i + 2) = *(_BYTE *)((unsigned __int8)((unsigned __int16)(((int)v31 >> 8) + v31) >> 8)
                                                   + *(_DWORD *)(a1 + 392));
          }
          else
          {
            v3 = v41 + 3 * i;
            *(_WORD *)v3 = v39;
            *(_BYTE *)(v3 + 2) = v40;
          }
        }
        *(_DWORD *)(a1 + 116) &= 0xFFFFDF7F;
      }
      else
      {
        v28 = 100000;
        v7 = *(_BYTE *)(a1 + 332);
        switch ( v7 )
        {
          case 1:
            v30 = *(_DWORD *)(a1 + 380);
            v4 = png_gamma_significant(v30);
            break;
          case 2:
            v30 = png_reciprocal(*(_DWORD *)(a1 + 376));
            v28 = png_reciprocal2(*(_DWORD *)(a1 + 376), *(_DWORD *)(a1 + 380));
            v4 = png_gamma_significant(v30);
            break;
          case 3:
            v30 = png_reciprocal(*(_DWORD *)(a1 + 336));
            v28 = png_reciprocal2(*(_DWORD *)(a1 + 336), *(_DWORD *)(a1 + 380));
            v4 = png_gamma_significant(v30);
            break;
          default:
            png_error(a1, (int)"invalid background gamma type");
        }
        v27 = v4;
        v29 = png_gamma_significant(v28);
        if ( v27 )
          *(_WORD *)(a1 + 358) = png_gamma_correct(a1, *(unsigned __int16 *)(a1 + 348), v30);
        if ( v29 )
          *(_WORD *)(a1 + 348) = png_gamma_correct(a1, *(unsigned __int16 *)(a1 + 348), v28);
        if ( *(unsigned __int16 *)(a1 + 342) == *(unsigned __int16 *)(a1 + 344)
          && *(unsigned __int16 *)(a1 + 342) == *(unsigned __int16 *)(a1 + 346)
          && *(unsigned __int16 *)(a1 + 342) == *(unsigned __int16 *)(a1 + 348) )
        {
          *(_WORD *)(a1 + 356) = *(_WORD *)(a1 + 358);
          *(_WORD *)(a1 + 354) = *(_WORD *)(a1 + 356);
          *(_WORD *)(a1 + 352) = *(_WORD *)(a1 + 354);
          *(_WORD *)(a1 + 346) = *(_WORD *)(a1 + 348);
          *(_WORD *)(a1 + 344) = *(_WORD *)(a1 + 346);
          *(_WORD *)(a1 + 342) = *(_WORD *)(a1 + 344);
        }
        else
        {
          if ( v27 )
          {
            *(_WORD *)(a1 + 352) = png_gamma_correct(a1, *(unsigned __int16 *)(a1 + 342), v30);
            *(_WORD *)(a1 + 354) = png_gamma_correct(a1, *(unsigned __int16 *)(a1 + 344), v30);
            *(_WORD *)(a1 + 356) = png_gamma_correct(a1, *(unsigned __int16 *)(a1 + 346), v30);
          }
          if ( v29 )
          {
            *(_WORD *)(a1 + 342) = png_gamma_correct(a1, *(unsigned __int16 *)(a1 + 342), v28);
            *(_WORD *)(a1 + 344) = png_gamma_correct(a1, *(unsigned __int16 *)(a1 + 344), v28);
            *(_WORD *)(a1 + 346) = png_gamma_correct(a1, *(unsigned __int16 *)(a1 + 346), v28);
          }
        }
        *(_BYTE *)(a1 + 332) = 1;
      }
    }
    else if ( *(_BYTE *)(a1 + 315) == 3
           && ((*(_DWORD *)(a1 + 116) & 0x1000) == 0 || ((unsigned int)&loc_600000 & *(_DWORD *)(a1 + 116)) == 0) )
    {
      v24 = *(_DWORD *)(a1 + 296);
      v26 = *(unsigned __int16 *)(a1 + 300);
      for ( j = 0; j < v26; ++j )
      {
        *(_BYTE *)(v24 + 3 * j) = *(_BYTE *)(*(unsigned __int8 *)(v24 + 3 * j) + *(_DWORD *)(a1 + 384));
        *(_BYTE *)(v24 + 3 * j + 1) = *(_BYTE *)(*(unsigned __int8 *)(v24 + 3 * j + 1) + *(_DWORD *)(a1 + 384));
        *(_BYTE *)(v24 + 3 * j + 2) = *(_BYTE *)(*(unsigned __int8 *)(v24 + 3 * j + 2) + *(_DWORD *)(a1 + 384));
      }
      *(_DWORD *)(a1 + 116) &= ~0x2000u;
    }
  }
  else if ( (*(_DWORD *)(a1 + 116) & 0x80) != 0 && *(_BYTE *)(a1 + 315) == 3 )
  {
    v19 = *(unsigned __int16 *)(a1 + 308);
    v22 = *(_DWORD *)(a1 + 296);
    LOBYTE(v20) = *(_BYTE *)(a1 + 342);
    HIBYTE(v20) = *(_BYTE *)(a1 + 344);
    v21 = *(_BYTE *)(a1 + 346);
    for ( k = 0; k < v19; ++k )
    {
      if ( *(_BYTE *)(*(_DWORD *)(a1 + 420) + k) )
      {
        if ( *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + k) != 255 )
        {
          v18 = *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + k) * *(unsigned __int8 *)(v22 + 3 * k)
              + (255 - *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + k)) * (unsigned __int8)v20
              + 128;
          *(_BYTE *)(v22 + 3 * k) = (unsigned __int16)(((int)v18 >> 8) + v18) >> 8;
          v17 = *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + k) * *(unsigned __int8 *)(v22 + 3 * k + 1)
              + (255 - *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + k)) * HIBYTE(v20)
              + 128;
          *(_BYTE *)(v22 + 3 * k + 1) = (unsigned __int16)(((int)v17 >> 8) + v17) >> 8;
          v16 = *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + k) * *(unsigned __int8 *)(v22 + 3 * k + 2)
              + (255 - *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + k)) * v21
              + 128;
          *(_BYTE *)(v22 + 3 * k + 2) = (unsigned __int16)(((int)v16 >> 8) + v16) >> 8;
        }
      }
      else
      {
        v5 = v22 + 3 * k;
        *(_WORD *)v5 = v20;
        *(_BYTE *)(v5 + 2) = v21;
      }
    }
    *(_DWORD *)(a1 + 116) &= ~0x80u;
  }
  result = a1;
  if ( (*(_DWORD *)(a1 + 116) & 8) != 0 )
  {
    result = *(_DWORD *)(a1 + 116) & 0x1000;
    if ( !result && *(_BYTE *)(a1 + 315) == 3 )
    {
      v12 = *(unsigned __int16 *)(a1 + 300);
      v9 = 8 - *(unsigned __int8 *)(a1 + 408);
      *(_DWORD *)(a1 + 116) &= ~8u;
      if ( v9 > 0 && v9 < 8 )
      {
        for ( m = 0; m < v12; ++m )
          *(_BYTE *)(3 * m + *(_DWORD *)(a1 + 296)) = (int)*(unsigned __int8 *)(*(_DWORD *)(a1 + 296) + 3 * m) >> v9;
      }
      v10 = 8 - *(unsigned __int8 *)(a1 + 409);
      if ( v10 > 0 && v10 < 8 )
      {
        for ( n = 0; n < v12; ++n )
          *(_BYTE *)(*(_DWORD *)(a1 + 296) + 3 * n + 1) = (int)*(unsigned __int8 *)(*(_DWORD *)(a1 + 296) + 3 * n + 1) >> v10;
      }
      result = *(unsigned __int8 *)(a1 + 410);
      v11 = 8 - result;
      if ( 8 - result > 0 && v11 < 8 )
      {
        for ( ii = 0; ; ++ii )
        {
          result = ii;
          if ( ii >= v12 )
            break;
          *(_BYTE *)(*(_DWORD *)(a1 + 296) + 3 * ii + 2) = (int)*(unsigned __int8 *)(*(_DWORD *)(a1 + 296) + 3 * ii + 2) >> v11;
        }
      }
    }
  }
  return result;
}
