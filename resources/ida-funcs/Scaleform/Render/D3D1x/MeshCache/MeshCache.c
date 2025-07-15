void __userpurge Scaleform::Render::D3D1x::MeshCache::MeshCache(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        int a2@<edi>,
        Scaleform::MemoryHeap *pheap,
        const Scaleform::Render::MeshCacheParams *params)
{
  _DWORD *v4; // eax
  int i; // ecx
  int v6; // ecx
  int v7; // ecx
  Scaleform::Render::D3D1x::MeshBufferSet *v8; // [esp-8h] [ebp-Ch]

  Scaleform::Render::MeshCache::MeshCache((Scaleform::Render::MeshCache *)a2, pheap, params);
  *(_DWORD *)a2 = &Scaleform::Render::D3D1x::MeshCache::`vftable'{for `Scaleform::Render::CacheBase'};
  *(_DWORD *)(a2 + 4) = &Scaleform::Render::D3D1x::MeshCache::`vftable'{for `Scaleform::Render::MeshCacheConfig'};
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 96) = 0;
  *(_DWORD *)(a2 + 104) = a2;
  v4 = (_DWORD *)(a2 + 108);
  for ( i = 5; i >= 0; --i )
  {
    *v4 = v4;
    v4[1] = v4;
    v4[2] = 0;
    v4 += 3;
  }
  *(_DWORD *)(a2 + 184) = &Scaleform::RefCountImplCore::`vftable';
  *(_DWORD *)(a2 + 188) = 1;
  *(_DWORD *)(a2 + 192) = a2 + 192;
  *(_DWORD *)(a2 + 196) = a2 + 192;
  *(_DWORD *)(a2 + 208) = 127;
  *(_DWORD *)(a2 + 200) = 0;
  *(_DWORD *)(a2 + 204) = 0;
  *(_DWORD *)(a2 + 212) = 0;
  *(_DWORD *)(a2 + 216) = a2 + 200;
  *(_DWORD *)(a2 + 228) = 127;
  *(_DWORD *)(a2 + 220) = 0;
  *(_DWORD *)(a2 + 224) = 0;
  *(_DWORD *)(a2 + 232) = 0;
  *(_DWORD *)(a2 + 236) = a2 + 220;
  *(_DWORD *)(a2 + 248) = 127;
  *(_DWORD *)(a2 + 240) = 0;
  *(_DWORD *)(a2 + 244) = 0;
  *(_DWORD *)(a2 + 252) = 0;
  *(_DWORD *)(a2 + 256) = a2 + 240;
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 184) = &Scaleform::Render::D3D1x::RenderSync::`vftable';
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 284) = 0;
  *(_DWORD *)(a2 + 288) = 0;
  Scaleform::Render::D3D1x::MeshBufferSet::MeshBufferSet(
    (Scaleform::Render::D3D1x::MeshBufferSet *)9,
    a2 + 296,
    pheap,
    16 * (5 * (params->MemGranularity >> 4) / 9));
  *(_DWORD *)(a2 + 296) = &Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer>::`vftable';
  v8 = (Scaleform::Render::D3D1x::MeshBufferSet *)((params->MemGranularity & 0xFFFFFFF0)
                                                 - 16 * (*(_DWORD *)(a2 + 324) >> 4));
  Scaleform::Render::D3D1x::MeshBufferSet::MeshBufferSet(v8, a2 + 332, pheap, (unsigned int)v8);
  *(_DWORD *)(a2 + 332) = &Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::IndexBuffer>::`vftable';
  *(_BYTE *)(a2 + 368) = 0;
  *(_DWORD *)(a2 + 372) = 0;
  *(_DWORD *)(a2 + 376) = 0;
  if ( a2 == -380 )
    v6 = 0;
  else
    v6 = a2 + 376;
  *(_DWORD *)(a2 + 380) = v6;
  *(_DWORD *)(a2 + 384) = v6;
  if ( a2 == -388 )
    v7 = 0;
  else
    v7 = a2 + 384;
  *(_DWORD *)(a2 + 388) = v7;
  *(_DWORD *)(a2 + 392) = v7;
  *(_DWORD *)(a2 + 396) = 0;
}
