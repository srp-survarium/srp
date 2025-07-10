void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::Clear(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy> > *this)
{
  unsigned int Size; // eax
  const Scaleform::MemoryHeap *pHeap; // ecx

  Size = this->Data.Size;
  pHeap = this->Data.pHeap;
  if ( !Size )
  {
    if ( !this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        0);
    goto LABEL_8;
  }
  if ( (this->Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_8:
    this->Data.Size = 0;
    return;
  }
  if ( this->Data.Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data.Data);
    this->Data.Data = 0;
  }
  this->Data.Policy.Capacity = 0;
  this->Data.Size = 0;
}
