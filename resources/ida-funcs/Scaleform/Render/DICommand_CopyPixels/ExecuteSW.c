void __thiscall Scaleform::Render::DICommand_CopyPixels::ExecuteSW(
        Scaleform::Render::DICommand_CopyPixels *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::Color v5; // ecx
  Scaleform::Render::ImagePlane *pPlanes; // eax
  int Height; // edx
  int *v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int x; // edi
  int v14; // eax
  Scaleform::Render::TextureManager *v15; // eax
  Scaleform::Render::TextureManager *v16; // eax
  Scaleform::Render::ImageData *v17; // ebx
  Scaleform::Render::ImageData *Raw; // ebx
  Scaleform::Render::TextureManager *v19; // eax
  int y1; // ebx
  int v21; // esi
  unsigned int v22; // edi
  int x1; // esi
  unsigned int v24; // edi
  int v25; // eax
  Scaleform::Render::Color *p_s; // eax
  int v27; // eax
  int v28; // ecx
  unsigned __int8 v29; // bl
  Scaleform::Render::Color final; // [esp+50h] [ebp-A0h]
  float finala; // [esp+50h] [ebp-A0h]
  Scaleform::Render::Color finalb; // [esp+50h] [ebp-A0h]
  float f; // [esp+54h] [ebp-9Ch]
  bool alphaImage; // [esp+5Bh] [ebp-95h]
  Scaleform::Render::Color s; // [esp+5Ch] [ebp-94h] BYREF
  Scaleform::Render::Point<long> deltaAlpha; // [esp+60h] [ebp-90h] BYREF
  int v37; // [esp+68h] [ebp-88h]
  int y; // [esp+6Ch] [ebp-84h]
  Scaleform::Render::Color d; // [esp+70h] [ebp-80h] BYREF
  Scaleform::Render::Rect<long> dstClippedRect; // [esp+74h] [ebp-7Ch] BYREF
  Scaleform::Render::Point<long> delta; // [esp+84h] [ebp-6Ch] BYREF
  Scaleform::Render::Rect<long> srcSize; // [esp+8Ch] [ebp-64h] BYREF
  Scaleform::Render::ImageSwizzlerContext dstSwiz; // [esp+9Ch] [ebp-54h] BYREF
  _BYTE v44[4]; // [esp+B4h] [ebp-3Ch] BYREF
  int i; // [esp+B8h] [ebp-38h]
  int j; // [esp+BCh] [ebp-34h]
  Scaleform::Render::ImageSwizzlerContext srcSwiz; // [esp+C0h] [ebp-30h] BYREF
  Scaleform::Render::ImageSwizzlerContext alphaSwiz; // [esp+D8h] [ebp-18h] BYREF

  v5 = (Scaleform::Render::Color)*psrc;
  pPlanes = dest->pPlanes;
  Height = pPlanes->Height;
  deltaAlpha.x = pPlanes->Width;
  v8 = *(int **)(*(_DWORD *)&v5 + 12);
  v9 = v8[1];
  deltaAlpha.y = Height;
  v10 = *v8;
  srcSize.y1 = v9;
  srcSize.x1 = v10;
  memset(&dstClippedRect, 0, sizeof(dstClippedRect));
  if ( Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
         this,
         (const Scaleform::Render::Size<unsigned long> *)&srcSize,
         (const Scaleform::Render::Size<unsigned long> *)&deltaAlpha,
         &this->SourceRect,
         &dstClippedRect,
         &delta) )
  {
    alphaImage = this->pAlphaSource.pObject != 0;
    if ( this->pAlphaSource.pObject )
    {
      v11 = this->SourceRect.y2 - this->SourceRect.y1;
      v12 = this->SourceRect.x2 - this->SourceRect.x1;
      x = this->AlphaPoint.x;
      s = (Scaleform::Render::Color)psrc[1];
      v14 = this->AlphaPoint.y + v11;
      srcSize.y1 = this->AlphaPoint.y;
      srcSize.y2 = v14;
      srcSize.x2 = x + v12;
      srcSize.x1 = x;
      if ( !Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
              this,
              (const Scaleform::Render::ImageData *)s.Raw,
              dest,
              &srcSize,
              &dstClippedRect,
              &deltaAlpha) )
        return;
    }
    else
    {
      s = (Scaleform::Render::Color)*psrc;
      deltaAlpha = delta;
    }
    v15 = context->pHAL->GetTextureManager(context->pHAL);
    dstSwiz.Swizzler = v15->GetImageSwizzler(v15);
    dstSwiz.pCurrentScanline = 0;
    dstSwiz.pImage = dest;
    memset(&dstSwiz.CachedBlockY, 0, 12);
    dstSwiz.Swizzler->Initialize(dstSwiz.Swizzler, &dstSwiz);
    v16 = context->pHAL->GetTextureManager(context->pHAL);
    v17 = *psrc;
    srcSwiz.Swizzler = v16->GetImageSwizzler(v16);
    srcSwiz.pCurrentScanline = 0;
    srcSwiz.pImage = v17;
    memset(&srcSwiz.CachedBlockY, 0, 12);
    srcSwiz.Swizzler->Initialize(srcSwiz.Swizzler, &srcSwiz);
    if ( alphaImage )
      Raw = (Scaleform::Render::ImageData *)s.Raw;
    else
      Raw = *psrc;
    v19 = context->pHAL->GetTextureManager(context->pHAL);
    alphaSwiz.Swizzler = v19->GetImageSwizzler(v19);
    alphaSwiz.pCurrentScanline = 0;
    alphaSwiz.pImage = Raw;
    memset(&alphaSwiz.CachedBlockY, 0, 12);
    alphaSwiz.Swizzler->Initialize(alphaSwiz.Swizzler, &alphaSwiz);
    y1 = dstClippedRect.y1;
    y = dstClippedRect.y1;
    if ( dstClippedRect.y1 < dstClippedRect.y2 )
    {
      v21 = deltaAlpha.y - delta.y;
      v22 = dstClippedRect.y1 - deltaAlpha.y;
      v37 = dstClippedRect.y1 - deltaAlpha.y;
      for ( i = deltaAlpha.y - delta.y; ; v21 = i )
      {
        dstSwiz.Swizzler->CacheScanline(dstSwiz.Swizzler, &dstSwiz, y1);
        srcSwiz.Swizzler->CacheScanline(srcSwiz.Swizzler, &srcSwiz, v22 + v21);
        alphaSwiz.Swizzler->CacheScanline(alphaSwiz.Swizzler, &alphaSwiz, v22);
        x1 = dstClippedRect.x1;
        if ( dstClippedRect.x1 < dstClippedRect.x2 )
        {
          v24 = dstClippedRect.x1 - deltaAlpha.x;
          v25 = deltaAlpha.x - delta.x;
          for ( j = deltaAlpha.x - delta.x; ; v25 = j )
          {
            srcSwiz.Swizzler->GetPixelInScanline(srcSwiz.Swizzler, &s, &srcSwiz, v24 + v25);
            if ( !this->pSource.pObject->Transparent )
              s.Channels.Alpha = -1;
            if ( alphaImage )
            {
              alphaSwiz.Swizzler->GetPixelInScanline(
                alphaSwiz.Swizzler,
                (Scaleform::Render::Color *)v44,
                &alphaSwiz,
                v24);
              p_s = (Scaleform::Render::Color *)v44;
            }
            else
            {
              p_s = &s;
            }
            final = (Scaleform::Render::Color)p_s->Raw;
            dstSwiz.Swizzler->GetPixelInScanline(dstSwiz.Swizzler, &d, &dstSwiz, x1);
            if ( alphaImage )
              v27 = final.Channels.Alpha + 1;
            else
              v27 = 256;
            v28 = (v27 * s.Channels.Alpha) >> 8;
            v29 = (unsigned __int16)(v27 * s.Channels.Alpha) >> 8;
            if ( this->MergeAlpha )
            {
              finala = (double)d.Channels.Alpha / 255.0;
              v29 = (int)(finala * (double)(255 - (unsigned __int8)v28) + (double)(unsigned __int8)v28);
            }
            if ( !this->pImage.pObject->Transparent )
              v29 = -1;
            f = (double)(unsigned __int8)v28 / (double)v29;
            finalb = (Scaleform::Render::Color)Scaleform::Render::Color::Blend(
                                                 (Scaleform::Render::Color *)&srcSize,
                                                 d,
                                                 s,
                                                 f)->Raw;
            finalb.Channels.Alpha = v29;
            dstSwiz.Swizzler->SetPixelInScanline(dstSwiz.Swizzler, &dstSwiz, x1++, (unsigned int)finalb);
            ++v24;
            if ( x1 >= dstClippedRect.x2 )
              break;
          }
          y1 = y;
          v22 = v37;
        }
        ++y1;
        ++v22;
        y = y1;
        v37 = v22;
        if ( y1 >= dstClippedRect.y2 )
          break;
      }
    }
  }
}
