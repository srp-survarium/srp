void __thiscall Scaleform::Render::Text::DocView::AppendText(
        Scaleform::Render::Text::DocView *this,
        char *putf8Str,
        unsigned int utf8Len)
{
  unsigned int Length; // eax
  Scaleform::Render::Text::ParagraphFormat *ppdestParaFmt; // [esp+4h] [ebp-8h] BYREF
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [esp+8h] [ebp-4h] BYREF

  Length = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
  if ( Length
    && (unsigned __int8)Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
                          this->pDocument.pObject,
                          &ppdestTextFmt,
                          &ppdestParaFmt,
                          Length - 1) )
  {
    Scaleform::Render::Text::StyledText::AppendString(
      this->pDocument.pObject,
      putf8Str,
      utf8Len,
      (Scaleform::Render::Text::StyledText::NewLinePolicy)((this->RTFlags & 8) == 0),
      ppdestTextFmt,
      ppdestParaFmt);
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
