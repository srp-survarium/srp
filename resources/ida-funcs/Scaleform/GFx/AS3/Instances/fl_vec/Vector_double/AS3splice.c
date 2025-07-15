void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::AS3splice(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VectorBase<double>::Splice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
    &this->V,
    result,
    argc,
    argv,
    this);
}
