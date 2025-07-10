unsigned int __thiscall Scaleform::Render::D3D1x::MeshCache::Evict(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::MeshCacheItem *pbatch,
        Scaleform::AllocAddr *pallocator,
        Scaleform::Render::MeshBase *pskipMesh)
{
  Scaleform::Render::Fence *pObject; // eax
  Scaleform::Render::FenceImpl *Data; // eax
  Scaleform::Render::MeshCacheItem *pNext; // ecx
  Scaleform::Render::MeshCacheItem *pPrev; // eax
  unsigned int v10; // ebx
  Scaleform::Render::MeshCacheItem *v11; // eax
  unsigned int v12; // eax

  pObject = pbatch->GPUFence.pObject;
  if ( pObject
    && pObject->HasData
    && (Data = pObject->Data) != 0
    && Scaleform::Render::FenceImpl::IsPending(Data, FenceType_Vertex) )
  {
    Scaleform::Render::MeshCacheItem::Destroy(pbatch, pskipMesh, 0);
    pbatch->ListType = MCL_PendingFree;
    pNext = this->CacheList.Slots[5].Root.pNext;
    pbatch->pPrev = (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[5];
    pbatch->pNext = pNext;
    this->CacheList.Slots[5].Root.pNext->pPrev = pbatch;
    this->CacheList.Slots[5].Root.pNext = pbatch;
    this->CacheList.Slots[5].Size += pbatch->AllocSize;
    return 0;
  }
  else
  {
    pPrev = pbatch[1].pPrev;
    if ( pPrev )
      v10 = 16
          * Scaleform::AllocAddr::Free(
              &this->VertexBuffers.Allocator,
              ((unsigned int)pbatch[1].pCacheList >> 4) | (pPrev->HashKey << 24),
              (unsigned int)(pbatch[1].ListType + 15) >> 4);
    else
      v10 = 0;
    v11 = pbatch[1].pNext;
    if ( v11 )
      v12 = 16
          * Scaleform::AllocAddr::Free(
              &this->IndexBuffers.Allocator,
              ((unsigned int)pbatch[1].Type >> 4) | (v11->HashKey << 24),
              ((unsigned int)&pbatch[1].PrimitiveBatches.Root.pPrev[1].pVoidPrev + 3) >> 4);
    else
      v12 = 0;
    if ( pallocator )
    {
      if ( &this->VertexBuffers.Allocator != pallocator )
        v10 = v12;
    }
    else
    {
      v10 += v12;
    }
    this->VBSizeEvictedInLock += pbatch[1].ListType;
    Scaleform::Render::MeshCacheItem::Destroy(pbatch, pskipMesh, 1);
    return v10;
  }
}
