Scaleform::Render::Color *__thiscall Scaleform::Render::ImageSwizzlerContext::GetPixelInScanline(
        Scaleform::Render::ImageSwizzlerContext *this,
        Scaleform::Render::Color *result,
        unsigned int x)
{
  this->Swizzler->GetPixelInScanline(this->Swizzler, result, this, x);
  return result;
}
