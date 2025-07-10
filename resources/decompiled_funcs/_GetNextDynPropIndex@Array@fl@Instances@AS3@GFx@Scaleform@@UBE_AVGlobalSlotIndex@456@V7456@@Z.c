Scaleform::GFx::AS3::GlobalSlotIndex *__thiscall Scaleform::GFx::AS3::Instances::fl::Array::GetNextDynPropIndex(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::GlobalSlotIndex *result,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  unsigned int Index; // eax
  Scaleform::GFx::AS3::GlobalSlotIndex *v5; // edi
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // esi
  unsigned int v8; // eax

  Index = ind.Index;
  v5 = result;
  p_SA = &this->SA;
  result->Index = 0;
  if ( Index <= this->SA.Length )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::GetNextArrayIndex(
      &this->SA,
      (Scaleform::GFx::AS3::AbsoluteIndex *)&result,
      (Scaleform::GFx::AS3::AbsoluteIndex)(Index - 1));
    if ( (int)result >= 0 )
    {
      v5->Index = (unsigned int)&result->Index + 1;
      return v5;
    }
    Index = ind.Index;
  }
  if ( Index >= p_SA->Length )
    Index -= p_SA->Length;
  v8 = Scaleform::GFx::AS3::Object::GetNextDynPropIndex(
         this,
         (Scaleform::GFx::AS3::GlobalSlotIndex *)&result,
         (Scaleform::GFx::AS3::GlobalSlotIndex)Index)->Index;
  v5->Index = v8;
  if ( v8 )
    v5->Index = v8 + p_SA->Length;
  return v5;
}
