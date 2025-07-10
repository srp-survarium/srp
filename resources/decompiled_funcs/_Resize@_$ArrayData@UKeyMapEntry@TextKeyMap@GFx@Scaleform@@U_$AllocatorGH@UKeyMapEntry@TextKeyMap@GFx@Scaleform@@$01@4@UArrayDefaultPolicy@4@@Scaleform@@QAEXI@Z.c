void __thiscall Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v4; // eax
  int v5; // esi

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
  {
    v4 = &this->Data[Size];
    v5 = newSize - Size;
    if ( newSize != Size )
    {
      do
      {
        if ( v4 )
          v4->KeyCode = -1;
        ++v4;
        --v5;
      }
      while ( v5 );
    }
  }
}
