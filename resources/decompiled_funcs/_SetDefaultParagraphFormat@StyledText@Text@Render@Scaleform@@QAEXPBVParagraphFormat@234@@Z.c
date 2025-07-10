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
