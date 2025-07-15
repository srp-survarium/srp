int __thiscall Scaleform::Render::Texture::GetBytes(Scaleform::Render::Texture *this, int *memRegion)
{
  unsigned int Height; // edx
  Scaleform::Render::ImageFormat v3; // eax
  Scaleform::Render::Size<unsigned long> sz; // [esp+0h] [ebp-8h] BYREF

  if ( memRegion )
    *memRegion = 1;
  Height = this->ImgSize.Height;
  sz.Width = this->ImgSize.Width;
  sz.Height = Height;
  v3 = this->GetFormat(this);
  return Scaleform::Render::ImageData::GetMipLevelSize(v3, &sz, 0);
}
