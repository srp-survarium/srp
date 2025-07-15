BOOL __usercall inspect_error@<eax>(
        int y1@<eax>,
        int x0,
        int x1,
        int y0,
        const float *mask,
        const float *mdct,
        vorbis_info_floor1 *info)
{
  int v7; // ecx
  int v8; // edi
  unsigned int v9; // ebx
  int v10; // edx
  int v11; // eax
  int v12; // edx
  unsigned int v13; // ebx
  int v14; // edx
  float twofitatten; // xmm2_4
  vorbis_info_floor1 *v16; // ecx
  const float *v18; // esi
  int v19; // eax
  int v20; // edx
  float maxerr; // xmm0_4
  int v22; // [esp+Ch] [ebp-18h]
  int v23; // [esp+10h] [ebp-14h]
  int v24; // [esp+14h] [ebp-10h]
  int v25; // [esp+18h] [ebp-Ch]
  int v26; // [esp+1Ch] [ebp-8h]
  int v27; // [esp+1Ch] [ebp-8h]
  int v28; // [esp+20h] [ebp-4h]
  int v29; // [esp+34h] [ebp+10h]

  v7 = y1 - y0;
  v8 = x1 - x0;
  v9 = abs32(y1 - y0);
  v10 = (y1 - y0) / (x1 - x0);
  v22 = v10;
  v11 = v10 - 1;
  if ( v7 >= 0 )
    v11 = v10 + 1;
  v25 = 0;
  v23 = v11;
  v28 = y0;
  v26 = vorbis_dBquant(&mask[x0]);
  v13 = v9 - abs32(v8 * v12);
  v14 = (y0 - v26) * (y0 - v26);
  twofitatten = info->twofitatten;
  v16 = info;
  v24 = 1;
  if ( (float)(mdct[x0] + twofitatten) >= mask[x0]
    && ((float)v26 > (float)(info->maxover + (float)y0) || (float)((float)y0 - info->maxunder) > (float)v26) )
  {
    return 1;
  }
  v29 = x0 + 1;
  if ( x0 + 1 < x1 )
  {
    v18 = &mask[x0 + 1];
    while ( 1 )
    {
      v25 += v13;
      if ( v25 < v8 )
      {
        v19 = v22;
      }
      else
      {
        v25 -= v8;
        v19 = v23;
      }
      v28 += v19;
      v27 = vorbis_dBquant(v18);
      v14 = (v28 - v27) * (v28 - v27) + v20;
      ++v24;
      if ( (float)(*(const float *)((char *)v18 + (char *)mdct - (char *)mask) + twofitatten) >= *v18
        && v27
        && ((float)v27 > (float)(info->maxover + (float)v28) || (float)((float)v28 - info->maxunder) > (float)v27) )
      {
        return 1;
      }
      ++v29;
      ++v18;
      if ( v29 >= x1 )
      {
        v16 = info;
        break;
      }
    }
  }
  maxerr = v16->maxerr;
  return (float)((float)(v16->maxover * v16->maxover) / (float)v24) <= maxerr
      && (float)((float)(v16->maxunder * v16->maxunder) / (float)v24) <= maxerr
      && (float)(v14 / v24) > maxerr;
}
