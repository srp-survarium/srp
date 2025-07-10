void __thiscall Scaleform::GFx::AS3::Traits::StoreScopeStack(
        Scaleform::GFx::AS3::Traits *this,
        unsigned int baseSSInd,
        const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  unsigned int Size; // esi
  unsigned int v4; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_InitScope; // ebx
  unsigned int v6; // ecx
  unsigned int v7; // esi
  unsigned int v8; // eax
  Scaleform::Pair<double,unsigned long> *Data; // ebp
  unsigned int v10; // esi
  Scaleform::GFx::AS3::Value *v11; // edi
  Scaleform::Pair<double,unsigned long> *v12; // eax
  unsigned int *v13; // esi
  bool v14; // zf
  unsigned int v15; // [esp+8h] [ebp-4h]
  unsigned int baseSSInda; // [esp+10h] [ebp+4h]

  Size = ss->Data.Size;
  v4 = Size + this->InitScope.Data.Size;
  p_InitScope = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->InitScope;
  if ( v4 > this->InitScope.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_InitScope,
      this->InitScope.Data.pHeap,
      v4);
  if ( baseSSInd < Size )
  {
    v6 = 16 * baseSSInd;
    v7 = Size - baseSSInd;
    baseSSInda = 16 * baseSSInd;
    v15 = v7;
    do
    {
      v8 = p_InitScope->Size;
      Data = p_InitScope[1].Data;
      v10 = v8 + 1;
      v11 = (Scaleform::GFx::AS3::Value *)((char *)ss->Data.Data + v6);
      if ( v8 + 1 >= v8 )
      {
        if ( v10 >= p_InitScope->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_InitScope,
            Data,
            v10 + (v10 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
          (Scaleform::GFx::AS3::Value *)&p_InitScope->Data[v8 + 1],
          0xFFFFFFFF);
        if ( v10 < p_InitScope->Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_InitScope,
            Data,
            v10);
      }
      v12 = p_InitScope->Data;
      p_InitScope->Size = v10;
      v13 = (unsigned int *)&v12[v10 - 1];
      if ( v13 )
      {
        *v13 = v11->Flags;
        v13[1] = (unsigned int)v11->Bonus.pWeakProxy;
        v13[2] = v11->value.VS._1.VUInt;
        v13[3] = (unsigned int)v11->value.VS._2.VObj;
        if ( (v11->Flags & 0x1F) > 9 )
        {
          if ( (v11->Flags & 0x200) != 0 )
            ++v11->Bonus.pWeakProxy->RefCount;
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(v11);
        }
      }
      v6 = baseSSInda + 16;
      v14 = v15-- == 1;
      baseSSInda += 16;
    }
    while ( !v14 );
  }
}
