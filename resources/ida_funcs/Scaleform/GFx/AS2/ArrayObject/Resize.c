void __thiscall Scaleform::GFx::AS2::ArrayObject::Resize(Scaleform::GFx::AS2::ArrayObject *this, int size)
{
  unsigned int v2; // esi
  unsigned int v4; // eax
  unsigned int i; // ebx
  Scaleform::GFx::AS2::Value **Data; // ecx
  Scaleform::GFx::AS2::Value *v7; // edi
  unsigned int oldSize; // [esp+14h] [ebp+4h]

  v2 = size;
  if ( size < 0 )
    v2 = 0;
  v4 = this->Elements.Data.Size;
  oldSize = v4;
  for ( i = v2; i < v4; ++i )
  {
    Data = this->Elements.Data.Data;
    v7 = Data[i];
    if ( v7 )
    {
      if ( v7->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(Data[i]);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
      v4 = oldSize;
    }
  }
  if ( v2 >= this->Elements.Data.Size )
  {
    if ( v2 < this->Elements.Data.Policy.Capacity )
      goto LABEL_15;
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements,
      &this->Elements,
      v2 + (v2 >> 2));
  }
  else
  {
    if ( v2 >= this->Elements.Data.Policy.Capacity >> 1 )
      goto LABEL_15;
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements,
      &this->Elements,
      v2);
  }
  v4 = oldSize;
LABEL_15:
  for ( this->Elements.Data.Size = v2; v4 < v2; ++v4 )
    this->Elements.Data.Data[v4] = 0;
}
