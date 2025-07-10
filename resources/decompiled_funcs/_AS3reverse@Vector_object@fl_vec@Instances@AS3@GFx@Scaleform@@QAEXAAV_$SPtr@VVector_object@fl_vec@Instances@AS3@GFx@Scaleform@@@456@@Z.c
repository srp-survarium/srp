void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::AS3reverse(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *result)
{
  Scaleform::Alg::ReverseArray<Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy>>(&this->V.ValueA);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(result, this);
}
