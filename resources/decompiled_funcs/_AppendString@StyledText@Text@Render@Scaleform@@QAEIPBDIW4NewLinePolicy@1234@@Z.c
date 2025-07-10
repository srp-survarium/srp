unsigned int __thiscall Scaleform::Render::Text::StyledText::AppendString(
        Scaleform::Render::Text::StyledText *this,
        const char *putf8String,
        unsigned int stringSize,
        Scaleform::Render::Text::StyledText::NewLinePolicy newLinePolicy)
{
  return Scaleform::Render::Text::StyledText::AppendString(
           this,
           putf8String,
           stringSize,
           newLinePolicy,
           this->pDefaultTextFormat.pObject,
           this->pDefaultParagraphFormat.pObject);
}
