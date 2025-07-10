void __thiscall Scaleform::Render::DICommand_GetPixel32::ExecuteSW(
        Scaleform::Render::DICommand_GetPixel32 *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  Scaleform::Render::ImageSwizzler *v6; // eax
  Scaleform::Render::ImageSwizzlerContext mappedSwizzler; // [esp+Ch] [ebp-18h] BYREF

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = v5->GetImageSwizzler(v5);
  mappedSwizzler.pImage = dest;
  mappedSwizzler.Swizzler = v6;
  mappedSwizzler.pCurrentScanline = 0;
  memset(&mappedSwizzler.CachedBlockY, 0, 12);
  v6->Initialize(v6, &mappedSwizzler);
  mappedSwizzler.Swizzler->CacheScanline(mappedSwizzler.Swizzler, &mappedSwizzler, this->Y);
  if ( this->Result )
  {
    mappedSwizzler.Swizzler->GetPixelInScanline(
      mappedSwizzler.Swizzler,
      (Scaleform::Render::Color *)&context,
      &mappedSwizzler,
      this->X);
    *this->Result = (Scaleform::Render::Color)context;
  }
}
