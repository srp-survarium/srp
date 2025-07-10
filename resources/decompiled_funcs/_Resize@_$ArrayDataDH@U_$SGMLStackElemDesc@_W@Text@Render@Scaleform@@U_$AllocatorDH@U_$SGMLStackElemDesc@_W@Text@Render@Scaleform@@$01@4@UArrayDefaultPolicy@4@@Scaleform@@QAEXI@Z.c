void __thiscall Scaleform::ArrayDataDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,Scaleform::AllocatorDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayDataDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,Scaleform::AllocatorDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebp
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v4; // esi
  int v5; // edi

  Size = this->Size;
  Scaleform::ArrayDataBase<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,Scaleform::AllocatorDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    this->pHeap,
    newSize);
  if ( newSize > Size )
  {
    v4 = &this->Data[Size];
    v5 = newSize - Size;
    if ( newSize != Size )
    {
      do
      {
        if ( v4 )
          Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>::SGMLStackElemDesc<wchar_t>(v4);
        ++v4;
        --v5;
      }
      while ( v5 );
    }
  }
}
