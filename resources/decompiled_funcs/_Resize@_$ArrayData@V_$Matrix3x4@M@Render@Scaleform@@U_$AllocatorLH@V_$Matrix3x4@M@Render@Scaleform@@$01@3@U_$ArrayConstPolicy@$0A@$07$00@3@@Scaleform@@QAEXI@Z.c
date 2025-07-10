void __thiscall Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
        Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
      this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
    Scaleform::ConstructorMov<Scaleform::Render::Matrix3x4<float>>::ConstructArray(
      (float *)&this->Data[Size],
      newSize - Size);
}
