void __thiscall Scaleform::Render::DICommand_PixelDissolve::ExecuteSW(
        Scaleform::Render::DICommand_PixelDissolve *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        unsigned int psrc)
{
  Scaleform::Render::TextureManager *v5; // eax
  Scaleform::Render::ImageSwizzler *v6; // eax
  Scaleform::Render::ImageData *v7; // edi
  int *pPlanes; // edi
  int v9; // edx
  unsigned int v10; // edi
  signed int RandomSeed; // eax
  int v12; // ebp
  unsigned int v13; // et2
  unsigned int *Result; // esi
  Scaleform::Render::TextureManager *v15; // eax
  Scaleform::Render::ImageData *v16; // ebp
  Scaleform::Render::ImagePlane *v17; // ecx
  int y; // ebp
  Scaleform::Render::ImageData **v19; // edi
  int v20; // ecx
  Scaleform::Render::ImagePlane *v21; // eax
  int Width; // edx
  int Height; // eax
  int v24; // ecx
  int v25; // edi
  unsigned int v26; // ebx
  unsigned int v27; // ebp
  unsigned int *v28; // esi
  Scaleform::Render::Rect<long> srcClippedRect; // [esp+10h] [ebp-50h] BYREF
  Scaleform::Render::Rect<long> dstImageRect; // [esp+20h] [ebp-40h] BYREF
  Scaleform::Render::ImageSwizzlerContext destSwiz; // [esp+30h] [ebp-30h] BYREF
  Scaleform::Render::ImageSwizzlerContext srcSwiz; // [esp+48h] [ebp-18h] BYREF
  unsigned int i; // [esp+64h] [ebp+4h]
  signed int ia; // [esp+64h] [ebp+4h]
  unsigned int ib; // [esp+64h] [ebp+4h]

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = v5->GetImageSwizzler(v5);
  v7 = dest;
  destSwiz.Swizzler = v6;
  destSwiz.pCurrentScanline = 0;
  destSwiz.pImage = dest;
  memset(&destSwiz.CachedBlockY, 0, 12);
  v6->Initialize(v6, &destSwiz);
  if ( this->pImage.pObject == this->pSource.pObject )
  {
    pPlanes = (int *)v7->pPlanes;
    v9 = pPlanes[1];
    dstImageRect.x2 = *pPlanes;
    dstImageRect.x1 = 0;
    dstImageRect.y1 = 0;
    dstImageRect.y2 = v9;
    memset(&srcClippedRect, 0, sizeof(srcClippedRect));
    if ( Scaleform::Render::Rect<long>::IntersectRect(&dstImageRect, &srcClippedRect, &this->SourceRect) )
    {
      v10 = srcClippedRect.x2 - srcClippedRect.x1;
      i = srcClippedRect.x2 - srcClippedRect.x1;
      Scaleform::Render::LFSR::LFSR(
        (Scaleform::Render::LFSR *)&srcClippedRect,
        (srcClippedRect.x2 - srcClippedRect.x1) * (srcClippedRect.y2 - srcClippedRect.y1));
      RandomSeed = this->RandomSeed;
      v12 = 0;
      if ( this->NumPixels )
      {
        while ( 1 )
        {
          do
            RandomSeed = Scaleform::Render::LFSR::FeedbackPoly[srcClippedRect.y1]
                       & -(RandomSeed & 1)
                       ^ (RandomSeed >> 1);
          while ( (unsigned int)RandomSeed > srcClippedRect.x1 );
          psrc = RandomSeed;
          v13 = (RandomSeed - 1) % v10;
          destSwiz.Swizzler->CacheScanline(destSwiz.Swizzler, &destSwiz, (RandomSeed - 1) / v10);
          destSwiz.Swizzler->SetPixelInScanline(destSwiz.Swizzler, &destSwiz, v13, this->Fill.Raw);
          RandomSeed = psrc;
          if ( ++v12 >= this->NumPixels )
            break;
          v10 = i;
        }
      }
      Result = this->Result;
      if ( Result )
        *Result = RandomSeed;
      return;
    }
LABEL_21:
    this->Result = 0;
    return;
  }
  v15 = context->pHAL->GetTextureManager(context->pHAL);
  v16 = *(Scaleform::Render::ImageData **)psrc;
  srcSwiz.Swizzler = v15->GetImageSwizzler(v15);
  srcSwiz.pCurrentScanline = 0;
  srcSwiz.pImage = v16;
  memset(&srcSwiz.CachedBlockY, 0, 12);
  srcSwiz.Swizzler->Initialize(srcSwiz.Swizzler, &srcSwiz);
  v17 = v7->pPlanes;
  y = this->DestPoint.y;
  v19 = (Scaleform::Render::ImageData **)(v17->Width - this->DestPoint.x - this->DestPoint.x);
  v20 = v17->Height - y;
  if ( (int)v19 <= 0 )
    goto LABEL_21;
  ia = v20 - y;
  if ( v20 - y <= 0 )
    goto LABEL_21;
  v21 = *(Scaleform::Render::ImagePlane **)(*(_DWORD *)psrc + 12);
  Width = v21->Width;
  Height = v21->Height;
  dstImageRect.x2 = Width;
  dstImageRect.y2 = Height;
  memset(&srcClippedRect, 0, sizeof(srcClippedRect));
  dstImageRect.x1 = 0;
  dstImageRect.y1 = 0;
  if ( !Scaleform::Render::Rect<long>::IntersectRect(&this->SourceRect, &srcClippedRect, &dstImageRect) )
    goto LABEL_21;
  v24 = ia;
  if ( srcClippedRect.y2 - srcClippedRect.y1 < ia )
    v24 = srcClippedRect.y2 - srcClippedRect.y1;
  psrc = srcClippedRect.x2 - srcClippedRect.x1;
  if ( srcClippedRect.x2 - srcClippedRect.x1 >= (int)v19 )
    psrc = (unsigned int)v19;
  Scaleform::Render::LFSR::LFSR((Scaleform::Render::LFSR *)&srcClippedRect, v24 * psrc);
  v25 = this->RandomSeed;
  for ( ib = 0; ib < this->NumPixels; ++ib )
  {
    v25 = Scaleform::Render::LFSR::Next((Scaleform::Render::LFSR *)&srcClippedRect, v25);
    v26 = (v25 - 1) % psrc;
    v27 = (v25 - 1) / psrc;
    srcSwiz.Swizzler->CacheScanline(srcSwiz.Swizzler, &srcSwiz, v27 + this->SourceRect.y1);
    srcSwiz.Swizzler->GetPixelInScanline(
      srcSwiz.Swizzler,
      (Scaleform::Render::Color *)&dest,
      &srcSwiz,
      v26 + this->SourceRect.x1);
    destSwiz.Swizzler->CacheScanline(destSwiz.Swizzler, &destSwiz, v27 + this->DestPoint.y);
    destSwiz.Swizzler->SetPixelInScanline(destSwiz.Swizzler, &destSwiz, v26 + this->DestPoint.x, (unsigned int)dest);
  }
  v28 = this->Result;
  if ( v28 )
    *v28 = v25;
}
