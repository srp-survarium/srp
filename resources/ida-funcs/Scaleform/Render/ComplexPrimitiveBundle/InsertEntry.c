void __thiscall Scaleform::Render::ComplexPrimitiveBundle::InsertEntry(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        unsigned int index,
        Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::TreeCacheNode *pSourceNode; // esi
  Scaleform::GFx::Resource *v5; // eax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pRenderer2D; // esi
  Scaleform::Render::ComplexMesh *v7; // ebx
  Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry e; // [esp+10h] [ebp-8h] BYREF

  Scaleform::Render::Bundle::InsertEntry(this, index, entry);
  pSourceNode = entry->pSourceNode;
  v5 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::Render::TreeCacheNode *))pSourceNode->__vftable[1].HandleChanges)(pSourceNode);
  pRenderer2D = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)pSourceNode[1].pRenderer2D;
  v7 = (Scaleform::Render::ComplexMesh *)v5;
  e.M.pHandle = pRenderer2D;
  if ( pRenderer2D != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pRenderer2D->pHeader->RefCount;
  if ( v5 )
    Scaleform::RefCountImpl::AddRef(v5);
  e.pMesh.pObject = v7;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    &this->Instances,
    index,
    &e);
  if ( e.pMesh.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)e.pMesh.pObject);
  if ( e.M.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(e.M.pHandle->pHeader);
}
