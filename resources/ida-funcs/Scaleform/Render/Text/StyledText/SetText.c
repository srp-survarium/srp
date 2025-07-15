void __thiscall Scaleform::Render::Text::StyledText::SetText(
        Scaleform::Render::Text::StyledText *this,
        char *putf8String,
        unsigned int stringSize)
{
  Scaleform::Render::Text::StyledText::Clear(this);
  Scaleform::Render::Text::StyledText::AppendString(
    this,
    putf8String,
    stringSize,
    NLP_ReplaceCRLF,
    this->pDefaultTextFormat.pObject,
    this->pDefaultParagraphFormat.pObject);
}


void __thiscall Scaleform::Render::Text::StyledText::SetText(
        Scaleform::Render::Text::StyledText *this,
        const __m128i *pstr,
        unsigned int length)
{
  Scaleform::Render::Text::StyledText::Clear(this);
  Scaleform::Render::Text::StyledText::AppendString(
    this,
    pstr,
    length,
    NLP_ReplaceCRLF,
    this->pDefaultTextFormat.pObject,
    this->pDefaultParagraphFormat.pObject);
}
