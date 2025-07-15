char __userpurge Scaleform::Render::D3D1x::MeshCache::allocBuffer@<al>(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        int a2@<esi>,
        unsigned int *poffset,
        Scaleform::Render::D3D1x::MeshBuffer **pbuffer,
        Scaleform::Render::D3D1x::MeshBufferSet *mbs,
        unsigned int size,
        bool waitForCache)
{
  Scaleform::AllocAddr *p_Allocator; // ebx
  unsigned int v8; // eax
  unsigned int Granularity; // ecx
  unsigned int v11; // eax
  Scaleform::Render::D3D1x::MeshBuffer *v12; // eax
  unsigned int v13; // eax
  int v14; // edi
  int v15; // eax
  Scaleform::Render::FenceImpl *v16; // eax
  int v17; // edi
  int v18; // eax
  Scaleform::Render::FenceImpl *v19; // eax

  p_Allocator = &mbs->Allocator;
  v8 = Scaleform::AllocAddr::Alloc(&mbs->Allocator, (size + 15) >> 4);
  if ( v8 != -1 )
  {
    *pbuffer = mbs->Buffers.Data.Data[HIBYTE(v8)];
    *poffset = 16 * ((unsigned int)&vostok::memory::s_CRT_arena[5574199] & v8);
    return 1;
  }
  if ( !Scaleform::Render::MeshCacheListSet::EvictPendingFree(
          (Scaleform::Render::MeshCacheListSet *)(a2 + 100),
          p_Allocator) )
  {
    if ( (unsigned int)(*(_DWORD *)(a2 + 356) + *(_DWORD *)(a2 + 320) + 0x4000) > *(_DWORD *)(a2 + 20) )
      goto LABEL_34;
    if ( Scaleform::Render::MeshCacheListSet::EvictLRUTillLimit(
           (Scaleform::Render::MeshCacheListSet *)(a2 + 100),
           (Scaleform::Render::MeshCacheListSet::ListSlot *)(a2 + 152),
           p_Allocator,
           size,
           *(_DWORD *)(a2 + 28)) )
    {
      goto alloc_size_available;
    }
    Granularity = mbs->Granularity;
    if ( size > Granularity )
      return 0;
    v11 = *(_DWORD *)(a2 + 20) - *(_DWORD *)(a2 + 356) - *(_DWORD *)(a2 + 320);
    if ( v11 >= Granularity )
      v11 = mbs->Granularity;
    if ( size > v11 || (v12 = mbs->CreateBuffer(mbs, v11, 2, 0, *(_DWORD *)(a2 + 8), *(_DWORD *)(a2 + 88))) == 0 )
    {
LABEL_34:
      if ( !Scaleform::Render::MeshCacheListSet::EvictLRU(
              (Scaleform::Render::MeshCacheListSet *)(a2 + 100),
              (Scaleform::Render::MeshCacheListSet::ListSlot *)(a2 + 152),
              p_Allocator,
              size) )
      {
        if ( *(_DWORD *)(a2 + 364) > *(_DWORD *)(a2 + 36) )
          return 0;
        v14 = *(_DWORD *)(a2 + 144);
        if ( v14 == a2 + 140 )
        {
LABEL_23:
          v17 = *(_DWORD *)(a2 + 132);
          if ( waitForCache )
          {
            while ( v17 != a2 + 128 )
            {
              v18 = *(_DWORD *)(v17 + 52);
              if ( v18 && *(_BYTE *)(v18 + 6) )
              {
                v19 = *(Scaleform::Render::FenceImpl **)v18;
                if ( v19 )
                  Scaleform::Render::FenceImpl::WaitFence(v19, FenceType_Vertex);
              }
              if ( (*(int (__thiscall **)(int, int, Scaleform::AllocAddr *, _DWORD))(*(_DWORD *)a2 + 32))(
                     a2,
                     v17,
                     p_Allocator,
                     0) >= size )
                goto alloc_size_available;
              v17 = *(_DWORD *)(a2 + 132);
            }
          }
          return 0;
        }
        while ( 1 )
        {
          v15 = *(_DWORD *)(v14 + 52);
          if ( (!v15
             || !*(_BYTE *)(v15 + 6)
             || (v16 = *(Scaleform::Render::FenceImpl **)v15) == 0
             || !Scaleform::Render::FenceImpl::IsPending(v16, FenceType_Vertex))
            && (*(int (__thiscall **)(int, int, Scaleform::AllocAddr *, _DWORD))(*(_DWORD *)a2 + 32))(
                 a2,
                 v14,
                 p_Allocator,
                 0) >= size )
          {
            break;
          }
          v14 = *(_DWORD *)(a2 + 144);
          if ( v14 == a2 + 140 )
            goto LABEL_23;
        }
      }
      goto alloc_size_available;
    }
    v12->pPrev = *(Scaleform::Render::MeshBuffer **)(a2 + 372);
    v12->pNext = (Scaleform::Render::MeshBuffer *)(a2 + 368);
    *(_DWORD *)(*(_DWORD *)(a2 + 372) + 8) = v12;
    *(_DWORD *)(a2 + 372) = v12;
  }
alloc_size_available:
  v13 = Scaleform::AllocAddr::Alloc(p_Allocator, (size + 15) >> 4);
  if ( v13 != -1 )
  {
    *pbuffer = mbs->Buffers.Data.Data[HIBYTE(v13)];
    *poffset = 16 * ((unsigned int)&vostok::memory::s_CRT_arena[5574199] & v13);
    return 1;
  }
  return 0;
}
