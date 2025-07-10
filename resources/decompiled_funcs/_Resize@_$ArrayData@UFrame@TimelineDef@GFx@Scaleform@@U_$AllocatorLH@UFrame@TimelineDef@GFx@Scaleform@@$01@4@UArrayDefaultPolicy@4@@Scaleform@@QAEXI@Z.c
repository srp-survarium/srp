void __thiscall Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::GFx::TimelineDef::Frame *v5; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
  {
    v4 = newSize - Size;
    v5 = &this->Data[Size];
    if ( newSize != Size )
    {
      do
      {
        if ( v5 )
        {
          v5->pTagPtrList = 0;
          v5->TagCount = 0;
        }
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}
