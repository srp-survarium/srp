BOOL __thiscall Scaleform::Render::Text::HighlighterRangeIterator::IsFinished(
        Scaleform::Render::Text::HighlighterRangeIterator *this)
{
  return this->CurRangeIndex >= this->pManager->Highlighters.Data.Size || !this->CurDesc.GlyphNum;
}
