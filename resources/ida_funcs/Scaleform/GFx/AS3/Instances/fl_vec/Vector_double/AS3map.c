void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::AS3map(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *result,
        Scaleform::GFx::AS3::Value *mapper,
        Scaleform::GFx::AS3::Value *thisObj)
{
  Scaleform::GFx::AS3::VectorBase<double>::Map<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
    &this->V,
    result,
    mapper,
    thisObj,
    this);
}
