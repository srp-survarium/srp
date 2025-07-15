Scaleform::Render::Size<unsigned long> *__thiscall Scaleform::Render::D3D1x::Texture::GetTextureSize(
        Scaleform::Render::D3D1x::Texture *this,
        Scaleform::Render::Size<unsigned long> *result,
        unsigned int plane)
{
  Scaleform::Render::Size<unsigned long> *v3; // eax

  v3 = result;
  *result = this->pTextures[plane].Size;
  return v3;
}
