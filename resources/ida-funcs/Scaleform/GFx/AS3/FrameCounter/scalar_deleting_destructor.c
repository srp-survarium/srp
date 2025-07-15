Scaleform::GFx::AS3::FrameCounter *__thiscall Scaleform::GFx::AS3::FrameCounter::`scalar deleting destructor'(
        Scaleform::GFx::AS3::FrameCounter *this,
        char a2)
{
  Scaleform::GFx::DisplayObjContainer *pObject; // ecx

  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::AS3::FrameCounter_vtbl *)&Scaleform::GFx::AS3::FrameCounter::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::AS3::FrameCounter::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  pObject = this->pRoot.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  Scaleform::GFx::InteractiveObject::~InteractiveObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
