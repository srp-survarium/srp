void __thiscall Scaleform::GFx::AS3::Impl::ValuePtrCollector::operator()(
        Scaleform::GFx::AS3::Impl::ValuePtrCollector *this,
        unsigned int ind,
        Scaleform::GFx::ASStringNode *v)
{
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *Pairs; // edi
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *Data; // eax
  unsigned int v5; // esi
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *v6; // eax

  Pairs = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this->Pairs;
  Data = Pairs[1].Data;
  v5 = Pairs->Size + 1;
  if ( v5 >= Pairs->Size )
  {
    if ( v5 >= Pairs->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Pairs,
        Data,
        v5 + (v5 >> 2));
  }
  else if ( v5 < Pairs->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      Pairs,
      Data,
      Pairs->Size + 1);
  }
  v6 = &Pairs->Data[v5 - 1];
  Pairs->Size = v5;
  if ( v6 )
  {
    v6->First.pNode = v;
    v6->Second = ind;
  }
}
