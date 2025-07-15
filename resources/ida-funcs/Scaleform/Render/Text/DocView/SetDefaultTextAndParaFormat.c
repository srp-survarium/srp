void __thiscall Scaleform::Render::Text::DocView::SetDefaultTextAndParaFormat(
        Scaleform::Render::Text::DocView *this,
        unsigned int cursorPos)
{
  unsigned int v2; // edi
  unsigned int FirstCharInParagraph; // eax
  Scaleform::Render::Text::ParagraphFormat *ppdestParaFmt; // [esp+8h] [ebp-8h] BYREF
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [esp+Ch] [ebp-4h] BYREF

  v2 = cursorPos;
  ppdestParaFmt = 0;
  ppdestTextFmt = 0;
  FirstCharInParagraph = Scaleform::Render::Text::DocView::GetFirstCharInParagraph(this, cursorPos);
  if ( FirstCharInParagraph != -1 )
  {
    if ( FirstCharInParagraph != cursorPos )
      v2 = cursorPos - 1;
    if ( (unsigned __int8)Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
                            this->pDocument.pObject,
                            &ppdestTextFmt,
                            &ppdestParaFmt,
                            v2) )
    {
      Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(this->pDocument.pObject, ppdestParaFmt);
      Scaleform::Render::Text::StyledText::SetDefaultTextFormat(this->pDocument.pObject, ppdestTextFmt);
    }
  }
}
