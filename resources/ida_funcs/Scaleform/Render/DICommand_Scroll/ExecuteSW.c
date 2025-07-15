void __thiscall Scaleform::Render::DICommand_Scroll::ExecuteSW(
        Scaleform::Render::DICommand_Scroll *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImageData *v5; // edi
  int *pPlanes; // edi
  Scaleform::Render::Rect<long> *p_SourceRect; // eax
  int v8; // ebp
  int v9; // esi
  int v10; // edx
  Scaleform::Render::ImagePlane *v11; // ecx
  int Width; // edx
  int Height; // ecx
  Scaleform::Render::TextureManager *v14; // eax
  Scaleform::Render::TextureManager *v15; // eax
  Scaleform::Render::ImageData *v16; // edi
  signed int v17; // ebp
  unsigned int v18; // edi
  signed int v19; // esi
  unsigned int v20; // edi
  unsigned int v21; // [esp+30h] [ebp-B0h]
  Scaleform::Render::Color sCol; // [esp+34h] [ebp-ACh] BYREF
  Scaleform::Render::Rect<long> dstClippedRect; // [esp+38h] [ebp-A8h] BYREF
  Scaleform::Render::Rect<long> srcImageRect; // [esp+48h] [ebp-98h] BYREF
  Scaleform::Render::Rect<long> srcClippedRect; // [esp+58h] [ebp-88h] BYREF
  Scaleform::Render::DICommand_Scroll *v26; // [esp+68h] [ebp-78h]
  int v27; // [esp+6Ch] [ebp-74h]
  Scaleform::Render::ImageSwizzlerContext dstSwiz; // [esp+70h] [ebp-70h] BYREF
  Scaleform::Render::ImageSwizzlerContext srcSwiz; // [esp+88h] [ebp-58h] BYREF
  Scaleform::Render::Rect<long> dstImageRect; // [esp+A0h] [ebp-40h] BYREF
  Scaleform::Render::ImagePlane d; // [esp+B0h] [ebp-30h] BYREF
  Scaleform::Render::ImagePlane s; // [esp+C4h] [ebp-1Ch] BYREF
  Scaleform::Render::Point<long> delta; // [esp+D8h] [ebp-8h]

  v5 = *psrc;
  v26 = this;
  memset(&d, 0, sizeof(d));
  memset(&s, 0, sizeof(s));
  Scaleform::Render::ImageData::GetPlane(dest, 0, &d);
  Scaleform::Render::ImageData::GetPlane(v5, 0, &s);
  pPlanes = (int *)v5->pPlanes;
  p_SourceRect = &this->SourceRect;
  v8 = this->DestPoint.x - this->SourceRect.x1;
  v9 = this->DestPoint.y - this->SourceRect.y1;
  v10 = pPlanes[1];
  srcImageRect.x2 = *pPlanes;
  v11 = dest->pPlanes;
  srcImageRect.y2 = v10;
  Width = v11->Width;
  Height = v11->Height;
  dstImageRect.x2 = Width;
  dstImageRect.y2 = Height;
  delta.x = v8;
  srcImageRect.x1 = 0;
  srcImageRect.y1 = 0;
  dstImageRect.x1 = 0;
  dstImageRect.y1 = 0;
  memset(&srcClippedRect, 0, sizeof(srcClippedRect));
  memset(&dstClippedRect, 0, sizeof(dstClippedRect));
  if ( Scaleform::Render::Rect<long>::IntersectRect(&srcImageRect, &srcClippedRect, p_SourceRect) )
  {
    srcImageRect.y1 = srcClippedRect.y1 + v9;
    srcImageRect.x1 = v8 + srcClippedRect.x1;
    srcImageRect.x2 = srcClippedRect.x2 + v8;
    srcImageRect.y2 = v9 + srcClippedRect.y2;
    if ( Scaleform::Render::Rect<long>::IntersectRect(&srcImageRect, &dstClippedRect, &dstImageRect) )
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
      v17 = dstClippedRect.y2 - 1;
      if ( dstClippedRect.y2 - 1 >= dstClippedRect.y1 )
      {
        v18 = v17 - v9;
        v27 = dstClippedRect.x2 - 1;
        v21 = v17 - v9;
        do
        {
          dstSwiz.Swizzler->CacheScanline(dstSwiz.Swizzler, &dstSwiz, v17);
          srcSwiz.Swizzler->CacheScanline(srcSwiz.Swizzler, &srcSwiz, v18);
          v19 = v27;
          if ( v27 >= dstClippedRect.x1 )
          {
            v20 = v27 - delta.x;
            do
            {
              srcSwiz.Swizzler->GetPixelInScanline(srcSwiz.Swizzler, &sCol, &srcSwiz, v20);
              if ( !v26->pSource.pObject->Transparent || !v26->pImage.pObject->Transparent )
                sCol.Channels.Alpha = -1;
              dstSwiz.Swizzler->SetPixelInScanline(dstSwiz.Swizzler, &dstSwiz, v19--, (unsigned int)sCol);
              --v20;
            }
            while ( v19 >= dstClippedRect.x1 );
            v18 = v21;
          }
          --v17;
          v21 = --v18;
        }
        while ( v17 >= dstClippedRect.y1 );
      }
    }
  }
}
