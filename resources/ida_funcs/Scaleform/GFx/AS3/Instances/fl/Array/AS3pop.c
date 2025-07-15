void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3pop(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // esi
  const Scaleform::GFx::AS3::Value *v3; // eax

  p_SA = &this->SA;
  if ( this->SA.Length )
  {
    v3 = Scaleform::GFx::AS3::Impl::SparseArray::At(&this->SA, p_SA->Length - 1);
    Scaleform::GFx::AS3::Value::Assign(result, v3);
    if ( p_SA->Length )
      Scaleform::GFx::AS3::Impl::SparseArray::RemoveMultipleAt(p_SA, p_SA->Length - 1, 1u, opCut);
  }
}
