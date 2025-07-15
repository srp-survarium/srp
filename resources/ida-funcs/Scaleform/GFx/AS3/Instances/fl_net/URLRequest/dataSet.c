void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLRequest::dataSet(
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::AS3::Value *value)
{
  if ( (value->Flags & 0x1F) - 12 <= 3
    && (Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, value)->Flags & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->DataObj,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)value->value.VS._1.VInt);
  }
}
