Scaleform::Render::Text::HighlighterRangeIterator *__thiscall Scaleform::Render::Text::Highlighter::GetRangeIterator(
        Scaleform::Render::Text::Highlighter *this,
        Scaleform::Render::Text::HighlighterRangeIterator *result,
        unsigned int startPos,
        unsigned int flags)
{
  result->pManager = this;
  result->CurTextPos = startPos;
  result->CurRangeIndex = 0;
  result->CurDesc.StartPos = -1;
  result->CurDesc.Offset = -1;
  result->CurDesc.Length = 0;
  result->CurDesc.AdjStartPos = 0;
  result->CurDesc.GlyphNum = 0;
  result->CurDesc.Id = 0;
  result->CurDesc.Info.UnderlineColor.Raw = 0;
  result->CurDesc.Info.TextColor.Raw = 0;
  result->CurDesc.Info.BackgroundColor.Raw = 0;
  result->CurDesc.Info.Flags = 0;
  result->Flags = flags;
  Scaleform::Render::Text::HighlighterRangeIterator::InitCurDesc(result);
  return result;
}
