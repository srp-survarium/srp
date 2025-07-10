unsigned int __thiscall Scaleform::Render::Text::StyledText::InsertString(
        Scaleform::Render::Text::StyledText *this,
        wchar_t *pstr,
        unsigned int pos,
        unsigned int length,
        Scaleform::Render::Text::StyledText::NewLinePolicy newLinePolicy)
{
  return Scaleform::Render::Text::StyledText::InsertString(
           this,
           pstr,
           pos,
           length,
           newLinePolicy,
           this->pDefaultTextFormat.pObject,
           this->pDefaultParagraphFormat.pObject);
}
