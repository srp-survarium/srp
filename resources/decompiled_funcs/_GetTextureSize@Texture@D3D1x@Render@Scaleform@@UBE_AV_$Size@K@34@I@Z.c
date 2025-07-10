Scaleform::Render::Size<unsigned long> *__thiscall Scaleform::Render::D3D1x::Texture::GetTextureSize(
        Scaleform::Render::D3D1x::Texture *this,
        Scaleform::Render::Size<unsigned long> *result,
        unsigned int plane)
{
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *pTextures; // ecx
  unsigned int Width; // edx
  Scaleform::Render::Size<unsigned long> *v5; // eax
  unsigned int Height; // ecx

  pTextures = this->pTextures;
  Width = pTextures[plane].Size.Width;
  v5 = result;
  Height = pTextures[plane].Size.Height;
  result->Width = Width;
  result->Height = Height;
  return v5;
}
