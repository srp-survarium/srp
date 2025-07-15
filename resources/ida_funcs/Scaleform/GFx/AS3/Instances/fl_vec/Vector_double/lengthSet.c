void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::lengthSet(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int value)
{
  Scaleform::GFx::AS3::VectorBase<double>::Resize(&this->V, (Scaleform::GFx::AS3::CheckResult *)&value, value);
}
