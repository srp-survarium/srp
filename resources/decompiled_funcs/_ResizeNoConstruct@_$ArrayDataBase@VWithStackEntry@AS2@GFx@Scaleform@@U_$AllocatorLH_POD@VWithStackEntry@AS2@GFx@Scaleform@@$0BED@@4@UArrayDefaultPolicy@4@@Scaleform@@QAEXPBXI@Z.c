void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  if ( newSize >= this->Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)this,
        pheapAddr,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)this,
      pheapAddr,
      newSize);
    this->Size = newSize;
    return;
  }
  this->Size = newSize;
}
