void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Append(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        const Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> *arr)
{
  const Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> *v3; // eax
  unsigned int v4; // ebx
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  long double *Data; // ecx
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *v7; // eax
  unsigned int v8; // esi
  double *v9; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+13h] [ebp-5h] BYREF
  double *v11; // [esp+14h] [ebp-4h]

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v3 = arr;
    v4 = 0;
    if ( arr->Data.Size )
    {
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
      do
      {
        Data = v3->Data.Data;
        v7 = p_ValueA[1].Data;
        v8 = p_ValueA->Size + 1;
        v11 = &Data[v4];
        if ( v8 >= p_ValueA->Size )
        {
          if ( v8 >= p_ValueA->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              v7,
              v8 + (v8 >> 2));
        }
        else if ( v8 < p_ValueA->Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            v7,
            v8);
        }
        v9 = (double *)&p_ValueA->Data[v8 - 1];
        p_ValueA->Size = v8;
        if ( v9 )
          *v9 = *v11;
        v3 = arr;
        ++v4;
      }
      while ( v4 < arr->Data.Size );
    }
  }
}
