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
