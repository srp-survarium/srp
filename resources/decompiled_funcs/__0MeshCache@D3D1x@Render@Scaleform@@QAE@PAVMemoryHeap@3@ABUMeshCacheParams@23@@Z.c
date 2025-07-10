void __userpurge Scaleform::Render::D3D1x::MeshCache::MeshCache(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        int a2@<esi>,
        Scaleform::MemoryHeap *pheap,
        const Scaleform::Render::MeshCacheParams *params)
{
  Scaleform::Render::RenderSync *v4; // ecx
  unsigned int v5; // edx
  int v6; // edi
  unsigned int v7; // ecx
  unsigned int MemGranularity; // edi
  unsigned int v9; // edi
  int v10; // ecx

  Scaleform::Render::MeshCache::MeshCache((Scaleform::Render::MeshCache *)a2, pheap, params);
  *(_DWORD *)a2 = &Scaleform::Render::D3D1x::MeshCache::`vftable'{for `Scaleform::Render::CacheBase'};
  *(_DWORD *)(a2 + 4) = &Scaleform::Render::D3D1x::MeshCache::`vftable'{for `Scaleform::Render::MeshCacheConfig'};
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 100) = a2;
  `vector constructor iterator'(
    (char *)(a2 + 104),
    0xCu,
    6,
    (void *(__thiscall *)(void *))Scaleform::Render::MeshCacheListSet::ListSlot::ListSlot);
  Scaleform::Render::RenderSync::RenderSync(v4, (_DWORD *)(a2 + 176));
  *(_DWORD *)(a2 + 176) = &Scaleform::Render::D3D1x::RenderSync::`vftable';
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 276) = 0;
  *(_DWORD *)(a2 + 280) = 0;
  v5 = 5 * (params->MemGranularity >> 4) / 9;
  *(_DWORD *)(a2 + 288) = &Scaleform::Render::D3D1x::MeshBufferSet::`vftable';
  *(_DWORD *)(a2 + 292) = 0;
  *(_DWORD *)(a2 + 296) = 0;
  v6 = 16 * v5;
  *(_DWORD *)(a2 + 300) = 0;
  Scaleform::AllocAddr::AllocAddr((Scaleform::AllocAddr *)(a2 + 304), pheap);
  *(_DWORD *)(a2 + 316) = v6;
  *(_DWORD *)(a2 + 320) = 0;
  *(_DWORD *)(a2 + 288) = &Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer>::`vftable';
  v7 = v6;
  MemGranularity = params->MemGranularity;
  *(_DWORD *)(a2 + 324) = &Scaleform::Render::D3D1x::MeshBufferSet::`vftable';
  v9 = (MemGranularity & 0xFFFFFFF0) - 16 * (v7 >> 4);
  *(_DWORD *)(a2 + 328) = 0;
  *(_DWORD *)(a2 + 332) = 0;
  *(_DWORD *)(a2 + 336) = 0;
  Scaleform::AllocAddr::AllocAddr((Scaleform::AllocAddr *)(a2 + 340), pheap);
  *(_DWORD *)(a2 + 352) = v9;
  *(_DWORD *)(a2 + 356) = 0;
  *(_DWORD *)(a2 + 324) = &Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::IndexBuffer>::`vftable';
  *(_BYTE *)(a2 + 360) = 0;
  *(_DWORD *)(a2 + 364) = 0;
  *(_DWORD *)(a2 + 368) = 0;
  if ( a2 == -372 )
    v10 = 0;
  else
    v10 = a2 + 368;
  *(_DWORD *)(a2 + 372) = v10;
  *(_DWORD *)(a2 + 376) = v10;
  if ( a2 == -380 )
  {
    MEMORY[0] = 0;
    MEMORY[4] = 0;
  }
  else
  {
    *(_DWORD *)(a2 + 380) = a2 + 376;
    *(_DWORD *)(a2 + 384) = a2 + 376;
  }
  *(_DWORD *)(a2 + 388) = 0;
}
