void __thiscall Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(
        Scaleform::Render::Text::LineBuffer::GlyphIterator *this)
{
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v3; // eax

  pGlyphs = this->pGlyphs;
  if ( this->pGlyphs && pGlyphs < this->pEndGlyphs )
  {
    if ( !this->Delta )
      this->Delta = pGlyphs->LenAndFontSize >> 12;
    v3 = pGlyphs + 1;
    this->pGlyphs = v3;
    if ( (v3->LenAndFontSize & 0xF000) != 0
      && this->Delta
      && !Scaleform::Render::Text::HighlighterPosIterator::IsFinished(&this->HighlighterIter) )
    {
      Scaleform::Render::Text::HighlighterPosIterator::operator+=(&this->HighlighterIter, this->Delta);
      this->Delta = 0;
    }
    Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(this);
  }
}
