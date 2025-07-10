Scaleform::Render::Text::HighlighterPosIterator *__thiscall Scaleform::Render::Text::Highlighter::GetPosIterator(
        Scaleform::Render::Text::Highlighter *this,
        Scaleform::Render::Text::HighlighterPosIterator *result,
        unsigned int startPos,
        unsigned int len)
{
  int v4; // ecx

  result->pManager = this;
  result->CurAdjStartPos = startPos;
  result->NumGlyphs = len;
  result->CurDesc.StartPos = -1;
  result->CurDesc.Length = 0;
  result->CurDesc.Offset = -1;
  result->CurDesc.AdjStartPos = 0;
  result->CurDesc.GlyphNum = 0;
  result->CurDesc.Id = 0;
  result->CurDesc.Info.UnderlineColor.Raw = 0;
  result->CurDesc.Info.TextColor.Raw = 0;
  result->CurDesc.Info.BackgroundColor.Raw = 0;
  result->CurDesc.Info.Flags = 0;
  Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(result);
  return (Scaleform::Render::Text::HighlighterPosIterator *)v4;
}
