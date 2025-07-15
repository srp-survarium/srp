void __thiscall Scaleform::Render::DICommand_CopyChannel::ExecuteSW(
        Scaleform::Render::DICommand_CopyChannel *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImageData *v4; // esi
  Scaleform::Render::ImagePlane *pPlanes; // eax
  unsigned int Height; // edx
  unsigned int Width; // ecx
  unsigned int *p_Width; // esi
  unsigned int v10; // eax
  unsigned int v11; // ecx
  Scaleform::Render::DrawableImage::ChannelBits SourceChannel; // eax
  Scaleform::Render::DrawableImage::ChannelBits DestChannel; // eax
  Scaleform::Render::TextureManager *v14; // eax
  Scaleform::Render::TextureManager *v15; // eax
  Scaleform::Render::ImageData *v16; // esi
  signed int y1; // edi
  int x1; // esi
  unsigned int v19; // edi
  Scaleform::Render::DrawableImage *pObject; // ecx
  Scaleform::Render::DrawableImage *v21; // edx
  unsigned __int8 v22; // al
  unsigned __int8 dCI; // [esp+2Eh] [ebp-9Ah]
  unsigned __int8 sCI; // [esp+2Fh] [ebp-99h]
  Scaleform::Render::Color dCol; // [esp+30h] [ebp-98h] BYREF
  unsigned __int8 dChannels[4]; // [esp+34h] [ebp-94h] BYREF
  unsigned __int8 sChannels[4]; // [esp+38h] [ebp-90h] BYREF
  Scaleform::Render::Color sCol; // [esp+3Ch] [ebp-8Ch] BYREF
  unsigned int v29; // [esp+40h] [ebp-88h]
  int y; // [esp+44h] [ebp-84h]
  Scaleform::Render::Rect<long> dstClippedRect; // [esp+48h] [ebp-80h] BYREF
  Scaleform::Render::Size<unsigned long> srcSize; // [esp+58h] [ebp-70h] BYREF
  Scaleform::Render::Size<unsigned long> destSize; // [esp+60h] [ebp-68h] BYREF
  Scaleform::Render::ImageSwizzlerContext dstSwiz; // [esp+68h] [ebp-60h] BYREF
  Scaleform::Render::ImageSwizzlerContext srcSwiz; // [esp+80h] [ebp-48h] BYREF
  Scaleform::Render::Point<long> delta; // [esp+98h] [ebp-30h] BYREF
  Scaleform::Render::ImagePlane d; // [esp+A0h] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane s; // [esp+B4h] [ebp-14h] BYREF

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
  destSize.Width = Width;
  v11 = p_Width[1];
  destSize.Height = Height;
  srcSize.Width = v10;
  srcSize.Height = v11;
  memset(&dstClippedRect, 0, sizeof(dstClippedRect));
  if ( Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
         this,
         &srcSize,
         &destSize,
         &this->SourceRect,
         &dstClippedRect,
         &delta) )
  {
    SourceChannel = this->SourceChannel;
    sCI = SourceChannel > Channel_Alpha ? -1 : Scaleform::Render::ChannelIndexMap[SourceChannel];
    DestChannel = this->DestChannel;
    dCI = DestChannel > Channel_Alpha ? -1 : Scaleform::Render::ChannelIndexMap[DestChannel];
    if ( sCI != 0xFF && dCI != 0xFF )
    {
      v14 = context->pHAL->GetTextureManager(context->pHAL);
      dstSwiz.Swizzler = v14->GetImageSwizzler(v14);
      dstSwiz.pCurrentScanline = 0;
      dstSwiz.pImage = dest;
      memset(&dstSwiz.CachedBlockY, 0, 12);
      dstSwiz.Swizzler->Initialize(dstSwiz.Swizzler, &dstSwiz);
      v15 = context->pHAL->GetTextureManager(context->pHAL);
      v16 = *psrc;
      srcSwiz.Swizzler = v15->GetImageSwizzler(v15);
      srcSwiz.pCurrentScanline = 0;
      srcSwiz.pImage = v16;
      memset(&srcSwiz.CachedBlockY, 0, 12);
      srcSwiz.Swizzler->Initialize(srcSwiz.Swizzler, &srcSwiz);
      y1 = dstClippedRect.y1;
      y = dstClippedRect.y1;
      if ( dstClippedRect.y1 < dstClippedRect.y2 )
      {
        v29 = dstClippedRect.y1 - delta.y;
        do
        {
          dstSwiz.Swizzler->CacheScanline(dstSwiz.Swizzler, &dstSwiz, y1);
          srcSwiz.Swizzler->CacheScanline(srcSwiz.Swizzler, &srcSwiz, v29);
          x1 = dstClippedRect.x1;
          if ( dstClippedRect.x1 < dstClippedRect.x2 )
          {
            v19 = dstClippedRect.x1 - delta.x;
            srcSize.Width = (unsigned int)&sChannels[sCI];
            destSize.Width = (unsigned int)&dChannels[dCI];
            do
            {
              dstSwiz.Swizzler->GetPixelInScanline(dstSwiz.Swizzler, &dCol, &dstSwiz, x1);
              srcSwiz.Swizzler->GetPixelInScanline(srcSwiz.Swizzler, &sCol, &srcSwiz, v19);
              dChannels[0] = dCol.Channels.Red;
              dChannels[1] = dCol.Channels.Green;
              dChannels[2] = dCol.Channels.Blue;
              sChannels[1] = sCol.Channels.Green;
              sChannels[2] = sCol.Channels.Blue;
              dChannels[3] = dCol.Channels.Alpha;
              pObject = this->pSource.pObject;
              sChannels[3] = sCol.Channels.Alpha;
              sChannels[0] = sCol.Channels.Red;
              if ( !pObject->Transparent )
                sChannels[3] = -1;
              v21 = this->pImage.pObject;
              *(_BYTE *)destSize.Width = *(_BYTE *)srcSize.Width;
              if ( v21->Transparent )
                v22 = dChannels[3];
              else
                v22 = -1;
              dCol.Channels.Red = dChannels[0];
              dCol.Channels.Green = dChannels[1];
              dCol.Channels.Blue = dChannels[2];
              dCol.Channels.Alpha = v22;
              dstSwiz.Swizzler->SetPixelInScanline(dstSwiz.Swizzler, &dstSwiz, x1++, (unsigned int)dCol);
              ++v19;
            }
            while ( x1 < dstClippedRect.x2 );
            y1 = y;
          }
          ++v29;
          y = ++y1;
        }
        while ( y1 < dstClippedRect.y2 );
      }
    }
  }
}
