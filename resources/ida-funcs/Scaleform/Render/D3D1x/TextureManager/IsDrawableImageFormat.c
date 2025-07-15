BOOL __thiscall Scaleform::Render::D3D1x::TextureManager::IsDrawableImageFormat(
        Scaleform::Render::D3D1x::TextureManager *this,
        Scaleform::Render::ImageFormat format)
{
  BOOL result; // eax

  result = 1;
  if ( format != Image_B8G8R8A8 )
    return format == Image_R8G8B8A8;
  return result;
}
