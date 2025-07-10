void __thiscall Scaleform::Render::Text::HighlighterPosIterator::operator+=(
        Scaleform::Render::Text::HighlighterPosIterator *this,
        unsigned int p)
{
  unsigned int CurAdjStartPos; // eax

  CurAdjStartPos = this->CurAdjStartPos;
  if ( CurAdjStartPos < this->NumGlyphs )
  {
    if ( p )
    {
      this->CurAdjStartPos = p + CurAdjStartPos;
      Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(this);
    }
  }
}
