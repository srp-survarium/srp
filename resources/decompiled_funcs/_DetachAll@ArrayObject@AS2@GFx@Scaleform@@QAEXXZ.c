void __thiscall Scaleform::GFx::AS2::ArrayObject::DetachAll(Scaleform::GFx::AS2::ArrayObject *this)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS2::Value *,2,Scaleform::ArrayDefaultPolicy> *p_Elements; // esi

  p_Elements = &this->Elements;
  if ( !this->Elements.Data.Size )
  {
    if ( !this->Elements.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements,
        &this->Elements,
        0);
    goto LABEL_8;
  }
  if ( (this->Elements.Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_8:
    p_Elements->Data.Size = 0;
    return;
  }
  if ( p_Elements->Data.Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Elements->Data.Data);
    p_Elements->Data.Data = 0;
  }
  p_Elements->Data.Policy.Capacity = 0;
  p_Elements->Data.Size = 0;
}
