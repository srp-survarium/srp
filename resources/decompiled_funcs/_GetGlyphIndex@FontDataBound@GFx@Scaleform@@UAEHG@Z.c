void __thiscall Scaleform::GFx::FontDataBound::GetGlyphIndex(
        Scaleform::Render::Text::DocView::DocumentText *this,
        const Scaleform::Render::Text::Paragraph *para)
{
  this->pDocument->OnDocumentParagraphRemoving(this->pDocument, para);
}
