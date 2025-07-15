void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::blendModeSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::DisplayObject *pObject; // esi
  Scaleform::GFx::DisplayObject_vtbl *v4; // edi
  int BlendMode; // eax

  pObject = this->pDispObj.pObject;
  v4 = pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
  BlendMode = Scaleform::GFx::AS3::Classes::fl_display::BlendMode::GetBlendMode(value);
  v4->SetBlendMode(pObject, (Scaleform::Render::BlendMode)BlendMode);
}
