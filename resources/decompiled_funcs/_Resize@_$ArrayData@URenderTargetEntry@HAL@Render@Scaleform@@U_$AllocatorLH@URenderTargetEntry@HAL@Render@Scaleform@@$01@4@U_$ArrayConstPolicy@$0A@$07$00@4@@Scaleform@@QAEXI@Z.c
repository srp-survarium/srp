void __thiscall Scaleform::ArrayData<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
        Scaleform::ArrayData<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        unsigned int newSize)
{
  unsigned int Size; // esi

  Size = this->Size;
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
    this,
    this,
    newSize);
  if ( newSize > Size )
    Scaleform::ConstructorMov<Scaleform::Render::HAL::RenderTargetEntry>::ConstructArray(
      &this->Data[Size],
      newSize - Size);
}
