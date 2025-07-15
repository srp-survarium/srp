void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::AS3splice(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VectorBase<unsigned long>::Splice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
    &this->V,
    result,
    argc,
    argv,
    this);
}
