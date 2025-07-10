void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index,
        const long double *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v5; // esi
  double *v6; // eax

  pHeap = this->Data.pHeap;
  v5 = this->Data.Size + 1;
  if ( v5 >= this->Data.Size )
  {
    if ( v5 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        v5 + (v5 >> 2));
  }
  else if ( v5 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v5);
  }
  this->Data.Size = v5;
  if ( index < v5 - 1 )
    memmove(
      (unsigned __int8 *)&this->Data.Data[index + 1],
      (unsigned __int8 *)&this->Data.Data[index],
      8 * (v5 - index) - 8);
  v6 = &this->Data.Data[index];
  if ( v6 )
    *v6 = *(double *)val;
}
