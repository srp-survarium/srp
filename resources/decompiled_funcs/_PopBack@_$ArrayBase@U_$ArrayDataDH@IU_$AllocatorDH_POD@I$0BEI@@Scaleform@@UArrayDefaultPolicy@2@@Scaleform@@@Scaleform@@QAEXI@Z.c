void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy>>::PopBack(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int count)
{
  unsigned int Size; // eax
  const Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // esi

  Size = this->Data.Size;
  pHeap = this->Data.pHeap;
  v5 = Size - count;
  if ( Size < count )
  {
    if ( v5 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        v5 + (v5 >> 2));
  }
  else if ( v5 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v5);
    this->Data.Size = v5;
    return;
  }
  this->Data.Size = v5;
}
