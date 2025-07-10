void __thiscall Scaleform::Render::Text::DocView::SetText(
        Scaleform::Render::Text::DocView *this,
        const char *putf8String,
        unsigned int stringSize)
{
  Scaleform::Render::Text::StyledText::SetText(this->pDocument.pObject, putf8String, stringSize);
  this->OnDocumentChanged(this, 262u);
}
