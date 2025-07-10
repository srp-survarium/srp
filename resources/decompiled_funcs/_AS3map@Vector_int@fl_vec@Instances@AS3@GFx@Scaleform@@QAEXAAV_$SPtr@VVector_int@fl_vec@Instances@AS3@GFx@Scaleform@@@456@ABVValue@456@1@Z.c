void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::AS3map(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *result,
        Scaleform::GFx::AS3::Value *mapper,
        Scaleform::GFx::AS3::Value *thisObj)
{
  Scaleform::GFx::AS3::VectorBase<long>::Map<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>(
    &this->V,
    result,
    mapper,
    thisObj,
    this);
}
