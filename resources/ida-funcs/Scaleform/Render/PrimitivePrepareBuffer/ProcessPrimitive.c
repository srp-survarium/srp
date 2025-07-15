Scaleform::Render::RenderQueueItem::QIPrepareResult __thiscall Scaleform::Render::PrimitivePrepareBuffer::ProcessPrimitive(
        Scaleform::Render::PrimitivePrepareBuffer *this,
        BOOL waitForCache)
{
  Scaleform::Render::PrimitiveBatch *p_Batches; // ebp
  Scaleform::Render::PrimitiveBatch *pPrepare; // edi
  Scaleform::Render::Primitive *v5; // ecx
  unsigned int MeshCount; // ecx
  Scaleform::Render::MeshBase **p_pObject; // edx
  unsigned int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // ebx
  Scaleform::Render::PrimitiveBatch *v11; // ebx
  Scaleform::Render::MeshCache *pCache; // ecx
  Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor> >::TableType *pTable; // ebp
  Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor> > *p_BatchCacheItemHash; // ecx
  signed int v15; // eax
  Scaleform::Render::MeshCacheItem *pMeshItem; // eax
  Scaleform::Render::MeshCacheListSet *pCacheList; // edx
  unsigned int *p_Size; // ecx
  Scaleform::Render::MeshCacheListSet *v19; // edx
  Scaleform::Render::PrimitiveBatch *v20; // edx
  Scaleform::Render::PrimitiveBatch *pConvert; // eax
  Scaleform::Render::PrimitiveBatch *pNext; // ecx
  Scaleform::Render::PrimitiveBatch *v23; // eax
  Scaleform::Render::Primitive *pPrimitive; // eax
  Scaleform::Render::RenderQueueItem::QIPrepareResult result; // eax
  Scaleform::Render::PrimitiveBatch *v26; // [esp+Ch] [ebp-14h]
  Scaleform::Render::MeshCacheItem::MeshContent v27; // [esp+10h] [ebp-10h] BYREF

  p_Batches = (Scaleform::Render::PrimitiveBatch *)&this->pPrimitive->Batches;
  v26 = p_Batches;
  if ( this->pPrepare == p_Batches )
    return 0;
  while ( this->pPrepare == this->pPrepareTail )
  {
LABEL_21:
    if ( this->Converting )
      goto LABEL_31;
    if ( this->pConvert != p_Batches )
    {
      do
      {
        pConvert = this->pConvert;
        if ( pConvert->Type == DP_Virtual )
          break;
        this->pPrepareTail = pConvert;
        pNext = pConvert->pNext;
        this->pConvert = pNext;
      }
      while ( pNext != p_Batches );
    }
    v23 = this->pConvert;
    if ( v23 != p_Batches )
    {
      pPrimitive = v23->pPrimitive;
      if ( pPrimitive->ModifyIndex < pPrimitive->Meshes.Data.Size )
        Scaleform::Render::Primitive::updateMeshIndicies_Impl(pPrimitive);
      if ( !this->pConvert->MeshCount )
        goto LABEL_32;
      this->Converting = 1;
LABEL_31:
      Scaleform::Render::PrimitivePrepareBuffer::batchConvertStep(this);
      goto LABEL_32;
    }
    this->pPrepareTail = v23;
LABEL_32:
    if ( this->pPrepare == p_Batches )
      return 0;
  }
  while ( 1 )
  {
    pPrepare = this->pPrepare;
    if ( pPrepare->MeshNode.pMeshItem )
      goto LABEL_18;
    v5 = pPrepare->pPrimitive;
    if ( v5->ModifyIndex < v5->Meshes.Data.Size )
      Scaleform::Render::Primitive::updateMeshIndicies_Impl(v5);
    MeshCount = 1;
    if ( pPrepare->Type != DP_Instanced )
      MeshCount = pPrepare->MeshCount;
    p_pObject = &pPrepare->pPrimitive->Meshes.Data.Data[pPrepare->MeshIndex].pMesh.pObject;
    v8 = 0;
    v9 = 0;
    v27.Meshes.pData = p_pObject;
    v27.Meshes.Size = MeshCount;
    for ( v27.Meshes.StrideSize = 8; v9 < MeshCount; v8 ^= v10 )
      v10 = (unsigned int)p_pObject[2 * v9++] >> 5;
    v11 = this->pPrepare;
    v27.HashKey = v8;
    if ( v11->Type == DP_Failed )
      goto LABEL_17;
    if ( this->State )
      goto LABEL_16;
    pCache = this->pCache;
    pTable = pCache->BatchCacheItemHash.pTable;
    p_BatchCacheItemHash = &pCache->BatchCacheItemHash;
    if ( !pTable )
      break;
    v15 = Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor>>::findIndexCore<Scaleform::Render::MeshCacheItem::MeshContent>(
            p_BatchCacheItemHash,
            &v27,
            v8 & pTable->SizeMask);
    if ( v15 < 0 )
      break;
    Scaleform::Render::MeshCacheItemUseNode::SetMeshItem(
      &v11->MeshNode,
      *((Scaleform::Render::MeshCacheItem **)&pTable[2].EntryCount + 3 * v15));
    p_Batches = v26;
LABEL_17:
    this->State = PS_Loop;
    LOBYTE(waitForCache) = 0;
LABEL_18:
    pMeshItem = this->pPrepare->MeshNode.pMeshItem;
    if ( pMeshItem )
    {
      pCacheList = pMeshItem->pCacheList;
      pMeshItem->pPrev->pNext = pMeshItem->pNext;
      pMeshItem->pNext->Scaleform::ListNode<Scaleform::Render::MeshCacheItem>::$91FE2188799D963DDDCE23AE0AD4A8E3::pPrev = pMeshItem->pPrev;
      p_Size = &pCacheList->Slots[pMeshItem->ListType].Size;
      *p_Size -= pMeshItem->AllocSize;
      v19 = pMeshItem->pCacheList;
      pMeshItem->ListType = MCL_InFlight;
      pMeshItem->pNext = v19->Slots[1].Root.pNext;
      pMeshItem->pPrev = (Scaleform::Render::MeshCacheItem *)&v19->Slots[1];
      v19->Slots[1].Root.pNext->pPrev = pMeshItem;
      v19->Slots[1].Root.pNext = pMeshItem;
      v19->Slots[1].Size += pMeshItem->AllocSize;
    }
    v20 = this->pPrepare->pNext;
    this->pPrepare = v20;
    if ( v20 == this->pPrepareTail )
      goto LABEL_21;
  }
  p_Batches = v26;
LABEL_16:
  if ( this->pCache->PreparePrimitive(this->pCache, v11, &v27, waitForCache) )
    goto LABEL_17;
  result = QIP_NeedCache;
  this->State = PS_NeedCache;
  return result;
}
