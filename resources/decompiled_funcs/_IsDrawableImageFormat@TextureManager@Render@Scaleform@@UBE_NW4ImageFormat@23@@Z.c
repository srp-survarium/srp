BOOL __thiscall Scaleform::Render::TextureManager::IsDrawableImageFormat(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::ImageFormat format)
{
  return format == Image_R8G8B8A8;
}
