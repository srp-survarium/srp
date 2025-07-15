void __thiscall Scaleform::GFx::InteractiveObject::InteractiveObject(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::MovieDefImpl *pbindingDefImpl,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *pparent,
        Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::DisplayObject::DisplayObject(this, pasRoot, pparent, id);
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::InteractiveObject_vtbl *)&Scaleform::GFx::InteractiveObject::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::InteractiveObject::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( pbindingDefImpl )
    Scaleform::RefCountImpl::AddRef(pbindingDefImpl);
  this->pDefImpl.pObject = pbindingDefImpl;
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x80u;
  this->RollOverCnt = 0;
  this->pDisplayCallback = 0;
  this->DisplayCallbackUserPtr = 0;
  this->pPlayPrev = 0;
  this->pPlayNext = 0;
  this->pPlayPrevOpt = 0;
  this->pPlayNextOpt = 0;
  this->TabIndex = 0;
  this->FocusGroupMask = 0;
  this->Flags = 16;
}
