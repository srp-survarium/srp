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


char __thiscall Scaleform::Render::D3D1x::Texture::Initialize(Scaleform::Render::D3D1x::Texture *this)
{
  Scaleform::Render::ImageFormat v3; // eax
  bool v4; // zf
  Scaleform::Render::D3D1x::TextureManager *v5; // edx
  unsigned int v6; // ebp
  int v7; // ebx
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v8; // edi
  Scaleform::Render::Size<unsigned long> *FormatPlaneSize; // eax
  unsigned int Height; // ecx
  unsigned int v11; // ebp
  unsigned int v12; // ebx
  int v13; // edi
  unsigned int v14; // eax
  unsigned __int16 Use; // ax
  bool v16; // cl
  bool v17; // al
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v18; // edi
  unsigned int MipLevels; // edx
  Scaleform::Render::D3D1x::TextureManager *v20; // ebx
  const Scaleform::Render::TextureFormat *pFormat; // ecx
  DXGI_FORMAT GetImageFormat; // ecx
  ID3D11Device *pDevice; // eax
  unsigned int TextureCount; // ecx
  int v25; // [esp+20h] [ebp-48h]
  D3D11_USAGE usage; // [esp+24h] [ebp-44h]
  unsigned int bindFlags; // [esp+28h] [ebp-40h]
  Scaleform::Render::Size<unsigned long> cpu; // [esp+2Ch] [ebp-3Ch] BYREF
  Scaleform::Render::ImageFormat format; // [esp+34h] [ebp-34h]
  Scaleform::Render::D3D1x::TextureManager *pmanager; // [esp+38h] [ebp-30h]
  D3D11_TEXTURE2D_DESC desc; // [esp+3Ch] [ebp-2Ch] BYREF

  if ( (this->TextureFlags & 4) != 0 )
    return Scaleform::Render::D3D1x::Texture::Initialize(this, this->pTextures->pTexture);
  v3 = this->GetImageFormat(this);
  v4 = this->State == (State_Dead|State_Valid);
  v5 = (Scaleform::Render::D3D1x::TextureManager *)this->pManagerLocks.pObject->pManager;
  format = v3;
  pmanager = v5;
  if ( !v4 )
  {
    v6 = 0;
    if ( this->TextureCount )
    {
      v7 = 0;
      do
      {
        v8 = &this->pTextures[v7];
        FormatPlaneSize = Scaleform::Render::ImageData::GetFormatPlaneSize(&cpu, format, &this->ImgSize, v6);
        Height = FormatPlaneSize->Height;
        v8->Size.Width = FormatPlaneSize->Width;
        v8->Size.Height = Height;
        ++v6;
        ++v7;
      }
      while ( v6 < this->TextureCount );
    }
  }
  if ( (this->Use & 2) != 0
    && Scaleform::Render::D3D1x::IsD3DFormatMipGenCompatible((DXGI_FORMAT)this->pFormat[1].GetImageFormat) )
  {
    this->TextureFlags |= 2u;
    v11 = 0;
    v12 = 31;
    if ( this->TextureCount )
    {
      v13 = 0;
      do
      {
        v14 = Scaleform::Render::ImageSize_MipLevelCount(this->pTextures[v13].Size);
        if ( v12 >= v14 )
          v12 = v14;
        ++v11;
        ++v13;
      }
      while ( v11 < this->TextureCount );
    }
    this->MipLevels = v12;
  }
  Use = this->Use;
  v16 = (Use & 0x100) != 0 && (Use & 0xE0) != 0;
  v17 = (Use & 0x400) != 0;
  usage = D3D11_USAGE_DEFAULT;
  cpu.Width = 0;
  bindFlags = 8;
  if ( v16 )
  {
    usage = D3D11_USAGE_DYNAMIC;
    cpu.Width = (unsigned int)&_sbh_sizeHeaderList;
  }
  if ( v17 )
    bindFlags = 40;
  v4 = this->TextureCount == 0;
  format = Image_None;
  if ( v4 )
  {
LABEL_28:
    if ( !this->pImage || Scaleform::Render::Texture::Update(this) )
    {
      this->State = State_Dead;
      return Scaleform::Render::Texture::Initialize(this);
    }
  }
  else
  {
    v25 = 0;
    while ( 1 )
    {
      v18 = &this->pTextures[v25];
      memset((int)&desc, 0, sizeof(desc));
      MipLevels = this->MipLevels;
      v20 = pmanager;
      desc.Width = v18->Size.Width;
      desc.Height = v18->Size.Height;
      pFormat = this->pFormat;
      desc.MipLevels = MipLevels;
      desc.ArraySize = 1;
      GetImageFormat = (DXGI_FORMAT)pFormat[1].GetImageFormat;
      desc.Usage = usage;
      desc.Format = GetImageFormat;
      desc.CPUAccessFlags = cpu.Width;
      desc.SampleDesc.Count = 1;
      pDevice = pmanager->pDevice;
      desc.BindFlags = bindFlags;
      if ( pDevice->CreateTexture2D(pDevice, &desc, 0, &v18->pTexture) < 0
        || v20->pDevice->CreateShaderResourceView(v20->pDevice, v18->pTexture, 0, &v18->pView) < 0 )
      {
        break;
      }
      TextureCount = this->TextureCount;
      ++v25;
      if ( ++format >= TextureCount )
        goto LABEL_28;
    }
  }
  this->ReleaseHWTextures(this, 1);
  if ( this->State != (State_Dead|State_Valid) )
    this->State = State_Valid;
  return 0;
}
