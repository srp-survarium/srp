void __thiscall Scaleform::Render::Text::LineBuffer::GlyphInserter::ResetTo(
        Scaleform::Render::Text::LineBuffer::GlyphInserter *this,
        const Scaleform::Render::Text::LineBuffer::GlyphInserter *savedPos)
{
  unsigned int GlyphIndex; // eax

  GlyphIndex = this->GlyphIndex;
  if ( savedPos->GlyphIndex < GlyphIndex && this->GlyphsCount )
    Scaleform::Render::Text::LineBuffer::ReleasePartOfLine(
      &savedPos->pGlyphs[savedPos->GlyphIndex],
      GlyphIndex - savedPos->GlyphIndex,
      &savedPos->pNextFormatData[savedPos->FormatDataIndex]);
  *this = *savedPos;
}
