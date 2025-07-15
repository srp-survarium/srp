Scaleform::RefCountVImpl *__thiscall Scaleform::Render::D3D1x::TextureManager::CreateTexture(
        Scaleform::Render::D3D1x::TextureManager *this,
        ID3D11Texture2D *pd3dtexture,
        Scaleform::Render::Size<unsigned long> imgSize,
        Scaleform::Render::ImageBase *image)
{
  Scaleform::Render::D3D1x::Texture *v6; // ecx
  Scaleform::RefCountVImpl *v7; // eax
  Scaleform::RefCountVImpl *v8; // edi

  if ( !pd3dtexture )
    return 0;
  v6 = (Scaleform::Render::D3D1x::Texture *)Scaleform::NewOverrideBase<75>::operator new(
                                              0x4Cu,
                                              (Scaleform::MemAddressStub *)this);
  if ( v6 )
  {
    Scaleform::Render::D3D1x::Texture::Texture(v6, pd3dtexture, this->pLocks.pObject, imgSize, image);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  if ( this->RenderThreadId == (void *)Scaleform::GetCurrentThreadId() )
    return Scaleform::Render::TextureManager::postCreateTexture(this, v8, 0);
  v8[1].__vftable = (Scaleform::RefCountVImpl_vtbl *)this->TextureInitQueue.Root.pPrev;
  v8[1].RefCount = (volatile int)&this->Textures;
  this->TextureInitQueue.Root.pPrev->pNext = (Scaleform::Render::Texture *)v8;
  this->TextureInitQueue.Root.pPrev = (Scaleform::Render::Texture *)v8;
  return v8;
}


Scaleform::Render::D3D1x::TextureFormat *__thiscall Scaleform::Render::D3D1x::TextureManager::CreateTexture(
        Scaleform::Render::D3D1x::TextureManager *this,
        Scaleform::Render::ImageFormat format,
        unsigned __int8 mipLevels,
        const Scaleform::Render::Size<unsigned long> *size,
        __int16 use,
        Scaleform::Render::ImageBase *pimage,
        struct Scaleform::Render::MemoryManager *allocManager)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v9; // eax
  Scaleform::Render::D3D1x::TextureFormat *Texture; // edi
  Scaleform::Render::D3D1x::Texture *v12; // eax
  Scaleform::Render::D3D1x::TextureFormat *v13; // eax
  Scaleform::AmpFunctionTimer v14; // [esp+8h] [ebp-10h] BYREF

  if ( this->RenderThreadId == (void *)Scaleform::GetCurrentThreadId() )
  {
    Instance = Scaleform::AmpServer::GetInstance();
    v9 = Instance->GetDisplayStats(Instance);
  }
  else
  {
    v9 = 0;
  }
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v14,
    v9,
    "Scaleform::Render::D3D1x::TextureManager::CreateTexture",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  if ( this->pDevice )
  {
    Texture = (Scaleform::Render::D3D1x::TextureFormat *)Scaleform::Render::TextureManager::precreateTexture(
                                                           this,
                                                           format,
                                                           use,
                                                           pimage);
    if ( Texture )
    {
      v12 = (Scaleform::Render::D3D1x::Texture *)Scaleform::NewOverrideBase<75>::operator new(
                                                   0x4Cu,
                                                   (Scaleform::MemAddressStub *)this);
      if ( v12 )
      {
        Scaleform::Render::D3D1x::Texture::Texture(
          v12,
          Texture,
          (Scaleform::Render::Texture *)this->pLocks.pObject,
          this->pLocks.pObject,
          mipLevels,
          size,
          use,
          pimage);
        Texture = v13;
      }
      else
      {
        Texture = 0;
      }
      if ( this->RenderThreadId == (void *)Scaleform::GetCurrentThreadId() )
      {
        Texture = (Scaleform::Render::D3D1x::TextureFormat *)Scaleform::Render::TextureManager::postCreateTexture(
                                                               this,
                                                               (Scaleform::RefCountVImpl *)Texture,
                                                               use);
      }
      else
      {
        Texture->D3DUsage = (unsigned int)this->TextureInitQueue.Root.pPrev;
        Texture[1].__vftable = (Scaleform::Render::D3D1x::TextureFormat_vtbl *)&this->Textures;
        this->TextureInitQueue.Root.pPrev->pNext = (Scaleform::Render::Texture *)Texture;
        this->TextureInitQueue.Root.pPrev = (Scaleform::Render::Texture *)Texture;
      }
    }
    Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v14);
    return Texture;
  }
  else
  {
    Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v14);
    return 0;
  }
}
