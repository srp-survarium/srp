void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::GetDynamicProperty(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Value *value)
{
  this->V.GetValue(&this->V, ind.Index, value);
}
