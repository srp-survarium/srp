void __thiscall Scaleform::GFx::DisplayObjContainer::DisplayObjContainer(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::MovieDefImpl *pbindingDefImpl,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *pparent,
        Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::InteractiveObject::InteractiveObject(this, pbindingDefImpl, pasRoot, pparent, id);
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::DisplayObjContainer_vtbl *)&Scaleform::GFx::DisplayObjContainer::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::DisplayObjContainer::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  Scaleform::GFx::DisplayList::DisplayList(&this->mDisplayList);
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x200u;
  this->pRootNode = 0;
}
