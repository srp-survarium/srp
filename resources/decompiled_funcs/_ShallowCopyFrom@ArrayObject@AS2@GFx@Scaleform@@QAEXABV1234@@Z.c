void __thiscall Scaleform::GFx::AS2::ArrayObject::ShallowCopyFrom(
        Scaleform::GFx::AS2::ArrayObject *this,
        const Scaleform::GFx::AS2::ArrayObject *ao)
{
  unsigned int Size; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Elements; // esi
  unsigned int v5; // ecx
  unsigned int i; // eax

  Size = ao->Elements.Data.Size;
  p_Elements = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements;
  if ( Size >= this->Elements.Data.Size )
  {
    if ( Size >= this->Elements.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Elements,
        p_Elements,
        Size + (Size >> 2));
  }
  else if ( Size < this->Elements.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_Elements,
      p_Elements,
      ao->Elements.Data.Size);
  }
  p_Elements->Size = Size;
  v5 = this->Elements.Data.Size;
  for ( i = 0; i < v5; ++i )
    p_Elements->Data[i].pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)ao->Elements.Data.Data[i];
}
