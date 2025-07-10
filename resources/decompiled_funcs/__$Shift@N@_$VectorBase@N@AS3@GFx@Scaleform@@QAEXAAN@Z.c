void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Shift<double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        long double *result)
{
  long double v3; // st7
  Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // esi
  unsigned int Size; // ecx
  Scaleform::GFx::AS3::CheckResult v6; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v6)->Result && this->ValueA.Data.Size )
  {
    v3 = *this->ValueA.Data.Data;
    p_ValueA = &this->ValueA;
    *result = v3;
    Size = p_ValueA->Data.Size;
    if ( Size == 1 )
    {
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::Clear(p_ValueA);
    }
    else
    {
      memmove((unsigned __int8 *)p_ValueA->Data.Data, (unsigned __int8 *)p_ValueA->Data.Data + 8, 8 * Size - 8);
      --p_ValueA->Data.Size;
    }
  }
}
