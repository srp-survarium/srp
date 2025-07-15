const Scaleform::Render::TextureFormat *__thiscall Scaleform::Render::TextureManager::getTextureFormat(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::ImageFormat format)
{
  int v3; // esi
  Scaleform::Render::TextureFormat **Data; // eax
  bool v5; // zf
  Scaleform::Render::TextureFormat **v6; // eax

  v3 = 0;
  if ( !this->TextureFormats.Data.Size )
    return 0;
  while ( 1 )
  {
    Data = this->TextureFormats.Data.Data;
    v5 = Data[v3] == 0;
    v6 = &Data[v3];
    if ( !v5 && (*v6)->GetImageFormat(*v6) == format )
      break;
    if ( ++v3 >= this->TextureFormats.Data.Size )
      return 0;
  }
  return this->TextureFormats.Data.Data[v3];
}
