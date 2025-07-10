void __thiscall Scaleform::GFx::DisplayObject::DisplayObject(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *pparent,
        Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::DisplayObjectBase::DisplayObjectBase(this, pasRoot, pparent, id);
  this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::DisplayObject_vtbl *)&Scaleform::GFx::DisplayObject::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::DisplayObject::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  this->pNameHandle.pObject = 0;
  this->pScrollRect = 0;
  this->pMaskCharacter = 0;
  this->Scaleform::GFx::DisplayObjectBase::Flags |= 0x100u;
  this->Flags = 10;
}
