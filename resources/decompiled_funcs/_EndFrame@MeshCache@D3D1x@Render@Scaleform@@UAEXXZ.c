void __usercall Scaleform::Render::D3D1x::MeshCache::EndFrame(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        Scaleform::Render::D3D1x::MeshBuffer *a2@<ebp>)
{
  Scaleform::Render::D3D1x::MeshCache *v3; // ecx
  unsigned int Size; // eax
  signed int v5; // ebx
  Scaleform::List<Scaleform::Render::MeshBuffer,Scaleform::Render::MeshBuffer> *p_ChunkBuffers; // eax
  Scaleform::Render::MeshBuffer *v7; // ecx
  Scaleform::Render::MeshCacheItem *pPrev; // esi
  char *p_VertexBuffers; // ebp
  Scaleform::Render::D3D1x::MeshBuffer *v10; // [esp-4h] [ebp-14h]
  bool allEvicted; // [esp+Fh] [ebp-1h]

  this->RSync.EndFrame(&this->RSync);
  Scaleform::Render::MeshCacheListSet::EndFrame(&this->CacheList);
  Scaleform::Render::MeshCacheListSet::EvictPendingFree(&this->CacheList, &this->IndexBuffers.Allocator);
  Scaleform::Render::MeshCacheListSet::EvictPendingFree(&this->CacheList, &this->VertexBuffers.Allocator);
  Scaleform::Render::D3D1x::MeshCache::destroyPendingBuffers(v3, this);
  Size = this->CacheList.Slots[4].Size;
  if ( Size >= this->Params.LRUTailSize )
    Size = this->Params.LRUTailSize;
  v5 = this->VertexBuffers.TotalSize
     + this->IndexBuffers.TotalSize
     - ((this->CacheList.Slots[3].Size + Size) >> 2)
     - (this->CacheList.Slots[3].Size
      + Size);
  if ( v5 > (signed int)this->Params.MemGranularity )
  {
    v10 = a2;
    while ( 1 )
    {
      p_ChunkBuffers = &this->ChunkBuffers;
      v7 = this == (Scaleform::Render::D3D1x::MeshCache *)-372
         ? 0
         : (Scaleform::Render::MeshBuffer *)&this->LockedBuffers;
      if ( this->ChunkBuffers.Root.pNext == v7 || v5 <= (signed int)this->Params.MemGranularity )
        break;
      pPrev = (Scaleform::Render::MeshCacheItem *)p_ChunkBuffers->Root.pPrev;
      p_ChunkBuffers->Root.pPrev->pPrev->pNext = p_ChunkBuffers->Root.pPrev->pNext;
      pPrev->pCacheList->Slots[0].Root.pPrev = pPrev->pNext;
      v5 -= (signed int)pPrev->PrimitiveBatches.Root.pPrev;
      p_VertexBuffers = (char *)&this->VertexBuffers;
      if ( ((int (__thiscall *)(Scaleform::Render::MeshCacheItem *))pPrev->pPrev->Type)(pPrev) )
        p_VertexBuffers = (char *)&this->IndexBuffers;
      allEvicted = Scaleform::Render::D3D1x::MeshCache::evictMeshesInBuffer(
                     (Scaleform::Render::D3D1x::MeshCache *)this->CacheList.Slots,
                     (int)this,
                     this->CacheList.Slots,
                     pPrev,
                     v10);
      Scaleform::AllocAddr::RemoveSegment(
        (Scaleform::AllocAddr *)(p_VertexBuffers + 16),
        pPrev->HashKey << 24,
        ((unsigned int)&pPrev->PrimitiveBatches.Root.pPrev[1].pVoidPrev + 3) >> 4);
      *((_DWORD *)p_VertexBuffers + 8) -= pPrev->PrimitiveBatches.Root.pPrev;
      *(_DWORD *)(*((_DWORD *)p_VertexBuffers + 1) + 4 * pPrev->HashKey) = 0;
      if ( allEvicted )
      {
        ((void (__thiscall *)(Scaleform::Render::MeshCacheItem *, int))pPrev->pPrev->pPrev)(pPrev, 1);
      }
      else
      {
        pPrev->pNext = (Scaleform::Render::MeshCacheItem *)this->PendingDestructionBuffers.Root.pPrev;
        pPrev->pCacheList = (Scaleform::Render::MeshCacheListSet *)&this->ChunkBuffers.Root.4;
        this->PendingDestructionBuffers.Root.pPrev->pNext = (Scaleform::Render::MeshBuffer *)pPrev;
        this->PendingDestructionBuffers.Root.pPrev = (Scaleform::Render::MeshBuffer *)pPrev;
      }
    }
  }
}
