void __thiscall Scaleform::Render::TreeCacheMeshBase::~TreeCacheMeshBase(Scaleform::Render::TreeCacheMeshBase *this)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::Bundle *v4; // edi
  Scaleform::Render::Bundle *v5; // ecx

  this->__vftable = (Scaleform::Render::TreeCacheMeshBase_vtbl *)&Scaleform::Render::TreeCacheMeshBase::`vftable';
  pHandle = this->M.pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(pHandle->pHeader);
  if ( this->SorterShapeNode.pBundle.pObject )
  {
    pObject = this->SorterShapeNode.pBundle.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v4 = this->SorterShapeNode.pBundle.pObject;
    Scaleform::Render::Bundle::RemoveEntry(v4, &this->SorterShapeNode);
    if ( v4 )
      Scaleform::RefCountNTSImpl::Release(v4);
  }
  v5 = this->SorterShapeNode.pBundle.pObject;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  this->SorterShapeNode.Key.pImpl->Release(this->SorterShapeNode.Key.pImpl, this->SorterShapeNode.Key.Data);
  Scaleform::Render::TreeCacheNode::~TreeCacheNode(this);
}
