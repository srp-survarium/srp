void __thiscall Scaleform::Render::DICommand_PaletteMap::ExecuteSW(
        Scaleform::Render::DICommand_PaletteMap *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImageData *v4; // esi
  Scaleform::Render::ImagePlane *pPlanes; // eax
  int Height; // edx
  int Width; // ecx
  unsigned int *p_Width; // esi
  unsigned int v10; // eax
  unsigned int v11; // ecx
  Scaleform::Render::TextureManager *v12; // eax
  Scaleform::Render::TextureManager *v13; // eax
  Scaleform::Render::ImageData *v14; // esi
  signed int y1; // esi
  int x2; // ebp
  unsigned int v17; // eax
  unsigned __int8 Alpha; // al
  unsigned int v19; // edx
  int v20; // eax
  int v21; // esi
  int i; // ecx
  int v23; // esi
  Scaleform::Render::Color sCol; // [esp+28h] [ebp-A0h] BYREF
  unsigned __int8 rgba[4]; // [esp+2Ch] [ebp-9Ch]
  unsigned int v26; // [esp+30h] [ebp-98h]
  Scaleform::Render::Size<unsigned long> srcSize; // [esp+34h] [ebp-94h] BYREF
  int x; // [esp+3Ch] [ebp-8Ch]
  int y[2]; // [esp+40h] [ebp-88h] BYREF
  Scaleform::Render::Rect<long> dstClippedRect; // [esp+48h] [ebp-80h] BYREF
  Scaleform::Render::ImageSwizzlerContext dstSwiz; // [esp+58h] [ebp-70h] BYREF
  Scaleform::Render::ImageSwizzlerContext srcSwiz; // [esp+70h] [ebp-58h] BYREF
  Scaleform::Render::Point<long> delta; // [esp+88h] [ebp-40h] BYREF
  unsigned int outCols[4]; // [esp+90h] [ebp-38h]
  Scaleform::Render::ImagePlane s; // [esp+A0h] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane d; // [esp+B4h] [ebp-14h] BYREF

  v4 = *psrc;
  memset(&d, 0, sizeof(d));
  memset(&s, 0, sizeof(s));
  Scaleform::Render::ImageData::GetPlane(dest, 0, &d);
  Scaleform::Render::ImageData::GetPlane(v4, 0, &s);
  pPlanes = dest->pPlanes;
  Height = pPlanes->Height;
  Width = pPlanes->Width;
  p_Width = &v4->pPlanes->Width;
  v10 = *p_Width;
  y[0] = Width;
  v11 = p_Width[1];
  y[1] = Height;
  srcSize.Width = v10;
  srcSize.Height = v11;
  memset(&dstClippedRect, 0, sizeof(dstClippedRect));
  if ( Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
         this,
         &srcSize,
         (const Scaleform::Render::Size<unsigned long> *)y,
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
      x2 = dstClippedRect.x2;
      v26 = dstClippedRect.y1 - delta.y;
      do
      {
        dstSwiz.Swizzler->CacheScanline(dstSwiz.Swizzler, &dstSwiz, y1);
        srcSwiz.Swizzler->CacheScanline(srcSwiz.Swizzler, &srcSwiz, v26);
        x = dstClippedRect.x1;
        if ( dstClippedRect.x1 < x2 )
        {
          v17 = dstClippedRect.x1 - delta.x;
          srcSize.Width = dstClippedRect.x1 - delta.x;
          do
          {
            srcSwiz.Swizzler->GetPixelInScanline(srcSwiz.Swizzler, &sCol, &srcSwiz, v17);
            if ( this->pSource.pObject->Transparent )
            {
              Alpha = sCol.Channels.Alpha;
            }
            else
            {
              Alpha = -1;
              sCol.Channels.Alpha = -1;
            }
            rgba[3] = Alpha;
            rgba[0] = sCol.Channels.Red;
            outCols[3] = Alpha << 24;
            rgba[1] = sCol.Channels.Green;
            outCols[0] = sCol.Channels.Red << 16;
            rgba[2] = sCol.Channels.Blue;
            outCols[1] = sCol.Channels.Green << 8;
            v19 = 0;
            outCols[2] = sCol.Channels.Blue;
            v20 = 0;
            v21 = 1;
            for ( i = 0; i < 1024; i += 256 )
            {
              if ( (v21 & this->ChannelMask) != 0 )
                outCols[v20] = this->Channels[i + rgba[v20]];
              v19 += outCols[v20++];
              v21 = __ROL4__(v21, 1);
            }
            if ( !this->pImage.pObject->Transparent )
              v19 |= 0xFF000000;
            v23 = x;
            dstSwiz.Swizzler->SetPixelInScanline(dstSwiz.Swizzler, &dstSwiz, x, v19);
            x2 = dstClippedRect.x2;
            v17 = srcSize.Width + 1;
            x = v23 + 1;
            ++srcSize.Width;
          }
          while ( v23 + 1 < dstClippedRect.x2 );
          y1 = y[0];
        }
        ++v26;
        y[0] = ++y1;
      }
      while ( y1 < dstClippedRect.y2 );
    }
  }
}
