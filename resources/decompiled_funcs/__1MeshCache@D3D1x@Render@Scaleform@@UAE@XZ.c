void __usercall Scaleform::Render::D3D1x::MeshCache::~MeshCache(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax

  *(_DWORD *)a2 = &Scaleform::Render::D3D1x::MeshCache::`vftable'{for `Scaleform::Render::CacheBase'};
  *(_DWORD *)(a2 + 4) = &Scaleform::Render::D3D1x::MeshCache::`vftable'{for `Scaleform::Render::MeshCacheConfig'};
  Scaleform::Render::D3D1x::MeshCache::Reset(this, a2);
  v2 = *(_DWORD *)(a2 + 388);
  if ( v2 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(a2 + 388));
  *(_DWORD *)(a2 + 324) = &Scaleform::Render::D3D1x::MeshBufferSet::`vftable';
  Scaleform::AllocAddr::~AllocAddr((Scaleform::AllocAddr *)(a2 + 340));
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *(void **)(a2 + 328));
  *(_DWORD *)(a2 + 288) = &Scaleform::Render::D3D1x::MeshBufferSet::`vftable';
  Scaleform::AllocAddr::~AllocAddr((Scaleform::AllocAddr *)(a2 + 304));
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *(void **)(a2 + 292));
  v3 = *(_DWORD *)(a2 + 280);
  if ( v3 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(*(_DWORD *)(a2 + 280));
  v4 = *(_DWORD *)(a2 + 276);
  if ( v4 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(*(_DWORD *)(a2 + 276));
  Scaleform::Render::RenderSync::~RenderSync((Scaleform::Render::RenderSync *)(a2 + 176));
  v5 = *(_DWORD *)(a2 + 92);
  if ( v5 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(*(_DWORD *)(a2 + 92));
  v6 = *(_DWORD *)(a2 + 88);
  if ( v6 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v6 + 8))(*(_DWORD *)(a2 + 88));
  Scaleform::Render::MeshCache::~MeshCache((Scaleform::Render::MeshCache *)a2);
}
