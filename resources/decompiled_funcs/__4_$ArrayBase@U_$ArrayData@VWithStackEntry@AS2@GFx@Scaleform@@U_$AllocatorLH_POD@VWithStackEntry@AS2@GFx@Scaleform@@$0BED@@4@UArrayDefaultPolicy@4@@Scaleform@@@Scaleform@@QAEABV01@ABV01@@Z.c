const Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy> > *__thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy>>::operator=(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy> > *a)
{
  unsigned int Size; // edi
  unsigned int v4; // eax

  Size = a->Data.Size;
  if ( Size >= this->Data.Size )
  {
    if ( Size >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        Size + (Size >> 2));
  }
  else if ( Size < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      a->Data.Size);
  }
  v4 = 0;
  for ( this->Data.Size = Size; v4 < this->Data.Size; ++v4 )
    this->Data.Data[v4] = a->Data.Data[v4];
  return this;
}
