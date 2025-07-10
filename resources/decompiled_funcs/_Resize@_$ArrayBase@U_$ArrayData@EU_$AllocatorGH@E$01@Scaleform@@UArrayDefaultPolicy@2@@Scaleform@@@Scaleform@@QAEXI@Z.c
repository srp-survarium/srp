void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int newSize)
{
  if ( newSize >= this->Data.Size )
  {
    if ( newSize >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      newSize);
    this->Data.Size = newSize;
    return;
  }
  this->Data.Size = newSize;
}
