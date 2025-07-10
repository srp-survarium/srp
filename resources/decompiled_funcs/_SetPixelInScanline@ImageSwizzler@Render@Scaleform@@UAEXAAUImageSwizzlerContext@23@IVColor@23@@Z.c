void __thiscall Scaleform::Render::ImageSwizzler::SetPixelInScanline(
        Scaleform::Render::ImageSwizzler *this,
        Scaleform::Render::ImageSwizzlerContext *ctx,
        unsigned int x,
        Scaleform::Render::Color c)
{
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->SetPixelInScanline)(ctx, x, c);
}
