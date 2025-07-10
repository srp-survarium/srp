char __usercall Scaleform::Render::D3D1x::Texture::Initialize@<al>(
        Scaleform::Render::D3D1x::Texture *this@<esi>,
        ID3D11Texture2D *ptexture@<eax>)
{
  Scaleform::Render::TextureManagerLocks *pObject; // ecx
  Scaleform::Render::TextureManager *pManager; // edi
  Scaleform::Render::ImageBase *pImage; // ecx
  int v6; // eax
  Scaleform::Render::D3D1x::TextureFormat::Mapping *v7; // eax
  unsigned int Height; // ecx
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *pTextures; // eax
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v11; // eax
  unsigned int v12; // ecx
  D3D11_TEXTURE2D_DESC texDesc; // [esp+14h] [ebp-2Ch] BYREF

  if ( !ptexture )
    return 0;
  if ( this->pTextures->pTexture != ptexture )
  {
    this->ReleaseHWTextures(this, 1);
    this->pTextures->pTexture = ptexture;
    this->pTextures->pTexture->AddRef(this->pTextures->pTexture);
  }
  ptexture->GetDesc(ptexture, &texDesc);
  pObject = this->pManagerLocks.pObject;
  this->MipLevels = texDesc.MipLevels;
  this->pFormat = 0;
  pManager = pObject->pManager;
  pImage = this->pImage;
  if ( pImage )
  {
    v6 = pImage->GetFormat(pImage);
    this->pFormat = pManager->getTextureFormat(pManager, (Scaleform::Render::ImageFormat)(v6 & 0xFFEFFFFF));
  }
  if ( !this->pFormat )
  {
    v7 = Scaleform::Render::D3D1x::TextureFormatMapping;
    if ( Scaleform::Render::D3D1x::TextureFormatMapping[0].Format )
    {
      while ( v7->D3DFormat != texDesc.Format )
      {
        ++v7;
        if ( v7->Format == Image_None )
          goto LABEL_12;
      }
      this->pFormat = pManager->getTextureFormat(pManager, v7->Format);
    }
LABEL_12:
    if ( !this->pFormat )
      goto LABEL_13;
  }
  Height = texDesc.Height;
  pTextures = this->pTextures;
  pTextures->Size.Width = texDesc.Width;
  pTextures->Size.Height = Height;
  if ( !this->ImgSize.Width && !this->ImgSize.Height )
  {
    v11 = this->pTextures;
    v12 = v11->Size.Height;
    this->ImgSize.Width = v11->Size.Width;
    this->ImgSize.Height = v12;
  }
  if ( (*((int (__stdcall **)(Scaleform::Render::TextureManager_vtbl *, ID3D11Texture2D *, _DWORD, ID3D11ShaderResourceView **))this->pManagerLocks.pObject->pManager[1].~Scaleform::Render::TextureManager
        + 7))(
         this->pManagerLocks.pObject->pManager[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable,
         this->pTextures->pTexture,
         0,
         &this->pTextures->pView) < 0 )
  {
LABEL_13:
    this->State = State_Valid;
    return 0;
  }
  this->State = State_Dead;
  return Scaleform::Render::Texture::Initialize(this);
}
