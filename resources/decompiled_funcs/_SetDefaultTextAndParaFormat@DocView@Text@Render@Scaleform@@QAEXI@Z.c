void __thiscall Scaleform::Render::Text::DocView::SetDefaultTextAndParaFormat(
        Scaleform::Render::Text::DocView *this,
        unsigned int cursorPos)
{
  unsigned int v2; // edi
  unsigned int FirstCharInParagraph; // eax
  const Scaleform::Render::Text::ParagraphFormat *pparaFmt; // [esp+8h] [ebp-8h] BYREF
  const Scaleform::Render::Text::TextFormat *ptextFmt; // [esp+Ch] [ebp-4h] BYREF

  v2 = cursorPos;
  pparaFmt = 0;
  ptextFmt = 0;
  FirstCharInParagraph = Scaleform::Render::Text::DocView::GetFirstCharInParagraph(this, cursorPos);
  if ( FirstCharInParagraph != -1 )
  {
    if ( FirstCharInParagraph != cursorPos )
      v2 = cursorPos - 1;
    if ( Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
           this->pDocument.pObject,
           &ptextFmt,
           &pparaFmt,
           v2) )
    {
      Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(this->pDocument.pObject, pparaFmt);
      Scaleform::Render::Text::StyledText::SetDefaultTextFormat(this->pDocument.pObject, ptextFmt);
    }
  }
}
