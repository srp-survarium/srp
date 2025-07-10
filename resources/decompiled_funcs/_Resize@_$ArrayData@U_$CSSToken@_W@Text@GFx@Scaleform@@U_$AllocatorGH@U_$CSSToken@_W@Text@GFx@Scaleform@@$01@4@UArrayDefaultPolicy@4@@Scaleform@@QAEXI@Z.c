void __thiscall Scaleform::ArrayData<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
    Scaleform::ConstructorMov<Scaleform::GFx::Text::CSSToken<wchar_t>>::ConstructArray(
      &this->Data[Size],
      newSize - Size);
}
