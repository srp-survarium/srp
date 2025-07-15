void __thiscall Scaleform::Render::Text::DocView::SetTextFormat(
        Scaleform::Render::Text::DocView *this,
        const Scaleform::Render::Text::TextFormat *fmt,
        unsigned int startPos,
        unsigned int endPos)
{
  this->RTFlags &= ~0x10u;
  Scaleform::Render::Text::StyledText::SetTextFormat(this->pDocument.pObject, fmt, startPos, endPos);
  this->OnDocumentChanged(this, 1u);
}
