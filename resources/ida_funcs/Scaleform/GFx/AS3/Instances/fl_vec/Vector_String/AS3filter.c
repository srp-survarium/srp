void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3filter(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result,
        Scaleform::GFx::AS3::Value *checker,
        Scaleform::GFx::AS3::Value *thisObj)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Filter<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(
    &this->V,
    result,
    checker,
    thisObj,
    this);
}
