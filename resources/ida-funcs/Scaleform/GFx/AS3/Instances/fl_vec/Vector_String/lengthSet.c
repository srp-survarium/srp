void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::lengthSet(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int value)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Resize(
    &this->V,
    (Scaleform::GFx::AS3::CheckResult *)&value,
    value);
}
