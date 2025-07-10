void __thiscall Scaleform::ArrayData<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::GFx::StaticTextRecord::GlyphEntry *v5; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
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
          v5->GlyphAdvance = 0.0;
          v5->GlyphIndex = -1;
        }
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}
