void __thiscall Scaleform::GFx::AS3::VectorBase<double>::PushBackUnsafe(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        const Scaleform::GFx::AS3::Value *v)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v4; // esi
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *Data; // eax
  double *v6; // eax
  double VNumber; // [esp+4h] [ebp-8h]

  pHeap = this->ValueA.Data.pHeap;
  VNumber = v->value.VNumber;
  p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
  v4 = this->ValueA.Data.Size + 1;
  if ( v4 >= this->ValueA.Data.Size )
  {
    if ( v4 >= this->ValueA.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_ValueA,
        pHeap,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->ValueA.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_ValueA,
      pHeap,
      v4);
  }
  Data = p_ValueA->Data;
  p_ValueA->Size = v4;
  v6 = (double *)&Data[v4 - 1];
  if ( v6 )
    *v6 = VNumber;
}
