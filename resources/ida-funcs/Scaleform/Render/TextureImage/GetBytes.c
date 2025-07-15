unsigned int __thiscall Scaleform::Render::TextureImage::GetBytes(
        Scaleform::Render::TextureImage *this,
        int *memRegion)
{
  int v4; // eax
  Scaleform::Render::ImageFormat v5; // eax
  Scaleform::Render::Size<unsigned long> v6; // [esp+4h] [ebp-8h] BYREF

  if ( memRegion )
    *memRegion = 0;
  if ( this->pTexture.Value )
    return this->pTexture.Value->GetBytes(this->pTexture.Value, memRegion);
  if ( memRegion )
    *memRegion = 0;
  v4 = ((int (__thiscall *)(Scaleform::Render::TextureImage *))this->GetSize)(this);
  v5 = ((int (__thiscall *)(Scaleform::Render::TextureImage *, int))this->GetFormat)(this, v4);
  return Scaleform::Render::ImageData::GetMipLevelSize(v5, &v6, 0);
}
