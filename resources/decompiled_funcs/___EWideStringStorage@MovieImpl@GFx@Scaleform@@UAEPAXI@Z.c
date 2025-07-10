Scaleform::GFx::MovieImpl::WideStringStorage *__thiscall Scaleform::GFx::MovieImpl::WideStringStorage::`vector deleting destructor'(
        Scaleform::GFx::MovieImpl::WideStringStorage *this,
        char a2)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx

  pNode = this->pNode;
  this->__vftable = (Scaleform::GFx::MovieImpl::WideStringStorage_vtbl *)&Scaleform::GFx::MovieImpl::WideStringStorage::`vftable';
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
