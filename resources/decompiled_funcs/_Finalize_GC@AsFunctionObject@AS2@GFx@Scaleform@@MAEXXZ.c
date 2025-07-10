void __thiscall Scaleform::GFx::AS2::AsFunctionObject::Finalize_GC(Scaleform::GFx::AS2::AsFunctionObject *this)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS2::ActionBuffer *pObject; // ecx
  Scaleform::GFx::CharacterHandle *v5; // edi

  pNode = this->Args.Data.DefaultValue.Name.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>(&this->Args.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->WithStack.Data.Data);
  pObject = this->pActionBuffer.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pActionBuffer.pObject = 0;
  v5 = this->TargetHandle.pObject;
  if ( v5 )
  {
    if ( --v5->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(v5);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
    }
  }
  this->TargetHandle.pObject = 0;
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
