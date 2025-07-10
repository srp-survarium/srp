void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  unsigned int Size; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newSize + (newSize >> 2));
  }
  else
  {
    Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::Sprite>>::DestructArray(
      (Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase> *)&this->Data[newSize],
      Size - newSize);
    if ( newSize < this->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newSize);
      this->Size = newSize;
      return;
    }
  }
  this->Size = newSize;
}
