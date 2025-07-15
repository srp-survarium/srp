void __thiscall Scaleform::GFx::AS3::Instances::fl_display::SimpleButton::overStateSet(
        Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *value)
{
  Scaleform::GFx::DisplayObject *pObject; // eax

  pObject = this->pDispObj.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::AvmButton::SetOverStateObject(
      (Scaleform::GFx::AS3::AvmButton *)(&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                       + pObject->AvmObjOffset),
      value->pDispObj.pObject);
  else
    Scaleform::GFx::AS3::AvmButton::SetOverStateObject(0, value->pDispObj.pObject);
}
