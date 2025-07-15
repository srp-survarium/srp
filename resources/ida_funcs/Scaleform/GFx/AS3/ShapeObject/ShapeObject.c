void __thiscall Scaleform::GFx::AS3::ShapeObject::ShapeObject(
        Scaleform::GFx::AS3::ShapeObject *this,
        Scaleform::GFx::ShapeBaseCharacterDef *pdef,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *pparent,
        Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::DisplayObject::DisplayObject(this, pasRoot, pparent, id);
  Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(&this->Scaleform::GFx::AS3::AvmDisplayObj, this);
  this->Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS3::AvmDisplayObj_vtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable';
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::AS3::ShapeObject_vtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( pdef )
    Scaleform::RefCountImpl::AddRef(pdef);
  this->pDef.pObject = pdef;
  this->pDrawing.pObject = 0;
}
