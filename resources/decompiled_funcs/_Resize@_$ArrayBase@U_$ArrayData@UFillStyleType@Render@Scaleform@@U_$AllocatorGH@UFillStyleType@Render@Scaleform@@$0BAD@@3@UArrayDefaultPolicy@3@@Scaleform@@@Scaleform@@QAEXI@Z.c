void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>>::Resize(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::Render::FillStyleType *v5; // eax

  Size = this->Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data,
    this,
    newSize);
  if ( newSize > Size )
  {
    v4 = newSize - Size;
    v5 = &this->Data.Data[Size];
    if ( newSize != Size )
    {
      do
      {
        if ( v5 )
          v5->pFill.pObject = 0;
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}
