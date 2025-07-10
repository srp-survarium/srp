void __thiscall Scaleform::Render::MeshCacheItem::Destroy(
        Scaleform::Render::MeshCacheItem *this,
        Scaleform::Render::MeshBase *pskipMesh,
        bool freeMemory)
{
  Scaleform::Render::MeshCacheListSet *pCacheList; // ecx
  unsigned int *p_Size; // eax
  Scaleform::Render::MeshCacheItemUseNode *pNext; // eax
  Scaleform::List<Scaleform::Render::MeshCacheItemUseNode,Scaleform::Render::MeshCacheItemUseNode> *i; // ecx
  Scaleform::Render::MeshCacheItem::MeshType Type; // eax
  Scaleform::HashSetLH<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,2,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor> > *p_BatchCacheItemHash; // ecx
  unsigned int j; // edi
  Scaleform::Render::MeshBase **v11; // ecx
  unsigned int k; // ebx
  Scaleform::Render::MeshBase **v13; // eax
  bool v14; // zf
  Scaleform::Render::MeshBase **v15; // eax
  Scaleform::Render::MeshBase *v16; // edi
  Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Render::MeshCacheItem *,2> *v17; // ebp
  Scaleform::Render::MeshProvider *v18; // ecx
  unsigned int m; // edi
  Scaleform::Render::MeshBase **v20; // eax
  Scaleform::RefCountVImpl **v21; // eax
  Scaleform::Render::MeshBase **pMeshes; // eax
  Scaleform::Render::MeshBase *v23; // ecx
  Scaleform::Render::MeshBase *v24; // eax
  Scaleform::Render::MeshProvider *pObject; // ecx
  Scaleform::Render::Fence *v26; // ecx
  Scaleform::Render::MeshCacheItem *key; // [esp+8h] [ebp-4h] BYREF

  pCacheList = this->pCacheList;
  this->pPrev->pNext = this->pNext;
  this->pNext->Scaleform::ListNode<Scaleform::Render::MeshCacheItem>::$181941B0ECCE92AAF0AD80025FE0C204::pPrev = this->pPrev;
  p_Size = &pCacheList->Slots[this->ListType].Size;
  *p_Size -= this->AllocSize;
  if ( this->Type <= (unsigned int)Mesh_Complex )
  {
    pNext = this->PrimitiveBatches.Root.pNext;
    for ( i = &this->PrimitiveBatches; pNext != (Scaleform::Render::MeshCacheItemUseNode *)i; pNext = pNext->pNext )
      pNext->pMeshItem = 0;
    i->Root.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)i;
    this->PrimitiveBatches.Root.pNext = (Scaleform::Render::MeshCacheItemUseNode *)&this->PrimitiveBatches;
  }
  Type = this->Type;
  if ( Type )
  {
    if ( Type == Mesh_Complex )
    {
      pMeshes = this->pMeshes;
      v23 = *pMeshes;
      if ( *pMeshes != pskipMesh )
      {
        v24 = *pMeshes;
        pObject = v23->pProvider.pObject;
        v24[1].pPrev = 0;
        if ( pObject )
          pObject->OnEvict(pObject, v24);
      }
    }
  }
  else
  {
    p_BatchCacheItemHash = &this->pCacheList->pCache->BatchCacheItemHash;
    key = this;
    Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor>>::RemoveAlt<Scaleform::Render::MeshCacheItem *>(
      p_BatchCacheItemHash,
      &key);
    for ( j = 0; j < this->MeshCount; ++j )
    {
      v11 = this->pMeshes;
      if ( v11[j] != pskipMesh )
        Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v11[j]);
    }
    for ( k = 0; k < this->MeshCount; ++k )
    {
      v13 = this->pMeshes;
      v14 = v13[k] == pskipMesh;
      v15 = &v13[k];
      if ( !v14 )
      {
        v16 = *v15;
        v17 = (Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Render::MeshCacheItem *,2> *)&(*v15)[1];
        key = this;
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Render::MeshCacheItem *,2>::Remove(v17, &key);
        if ( !v17->Size && !v16->StagingBufferSize )
        {
          v18 = v16->pProvider.pObject;
          if ( v18 )
            v18->OnEvict(v18, v16);
        }
      }
    }
    for ( m = 0; m < this->MeshCount; ++m )
    {
      v20 = this->pMeshes;
      v14 = v20[m] == pskipMesh;
      v21 = (Scaleform::RefCountVImpl **)&v20[m];
      if ( !v14 )
        Scaleform::RefCountImpl::Release(*v21);
    }
  }
  this->Type = Mesh_Destroyed;
  if ( freeMemory )
  {
    v26 = this->GPUFence.pObject;
    if ( v26 )
      Scaleform::Render::Fence::Release(v26);
    this->GPUFence.pObject = 0;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  }
}
