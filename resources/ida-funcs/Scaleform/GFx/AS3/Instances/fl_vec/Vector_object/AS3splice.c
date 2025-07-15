void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::AS3splice(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Splice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>(
    &this->V,
    result,
    argc,
    argv,
    this);
}
