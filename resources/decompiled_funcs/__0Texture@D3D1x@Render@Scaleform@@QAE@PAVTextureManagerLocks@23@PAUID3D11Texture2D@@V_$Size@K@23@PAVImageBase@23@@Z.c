void __userpurge Scaleform::Render::D3D1x::Texture::Texture(
        Scaleform::Render::D3D1x::Texture *this@<ecx>,
        Scaleform::GFx::Resource *pmanagerLocks@<edi>,
        Scaleform::Render::ImageBase *image@<eax>,
        ID3D11Texture2D *ptexture,
        Scaleform::Render::Size<unsigned long> size)
{
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *pTextures; // eax
  unsigned int Height; // ecx

  Scaleform::Render::Texture::Texture(this, pmanagerLocks, &size, 0, 0, image, 0);
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
