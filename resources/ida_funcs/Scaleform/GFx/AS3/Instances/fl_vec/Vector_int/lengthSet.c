void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::lengthSet(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int value)
{
  Scaleform::GFx::AS3::VectorBase<long>::Resize(
    (Scaleform::GFx::AS3::VectorBase<long> *)&this->V,
    (Scaleform::GFx::AS3::CheckResult *)&value,
    value);
}
