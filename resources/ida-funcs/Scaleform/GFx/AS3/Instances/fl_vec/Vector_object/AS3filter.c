void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::AS3filter(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *result,
        Scaleform::GFx::AS3::Value *checker,
        Scaleform::GFx::AS3::Value *thisObj)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Filter<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>(
    &this->V,
    result,
    checker,
    thisObj,
    this);
}
