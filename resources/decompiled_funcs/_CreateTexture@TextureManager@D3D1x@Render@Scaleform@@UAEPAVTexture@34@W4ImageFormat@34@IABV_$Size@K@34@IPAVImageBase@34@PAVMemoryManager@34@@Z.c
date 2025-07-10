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
