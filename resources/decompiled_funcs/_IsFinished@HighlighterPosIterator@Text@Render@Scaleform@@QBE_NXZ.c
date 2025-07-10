BOOL __thiscall Scaleform::Render::Text::HighlighterPosIterator::IsFinished(
        Scaleform::Render::Text::HighlighterPosIterator *this)
{
  return this->CurAdjStartPos >= this->NumGlyphs;
}
