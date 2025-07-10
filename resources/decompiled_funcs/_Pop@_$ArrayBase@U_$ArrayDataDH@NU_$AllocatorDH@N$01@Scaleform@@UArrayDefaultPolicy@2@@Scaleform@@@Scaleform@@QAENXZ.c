long double __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy> > *this)
{
  unsigned int Size; // eax
  long double result; // st7
  const Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // edi

  Size = this->Data.Size;
  result = this->Data.Data[Size - 1];
  pHeap = this->Data.pHeap;
  v5 = Size - 1;
  if ( Size )
  {
    if ( v5 < this->Data.Policy.Capacity >> 1 )
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        Size - 1);
  }
  else if ( v5 >= this->Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v5 + (v5 >> 2));
  }
  this->Data.Size = v5;
  return result;
}
