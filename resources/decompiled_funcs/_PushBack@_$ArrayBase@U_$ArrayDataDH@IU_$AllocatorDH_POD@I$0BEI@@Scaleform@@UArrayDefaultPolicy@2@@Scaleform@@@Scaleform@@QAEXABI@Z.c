void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy> > *this,
        const unsigned int *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v4; // esi
  unsigned int *Data; // eax

  pHeap = this->Data.pHeap;
  v4 = this->Data.Size + 1;
  if ( v4 >= this->Data.Size )
  {
    if ( v4 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v4);
  }
  Data = this->Data.Data;
  this->Data.Size = v4;
  Data[v4 - 1] = *val;
}
