void __thiscall Scaleform::GFx::AS3::AvmButton::OnEventLoad(Scaleform::GFx::AS3::AvmButton *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax

  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pAS3CollectiblePtr,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)pAS3RawPtr);
  this->pAS3RawPtr = 0;
}
