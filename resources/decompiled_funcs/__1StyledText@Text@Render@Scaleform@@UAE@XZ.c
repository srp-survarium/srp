void __thiscall Scaleform::Render::Text::StyledText::~StyledText(Scaleform::Render::Text::StyledText *this)
{
  Scaleform::Render::Text::TextFormat *pObject; // edi
  bool v3; // zf
  Scaleform::Render::Text::ParagraphFormat *v4; // edi
  Scaleform::Render::Text::Allocator *v5; // ecx

  this->__vftable = (Scaleform::Render::Text::StyledText_vtbl *)&Scaleform::Render::Text::StyledText::`vftable';
  Scaleform::Render::Text::StyledText::Clear(this);
  pObject = this->pDefaultTextFormat.pObject;
  if ( pObject )
  {
    v3 = pObject->RefCount-- == 1;
    if ( v3 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  v4 = this->pDefaultParagraphFormat.pObject;
  if ( v4 )
  {
    v3 = v4->RefCount-- == 1;
    if ( v3 )
    {
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(v4);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper>::DestructArray(
    (Scaleform::Render::Text::Paragraph *)v4,
    this->Paragraphs.Data.Data,
    this->Paragraphs.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Paragraphs.Data.Data);
  v5 = this->pTextAllocator.pObject;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}
