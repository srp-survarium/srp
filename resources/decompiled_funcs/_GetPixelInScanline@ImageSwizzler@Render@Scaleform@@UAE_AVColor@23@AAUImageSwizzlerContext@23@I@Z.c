Scaleform::Render::Color *__thiscall Scaleform::Render::ImageSwizzler::GetPixelInScanline(
        Scaleform::Render::ImageSwizzler *this,
        Scaleform::Render::Color *result,
        Scaleform::Render::ImageSwizzlerContext *ctx,
        unsigned int x)
{
  Scaleform::Render::ImageData::GetPixelInScanline(ctx->pImage, result, ctx->pCurrentScanline, x);
  return result;
}
