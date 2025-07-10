void __cdecl Scaleform::Render::ImageResizeFilter2x2_void____cdecl___unsigned_char___unsigned_char_const___unsigned_char_const___unsigned_char_const___unsigned_char_const___int_int__(
        unsigned __int8 *pDst,
        int dstWidth,
        int dstHeight,
        int dstPitch,
        int dstBpp,
        const unsigned __int8 *pSrc,
        int srcWidth,
        int srcHeight,
        int srcPitch,
        int srcBpp,
        void (__cdecl *filter)(unsigned __int8 *, const unsigned __int8 *, const unsigned __int8 *, const unsigned __int8 *, const unsigned __int8 *, int, int))
{
  int v11; // ebp
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  int v16; // ebx
  int v17; // esi
  int v18; // eax
  unsigned __int8 *v19; // edx
  int v20; // ecx
  int v21; // ebx
  const unsigned __int8 *v22; // edi
  int v23; // ebx
  const unsigned __int8 *v24; // ebx
  int v25; // esi
  unsigned __int8 *i; // ebp
  const unsigned __int8 *v27; // edi
  const unsigned __int8 *j; // ebx
  int v29; // eax
  bool v30; // zf
  unsigned __int8 *pDst2; // [esp+10h] [ebp-34h]
  int v32; // [esp+14h] [ebp-30h]
  int v33; // [esp+18h] [ebp-2Ch]
  int xFract; // [esp+1Ch] [ebp-28h]
  int v35; // [esp+20h] [ebp-24h]
  Scaleform::ArrayUnsafe<int,2> srcCoordX; // [esp+24h] [ebp-20h] BYREF
  Scaleform::Render::LinearInterpolator iy; // [esp+30h] [ebp-14h]
  unsigned __int8 *pDsta; // [esp+48h] [ebp+4h]
  int yFract; // [esp+60h] [ebp+1Ch]

  v11 = srcWidth;
  memset(&srcCoordX, 0, sizeof(srcCoordX));
  Scaleform::ArrayUnsafeBase<int,Scaleform::AllocatorGH<int,2>>::Reserve(&srcCoordX, dstWidth, 0);
  v12 = (srcWidth << 8) / dstWidth;
  v13 = (srcWidth << 8) % dstWidth;
  v14 = v13;
  if ( v13 <= 0 )
  {
    v13 += dstWidth;
    v14 += dstWidth;
    --v12;
  }
  v15 = v13 - dstWidth;
  v16 = 0;
  if ( dstWidth > 0 )
  {
    v17 = (srcWidth << 7) / dstWidth - 128;
    do
    {
      srcCoordX.Data[v16] = v17;
      v15 += v14;
      v17 += v12;
      if ( v15 > 0 )
      {
        v15 -= dstWidth;
        ++v17;
      }
      ++v16;
    }
    while ( v16 < dstWidth );
    v11 = srcWidth;
  }
  iy.Lft = (srcHeight << 8) / dstHeight;
  v18 = (srcHeight << 8) % dstHeight;
  iy.Rem = v18;
  iy.Mod = v18;
  if ( v18 <= 0 )
  {
    --iy.Lft;
    iy.Mod = dstHeight + v18;
    iy.Rem = dstHeight + v18;
  }
  iy.Mod -= dstHeight;
  v19 = pDst;
  pDst2 = pDst;
  if ( dstHeight > 0 )
  {
    v33 = v11 - 1;
    v20 = (srcHeight << 7) / dstHeight - 128;
    v35 = srcBpp * (v11 - 1);
    pDsta = (unsigned __int8 *)v20;
    v32 = dstHeight;
    do
    {
      v21 = v20 >> 8;
      yFract = (unsigned __int8)v20;
      if ( v20 >> 8 >= 0 )
        v22 = &pSrc[srcPitch * v21];
      else
        v22 = pSrc;
      v23 = v21 + 1;
      if ( v23 >= srcHeight )
        v23 = srcHeight - 1;
      v24 = &pSrc[srcPitch * v23];
      v25 = 0;
      for ( i = v19; v25 < dstWidth; ++v25 )
      {
        if ( srcCoordX.Data[v25] >= 0 )
          break;
        filter(i, v22, v22, v24, v24, (unsigned __int8)srcCoordX.Data[v25], yFract);
        i += dstBpp;
      }
      for ( ; v25 < dstWidth; ++v25 )
      {
        xFract = srcCoordX.Data[v25];
        if ( xFract >> 8 >= v33 )
          break;
        filter(
          i,
          &v22[srcBpp * (xFract >> 8)],
          &v22[srcBpp * ((xFract >> 8) + 1)],
          &v24[srcBpp * (xFract >> 8)],
          &v24[srcBpp * ((xFract >> 8) + 1)],
          (unsigned __int8)xFract,
          yFract);
        i += dstBpp;
      }
      v27 = &v22[v35];
      for ( j = &v24[v35]; v25 < dstWidth; ++v25 )
      {
        filter(i, v27, v27, j, j, (unsigned __int8)srcCoordX.Data[v25], yFract);
        i += dstBpp;
      }
      v29 = iy.Rem + iy.Mod;
      v20 = (int)&pDsta[iy.Lft];
      iy.Mod = v29;
      pDsta += iy.Lft;
      if ( v29 > 0 )
      {
        ++v20;
        iy.Mod = v29 - dstHeight;
        pDsta = (unsigned __int8 *)v20;
      }
      v19 = &pDst2[dstPitch];
      v30 = v32-- == 1;
      pDst2 += dstPitch;
    }
    while ( !v30 );
  }
  if ( srcCoordX.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, srcCoordX.Data);
}
