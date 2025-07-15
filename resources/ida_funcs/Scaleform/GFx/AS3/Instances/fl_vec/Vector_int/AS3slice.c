void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::AS3slice(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VectorBase<long>::Slice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>(
    &this->V,
    result,
    argc,
    argv,
    this);
}
