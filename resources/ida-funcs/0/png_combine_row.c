void __cdecl png_combine_row(int a1, unsigned __int8 *dst, int a3)
{
  int v3; // [esp+8h] [ebp-74h]
  unsigned int v4; // [esp+Ch] [ebp-70h]
  int v5; // [esp+10h] [ebp-6Ch]
  int v6; // [esp+14h] [ebp-68h]
  int v7; // [esp+18h] [ebp-64h]
  int v8; // [esp+1Ch] [ebp-60h]
  unsigned int v9; // [esp+20h] [ebp-5Ch]
  unsigned int v10; // [esp+24h] [ebp-58h]
  unsigned int v11; // [esp+28h] [ebp-54h]
  unsigned __int8 *v12; // [esp+2Ch] [ebp-50h]
  unsigned __int8 *v13; // [esp+30h] [ebp-4Ch]
  unsigned int v14; // [esp+34h] [ebp-48h]
  unsigned int v15; // [esp+38h] [ebp-44h]
  int *v16; // [esp+3Ch] [ebp-40h]
  unsigned __int8 *v17; // [esp+40h] [ebp-3Ch]
  unsigned int v18; // [esp+44h] [ebp-38h]
  int v19; // [esp+48h] [ebp-34h]
  unsigned int v20; // [esp+4Ch] [ebp-30h]
  unsigned int count; // [esp+50h] [ebp-2Ch]
  unsigned __int8 v22; // [esp+54h] [ebp-28h]
  unsigned int v23; // [esp+58h] [ebp-24h]
  unsigned int v24; // [esp+5Ch] [ebp-20h]
  unsigned int v25; // [esp+60h] [ebp-1Ch]
  unsigned __int8 *v26; // [esp+64h] [ebp-18h]
  unsigned int v27; // [esp+68h] [ebp-14h]
  unsigned int v28; // [esp+68h] [ebp-14h]
  int v29; // [esp+6Ch] [ebp-10h]
  unsigned int v30; // [esp+70h] [ebp-Ch]
  unsigned int v31; // [esp+70h] [ebp-Ch]
  const __m128i *src; // [esp+74h] [ebp-8h]
  __m128i *srca; // [esp+74h] [ebp-8h]
  unsigned __int8 *srcb; // [esp+74h] [ebp-8h]
  unsigned __int8 *srcc; // [esp+74h] [ebp-8h]
  unsigned __int8 v36; // [esp+7Bh] [ebp-1h]
  unsigned __int8 *dsta; // [esp+88h] [ebp+Ch]
  unsigned __int8 *dstb; // [esp+88h] [ebp+Ch]
  unsigned __int8 *dstc; // [esp+88h] [ebp+Ch]

  v30 = *(unsigned __int8 *)(a1 + 323);
  src = (const __m128i *)(*(_DWORD *)(a1 + 264) + 1);
  v27 = *(_DWORD *)(a1 + 228);
  v25 = *(unsigned __int8 *)(a1 + 313);
  v26 = 0;
  v36 = 0;
  if ( !*(_BYTE *)(a1 + 323) )
    png_error(a1, (int)"internal row logic error");
  if ( *(_DWORD *)(a1 + 284) )
  {
    v10 = v30 < 8 ? (v30 * v27 + 7) >> 3 : v27 * (v30 >> 3);
    if ( *(_DWORD *)(a1 + 284) != v10 )
      png_error(a1, (int)"internal row size calculation error");
  }
  if ( !v27 )
    png_error(a1, (int)"internal row width error");
  LOBYTE(v29) = (v27 * v30) & 7;
  if ( (_BYTE)v29 )
  {
    if ( v30 < 8 )
      v9 = (v30 * v27 + 7) >> 3;
    else
      v9 = v27 * (v30 >> 3);
    v26 = &dst[v9 - 1];
    v36 = *v26;
    if ( ((unsigned int)&_sbh_sizeHeaderList & *(_DWORD *)(a1 + 116)) != 0 )
      v29 = 255 << v29;
    else
      v29 = 255 >> v29;
  }
  if ( !*(_BYTE *)(a1 + 312) || (*(_DWORD *)(a1 + 116) & 2) == 0 || v25 >= 6 || a3 && (a3 != 1 || (v25 & 1) == 0) )
  {
    if ( v30 < 8 )
      memcpy((int)dst, src, (v30 * v27 + 7) >> 3);
    else
      memcpy((int)dst, src, v27 * (v30 >> 3));
LABEL_104:
    if ( v26 )
      *v26 = ~(_BYTE)v29 & *v26 | v29 & v36;
    return;
  }
  if ( v27 <= (((v25 & 1) << (3 - ((v25 + 1) >> 1))) & 7) )
    return;
  if ( v30 < 8 )
  {
    v23 = 8 / v30;
    if ( ((unsigned int)&_sbh_sizeHeaderList & *(_DWORD *)(a1 + 116)) != 0 )
    {
      if ( a3 )
      {
        if ( v30 == 1 )
          v8 = 0;
        else
          v8 = (v30 != 2) + 1;
        v7 = dword_6F2C90[3 * v8 + (v25 >> 1)];
      }
      else
      {
        if ( v30 == 1 )
          v6 = 0;
        else
          v6 = (v30 != 2) + 1;
        v7 = dword_6F2C00[6 * v6 + v25];
      }
      v24 = v7;
    }
    else
    {
      if ( a3 )
      {
        if ( v30 == 1 )
          v5 = 0;
        else
          v5 = (v30 != 2) + 1;
        v4 = dword_6F2CB4[3 * v5 + (v25 >> 1)];
      }
      else
      {
        if ( v30 == 1 )
          v3 = 0;
        else
          v3 = (v30 != 2) + 1;
        v4 = dword_6F2C48[6 * v3 + v25];
      }
      v24 = v4;
    }
    while ( 1 )
    {
      v22 = v24;
      v24 = (v24 << 24) | ((unsigned __int64)v24 >> 8);
      if ( v22 )
      {
        if ( v22 == 255 )
          *dst = src->m128i_i8[0];
        else
          *dst = v22 & src->m128i_i8[0] | ~v22 & *dst;
      }
      if ( v27 <= v23 )
        break;
      v27 -= v23;
      ++dst;
      src = (const __m128i *)((char *)src + 1);
    }
    goto LABEL_104;
  }
  if ( (v30 & 7) != 0 )
    png_error(a1, (int)"invalid user transform pixel depth");
  v31 = v30 >> 3;
  v19 = v31 * (((v25 & 1) << (3 - ((v25 + 1) >> 1))) & 7);
  v28 = v31 * v27 - v19;
  dsta = &dst[v19];
  srca = (__m128i *)((char *)src + v19);
  if ( a3 )
  {
    count = v31 * (1 << ((6 - v25) >> 1));
    if ( count > v28 )
      count = v28;
  }
  else
  {
    count = v31;
  }
  v20 = v31 * (1 << ((7 - v25) >> 1));
  switch ( count )
  {
    case 1u:
      while ( 1 )
      {
        *dsta = srca->m128i_i8[0];
        if ( v28 <= v20 )
          break;
        dsta += v20;
        srca = (__m128i *)((char *)srca + v20);
        v28 -= v20;
      }
      break;
    case 2u:
      while ( 1 )
      {
        *dsta = srca->m128i_i8[0];
        dsta[1] = srca->m128i_u8[1];
        if ( v28 <= v20 )
          break;
        srca = (__m128i *)((char *)srca + v20);
        dsta += v20;
        v28 -= v20;
        if ( v28 <= 1 )
        {
          *dsta = srca->m128i_i8[0];
          return;
        }
      }
      break;
    case 3u:
      while ( 1 )
      {
        *dsta = srca->m128i_i8[0];
        dsta[1] = srca->m128i_u8[1];
        dsta[2] = srca->m128i_u8[2];
        if ( v28 <= v20 )
          break;
        srca = (__m128i *)((char *)srca + v20);
        dsta += v20;
        v28 -= v20;
      }
      break;
    default:
      if ( count >= 0x10 || ((unsigned __int8)dsta & 1) != 0 || ((unsigned __int8)srca & 1) != 0 || count % 2 || v20 % 2 )
      {
        while ( 1 )
        {
          memcpy((int)dsta, srca, count);
          if ( v28 <= v20 )
            break;
          srca = (__m128i *)((char *)srca + v20);
          dsta += v20;
          v28 -= v20;
          if ( count > v28 )
            count = v28;
        }
      }
      else if ( ((unsigned __int8)dsta & 3) != 0 || ((unsigned __int8)srca & 3) != 0 || count % 4 || v20 % 4 )
      {
        v12 = dsta;
        v13 = (unsigned __int8 *)srca;
        v14 = (v20 - count) >> 1;
        while ( 1 )
        {
          v11 = count;
          do
          {
            *(_WORD *)v12 = *(_WORD *)v13;
            v12 += 2;
            v13 += 2;
            v11 -= 2;
          }
          while ( v11 );
          if ( v28 <= v20 )
            break;
          v12 += 2 * v14;
          v13 += 2 * v14;
          v28 -= v20;
          if ( count > v28 )
          {
            dstc = v12;
            srcc = v13;
            do
            {
              *dstc++ = *srcc++;
              --v28;
            }
            while ( v28 );
            return;
          }
        }
      }
      else
      {
        v17 = dsta;
        v16 = (int *)srca;
        v18 = (v20 - count) >> 2;
        while ( 1 )
        {
          v15 = count;
          do
          {
            *(_DWORD *)v17 = *v16;
            v17 += 4;
            ++v16;
            v15 -= 4;
          }
          while ( v15 );
          if ( v28 <= v20 )
            break;
          v17 += 4 * v18;
          v16 += v18;
          v28 -= v20;
          if ( count > v28 )
          {
            dstb = v17;
            srcb = (unsigned __int8 *)v16;
            do
            {
              *dstb++ = *srcb++;
              --v28;
            }
            while ( v28 );
            return;
          }
        }
      }
      break;
  }
}
