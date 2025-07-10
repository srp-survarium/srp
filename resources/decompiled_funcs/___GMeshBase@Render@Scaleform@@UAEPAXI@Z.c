Scaleform::Render::MeshBase *__thiscall Scaleform::Render::MeshBase::`scalar deleting destructor'(
        Scaleform::Render::MeshBase *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::MeshProvider *v4; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pScale9Grid.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = this->pProvider.pObject;
  if ( v4 )
    v4->Release(v4);
  this->Scaleform::Render::MeshStagingNode::__vftable = (Scaleform::Render::MeshStagingNode_vtbl *)&Scaleform::Render::MeshStagingNode::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
