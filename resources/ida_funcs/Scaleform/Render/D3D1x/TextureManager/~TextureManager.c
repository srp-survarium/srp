void __usercall Scaleform::Render::D3D1x::TextureManager::~TextureManager(
        Scaleform::Render::D3D1x::TextureManager *this@<ecx>,
        int a2@<eax>)
{
  Scaleform::Mutex *v3; // edi
  Scaleform::Render::D3D1x::TextureManager *v4; // ecx
  void *v5; // edi

  v3 = (Scaleform::Mutex *)(*(_DWORD *)(a2 + 36) + 36);
  *(_DWORD *)a2 = &Scaleform::Render::D3D1x::TextureManager::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>'};
  *(_DWORD *)(a2 + 8) = &Scaleform::Render::D3D1x::TextureManager::`vftable'{for `Scaleform::Render::ImageUpdateSync'};
  Scaleform::Mutex::DoLock(v3);
  Scaleform::Render::D3D1x::TextureManager::Reset(v4, a2);
  *(_DWORD *)(*(_DWORD *)(a2 + 36) + 8) = 0;
  Scaleform::Mutex::Unlock(v3);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *(void **)(a2 + 244));
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *(void **)(a2 + 232));
  *(_DWORD *)(a2 + 96) = &Scaleform::Render::MappedTextureBase::`vftable';
  Scaleform::Render::ImageData::freePlanes((Scaleform::Render::ImageData *)(a2 + 112));
  v5 = *(void **)(a2 + 128);
  if ( v5 && InterlockedExchangeAdd((volatile LONG *)v5, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  Scaleform::Render::TextureManager::~TextureManager((Scaleform::Render::TextureManager *)a2);
}
