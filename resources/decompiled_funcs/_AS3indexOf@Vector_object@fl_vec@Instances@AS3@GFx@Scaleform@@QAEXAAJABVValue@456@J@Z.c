void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::AS3indexOf(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        int *result,
        const Scaleform::GFx::AS3::Value *value,
        unsigned int from)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::IndexOf(&this->V, result, value, from);
}
