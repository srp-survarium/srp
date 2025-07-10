void __thiscall Scaleform::ArrayDataDH<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        Scaleform::ArrayDataDH<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *this,
        const Scaleform::Pair<double,unsigned long> *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v4; // esi
  Scaleform::Pair<double,unsigned long> *Data; // eax
  Scaleform::Pair<double,unsigned long> *v6; // eax

  pHeap = this->pHeap;
  v4 = this->Size + 1;
  if ( v4 >= this->Size )
  {
    if ( v4 >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        pHeap,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
      pHeap,
      v4);
  }
  Data = this->Data;
  this->Size = v4;
  v6 = &Data[v4 - 1];
  if ( v6 )
    *v6 = *val;
}
