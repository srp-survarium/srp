Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VectorBase<double>::RemoveAt(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind)
{
  Scaleform::GFx::AS3::CheckResult *v3; // eax
  unsigned int Size; // eax
  Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // esi

  if ( ind < this->ValueA.Data.Size )
  {
    Size = this->ValueA.Data.Size;
    p_ValueA = &this->ValueA;
    if ( Size == 1 )
    {
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::Clear(&this->ValueA);
      v3 = result;
    }
    else
    {
      memmove(
        (unsigned __int8 *)&p_ValueA->Data.Data[ind],
        (unsigned __int8 *)&p_ValueA->Data.Data[ind + 1],
        8 * (Size - ind) - 8);
      v3 = result;
      --p_ValueA->Data.Size;
    }
    result->Result = 1;
  }
  else
  {
    v3 = result;
    result->Result = 0;
  }
  return v3;
}
