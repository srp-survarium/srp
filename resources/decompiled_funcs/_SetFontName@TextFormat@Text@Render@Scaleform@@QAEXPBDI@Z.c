void __thiscall Scaleform::Render::Text::TextFormat::SetFontName(
        Scaleform::Render::Text::TextFormat *this,
        char *pfontName,
        unsigned int fontNameSz)
{
  unsigned int v3; // eax

  v3 = fontNameSz;
  if ( fontNameSz == -1 )
    v3 = strlen(pfontName);
  Scaleform::Render::Text::TextFormat::SetFontList(this, pfontName, v3);
}
