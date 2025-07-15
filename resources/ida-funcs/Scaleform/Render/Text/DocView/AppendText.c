void __thiscall Scaleform::Render::Text::DocView::AppendText(
        Scaleform::Render::Text::DocView *this,
        const char *putf8Str,
        unsigned int utf8Len)
{
  unsigned int Length; // eax
  const Scaleform::Render::Text::ParagraphFormat *pparafmt; // [esp+4h] [ebp-8h] BYREF
  const Scaleform::Render::Text::TextFormat *ptxtfmt; // [esp+8h] [ebp-4h] BYREF

  Length = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
  if ( Length
    && Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
         this->pDocument.pObject,
         &ptxtfmt,
         &pparafmt,
         Length - 1) )
  {
    Scaleform::Render::Text::StyledText::AppendString(
      this->pDocument.pObject,
      putf8Str,
      utf8Len,
      (Scaleform::Render::Text::StyledText::NewLinePolicy)((this->RTFlags & 8) == 0),
      ptxtfmt,
      pparafmt);
    this->OnDocumentChanged(this, 6u);
  }
  else
  {
    Scaleform::Render::Text::StyledText::AppendString(
      this->pDocument.pObject,
      putf8Str,
      utf8Len,
      (Scaleform::Render::Text::StyledText::NewLinePolicy)((this->RTFlags & 8) == 0));
    this->OnDocumentChanged(this, 6u);
  }
}
