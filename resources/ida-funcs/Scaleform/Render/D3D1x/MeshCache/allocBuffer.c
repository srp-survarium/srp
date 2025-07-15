bool __userpurge Scaleform::Render::D3D1x::MeshCache::allocBuffer@<al>(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        int a2@<edi>,
        unsigned int *poffset,
        Scaleform::Render::D3D1x::MeshBuffer **pbuffer,
        Scaleform::Render::D3D1x::MeshBufferSet *mbs,
        unsigned int size,
        bool waitForCache)
{
  Scaleform::Render::D3D1x::MeshBufferSet *v7; // ebx
  unsigned int Granularity; // ecx
  unsigned int v10; // eax
  Scaleform::Render::D3D1x::MeshBuffer *v11; // eax
  int v12; // eax
  Scaleform::Render::FenceImpl *v13; // eax
  int v15; // esi
  int v16; // esi
  int v17; // eax
  Scaleform::Render::FenceImpl *v18; // eax

  v7 = mbs;
  if ( Scaleform::Render::D3D1x::MeshBufferSet::Alloc(mbs, size, pbuffer, poffset) )
    return 1;
  if ( Scaleform::Render::MeshCacheListSet::EvictPendingFree(
         (Scaleform::Render::MeshCacheListSet *)(a2 + 104),
         &mbs->Allocator) )
  {
    return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(v7, size, pbuffer, poffset) != 0;
  }
  if ( (unsigned int)(*(_DWORD *)(a2 + 328) + *(_DWORD *)(a2 + 364) + 0x4000) > *(_DWORD *)(a2 + 20) )
    goto LABEL_12;
  if ( !Scaleform::Render::MeshCacheListSet::EvictLRUTillLimit(
          (Scaleform::Render::MeshCacheListSet *)(a2 + 104),
          (Scaleform::Render::MeshCacheListSet::ListSlot *)(a2 + 156),
          &mbs->Allocator,
          size,
          *(_DWORD *)(a2 + 28)) )
  {
    Granularity = mbs->Granularity;
    if ( size > Granularity )
      return 0;
    v10 = *(_DWORD *)(a2 + 20) - *(_DWORD *)(a2 + 328) - *(_DWORD *)(a2 + 364);
    if ( v10 >= Granularity )
      v10 = mbs->Granularity;
    if ( size <= v10 )
    {
      v11 = mbs->CreateBuffer(mbs, v10, 2, 0, *(_DWORD *)(a2 + 8), *(_DWORD *)(a2 + 92));
      if ( v11 )
      {
        v11->pPrev = *(Scaleform::Render::MeshBuffer **)(a2 + 380);
        v11->pNext = (Scaleform::Render::MeshBuffer *)(a2 + 376);
        *(_DWORD *)(*(_DWORD *)(a2 + 380) + 8) = v11;
        *(_DWORD *)(a2 + 380) = v11;
        return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(v7, size, pbuffer, poffset) != 0;
      }
    }
LABEL_12:
    if ( Scaleform::Render::MeshCacheListSet::EvictLRU(
           (Scaleform::Render::MeshCacheListSet *)(a2 + 104),
           (Scaleform::Render::MeshCacheListSet::ListSlot *)(a2 + 156),
           &mbs->Allocator,
           size) )
    {
      return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(v7, size, pbuffer, poffset) != 0;
    }
    if ( *(_DWORD *)(a2 + 372) <= *(_DWORD *)(a2 + 36) )
    {
      while ( 1 )
      {
        v15 = *(_DWORD *)(a2 + 148);
        if ( v15 == a2 + 144 )
          break;
        v12 = *(_DWORD *)(v15 + 52);
        if ( v12 )
        {
          if ( *(_BYTE *)(v12 + 6)
            && (v13 = *(Scaleform::Render::FenceImpl **)v12) != 0
            && Scaleform::Render::FenceImpl::IsPending(v13, FenceType_Vertex) )
          {
            continue;
          }
        }
        if ( (*(int (__thiscall **)(int, int, Scaleform::AllocAddr *, _DWORD))(*(_DWORD *)a2 + 32))(
               a2,
               v15,
               &mbs->Allocator,
               0) >= size )
          return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(v7, size, pbuffer, poffset) != 0;
      }
      v16 = *(_DWORD *)(a2 + 136);
      if ( waitForCache )
      {
        while ( v16 != a2 + 132 )
        {
          v17 = *(_DWORD *)(v16 + 52);
          if ( v17 && *(_BYTE *)(v17 + 6) )
          {
            v18 = *(Scaleform::Render::FenceImpl **)v17;
            if ( v18 )
              Scaleform::Render::FenceImpl::WaitFence(v18, FenceType_Vertex);
          }
          if ( (*(int (__thiscall **)(int, int, Scaleform::AllocAddr *, _DWORD))(*(_DWORD *)a2 + 32))(
                 a2,
                 v16,
                 &mbs->Allocator,
                 0) >= size )
          {
            v7 = mbs;
            return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(v7, size, pbuffer, poffset) != 0;
          }
          v16 = *(_DWORD *)(a2 + 136);
        }
      }
    }
    return 0;
  }
  return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(v7, size, pbuffer, poffset) != 0;
}
