void __thiscall Scaleform::Render::Text::DocView::DocumentText::OnTextRemoving(
        Scaleform::Render::Text::DocView::DocumentText *this,
        unsigned int startPos,
        unsigned int length)
{
  this->pDocument->OnDocumentChanged(this->pDocument, 2u);
}
