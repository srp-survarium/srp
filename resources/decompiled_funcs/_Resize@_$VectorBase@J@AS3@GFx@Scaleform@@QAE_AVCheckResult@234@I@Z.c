Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VectorBase<long>::Resize(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int newSise)
{
  unsigned int Size; // esi
  Scaleform::ArrayDH<long,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  Scaleform::GFx::AS3::CheckResult v7; // [esp+Bh] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v7)->Result )
  {
    Size = this->ValueA.Data.Size;
    p_ValueA = &this->ValueA;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      p_ValueA,
      newSise);
    for ( ; Size < newSise; ++Size )
      p_ValueA->Data.Data[Size] = 0;
    v6 = result;
    result->Result = 1;
  }
  else
  {
    v6 = result;
    result->Result = 0;
  }
  return v6;
}
