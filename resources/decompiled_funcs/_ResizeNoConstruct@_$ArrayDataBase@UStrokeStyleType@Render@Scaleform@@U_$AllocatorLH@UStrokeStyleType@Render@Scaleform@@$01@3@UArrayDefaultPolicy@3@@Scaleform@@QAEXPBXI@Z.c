void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  unsigned int Size; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newSize + (newSize >> 2));
  }
  else
  {
    Scaleform::ConstructorMov<Scaleform::Render::StrokeStyleType>::DestructArray(&this->Data[newSize], Size - newSize);
    if ( newSize < this->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr,
        newSize);
      this->Size = newSize;
      return;
    }
  }
  this->Size = newSize;
}
