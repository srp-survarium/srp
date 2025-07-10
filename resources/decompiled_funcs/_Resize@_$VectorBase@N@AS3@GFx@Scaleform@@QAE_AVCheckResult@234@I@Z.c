Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VectorBase<double>::Resize(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int newSise)
{
  unsigned int Size; // esi
  Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  Scaleform::GFx::AS3::CheckResult v7; // [esp+13h] [ebp-5h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v7)->Result )
  {
    Size = this->ValueA.Data.Size;
    p_ValueA = &this->ValueA;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      p_ValueA,
      newSise);
    if ( Size < newSise )
    {
      if ( (int)(newSise - Size) >= 4 )
      {
        do
        {
          p_ValueA->Data.Data[Size] = 0.0;
          p_ValueA->Data.Data[Size + 1] = 0.0;
          p_ValueA->Data.Data[Size + 2] = 0.0;
          p_ValueA->Data.Data[Size + 3] = 0.0;
          Size += 4;
        }
        while ( Size < newSise - 3 );
      }
      for ( ; Size < newSise; ++Size )
        p_ValueA->Data.Data[Size] = 0.0;
    }
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
