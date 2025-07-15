void __thiscall Scaleform::GFx::TextField::SetDefaultTextFormat(
        Scaleform::GFx::TextField *this,
        Scaleform::Render::Text::TextFormat *defaultTextFmt)
{
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(this->pDocument.pObject->pDocument.pObject, defaultTextFmt);
  this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
}
