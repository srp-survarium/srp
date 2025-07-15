void __thiscall Scaleform::GFx::AS2::ArrayObject::InsertEmpty(
        Scaleform::GFx::AS2::ArrayObject *this,
        int start,
        int count)
{
  unsigned int Size; // ebp
  unsigned int v5; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Elements; // esi
  signed int v7; // eax
  int v8; // edx
  int v9; // ecx
  int v10; // eax

  Size = this->Elements.Data.Size;
  v5 = count + Size;
  p_Elements = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements;
  if ( count + Size >= Size )
  {
    if ( v5 >= this->Elements.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Elements,
        p_Elements,
        v5 + (v5 >> 2));
  }
  else if ( v5 < this->Elements.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_Elements,
      p_Elements,
      count + Size);
  }
  p_Elements->Size = v5;
  if ( Size )
  {
    v7 = this->Elements.Data.Size - 1;
    if ( v7 >= count + start )
    {
      v8 = v7 - count;
      do
        p_Elements->Data[v7--].pObject = p_Elements->Data[v8--].pObject;
      while ( v7 >= count + start );
    }
  }
  v9 = count;
  if ( count > 0 )
  {
    v10 = start;
    do
    {
      p_Elements->Data[v10++].pObject = 0;
      --v9;
    }
    while ( v9 );
  }
}
