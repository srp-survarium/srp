unsigned int __thiscall Scaleform::Render::Texture::GetPlaneCount(Scaleform::Render::Texture *this)
{
  int MipLevels; // esi
  Scaleform::Render::ImageFormat v2; // eax

  if ( (this->Use & 2) != 0 )
    MipLevels = 1;
  else
    MipLevels = this->MipLevels;
  v2 = this->GetFormat(this);
  return MipLevels * Scaleform::Render::ImageData::GetFormatPlaneCount(v2);
}
