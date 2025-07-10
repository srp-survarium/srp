void __thiscall Scaleform::Render::DICommand_SetPixel32::ExecuteSW(
        Scaleform::Render::DICommand_SetPixel32 *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  Scaleform::Render::ImageSwizzler *v6; // eax
  Scaleform::Render::ImageSwizzlerContext imgSwiz; // [esp+18h] [ebp-18h] BYREF
  Scaleform::Render::Color c; // [esp+34h] [ebp+4h]

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = v5->GetImageSwizzler(v5);
  imgSwiz.pImage = dest;
  imgSwiz.Swizzler = v6;
  imgSwiz.pCurrentScanline = 0;
  memset(&imgSwiz.CachedBlockY, 0, 12);
  v6->Initialize(v6, &imgSwiz);
  imgSwiz.Swizzler->CacheScanline(imgSwiz.Swizzler, &imgSwiz, this->Y);
  c = (Scaleform::Render::Color)this->Fill.Raw;
  if ( !this->OverwriteAlpha )
  {
    imgSwiz.Swizzler->GetPixelInScanline(imgSwiz.Swizzler, (Scaleform::Render::Color *)&dest, &imgSwiz, this->X);
    c.Channels.Alpha = HIBYTE(dest);
  }
  imgSwiz.Swizzler->SetPixelInScanline(imgSwiz.Swizzler, &imgSwiz, this->X, (unsigned int)c);
}
