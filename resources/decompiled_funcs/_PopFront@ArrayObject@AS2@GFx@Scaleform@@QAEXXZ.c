void __thiscall Scaleform::GFx::AS2::ArrayObject::PopFront(Scaleform::GFx::AS2::ArrayObject *this)
{
  Scaleform::GFx::AS2::Value *v2; // ebx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Elements; // esi
  unsigned int i; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // edx
  int v6; // ecx
  unsigned int v7; // edi

  if ( this->Elements.Data.Size )
  {
    v2 = *this->Elements.Data.Data;
    p_Elements = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements;
    if ( v2 )
    {
      if ( v2->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v2);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v2);
    }
    for ( i = 1; i < this->Elements.Data.Size; *(_DWORD *)(v6 - 4) = pObject )
    {
      pObject = p_Elements->Data[i].pObject;
      v6 = (int)&p_Elements->Data[i++];
    }
    p_Elements->Data[this->Elements.Data.Size - 1].pObject = 0;
    v7 = this->Elements.Data.Size - 1;
    if ( v7 >= p_Elements->Size )
    {
      if ( v7 >= p_Elements->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_Elements,
          p_Elements,
          v7 + (v7 >> 2));
    }
    else if ( v7 < p_Elements->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Elements,
        p_Elements,
        v7);
      p_Elements->Size = v7;
      return;
    }
    p_Elements->Size = v7;
  }
}
