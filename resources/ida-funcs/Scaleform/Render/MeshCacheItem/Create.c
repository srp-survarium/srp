Scaleform::Render::MeshCacheItem *__cdecl Scaleform::Render::MeshCacheItem::Create(
        Scaleform::Render::MeshCacheItem::MeshType type,
        Scaleform::Render::MeshCacheListSet *pcacheList,
        unsigned int classSize,
        Scaleform::Render::MeshCache *content,
        unsigned int allocSize,
        unsigned int vertexCount,
        unsigned int indexCount)
{
  unsigned int v8; // ebp
  unsigned int v9; // edi
  Scaleform::Render::MeshCacheItem *result; // eax
  Scaleform::Render::MeshCacheItem *v11; // esi
  Scaleform::Render::MeshCacheListSet *v12; // ecx
  unsigned int v13; // eax
  int v14; // ecx
  unsigned int v15; // edx
  Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *v16; // ecx
  Scaleform::Render::MeshCacheItem **pData; // edi
  int v18; // eax
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *inserted; // eax
  Scaleform::Render::MeshCacheItem *pNext; // edx
  Scaleform::Render::MeshCacheItem *p; // [esp+10h] [ebp-4h] BYREF
  unsigned int i; // [esp+20h] [ebp+Ch]
  Scaleform::Render::MeshCache *pcache; // [esp+24h] [ebp+10h]

  v8 = (unsigned int)content->Scaleform::Render::MeshCacheConfig::__vftable;
  v9 = (classSize + 3) & 0xFFFFFFFC;
  pcache = pcacheList->pCache;
  result = (Scaleform::Render::MeshCacheItem *)pcacheList->pCache->pHeap->Alloc(
                                                 pcacheList->pCache->pHeap,
                                                 v9 + 4 * v8,
                                                 0);
  v11 = result;
  p = result;
  if ( result )
  {
    v12 = pcacheList;
    result->Type = type;
    result->pCacheList = pcacheList;
    result->HashKey = (unsigned int)content->pRQCaches;
    result->MeshCount = v8;
    result->pMeshes = (Scaleform::Render::MeshBase **)((char *)result + v9);
    v13 = 0;
    if ( v8 )
    {
      do
      {
        v11->pMeshes[v13] = *(Scaleform::Render::MeshBase **)((char *)&content->~Scaleform::Render::MeshCache
                                                            + v13 * (unsigned int)content->pHeap);
        ++v13;
      }
      while ( v13 < v8 );
      v12 = pcacheList;
    }
    v11->PrimitiveBatches.Root.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)&v11->PrimitiveBatches;
    v11->PrimitiveBatches.Root.pNext = (Scaleform::Render::MeshCacheItemUseNode *)&v11->PrimitiveBatches;
    v11->AllocSize = allocSize;
    v11->VertexCount = vertexCount;
    v11->IndexCount = indexCount;
    v11->GPUFence.pObject = 0;
    if ( type )
    {
      (*v11->pMeshes)[1].pPrev = (Scaleform::Render::MeshStagingNode *)v11;
    }
    else
    {
      for ( i = 0; i < v8; ++i )
      {
        v14 = *(int *)((char *)&content->~Scaleform::Render::MeshCache + i * (unsigned int)content->pHeap);
        v15 = *(_DWORD *)(v14 + 112);
        v16 = (Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *)(v14 + 112);
        if ( v15 <= 2 )
          pData = (Scaleform::Render::MeshCacheItem **)&v16->4;
        else
          pData = (Scaleform::Render::MeshCacheItem **)v16->AD.pData;
        v18 = 0;
        if ( v15 )
        {
          while ( pData[v18] != v11 )
          {
            if ( ++v18 >= v15 )
              goto LABEL_13;
          }
        }
        else
        {
LABEL_13:
          inserted = Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::insertSpot(
                       v16,
                       v15);
          if ( inserted )
            inserted->pObject = (Scaleform::Render::TextLayerPrimitive *)v11;
        }
      }
      Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor>>::add<Scaleform::Render::MeshCacheItem *>(
        &pcache->BatchCacheItemHash,
        &pcache->BatchCacheItemHash,
        &p,
        v11->HashKey);
      v12 = pcacheList;
    }
    v11->ListType = MCL_Uncached;
    pNext = v12->Slots[0].Root.pNext;
    v11->pPrev = (Scaleform::Render::MeshCacheItem *)v12->Slots;
    v11->pNext = pNext;
    v12->Slots[0].Root.pNext->pPrev = v11;
    v12->Slots[0].Root.pNext = v11;
    v12->Slots[0].Size += v11->AllocSize;
    return v11;
  }
  return result;
}
