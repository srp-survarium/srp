void __userpurge Scaleform::Render::D3D1x::Texture::Texture(
        Scaleform::Render::D3D1x::Texture *this@<ecx>,
        ID3D11Texture2D *ptexture@<eax>,
        Scaleform::Render::TextureManagerLocks *pmanagerLocks,
        Scaleform::Render::Size<unsigned long> size,
        Scaleform::Render::ImageBase *image)
{
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *pTextures; // ecx
  unsigned int Height; // edx

  Scaleform::Render::Texture::Texture(this, (int)this, (Scaleform::GFx::Resource *)pmanagerLocks, &size, 0, 0, image, 0);
  this->TextureFlags |= 4u;
  this->__vftable = (Scaleform::Render::D3D1x::Texture_vtbl *)&Scaleform::Render::D3D1x::Texture::`vftable';
  ptexture->AddRef(ptexture);
  this->pTextures = &this->Texture0;
  this->Texture0.pTexture = ptexture;
  this->pTextures->pView = 0;
  pTextures = this->pTextures;
  Height = size.Height;
  pTextures->Size.Width = size.Width;
  pTextures->Size.Height = Height;
  this->pTextures->pStagingTexture = 0;
}


void __userpurge Scaleform::Render::D3D1x::Texture::Texture(
        Scaleform::Render::D3D1x::Texture *this@<eax>,
        Scaleform::Render::D3D1x::TextureFormat *pformat@<edi>,
        Scaleform::Render::Texture *a3@<ecx>,
        Scaleform::Render::TextureManagerLocks *pmanagerLocks,
        unsigned __int8 mipLevels,
        const Scaleform::Render::Size<unsigned long> *size,
        unsigned __int16 use,
        Scaleform::Render::ImageBase *pimage)
{
  Scaleform::Render::ImageFormat v9; // eax
  unsigned __int8 FormatPlaneCount; // al
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *p_Texture0; // eax
  const Scaleform::Render::TextureFormat *v12; // [esp+0h] [ebp-8h]

  Scaleform::Render::Texture::Texture(
    a3,
    (int)this,
    (Scaleform::GFx::Resource *)pmanagerLocks,
    size,
    mipLevels,
    use,
    pimage,
    v12);
  this->__vftable = (Scaleform::Render::D3D1x::Texture_vtbl *)&Scaleform::Render::D3D1x::Texture::`vftable';
  v9 = pformat->GetImageFormat(pformat);
  FormatPlaneCount = Scaleform::Render::ImageData::GetFormatPlaneCount(v9);
  this->TextureCount = FormatPlaneCount;
  if ( FormatPlaneCount <= 1u )
    p_Texture0 = &this->Texture0;
  else
    p_Texture0 = (Scaleform::Render::D3D1x::Texture::HWTextureDesc *)Scaleform::Memory::AllocAutoHeap(
                                                                       this,
                                                                       20 * FormatPlaneCount);
  this->pTextures = p_Texture0;
  memset((int)this->pTextures, 0, 20 * this->TextureCount);
}
