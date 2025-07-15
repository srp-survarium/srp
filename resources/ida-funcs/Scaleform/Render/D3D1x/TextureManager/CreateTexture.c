Scaleform::RefCountVImpl *__thiscall Scaleform::Render::D3D1x::TextureManager::CreateTexture(
        Scaleform::Render::D3D1x::TextureManager *this,
        int pd3dtexture,
        Scaleform::Render::Size<unsigned long> imgSize,
        Scaleform::Render::ImageBase *image)
{
  ID3D11Texture2D *v4; // ebx
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::Render::D3D1x::Texture *v8; // ecx
  Scaleform::RefCountVImpl *v9; // eax
  Scaleform::RefCountVImpl *v10; // edi
  Scaleform::Render::Texture *pPrev; // ecx

  v4 = (ID3D11Texture2D *)pd3dtexture;
  if ( !pd3dtexture )
    return 0;
  AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
  pd3dtexture = 75;
  v8 = (Scaleform::Render::D3D1x::Texture *)AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              76u,
                                              (const Scaleform::AllocInfo *)&pd3dtexture);
  if ( v8 )
  {
    Scaleform::Render::D3D1x::Texture::Texture(v8, (Scaleform::GFx::Resource *)this->pLocks.pObject, image, v4, imgSize);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  if ( this->RenderThreadId == (void *)Scaleform::GetCurrentThreadId() )
    return Scaleform::Render::TextureManager::postCreateTexture(this, v10, 0);
  pPrev = this->TextureInitQueue.Root.pPrev;
  v10[1].RefCount = (volatile int)&this->Textures;
  v10[1].__vftable = (Scaleform::RefCountVImpl_vtbl *)pPrev;
  this->TextureInitQueue.Root.pPrev->pNext = (Scaleform::Render::Texture *)v10;
  this->TextureInitQueue.Root.pPrev = (Scaleform::Render::Texture *)v10;
  return v10;
}


Scaleform::RefCountVImpl *__thiscall Scaleform::Render::D3D1x::TextureManager::CreateTexture(
        Scaleform::Render::D3D1x::TextureManager *this,
        Scaleform::Render::ImageFormat format,
        unsigned __int8 mipLevels,
        const Scaleform::Render::Size<unsigned long> *size,
        unsigned int use,
        Scaleform::Render::ImageBase *pimage,
        struct Scaleform::Render::MemoryManager *allocManager)
{
  Scaleform::RefCountVImpl *result; // eax
  __int16 v9; // bp
  Scaleform::Render::D3D1x::TextureFormat *v10; // ebx
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::Render::D3D1x::Texture *v12; // eax
  Scaleform::RefCountVImpl *v13; // eax
  Scaleform::RefCountVImpl *v14; // edi

  if ( !this->pDevice )
    return 0;
  v9 = use;
  result = (Scaleform::RefCountVImpl *)Scaleform::Render::TextureManager::precreateTexture(this, format, use, pimage);
  v10 = (Scaleform::Render::D3D1x::TextureFormat *)result;
  if ( result )
  {
    AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
    use = 75;
    v12 = (Scaleform::Render::D3D1x::Texture *)AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 76u,
                                                 (const Scaleform::AllocInfo *)&use);
    if ( v12 )
    {
      Scaleform::Render::D3D1x::Texture::Texture(
        (Scaleform::GFx::Resource *)this->pLocks.pObject,
        v9,
        pimage,
        v12,
        v10,
        mipLevels,
        size);
      v14 = v13;
    }
    else
    {
      v14 = 0;
    }
    if ( this->RenderThreadId == (void *)Scaleform::GetCurrentThreadId() )
    {
      return Scaleform::Render::TextureManager::postCreateTexture(this, v14, v9);
    }
    else
    {
      v14[1].__vftable = (Scaleform::RefCountVImpl_vtbl *)this->TextureInitQueue.Root.pPrev;
      result = (Scaleform::RefCountVImpl *)&this->Textures;
      v14[1].RefCount = (volatile int)&this->Textures;
      this->TextureInitQueue.Root.pPrev->pNext = (Scaleform::Render::Texture *)v14;
      this->TextureInitQueue.Root.pPrev = (Scaleform::Render::Texture *)v14;
    }
  }
  return result;
}
