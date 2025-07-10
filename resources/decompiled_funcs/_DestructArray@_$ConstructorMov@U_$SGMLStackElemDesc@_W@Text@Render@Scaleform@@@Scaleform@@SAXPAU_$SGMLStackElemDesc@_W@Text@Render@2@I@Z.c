void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>>::DestructArray(
        Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *p,
        unsigned int count)
{
  unsigned int v2; // edi
  Scaleform::Render::Text::TextFormat *p_TextFmt; // esi

  v2 = count;
  if ( count )
  {
    p_TextFmt = &p[count - 1].TextFmt;
    do
    {
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)&p_TextFmt[1]);
      Scaleform::Render::Text::TextFormat::~TextFormat(p_TextFmt);
      p_TextFmt = (Scaleform::Render::Text::TextFormat *)((char *)p_TextFmt - 76);
      --v2;
    }
    while ( v2 );
  }
}
