void __thiscall Scaleform::Render::DICommand_Merge::ExecuteSW(
        Scaleform::Render::DICommand_Merge *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImageData *v4; // ebx
  Scaleform::Render::ImagePlane *pPlanes; // eax
  unsigned int Height; // edx
  unsigned int Width; // ecx
  Scaleform::Render::ImagePlane *v9; // ebx
  int v10; // eax
  int v11; // ecx
  Scaleform::Render::TextureManager *v12; // eax
  Scaleform::Render::TextureManager *v13; // eax
  Scaleform::Render::ImageData *v14; // ebx
  signed int y1; // ebx
  unsigned int v16; // edi
  unsigned int BlueMultiplier; // eax
  int Alpha; // edi
  bool v19; // zf
  unsigned int v20; // ecx
  unsigned int v21; // edx
  unsigned int AlphaMultiplier; // ebx
  unsigned int v23; // ecx
  unsigned int v24; // edx
  unsigned int v25; // eax
  bool Transparent; // [esp+37h] [ebp-B9h]
  unsigned int blendedCol; // [esp+38h] [ebp-B8h]
  unsigned int x; // [esp+3Ch] [ebp-B4h]
  int i; // [esp+40h] [ebp-B0h]
  unsigned int v30; // [esp+44h] [ebp-ACh]
  Scaleform::Render::Color dCol; // [esp+48h] [ebp-A8h] BYREF
  Scaleform::Render::Color sCol; // [esp+4Ch] [ebp-A4h] BYREF
  int y[2]; // [esp+50h] [ebp-A0h] BYREF
  Scaleform::Render::Rect<long> dstClippedRect; // [esp+58h] [ebp-98h] BYREF
  unsigned __int8 bChan[4]; // [esp+68h] [ebp-88h] BYREF
  unsigned int v36; // [esp+6Ch] [ebp-84h]
  unsigned int dChan[4]; // [esp+70h] [ebp-80h]
  Scaleform::Render::ImageSwizzlerContext dstSwiz; // [esp+80h] [ebp-70h] BYREF
  Scaleform::Render::ImageSwizzlerContext srcSwiz; // [esp+98h] [ebp-58h] BYREF
  Scaleform::Render::Point<long> delta; // [esp+B0h] [ebp-40h] BYREF
  Scaleform::Render::ImagePlane d; // [esp+B8h] [ebp-38h] BYREF
  Scaleform::Render::ImagePlane s; // [esp+CCh] [ebp-24h] BYREF
  unsigned int factors[4]; // [esp+E0h] [ebp-10h]

  v4 = *psrc;
  memset(&d, 0, sizeof(d));
  memset(&s, 0, sizeof(s));
  Scaleform::Render::ImageData::GetPlane(dest, 0, &d);
  Scaleform::Render::ImageData::GetPlane(v4, 0, &s);
  pPlanes = dest->pPlanes;
  Height = pPlanes->Height;
  Width = pPlanes->Width;
  v9 = v4->pPlanes;
  v10 = v9->Width;
  *(_DWORD *)bChan = Width;
  v11 = v9->Height;
  v36 = Height;
  y[0] = v10;
  y[1] = v11;
  memset(&dstClippedRect, 0, sizeof(dstClippedRect));
  if ( Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
         this,
         (const Scaleform::Render::Size<unsigned long> *)y,
         (const Scaleform::Render::Size<unsigned long> *)bChan,
         &this->SourceRect,
         &dstClippedRect,
         &delta) )
  {
    v12 = context->pHAL->GetTextureManager(context->pHAL);
    dstSwiz.Swizzler = v12->GetImageSwizzler(v12);
    dstSwiz.pCurrentScanline = 0;
    dstSwiz.pImage = dest;
    memset(&dstSwiz.CachedBlockY, 0, 12);
    dstSwiz.Swizzler->Initialize(dstSwiz.Swizzler, &dstSwiz);
    v13 = context->pHAL->GetTextureManager(context->pHAL);
    v14 = *psrc;
    srcSwiz.Swizzler = v13->GetImageSwizzler(v13);
    srcSwiz.pCurrentScanline = 0;
    srcSwiz.pImage = v14;
    memset(&srcSwiz.CachedBlockY, 0, 12);
    srcSwiz.Swizzler->Initialize(srcSwiz.Swizzler, &srcSwiz);
    y1 = dstClippedRect.y1;
    y[0] = dstClippedRect.y1;
    if ( dstClippedRect.y1 < dstClippedRect.y2 )
    {
      v30 = dstClippedRect.y1 - delta.y;
      do
      {
        dstSwiz.Swizzler->CacheScanline(dstSwiz.Swizzler, &dstSwiz, y1);
        srcSwiz.Swizzler->CacheScanline(srcSwiz.Swizzler, &srcSwiz, v30);
        x = dstClippedRect.x1;
        if ( dstClippedRect.x1 < dstClippedRect.x2 )
        {
          v16 = dstClippedRect.x1 - delta.x;
          for ( i = dstClippedRect.x1 - delta.x; ; v16 = i )
          {
            dstSwiz.Swizzler->GetPixelInScanline(dstSwiz.Swizzler, &dCol, &dstSwiz, x);
            srcSwiz.Swizzler->GetPixelInScanline(srcSwiz.Swizzler, &sCol, &srcSwiz, v16);
            BlueMultiplier = this->BlueMultiplier;
            Alpha = sCol.Channels.Alpha;
            dChan[0] = dCol.Channels.Red;
            dChan[1] = dCol.Channels.Green;
            dChan[2] = dCol.Channels.Blue;
            v19 = !this->pSource.pObject->Transparent;
            factors[2] = BlueMultiplier;
            dChan[3] = dCol.Channels.Alpha;
            if ( v19 )
              Alpha = 255;
            Transparent = this->pImage.pObject->Transparent;
            if ( !Transparent )
              dChan[3] = 255;
            v20 = this->RedMultiplier * sCol.Channels.Red + dChan[0] * (256 - this->RedMultiplier);
            v21 = this->GreenMultiplier * sCol.Channels.Green + dChan[1] * (256 - this->GreenMultiplier);
            AlphaMultiplier = this->AlphaMultiplier;
            bChan[2] = (unsigned __int16)(LOWORD(factors[2]) * sCol.Channels.Blue
                                        + LOWORD(dChan[2]) * (256 - LOWORD(factors[2]))) >> 8;
            v23 = v20 >> 8;
            v24 = v21 >> 8;
            v25 = (AlphaMultiplier * Alpha + dChan[3] * (256 - AlphaMultiplier)) >> 8;
            if ( !Transparent )
              LOBYTE(v25) = -1;
            BYTE2(blendedCol) = v23;
            BYTE1(blendedCol) = v24;
            LOBYTE(blendedCol) = bChan[2];
            HIBYTE(blendedCol) = v25;
            dstSwiz.Swizzler->SetPixelInScanline(dstSwiz.Swizzler, &dstSwiz, x, blendedCol);
            ++i;
            if ( (int)++x >= dstClippedRect.x2 )
              break;
          }
          y1 = y[0];
        }
        ++v30;
        y[0] = ++y1;
      }
      while ( y1 < dstClippedRect.y2 );
    }
  }
}
