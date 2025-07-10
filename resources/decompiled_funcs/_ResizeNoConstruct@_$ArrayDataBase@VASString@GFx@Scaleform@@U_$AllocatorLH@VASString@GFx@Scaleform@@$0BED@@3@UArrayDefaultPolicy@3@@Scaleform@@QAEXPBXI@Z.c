void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  unsigned int Size; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *)this,
        pheapAddr,
        newSize + (newSize >> 2));
  }
  else
  {
    Scaleform::ConstructorMov<Scaleform::GFx::ASString>::DestructArray(&this->Data[newSize], Size - newSize);
    if ( newSize < this->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *)this,
        pheapAddr,
        newSize);
      this->Size = newSize;
      return;
    }
  }
  this->Size = newSize;
}
