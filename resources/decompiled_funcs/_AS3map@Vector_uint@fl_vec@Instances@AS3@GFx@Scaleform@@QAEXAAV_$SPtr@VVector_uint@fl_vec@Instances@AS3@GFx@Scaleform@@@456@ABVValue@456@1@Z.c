void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::AS3map(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *result,
        Scaleform::GFx::AS3::Value *mapper,
        Scaleform::GFx::AS3::Value *thisObj)
{
  Scaleform::GFx::AS3::VectorBase<unsigned long>::Map<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
    &this->V,
    result,
    mapper,
    thisObj,
    this);
}
