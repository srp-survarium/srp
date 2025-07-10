void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3concat(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Concat<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(
    &this->V,
    result,
    argc,
    argv,
    this);
}
