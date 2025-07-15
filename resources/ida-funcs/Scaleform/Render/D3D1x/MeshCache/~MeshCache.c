void __usercall Scaleform::Render::D3D1x::MeshCache::~MeshCache(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        int a2@<edi>)
{
  int v2; // eax
  Scaleform::Render::D3D1x::RenderSync *v3; // ecx
  int v4; // eax
  int v5; // eax

  *(_DWORD *)a2 = &Scaleform::Render::D3D1x::MeshCache::`vftable'{for `Scaleform::Render::CacheBase'};
  *(_DWORD *)(a2 + 4) = &Scaleform::Render::D3D1x::MeshCache::`vftable'{for `Scaleform::Render::MeshCacheConfig'};
  Scaleform::Render::D3D1x::MeshCache::Reset(this, a2);
  v2 = *(_DWORD *)(a2 + 396);
  if ( v2 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(a2 + 396));
  Scaleform::Render::D3D1x::MeshBufferSet::~MeshBufferSet((Scaleform::Render::D3D1x::MeshBufferSet *)(a2 + 332));
  Scaleform::Render::D3D1x::MeshBufferSet::~MeshBufferSet((Scaleform::Render::D3D1x::MeshBufferSet *)(a2 + 296));
  Scaleform::Render::D3D1x::RenderSync::~RenderSync(v3, (Scaleform::Render::RenderSync *)(a2 + 184));
  v4 = *(_DWORD *)(a2 + 96);
  if ( v4 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(*(_DWORD *)(a2 + 96));
  v5 = *(_DWORD *)(a2 + 92);
  if ( v5 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(*(_DWORD *)(a2 + 92));
  Scaleform::Render::MeshCache::~MeshCache((Scaleform::Render::MeshCache *)a2);
}
