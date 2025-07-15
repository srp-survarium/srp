void __thiscall Scaleform::Render::ImageSwizzler::CacheScanline(
        Scaleform::Render::ImageSwizzler *this,
        Scaleform::Render::ImageSwizzlerContext *ctx,
        unsigned int y)
{
  ctx->pCurrentScanline = &ctx->pImage->pPlanes->pData[y * ctx->pImage->pPlanes->Pitch];
}
