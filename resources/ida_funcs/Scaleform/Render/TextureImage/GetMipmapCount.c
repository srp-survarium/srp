unsigned int __thiscall Scaleform::Render::TextureImage::GetMipmapCount(Scaleform::Render::TextureImage *this)
{
  Scaleform::Render::Texture *volatile Value; // eax

  if ( !this->pTexture.Value )
    return 1;
  Value = this->pTexture.Value;
  if ( (Value->Use & 2) != 0 )
    return 1;
  else
    return Value->MipLevels;
}
