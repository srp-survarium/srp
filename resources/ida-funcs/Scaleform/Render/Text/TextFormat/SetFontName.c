// attributes: thunk
void __thiscall Scaleform::Render::Text::TextFormat::SetFontName(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::String *fontName)
{
  Scaleform::Render::Text::TextFormat::SetFontList(this, fontName);
}


void __thiscall Scaleform::Render::Text::TextFormat::SetFontName(
        Scaleform::Render::Text::TextFormat *this,
        const __m128i *pfontName,
        unsigned int fontNameSz)
{
  unsigned int v3; // eax

  v3 = fontNameSz;
  if ( fontNameSz == -1 )
    v3 = strlen(pfontName->m128i_i8);
  Scaleform::Render::Text::TextFormat::SetFontList(this, pfontName, v3);
}
