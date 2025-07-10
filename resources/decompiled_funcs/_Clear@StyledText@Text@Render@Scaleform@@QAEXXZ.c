void __thiscall Scaleform::Render::Text::StyledText::Clear(Scaleform::Render::Text::StyledText *this)
{
  unsigned int v2; // ebx
  Scaleform::MemoryHeap *v3; // esi
  Scaleform::Render::Text::Allocator *v4; // eax
  Scaleform::Render::Text::Allocator *v5; // eax
  Scaleform::Render::Text::Allocator *v6; // esi
  Scaleform::Render::Text::Allocator *pObject; // ecx
  Scaleform::Render::Text::Paragraph *pPara; // esi
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // esi
  unsigned int n; // [esp+10h] [ebp-4h]

  v2 = 0;
  n = this->Paragraphs.Data.Size;
  if ( n )
  {
    do
    {
      if ( !this->pTextAllocator.pObject )
      {
        v3 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
        v4 = (Scaleform::Render::Text::Allocator *)v3->Alloc(v3, 76u, 0);
        if ( v4 )
        {
          Scaleform::Render::Text::Allocator::Allocator(v4, v3, 0);
          v6 = v5;
        }
        else
        {
          v6 = 0;
        }
        pObject = this->pTextAllocator.pObject;
        if ( pObject )
          Scaleform::RefCountNTSImpl::Release(pObject);
        this->pTextAllocator.pObject = v6;
      }
      pPara = this->Paragraphs.Data.Data[v2].pPara;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pPara->Text.pText);
      ++v2;
      pPara->Text.pText = 0;
      pPara->Text.Allocated = 0;
      pPara->Text.Size = 0;
    }
    while ( v2 < n );
  }
  p_Paragraphs = &this->Paragraphs;
  if ( !this->Paragraphs.Data.Size )
  {
    if ( !this->Paragraphs.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Paragraphs,
        &this->Paragraphs,
        0);
    goto LABEL_17;
  }
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper>::DestructArray(
    (Scaleform::Render::Text::Paragraph *)this,
    p_Paragraphs->Data.Data,
    this->Paragraphs.Data.Size);
  if ( (this->Paragraphs.Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_17:
    this->Paragraphs.Data.Size = 0;
    this->RTFlags &= ~1u;
    return;
  }
  if ( p_Paragraphs->Data.Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Paragraphs->Data.Data);
    p_Paragraphs->Data.Data = 0;
  }
  this->Paragraphs.Data.Policy.Capacity = 0;
  this->Paragraphs.Data.Size = 0;
  this->RTFlags &= ~1u;
}
