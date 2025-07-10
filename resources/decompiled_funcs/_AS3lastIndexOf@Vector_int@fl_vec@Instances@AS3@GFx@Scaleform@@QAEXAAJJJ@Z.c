void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::AS3lastIndexOf(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        int *result,
        unsigned int value,
        int from)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::LastIndexOf(
    &this->V,
    result,
    &value,
    from);
}
