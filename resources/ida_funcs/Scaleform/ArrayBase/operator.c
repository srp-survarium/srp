const Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy> > *__thiscall Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy> > *a)
{
  unsigned int Size; // edi
  unsigned int v4; // eax

  Size = a->Data.Size;
  if ( Size >= this->Data.Size )
  {
    if ( Size >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        Size + (Size >> 2));
  }
  else if ( Size < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      a->Data.Size);
  }
  v4 = 0;
  for ( this->Data.Size = Size; v4 < this->Data.Size; ++v4 )
    this->Data.Data[v4] = a->Data.Data[v4];
  return this;
}


const Scaleform::ArrayBase<Scaleform::ArrayData<unsigned long,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::ArrayDefaultPolicy> > *__thiscall Scaleform::ArrayBase<Scaleform::ArrayData<unsigned long,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned long,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::ArrayBase<Scaleform::ArrayData<unsigned long,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::ArrayDefaultPolicy> > *a)
{
  unsigned int Size; // edi
  unsigned int v4; // eax

  Size = a->Data.Size;
  if ( Size >= this->Data.Size )
  {
    if ( Size >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        Size + (Size >> 2));
  }
  else if ( Size < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      a->Data.Size);
  }
  v4 = 0;
  for ( this->Data.Size = Size; v4 < this->Data.Size; ++v4 )
    this->Data.Data[v4] = a->Data.Data[v4];
  return this;
}


const Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *__thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *a)
{
  unsigned int Size; // edi
  unsigned int v4; // ebx
  Scaleform::GFx::AS2::Value *v5; // eax
  unsigned int i; // edi
  unsigned int v7; // ebx
  int v8; // edi

  Size = a->Data.Size;
  v4 = this->Data.Size;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data,
    this,
    Size);
  if ( Size > v4 )
  {
    v5 = &this->Data.Data[v4];
    for ( i = Size - v4; i; --i )
    {
      if ( v5 )
        v5->T.Type = 0;
      ++v5;
    }
  }
  v7 = 0;
  if ( this->Data.Size )
  {
    v8 = 0;
    do
    {
      Scaleform::GFx::AS2::Value::operator=(&this->Data.Data[v8], &a->Data.Data[v8]);
      ++v7;
      ++v8;
    }
    while ( v7 < this->Data.Size );
  }
  return this;
}


const Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> > *__thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy>>::operator=(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> > *a)
{
  unsigned int Size; // edi
  unsigned int v4; // ebx
  Scaleform::GFx::AS2::Value *v5; // eax
  unsigned int i; // edi
  unsigned int v7; // ebx
  int v8; // edi

  Size = a->Data.Size;
  v4 = this->Data.Size;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data,
    this,
    Size);
  if ( Size > v4 )
  {
    v5 = &this->Data.Data[v4];
    for ( i = Size - v4; i; --i )
    {
      if ( v5 )
        v5->T.Type = 0;
      ++v5;
    }
  }
  v7 = 0;
  if ( this->Data.Size )
  {
    v8 = 0;
    do
    {
      Scaleform::GFx::AS2::Value::operator=(&this->Data.Data[v8], &a->Data.Data[v8]);
      ++v7;
      ++v8;
    }
    while ( v7 < this->Data.Size );
  }
  return this;
}


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


const Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *__thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *a)
{
  unsigned int v3; // ebx
  int v4; // esi

  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    a->Data.Size);
  v3 = 0;
  if ( this->Data.Size )
  {
    v4 = 0;
    do
    {
      Scaleform::GFx::AS3::Value::Assign(&this->Data.Data[v4], &a->Data.Data[v4]);
      ++v3;
      ++v4;
    }
    while ( v3 < this->Data.Size );
  }
  return this;
}
