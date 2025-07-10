void __thiscall Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::GFx::AS3::Abc::StringView *v5; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)this,
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
          v5->Data = &Scaleform::GFx::AS3::Abc::StringView::Empty;
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}
