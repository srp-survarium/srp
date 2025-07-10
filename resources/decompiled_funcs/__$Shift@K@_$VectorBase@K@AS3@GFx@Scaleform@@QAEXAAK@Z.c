void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Shift<unsigned long>(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int *result)
{
  unsigned int v3; // edx
  Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // esi
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
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::Clear(p_ValueA);
    }
    else
    {
      memmove((unsigned __int8 *)p_ValueA->Data.Data, (unsigned __int8 *)p_ValueA->Data.Data + 4, 4 * Size - 4);
      --p_ValueA->Data.Size;
    }
  }
}
