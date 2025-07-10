void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3shift(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // esi
  const Scaleform::GFx::AS3::Value *v3; // eax

  p_SA = &this->SA;
  if ( this->SA.Length )
  {
    v3 = Scaleform::GFx::AS3::Impl::SparseArray::At(&this->SA, 0);
    Scaleform::GFx::AS3::Value::Assign(result, v3);
    if ( p_SA->Length )
    {
      if ( p_SA->ValueA.Data.Size )
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          &p_SA->ValueA,
          0);
      Scaleform::GFx::AS3::Impl::SparseArray::CutHash(p_SA, 0, 1u, 0);
      Scaleform::GFx::AS3::Impl::SparseArray::Optimize(p_SA);
      --p_SA->Length;
    }
  }
  else
  {
    if ( (result->Flags & 0x1F) > 9 )
    {
      if ( (result->Flags & 0x200) != 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
        result->Flags &= 0xFFFFFFE0;
        return;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
    }
    result->Flags &= 0xFFFFFFE0;
  }
}
