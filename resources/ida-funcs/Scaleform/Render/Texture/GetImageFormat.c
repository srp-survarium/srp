Scaleform::Render::ImageFormat __thiscall Scaleform::Render::Texture::GetImageFormat(Scaleform::Render::Texture *this)
{
  Scaleform::Render::ImageFormat result; // eax

  result = Image_None;
  if ( this->pFormat )
    return this->pFormat->GetImageFormat(this->pFormat);
  return result;
}
