void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3slice(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Slice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(
    &this->V,
    result,
    argc,
    argv,
    this);
}
