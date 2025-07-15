void __thiscall Scaleform::GFx::AS2::ArrayObject::RemoveElements(
        Scaleform::GFx::AS2::ArrayObject *this,
        int start,
        int count)
{
  int v4; // ecx
  int v5; // ebx
  int v6; // ebp
  Scaleform::GFx::AS2::Value **Data; // eax
  Scaleform::GFx::AS2::Value *v8; // edi
  signed int v9; // eax
  int v10; // edx
  unsigned int v11; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Elements; // esi

  if ( this->Elements.Data.Size )
  {
    v4 = count;
    if ( count > 0 )
    {
      v5 = start;
      v6 = count;
      do
      {
        Data = this->Elements.Data.Data;
        v8 = Data[v5];
        if ( v8 )
        {
          if ( v8->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(Data[v5]);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
          v4 = count;
        }
        ++v5;
        --v6;
      }
      while ( v6 );
    }
    v9 = start + v4;
    if ( start + v4 < (signed int)this->Elements.Data.Size )
    {
      v10 = start;
      do
      {
        this->Elements.Data.Data[v10] = this->Elements.Data.Data[v9];
        this->Elements.Data.Data[v9++] = 0;
        ++v10;
      }
      while ( v9 < (signed int)this->Elements.Data.Size );
      v4 = count;
    }
    v11 = this->Elements.Data.Size - v4;
    p_Elements = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements;
    if ( v11 >= p_Elements->Size )
    {
      if ( v11 >= p_Elements->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_Elements,
          p_Elements,
          v11 + (v11 >> 2));
    }
    else if ( v11 < p_Elements->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Elements,
        p_Elements,
        v11);
      p_Elements->Size = v11;
      return;
    }
    p_Elements->Size = v11;
  }
}
