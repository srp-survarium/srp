void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::AS3filter(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *result,
        Scaleform::GFx::AS3::Value *checker,
        Scaleform::GFx::AS3::Value *thisObj)
{
  Scaleform::GFx::AS3::VectorBase<double>::Filter<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
    &this->V,
    result,
    checker,
    thisObj,
    this);
}
