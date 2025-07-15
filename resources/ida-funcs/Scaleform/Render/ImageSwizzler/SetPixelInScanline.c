void __thiscall Scaleform::Render::ImageSwizzler::SetPixelInScanline(
        Scaleform::Render::ImageSwizzler *this,
        Scaleform::Render::ImageSwizzlerContext *ctx,
        unsigned int x,
        unsigned int c)
{
  Scaleform::Render::ImageData::SetPixelInScanline(ctx->pImage, ctx->pCurrentScanline, x, c);
}


void __thiscall Scaleform::Render::ImageSwizzler::SetPixelInScanline(
        Scaleform::Render::ImageSwizzler *this,
        Scaleform::Render::ImageSwizzlerContext *ctx,
        unsigned int x,
        unsigned int c)
{
  this->SetPixelInScanline(this, ctx, x, c);
}
