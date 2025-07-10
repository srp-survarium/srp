BOOL __thiscall Scaleform::Render::D3D1x::TextureManager::IsDrawableImageFormat(
        Scaleform::Render::D3D1x::TextureManager *this,
        Scaleform::Render::ImageFormat format)
{
  return format == Image_B8G8R8A8 || format == Image_R8G8B8A8;
}
