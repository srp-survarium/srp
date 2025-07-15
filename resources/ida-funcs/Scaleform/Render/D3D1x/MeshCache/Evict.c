unsigned int __thiscall Scaleform::Render::D3D1x::MeshCache::Evict(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::MeshCacheItem *pbatch,
        Scaleform::AllocAddr *pallocator,
        Scaleform::Render::MeshBase *pskipMesh)
{
  Scaleform::Render::Fence *pObject; // eax
  Scaleform::Render::FenceImpl *Data; // eax
  bool IsPending; // al
  Scaleform::Render::MeshCacheItem *pPrev; // eax
  unsigned int v10; // ebx
  Scaleform::Render::MeshCacheItem *pNext; // eax
  unsigned int v12; // eax

  pObject = pbatch->GPUFence.pObject;
  if ( pObject
    && (!pObject->HasData || (Data = pObject->Data) == 0
      ? (IsPending = 0)
      : (IsPending = Scaleform::Render::FenceImpl::IsPending(Data, FenceType_Vertex)),
        IsPending) )
  {
    Scaleform::Render::MeshCacheItem::Destroy(pbatch, pskipMesh, 0);
    Scaleform::Render::MeshCacheListSet::PushFront(&this->CacheList, MCL_PendingFree, pbatch);
    return 0;
  }
  else
  {
    pPrev = pbatch[1].pPrev;
    if ( pPrev )
      v10 = Scaleform::Render::D3D1x::MeshBufferSet::Free(
              (Scaleform::Render::D3D1x::MeshBuffer *)pPrev,
              (unsigned int)pbatch[1].pCacheList,
              &this->VertexBuffers,
              pbatch[1].ListType);
    else
      v10 = 0;
    pNext = pbatch[1].pNext;
    if ( pNext )
      v12 = Scaleform::Render::D3D1x::MeshBufferSet::Free(
              (Scaleform::Render::D3D1x::MeshBuffer *)pNext,
              pbatch[1].Type,
              &this->IndexBuffers,
              (unsigned int)pbatch[1].PrimitiveBatches.Root.pPrev);
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
