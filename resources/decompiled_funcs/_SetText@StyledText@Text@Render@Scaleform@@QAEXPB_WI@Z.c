void __thiscall Scaleform::Render::Text::StyledText::SetText(
        Scaleform::Render::Text::StyledText *this,
        wchar_t *pstr,
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
