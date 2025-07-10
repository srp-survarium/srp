void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::GFx::Button::CharToRec *v5; // eax

  Size = this->Data.Size;
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
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
          v5->Char.pObject = 0;
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}
