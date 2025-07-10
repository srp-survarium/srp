void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  Scaleform::GFx::AS2::Value *v4; // eax
  int v5; // esi

  Size = this->Data.Size;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data,
    this,
    newSize);
  if ( newSize > Size )
  {
    v4 = &this->Data.Data[Size];
    v5 = newSize - Size;
    if ( newSize != Size )
    {
      do
      {
        if ( v4 )
          v4->T.Type = 0;
        ++v4;
        --v5;
      }
      while ( v5 );
    }
  }
}
