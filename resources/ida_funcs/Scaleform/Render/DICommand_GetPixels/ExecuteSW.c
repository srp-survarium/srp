void __thiscall Scaleform::Render::DICommand_GetPixels::ExecuteSW(
        Scaleform::Render::DICommand_GetPixels *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  Scaleform::Render::ImageSwizzler *v6; // eax
  signed int i; // ebx
  signed int j; // edi
  Scaleform::Render::ImageSwizzlerContext mappedSwizzler; // [esp+Ch] [ebp-18h] BYREF

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = v5->GetImageSwizzler(v5);
  mappedSwizzler.pCurrentScanline = 0;
  memset(&mappedSwizzler.CachedBlockY, 0, 12);
  mappedSwizzler.pImage = dest;
  mappedSwizzler.Swizzler = v6;
  v6->Initialize(v6, &mappedSwizzler);
  for ( i = this->SourceRect.y1; i < this->SourceRect.y2; ++i )
  {
    mappedSwizzler.Swizzler->CacheScanline(mappedSwizzler.Swizzler, &mappedSwizzler, i);
    for ( j = this->SourceRect.x1; j < this->SourceRect.x2; ++j )
    {
      mappedSwizzler.Swizzler->GetPixelInScanline(
        mappedSwizzler.Swizzler,
        (Scaleform::Render::Color *)&context,
        &mappedSwizzler,
        j);
      this->Provider->WriteNextPixel(this->Provider, (unsigned int)context);
    }
  }
}
