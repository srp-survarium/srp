Scaleform::Render::DepthStencilSurface *__thiscall Scaleform::Render::D3D1x::TextureManager::CreateDepthStencilSurface(
        Scaleform::Render::D3D1x::TextureManager *this,
        const Scaleform::Render::Size<unsigned long> *size,
        struct Scaleform::Render::MemoryManager *manager)
{
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::Render::D3D1x::DepthStencilSurface *v6; // eax
  Scaleform::Render::DepthStencilSurface *v7; // eax
  int v8; // [esp+4h] [ebp-4h] BYREF

  if ( !this->pDevice )
    return 0;
  AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
  v8 = 75;
  v6 = (Scaleform::Render::D3D1x::DepthStencilSurface *)AllocAutoHeap(
                                                          Scaleform::Memory::pGlobalHeap,
                                                          this,
                                                          40u,
                                                          (const Scaleform::AllocInfo *)&v8);
  if ( !v6 )
    return Scaleform::Render::TextureManager::postCreateDepthStencilSurface(this, 0);
  Scaleform::Render::D3D1x::DepthStencilSurface::DepthStencilSurface(
    v6,
    (Scaleform::GFx::Resource *)this->pLocks.pObject,
    size);
  return Scaleform::Render::TextureManager::postCreateDepthStencilSurface(this, v7);
}
