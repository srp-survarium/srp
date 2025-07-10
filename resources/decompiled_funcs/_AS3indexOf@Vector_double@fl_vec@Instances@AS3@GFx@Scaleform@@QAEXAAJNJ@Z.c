void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::AS3indexOf(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this,
        int *result,
        long double value,
        int from)
{
  Scaleform::GFx::AS3::VectorBase<double>::IndexOf(&this->V, result, &value, from);
}
