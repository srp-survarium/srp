void __thiscall Scaleform::GFx::AS2::GenericDisplayObj::GenericDisplayObj(
        Scaleform::GFx::AS2::GenericDisplayObj *this,
        Scaleform::GFx::ShapeBaseCharacterDef *pdef,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *pparent,
        Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::DisplayObjectBase::DisplayObjectBase(this, pasRoot, pparent, id);
  this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::AS2::GenericDisplayObj_vtbl *)&Scaleform::GFx::AS2::GenericDisplayObj::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::AS2::GenericDisplayObj::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( pdef )
    Scaleform::RefCountImpl::AddRef(pdef);
  this->pDef.pObject = pdef;
}
