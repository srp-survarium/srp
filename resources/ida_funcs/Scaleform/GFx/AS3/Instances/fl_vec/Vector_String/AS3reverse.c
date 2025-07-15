void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3reverse(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *result)
{
  Scaleform::Alg::ReverseArray<Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy>>(&this->V.ValueA);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    result,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
}
