void __thiscall Scaleform::GFx::AS2::ArrayObject::MakeDeepCopyFrom(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::MemoryHeap *pheap,
        const Scaleform::GFx::AS2::ArrayObject *ao)
{
  unsigned int Size; // esi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Elements; // edi
  unsigned int v6; // eax
  unsigned int v7; // ebp
  Scaleform::GFx::AS2::Value *v8; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // eax
  unsigned int n; // [esp+10h] [ebp-4h]

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
  v6 = this->Elements.Data.Size;
  v7 = 0;
  for ( n = v6; v7 < v6; ++v7 )
  {
    if ( ao->Elements.Data.Data[v7] )
    {
      v8 = (Scaleform::GFx::AS2::Value *)pheap->Alloc(pheap, 16, 0);
      if ( v8 )
        Scaleform::GFx::AS2::Value::Value(v8, ao->Elements.Data.Data[v7]);
      else
        v9 = 0;
      p_Elements->Data[v7].pObject = v9;
      v6 = n;
    }
  }
}
