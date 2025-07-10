void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::lengthSet(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int value)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Resize(
    &this->V,
    (Scaleform::GFx::AS3::CheckResult *)&value,
    value);
}
