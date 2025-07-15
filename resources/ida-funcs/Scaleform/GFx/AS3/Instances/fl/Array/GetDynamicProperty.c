void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::GetDynamicProperty(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Value *value)
{
  const Scaleform::GFx::AS3::Value *v3; // eax

  v3 = Scaleform::GFx::AS3::Impl::SparseArray::At(&this->SA, ind.Index);
  Scaleform::GFx::AS3::Value::Assign(value, v3);
}
