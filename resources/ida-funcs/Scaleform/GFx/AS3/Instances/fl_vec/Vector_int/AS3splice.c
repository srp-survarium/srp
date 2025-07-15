void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::AS3splice(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VectorBase<long>::Splice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>(
    &this->V,
    result,
    argc,
    argv,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)this);
}
