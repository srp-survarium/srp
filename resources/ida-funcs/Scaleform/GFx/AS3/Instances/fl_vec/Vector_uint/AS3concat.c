void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::AS3concat(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::VectorBase<unsigned long>::Concat<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
    &this->V,
    result,
    argc,
    argv,
    this);
}
