Scaleform::GFx::AS3::Stage *__thiscall Scaleform::GFx::AS3::Stage::`vector deleting destructor'(
        Scaleform::GFx::AS3::Stage *this,
        char a2)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::InteractiveObject *pObject; // ecx
  Scaleform::GFx::DisplayObjContainer *v6; // ecx

  pNode = this->CurrentStageOrientation.pNode;
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::AS3::Stage_vtbl *)&Scaleform::GFx::AS3::Stage::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::AS3::Stage::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  pObject = this->FrameCounterObj.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v6 = this->pRoot.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  Scaleform::GFx::DisplayObjContainer::~DisplayObjContainer(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


void *__thiscall Scaleform::GFx::AS3::Stage::`vector deleting destructor'(char *this, unsigned int a2)
{
  return Scaleform::GFx::AS3::Stage::`vector deleting destructor'((Scaleform::GFx::AS3::Stage *)(this - 12), a2);
}
