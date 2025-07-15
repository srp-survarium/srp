void __thiscall Scaleform::Render::Text::DocView::DocumentText::OnTextInserting(
        Scaleform::Render::Text::DocView::DocumentText *this,
        unsigned int startPos,
        unsigned int length,
        const char *ptextInserting)
{
  this->pDocument->OnDocumentChanged(this->pDocument, 2u);
}
