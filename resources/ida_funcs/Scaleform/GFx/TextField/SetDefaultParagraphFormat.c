void __thiscall Scaleform::GFx::TextField::SetDefaultParagraphFormat(
        Scaleform::GFx::TextField *this,
        const Scaleform::Render::Text::ParagraphFormat *defaultParagraphFmt)
{
  Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
    this->pDocument.pObject->pDocument.pObject,
    defaultParagraphFmt);
  this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
}
