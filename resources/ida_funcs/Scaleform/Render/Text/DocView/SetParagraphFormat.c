void __thiscall Scaleform::Render::Text::DocView::SetParagraphFormat(
        Scaleform::Render::Text::DocView *this,
        const Scaleform::Render::Text::ParagraphFormat *fmt,
        unsigned int startPos,
        unsigned int endPos)
{
  Scaleform::Render::Text::StyledText::SetParagraphFormat(this->pDocument.pObject, fmt, startPos, endPos);
  this->OnDocumentChanged(this, 1u);
}
