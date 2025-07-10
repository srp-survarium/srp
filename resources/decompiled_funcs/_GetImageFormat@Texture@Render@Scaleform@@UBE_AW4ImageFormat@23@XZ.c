Scaleform::Render::ImageFormat __thiscall Scaleform::Render::Texture::GetImageFormat(Scaleform::Render::Texture *this)
{
  if ( this->pFormat )
    return this->pFormat->GetImageFormat(this->pFormat);
  else
    return 0;
}
