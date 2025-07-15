Scaleform::Render::Text::HighlightDesc *__thiscall Scaleform::Render::Text::HighlighterRangeIterator::operator*(
        Scaleform::Render::Text::HighlighterRangeIterator *this,
        Scaleform::Render::Text::HighlightDesc *result)
{
  Scaleform::Render::Text::HighlightDesc *v2; // eax

  v2 = result;
  *result = this->CurDesc;
  return v2;
}


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
