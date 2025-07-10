const Scaleform::Render::TextureFormat *__thiscall Scaleform::Render::D3D1x::TextureManager::GetTextureUseCaps(
        Scaleform::Render::D3D1x::TextureManager *this,
        Scaleform::Render::ImageFormat format)
{
  int v3; // edi
  const Scaleform::Render::TextureFormat *result; // eax

  v3 = 272;
  if ( (format & 0xFFFu) - 50 > 0xB )
    v3 = 306;
  result = this->getTextureFormat(this, format);
  if ( result )
  {
    if ( this->isScanlineCompatible(this, result) )
      return (const Scaleform::Render::TextureFormat *)(v3 | 0x80);
    return (const Scaleform::Render::TextureFormat *)v3;
  }
  return result;
}
