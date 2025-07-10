void __userpurge Scaleform::Render::D3D1x::Texture::Texture(
        Scaleform::GFx::Resource *pmanagerLocks@<edi>,
        unsigned __int16 use@<cx>,
        Scaleform::Render::ImageBase *pimage@<eax>,
        Scaleform::Render::D3D1x::Texture *this,
        Scaleform::Render::D3D1x::TextureFormat *pformat,
        unsigned __int8 mipLevels,
        const Scaleform::Render::Size<unsigned long> *size)
{
  Scaleform::Render::ImageFormat v7; // eax
  unsigned __int8 FormatPlaneCount; // al

  Scaleform::Render::Texture::Texture(this, pmanagerLocks, size, mipLevels, use, pimage, pformat);
  this->__vftable = (Scaleform::Render::D3D1x::Texture_vtbl *)&Scaleform::Render::D3D1x::Texture::`vftable';
  v7 = pformat->GetImageFormat(pformat);
  FormatPlaneCount = Scaleform::Render::ImageData::GetFormatPlaneCount(v7);
  this->TextureCount = FormatPlaneCount;
  if ( FormatPlaneCount <= 1u )
    this->pTextures = &this->Texture0;
  else
    this->pTextures = (Scaleform::Render::D3D1x::Texture::HWTextureDesc *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                            Scaleform::Memory::pGlobalHeap,
                                                                            this,
                                                                            20 * FormatPlaneCount,
                                                                            0);
  memset((int)this->pTextures, 0, 20 * this->TextureCount);
}
