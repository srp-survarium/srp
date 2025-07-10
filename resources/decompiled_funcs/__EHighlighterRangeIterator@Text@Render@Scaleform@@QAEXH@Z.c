void __thiscall Scaleform::Render::Text::HighlighterRangeIterator::operator++(
        Scaleform::Render::Text::HighlighterRangeIterator *this,
        int __formal)
{
  if ( this->CurRangeIndex < this->pManager->Highlighters.Data.Size )
  {
    if ( this->CurDesc.GlyphNum )
      Scaleform::Render::Text::HighlighterRangeIterator::InitCurDesc(this);
  }
}
