char __usercall Scaleform::Render::D3D1x::Texture::Initialize@<al>(
        Scaleform::Render::D3D1x::Texture *this@<esi>,
        ID3D11Texture2D *ptexture@<eax>)
{
  Scaleform::Render::ImageBase *pImage; // ecx
  Scaleform::Render::TextureManagerLocks *pObject; // eax
  Scaleform::Render::TextureManager *pManager; // edi
  int v7; // eax
  Scaleform::Render::D3D1x::TextureFormat::Mapping *v8; // eax
  unsigned int v9; // ecx
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *pTextures; // eax
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v11; // eax
  unsigned int Height; // ecx
  _DWORD v13[2]; // [esp+8h] [ebp-2Ch] BYREF
  unsigned __int8 v14; // [esp+10h] [ebp-24h]
  int v15; // [esp+18h] [ebp-1Ch]

  if ( !ptexture )
    return 0;
  if ( this->pTextures->pTexture != ptexture )
  {
    this->ReleaseHWTextures(this, 1);
    this->pTextures->pTexture = ptexture;
    this->pTextures->pTexture->AddRef(this->pTextures->pTexture);
  }
  ptexture->GetDesc(ptexture, (D3D11_TEXTURE2D_DESC *)v13);
  pImage = this->pImage;
  this->MipLevels = v14;
  pObject = this->pManagerLocks.pObject;
  this->pFormat = 0;
  pManager = pObject->pManager;
  if ( pImage )
  {
    v7 = pImage->GetFormat(pImage);
    this->pFormat = pManager->getTextureFormat(pManager, (Scaleform::Render::ImageFormat)(v7 & 0xFFEFFFFF));
  }
  if ( !this->pFormat )
  {
    v8 = Scaleform::Render::D3D1x::TextureFormatMapping;
    if ( Scaleform::Render::D3D1x::TextureFormatMapping[0].Format )
    {
      while ( v8->D3DFormat != v15 )
      {
        ++v8;
        if ( v8->Format == Image_None )
          goto LABEL_13;
      }
      this->pFormat = pManager->getTextureFormat(pManager, v8->Format);
    }
LABEL_13:
    if ( !this->pFormat )
      goto LABEL_14;
  }
  v9 = v13[1];
  pTextures = this->pTextures;
  pTextures->Size.Width = v13[0];
  pTextures->Size.Height = v9;
  if ( !this->ImgSize.Width && !this->ImgSize.Height )
  {
    v11 = this->pTextures;
    Height = v11->Size.Height;
    this->ImgSize.Width = v11->Size.Width;
    this->ImgSize.Height = Height;
  }
  if ( (*((int (__stdcall **)(Scaleform::Render::TextureManager_vtbl *, ID3D11Texture2D *, _DWORD, ID3D11ShaderResourceView **))this->pManagerLocks.pObject->pManager[1].~Scaleform::Render::TextureManager
        + 7))(
         this->pManagerLocks.pObject->pManager[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable,
         this->pTextures->pTexture,
         0,
         &this->pTextures->pView) < 0 )
  {
LABEL_14:
    this->State = State_Valid;
    return 0;
  }
  this->State = State_Dead;
  return Scaleform::Render::Texture::Initialize(this);
}


char __thiscall Scaleform::Render::D3D1x::Texture::Initialize(Scaleform::Render::D3D1x::Texture *this)
{
  Scaleform::Render::TextureManager *pManager; // edi
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v4; // eax
  char v5; // al
  char v6; // bl
  unsigned int v8; // ebx
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v9; // edi
  Scaleform::Render::Size<unsigned long> *FormatPlaneSize; // eax
  unsigned int Height; // ecx
  int v12; // edi
  unsigned int v13; // ebx
  unsigned int v14; // eax
  unsigned __int16 Use; // ax
  bool v16; // cl
  bool v17; // al
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v18; // edi
  int MipLevels; // edx
  const Scaleform::Render::TextureFormat *pFormat; // ebx
  unsigned int v21; // ecx
  int v22; // [esp+20h] [ebp-258h]
  unsigned int i; // [esp+20h] [ebp-258h]
  unsigned int v24; // [esp+20h] [ebp-258h]
  Scaleform::Render::ImageFormat fmt; // [esp+24h] [ebp-254h]
  HINSTANCE__ *fmta; // [esp+24h] [ebp-254h]
  int v27; // [esp+28h] [ebp-250h]
  Scaleform::Render::TextureManager *v28; // [esp+2Ch] [ebp-24Ch]
  int v29; // [esp+30h] [ebp-248h]
  Scaleform::Render::Size<unsigned long> result; // [esp+34h] [ebp-244h] BYREF
  unsigned __int8 dst[44]; // [esp+3Ch] [ebp-23Ch] BYREF
  Scaleform::AmpFunctionTimer v32; // [esp+68h] [ebp-210h] BYREF
  char v33[512]; // [esp+78h] [ebp-200h] BYREF

  pManager = this->pManagerLocks.pObject->pManager;
  if ( pManager->RenderThreadId == (void *)Scaleform::GetCurrentThreadId() )
  {
    Instance = Scaleform::AmpServer::GetInstance();
    v4 = Instance->GetDisplayStats(Instance);
  }
  else
  {
    v4 = 0;
  }
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v32,
    v4,
    "Scaleform::Render::D3D1x::Texture::Initialize",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  if ( (this->TextureFlags & 4) != 0 )
  {
    v5 = Scaleform::Render::D3D1x::Texture::Initialize(this, this->pTextures->pTexture);
LABEL_6:
    v6 = v5;
    goto LABEL_7;
  }
  fmt = this->GetImageFormat(this);
  v28 = this->pManagerLocks.pObject->pManager;
  if ( this->State != (State_Dead|State_Valid) )
  {
    v8 = 0;
    if ( this->TextureCount )
    {
      v22 = 0;
      do
      {
        v9 = &this->pTextures[v22];
        FormatPlaneSize = Scaleform::Render::ImageData::GetFormatPlaneSize(&result, fmt, &this->ImgSize, v8);
        Height = FormatPlaneSize->Height;
        ++v22;
        v9->Size.Width = FormatPlaneSize->Width;
        v9->Size.Height = Height;
        ++v8;
      }
      while ( v8 < this->TextureCount );
    }
  }
  if ( (this->Use & 2) != 0
    && Scaleform::Render::D3D1x::IsD3DFormatMipGenCompatible((DXGI_FORMAT)this->pFormat[1].GetImageFormat) )
  {
    this->TextureFlags |= 2u;
    v12 = 0;
    v13 = 31;
    for ( i = 0; i < this->TextureCount; ++v12 )
    {
      v14 = Scaleform::Render::ImageSize_MipLevelCount(this->pTextures[v12].Size);
      ++i;
      if ( v13 >= v14 )
        v13 = v14;
    }
    this->MipLevels = v13;
  }
  Use = this->Use;
  v16 = (Use & 0x100) != 0 && (Use & 0xE0) != 0;
  v17 = (Use & 0x400) != 0;
  v29 = 0;
  fmta = 0;
  result.Width = 8;
  if ( v16 )
  {
    v29 = 2;
    fmta = &_sbh_sizeHeaderList;
  }
  if ( v17 )
    result.Width = 40;
  v24 = 0;
  if ( this->TextureCount )
  {
    v27 = 0;
    while ( 1 )
    {
      v18 = &this->pTextures[v27];
      memset((int)dst, 0, sizeof(dst));
      MipLevels = this->MipLevels;
      pFormat = this->pFormat;
      *(_DWORD *)dst = v18->Size.Width;
      v21 = v18->Size.Height;
      *(_DWORD *)&dst[8] = MipLevels;
      *(_DWORD *)&dst[4] = v21;
      *(_DWORD *)&dst[12] = 1;
      *(_DWORD *)&dst[16] = pFormat[1].GetImageFormat;
      *(_DWORD *)&dst[28] = v29;
      *(_DWORD *)&dst[32] = result.Width;
      *(_DWORD *)&dst[36] = fmta;
      *(_DWORD *)&dst[20] = 1;
      vostok::sprintf<512>((char (*)[512])v33, "CreateTexture2D %dx%d", *(_DWORD *)dst, v21);
      g_log_output_ptr(0, v33);
      if ( (*((int (__stdcall **)(Scaleform::Render::TextureManager_vtbl *, unsigned __int8 *, _DWORD, ID3D11Texture2D **))v28[1].~Scaleform::Render::TextureManager
            + 5))(
             v28[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable,
             dst,
             0,
             &v18->pTexture) < 0
        || (*((int (__stdcall **)(Scaleform::Render::TextureManager_vtbl *, ID3D11Texture2D *, _DWORD, ID3D11ShaderResourceView **))v28[1].~Scaleform::Render::TextureManager
            + 7))(
             v28[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable,
             v18->pTexture,
             0,
             &v18->pView) < 0 )
      {
        break;
      }
      ++v24;
      ++v27;
      if ( v24 >= this->TextureCount )
        goto LABEL_32;
    }
  }
  else
  {
LABEL_32:
    if ( !this->pImage || Scaleform::Render::Texture::Update(this) )
    {
      this->State = State_Dead;
      v5 = Scaleform::Render::Texture::Initialize(this);
      goto LABEL_6;
    }
  }
  this->ReleaseHWTextures(this, 1);
  if ( this->State != (State_Dead|State_Valid) )
    this->State = State_Valid;
  v6 = 0;
LABEL_7:
  Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v32);
  return v6;
}
