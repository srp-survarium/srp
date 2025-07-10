void __thiscall Scaleform::Render::DICommand_Threshold::ExecuteSW(
        Scaleform::Render::DICommand_Threshold *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *pPlanes; // eax
  int Width; // ecx
  int Height; // edx
  Scaleform::Render::ImagePlane *v8; // eax
  const Scaleform::Render::ImageData *v9; // ecx
  const Scaleform::Render::ImageData *v10; // edx
  Scaleform::Render::TextureManager *v11; // eax
  Scaleform::Render::ImageSwizzler *v12; // eax
  Scaleform::Render::TextureManager *v13; // eax
  Scaleform::Render::ImageData *v14; // esi
  Scaleform::Render::ImageSwizzler *v15; // eax
  signed int y1; // esi
  signed int x1; // ebx
  unsigned int v18; // ebp
  unsigned int Mask; // eax
  unsigned int v20; // ecx
  unsigned int v21; // eax
  bool v22; // dl
  unsigned int ThresholdColor; // eax
  const Scaleform::Render::ImageData *src[2]; // [esp+30h] [ebp-84h] BYREF
  Scaleform::Render::Color sCol; // [esp+38h] [ebp-7Ch] BYREF
  int y[2]; // [esp+3Ch] [ebp-78h] BYREF
  Scaleform::Render::Rect<long> dstClippedRect; // [esp+44h] [ebp-70h] BYREF
  Scaleform::Render::ImageSwizzlerContext srcSwiz; // [esp+54h] [ebp-60h] BYREF
  Scaleform::Render::ImageSwizzlerContext dstSwiz; // [esp+6Ch] [ebp-48h] BYREF
  Scaleform::Render::Point<long> delta; // [esp+84h] [ebp-30h] BYREF
  Scaleform::Render::ImagePlane s; // [esp+8Ch] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane d; // [esp+A0h] [ebp-14h] BYREF

  src[0] = *psrc;
  memset(&d, 0, sizeof(d));
  memset(&s, 0, sizeof(s));
  Scaleform::Render::ImageData::GetPlane(dest, 0, &d);
  Scaleform::Render::ImageData::GetPlane((Scaleform::Render::ImageData *)src[0], 0, &s);
  pPlanes = dest->pPlanes;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  v8 = src[0]->pPlanes;
  y[0] = Width;
  v9 = (const Scaleform::Render::ImageData *)v8->Width;
  y[1] = Height;
  v10 = (const Scaleform::Render::ImageData *)v8->Height;
  src[0] = v9;
  src[1] = v10;
  memset(&dstClippedRect, 0, sizeof(dstClippedRect));
  if ( Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
         this,
         (const Scaleform::Render::Size<unsigned long> *)src,
         (const Scaleform::Render::Size<unsigned long> *)y,
         &this->SourceRect,
         &dstClippedRect,
         &delta) )
  {
    v11 = context->pHAL->GetTextureManager(context->pHAL);
    v12 = v11->GetImageSwizzler(v11);
    dstSwiz.pCurrentScanline = 0;
    memset(&dstSwiz.CachedBlockY, 0, 12);
    dstSwiz.Swizzler = v12;
    dstSwiz.pImage = dest;
    v12->Initialize(v12, &dstSwiz);
    v13 = context->pHAL->GetTextureManager(context->pHAL);
    v14 = *psrc;
    v15 = v13->GetImageSwizzler(v13);
    srcSwiz.pCurrentScanline = 0;
    memset(&srcSwiz.CachedBlockY, 0, 12);
    srcSwiz.Swizzler = v15;
    srcSwiz.pImage = v14;
    v15->Initialize(v15, &srcSwiz);
    y1 = dstClippedRect.y1;
    y[0] = dstClippedRect.y1;
    if ( dstClippedRect.y1 < dstClippedRect.y2 )
    {
      src[0] = (const Scaleform::Render::ImageData *)(dstClippedRect.y1 - delta.y);
      do
      {
        dstSwiz.Swizzler->CacheScanline(dstSwiz.Swizzler, &dstSwiz, y1);
        srcSwiz.Swizzler->CacheScanline(srcSwiz.Swizzler, &srcSwiz, (unsigned int)src[0]);
        x1 = dstClippedRect.x1;
        if ( dstClippedRect.x1 < dstClippedRect.x2 )
        {
          v18 = dstClippedRect.x1 - delta.x;
          do
          {
            srcSwiz.Swizzler->GetPixelInScanline(srcSwiz.Swizzler, &sCol, &srcSwiz, v18);
            Mask = this->Mask;
            v20 = Mask & this->Threshold;
            v21 = sCol.Raw & Mask;
            v22 = 0;
            switch ( this->Operation )
            {
              case Operator_LT:
                v22 = v21 < v20;
                break;
              case Operator_LE:
                v22 = v21 <= v20;
                break;
              case Operator_GT:
                v22 = v21 > v20;
                break;
              case Operator_GE:
                v22 = v21 >= v20;
                break;
              case Operator_EQ:
                v22 = v21 == v20;
                break;
              case Operator_NE:
                v22 = v21 != v20;
                break;
              default:
                break;
            }
            if ( !this->pSource.pObject->Transparent )
              sCol.Channels.Alpha = -1;
            if ( v22 )
              ThresholdColor = this->ThresholdColor;
            else
              ThresholdColor = sCol.Raw;
            if ( !this->pImage.pObject->Transparent )
              ThresholdColor |= 0xFF000000;
            dstSwiz.Swizzler->SetPixelInScanline(dstSwiz.Swizzler, &dstSwiz, x1++, ThresholdColor);
            ++v18;
          }
          while ( x1 < dstClippedRect.x2 );
          y1 = y[0];
        }
        ++src[0];
        y[0] = ++y1;
      }
      while ( y1 < dstClippedRect.y2 );
    }
  }
}
