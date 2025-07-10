unsigned int __thiscall Scaleform::Render::Text::StyledText::AppendString(
        Scaleform::Render::Text::StyledText *this,
        wchar_t *pstr,
        unsigned int length,
        const Scaleform::Render::Text::TextFormat *pdefTextFmt,
        Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  return Scaleform::Render::Text::StyledText::AppendString(
           this,
           pstr,
           length,
           NLP_ReplaceCRLF,
           pdefTextFmt,
           pdefParaFmt);
}
