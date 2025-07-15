int __thiscall Scaleform::Render::Text::DocView::ReplaceTextA(
        Scaleform::Render::Text::DocView *this,
        wchar_t *pstr,
        unsigned int startPos,
        unsigned int endPos,
        unsigned int strLen)
{
  unsigned int v6; // eax

  if ( endPos < startPos )
    v6 = 0;
  else
    v6 = endPos - startPos;
  Scaleform::Render::Text::StyledText::Remove(
    this->pDocument.pObject,
    (Scaleform::Render::Text::Paragraph *)this,
    startPos,
    v6);
  return Scaleform::Render::Text::StyledText::InsertString(
           this->pDocument.pObject,
           pstr,
           startPos,
           strLen,
           NLP_ReplaceCRLF);
}
