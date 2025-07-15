void __thiscall Scaleform::GFx::AS3::Stage::Stage(
        Scaleform::GFx::AS3::Stage *this,
        Scaleform::GFx::MovieDefImpl *pbindingDefImpl,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *pparent,
        Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax

  Scaleform::GFx::DisplayObjContainer::DisplayObjContainer(this, pbindingDefImpl, pasRoot, pparent, id);
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::AS3::Stage_vtbl *)&Scaleform::GFx::AS3::Stage::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::AS3::Stage::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  this->pRoot.pObject = 0;
  this->FrameCounterObj.pObject = 0;
  p_EmptyStringNode = &Scaleform::GFx::InteractiveObject::GetStringManager(this)->EmptyStringNode;
  this->CurrentStageOrientation.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Flags |= 1u;
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x2000u;
  this->MouseCursorEventCnt = 0;
}
