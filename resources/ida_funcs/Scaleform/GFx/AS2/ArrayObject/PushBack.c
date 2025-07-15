void __thiscall Scaleform::GFx::AS2::ArrayObject::PushBack(
        Scaleform::GFx::AS2::ArrayObject *this,
        const Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // ebx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Elements; // edi
  unsigned int v7; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v8; // eax
  int v9; // [esp+8h] [ebp-4h] BYREF

  v9 = 323;
  v3 = (Scaleform::GFx::AS2::Value *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                       Scaleform::Memory::pGlobalHeap,
                                       this,
                                       16,
                                       &v9);
  if ( v3 )
  {
    Scaleform::GFx::AS2::Value::Value(v3, val);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  p_Elements = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements;
  v7 = this->Elements.Data.Size + 1;
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
  }
  v8 = &p_Elements->Data[v7 - 1];
  p_Elements->Size = v7;
  if ( v8 )
    v8->pObject = v5;
}


void __thiscall Scaleform::GFx::AS2::ArrayObject::PushBack(Scaleform::GFx::AS2::ArrayObject *this)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Elements; // edi
  unsigned int v2; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // edx

  p_Elements = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements;
  v2 = this->Elements.Data.Size + 1;
  if ( v2 >= this->Elements.Data.Size )
  {
    if ( v2 >= this->Elements.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Elements,
        p_Elements,
        v2 + (v2 >> 2));
  }
  else if ( v2 < this->Elements.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_Elements,
      p_Elements,
      this->Elements.Data.Size + 1);
  }
  Data = p_Elements->Data;
  p_Elements->Size = v2;
  if ( &Data[v2] != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)4 )
    Data[v2 - 1].pObject = 0;
}
