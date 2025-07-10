void __thiscall Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::ResizeNoConstruct(
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1> > *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  if ( newSize >= this->Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
        this,
        pheapAddr,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
      this,
      pheapAddr,
      newSize);
    this->Size = newSize;
    return;
  }
  this->Size = newSize;
}
