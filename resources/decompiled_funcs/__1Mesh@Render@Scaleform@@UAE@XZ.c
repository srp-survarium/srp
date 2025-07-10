void __thiscall Scaleform::Render::Mesh::~Mesh(Scaleform::Render::Mesh *this)
{
  unsigned int Size; // ebx
  Scaleform::Render::MeshCacheItem **pData; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::MeshProvider *v5; // ecx

  Size = this->CacheItems.Size;
  this->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,70>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,70>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::Mesh_vtbl *)&Scaleform::Render::Mesh::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,70>'};
  this->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::__vftable = (Scaleform::Render::MeshStagingNode_vtbl *)&Scaleform::Render::Mesh::`vftable'{for `Scaleform::Render::MeshStagingNode'};
  if ( Size <= 2 )
    pData = (Scaleform::Render::MeshCacheItem **)&this->CacheItems.4;
  else
    pData = this->CacheItems.AD.pData;
  for ( ; Size; ++pData )
  {
    --Size;
    if ( *pData )
      Scaleform::Render::MeshCacheItem::NotifyMeshRelease(*pData, this);
  }
  if ( this->StagingBufferSize )
  {
    this->pPrev->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::pNext = this->pNext;
    this->pNext->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::pPrev = this->pPrev;
  }
  if ( this->CacheItems.Size > 2 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->CacheItems.AD.pData);
  pObject = (Scaleform::RefCountVImpl *)this->pScale9Grid.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v5 = this->pProvider.pObject;
  if ( v5 )
    v5->Release(v5);
  this->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::__vftable = (Scaleform::Render::MeshStagingNode_vtbl *)&Scaleform::Render::MeshStagingNode::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
