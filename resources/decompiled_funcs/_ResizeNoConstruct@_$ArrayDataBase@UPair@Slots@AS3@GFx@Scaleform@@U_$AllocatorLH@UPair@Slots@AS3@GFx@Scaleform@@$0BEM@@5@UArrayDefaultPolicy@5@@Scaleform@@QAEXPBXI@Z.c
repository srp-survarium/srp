void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  unsigned int Size; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newSize + (newSize >> 2));
  }
  else
  {
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Slots::Pair>::DestructArray(&this->Data[newSize], Size - newSize);
    if ( newSize < this->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newSize);
      this->Size = newSize;
      return;
    }
  }
  this->Size = newSize;
}
