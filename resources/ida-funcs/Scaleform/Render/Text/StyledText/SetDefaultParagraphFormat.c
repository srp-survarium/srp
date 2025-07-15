void __thiscall Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
        Scaleform::Render::Text::StyledText *this,
        const Scaleform::Render::Text::ParagraphFormat *defaultParagraphFmt)
{
  Scaleform::Render::Text::Allocator *Allocator; // eax
  Scaleform::Render::Text::ParagraphFormat *ParagraphFormat; // eax
  Scaleform::Render::Text::ParagraphFormat *pObject; // edi
  Scaleform::Render::Text::ParagraphFormat *v6; // ebx

  Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this);
  ParagraphFormat = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(Allocator, defaultParagraphFmt);
  pObject = this->pDefaultParagraphFormat.pObject;
  v6 = ParagraphFormat;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
    {
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  this->pDefaultParagraphFormat.pObject = v6;
}


void __thiscall Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::ParagraphFormat *pdefaultParagraphFmt)
{
  Scaleform::Render::Text::ParagraphFormat *pObject; // esi

  if ( pdefaultParagraphFmt )
    ++pdefaultParagraphFmt->RefCount;
  pObject = this->pDefaultParagraphFormat.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
    {
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  this->pDefaultParagraphFormat.pObject = pdefaultParagraphFmt;
}
