void __thiscall Scaleform::Render::ComplexMesh::~ComplexMesh(Scaleform::Render::ComplexMesh *this)
{
  bool v2; // zf
  Scaleform::Render::MeshCacheItem *pCacheMeshItem; // ecx
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::MeshProvider *v5; // ecx

  v2 = this->UpdateListNode.pPrev == 0;
  this->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,70>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,70>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ComplexMesh_vtbl *)&Scaleform::Render::ComplexMesh::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,70>'};
  this->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::__vftable = (Scaleform::Render::MeshStagingNode_vtbl *)&Scaleform::Render::ComplexMesh::`vftable'{for `Scaleform::Render::MeshStagingNode'};
  if ( !v2 )
  {
    this->UpdateListNode.pPrev->pNext = this->UpdateListNode.pNext;
    this->UpdateListNode.pNext->pPrev = this->UpdateListNode.pPrev;
  }
  pCacheMeshItem = this->pCacheMeshItem;
  if ( pCacheMeshItem )
    Scaleform::Render::MeshCacheItem::NotifyMeshRelease(pCacheMeshItem, this);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>(&this->GradientImages.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->FillMatrixCache.Data.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy>(&this->FillRecords.Data);
  pObject = (Scaleform::RefCountVImpl *)this->pScale9Grid.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v5 = this->pProvider.pObject;
  if ( v5 )
    v5->Release(v5);
  this->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::__vftable = (Scaleform::Render::MeshStagingNode_vtbl *)&Scaleform::Render::MeshStagingNode::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
