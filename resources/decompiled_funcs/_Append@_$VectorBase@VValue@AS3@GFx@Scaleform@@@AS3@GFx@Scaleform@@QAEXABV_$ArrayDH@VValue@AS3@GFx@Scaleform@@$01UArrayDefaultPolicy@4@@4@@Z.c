void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Append(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *arr)
{
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v3; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebx
  Scaleform::GFx::AS3::Value *Data; // edi
  unsigned int Size; // eax
  Scaleform::GFx::AS3::Value *v7; // edi
  Scaleform::Pair<double,unsigned long> *v8; // ebp
  unsigned int v9; // esi
  Scaleform::Pair<double,unsigned long> *v10; // ecx
  unsigned int *v11; // esi
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-9h] BYREF
  unsigned int v13; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v3 = arr;
    i = 0;
    if ( arr->Data.Size )
    {
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
      v13 = 0;
      do
      {
        Data = v3->Data.Data;
        Size = p_ValueA->Size;
        v7 = &Data[v13 / 0x10];
        v8 = p_ValueA[1].Data;
        v9 = Size + 1;
        if ( Size + 1 >= Size )
        {
          if ( v9 >= p_ValueA->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              v8,
              v9 + (v9 >> 2));
        }
        else
        {
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
            (Scaleform::GFx::AS3::Value *)&p_ValueA->Data[Size + 1],
            0xFFFFFFFF);
          if ( v9 < p_ValueA->Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              v8,
              v9);
        }
        v10 = p_ValueA->Data;
        p_ValueA->Size = v9;
        v11 = (unsigned int *)&v10[v9 - 1];
        if ( v11 )
        {
          *v11 = v7->Flags;
          v11[1] = (unsigned int)v7->Bonus.pWeakProxy;
          v11[2] = v7->value.VS._1.VUInt;
          v11[3] = (unsigned int)v7->value.VS._2.VObj;
          if ( (v7->Flags & 0x1F) > 9 )
          {
            if ( (v7->Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::AddRefWeakRef(v7);
            else
              Scaleform::GFx::AS3::Value::AddRefInternal(v7);
          }
        }
        v3 = arr;
        v13 += 16;
        ++i;
      }
      while ( i < arr->Data.Size );
    }
  }
}
