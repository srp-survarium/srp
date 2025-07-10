void __thiscall Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(
        Scaleform::Render::Text::LineBuffer::GlyphIterator *this,
        Scaleform::Render::Text::LineBuffer::GlyphEntry *pglyphs,
        unsigned int glyphsCount,
        Scaleform::Render::Text::LineBuffer::FormatDataEntry *pfmtData)
{
  this->HighlighterIter.CurDesc.Length = 0;
  this->HighlighterIter.CurDesc.AdjStartPos = 0;
  this->HighlighterIter.CurDesc.GlyphNum = 0;
  this->HighlighterIter.CurDesc.Id = 0;
  this->HighlighterIter.CurDesc.StartPos = -1;
  this->HighlighterIter.CurDesc.Offset = -1;
  this->HighlighterIter.CurDesc.Info.UnderlineColor.Raw = 0;
  this->HighlighterIter.CurDesc.Info.TextColor.Raw = 0;
  this->HighlighterIter.CurDesc.Info.BackgroundColor.Raw = 0;
  this->HighlighterIter.CurDesc.Info.Flags = 0;
  this->HighlighterIter.NumGlyphs = 0;
  this->HighlighterIter.CurAdjStartPos = 0;
  this->ColorV = 0;
  this->OrigColor = 0;
  this->UnderlineColor = 0;
  this->SelectionColor = 0;
  this->pFontHandle.pObject = 0;
  this->pImage.pObject = 0;
  this->UnderlineStyle = Underline_None;
  this->Delta = 0;
  this->pGlyphs = pglyphs;
  this->pEndGlyphs = &pglyphs[glyphsCount];
  this->pNextFormatData = pfmtData;
  Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(this);
}
