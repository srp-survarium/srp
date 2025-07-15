Scaleform::GFx::AS2::ActionBuffer *__thiscall Scaleform::GFx::AS2::ActionBuffer::`scalar deleting destructor'(
        Scaleform::GFx::AS2::ActionBuffer *this,
        char a2)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::GFx::AS2::ActionBuffer_vtbl *)&Scaleform::GFx::AS2::ActionBuffer::`vftable';
  pNode = this->Dictionary.Data.DefaultValue.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>(&this->Dictionary.Data);
  pObject = (Scaleform::RefCountVImpl *)this->pBufferData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
