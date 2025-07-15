void __thiscall Scaleform::Render::DICommand_FillRect::ExecuteSW(
        Scaleform::Render::DICommand_FillRect *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  Scaleform::Render::ImagePlane *pPlanes; // eax
  int Height; // edx
  unsigned int Raw; // ebp
  signed int y1; // ebx
  int x2; // edi
  signed int i; // esi
  Scaleform::Render::Rect<long> clippedRect; // [esp+Ch] [ebp-38h] BYREF
  Scaleform::Render::Rect<long> dstImageRect; // [esp+1Ch] [ebp-28h] BYREF
  Scaleform::Render::ImageSwizzlerContext dstSwiz; // [esp+2Ch] [ebp-18h] BYREF

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  dstSwiz.Swizzler = v5->GetImageSwizzler(v5);
  dstSwiz.pCurrentScanline = 0;
  dstSwiz.pImage = dest;
  memset(&dstSwiz.CachedBlockY, 0, 12);
  dstSwiz.Swizzler->Initialize(dstSwiz.Swizzler, &dstSwiz);
  pPlanes = dest->pPlanes;
  Height = pPlanes->Height;
  dstImageRect.x2 = pPlanes->Width;
  dstImageRect.x1 = 0;
  dstImageRect.y1 = 0;
  dstImageRect.y2 = Height;
  memset(&clippedRect, 0, sizeof(clippedRect));
  if ( Scaleform::Render::Rect<long>::IntersectRect(&dstImageRect, &clippedRect, &this->ApplyRect) )
  {
    Raw = this->FillColor.Raw;
    if ( !this->pImage.pObject->Transparent )
      Raw |= 0xFF000000;
    y1 = clippedRect.y1;
    if ( clippedRect.y1 < clippedRect.y2 )
    {
      x2 = clippedRect.x2;
      do
      {
        dstSwiz.Swizzler->CacheScanline(dstSwiz.Swizzler, &dstSwiz, y1);
        for ( i = clippedRect.x1; i < x2; ++i )
          dstSwiz.Swizzler->SetPixelInScanline(dstSwiz.Swizzler, &dstSwiz, i, Raw);
        ++y1;
      }
      while ( y1 < clippedRect.y2 );
    }
  }
}
