char __thiscall Scaleform::Render::Text::ParagraphFormatter::CheckWordWrap(
        Scaleform::Render::Text::ParagraphFormatter *this)
{
  int Pass; // ecx
  const Scaleform::Render::Text::Paragraph::TextBuffer *pText; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // edx
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *pNextFormatData; // eax
  unsigned int GlyphsCount; // edx
  unsigned int FormatDataIndex; // eax
  const Scaleform::Render::Text::GFxLineCursor *v8; // eax
  unsigned int StartIndex; // ebx
  unsigned int Index; // ebp
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pPrevGrec; // eax
  unsigned int v12; // ebp
  Scaleform::Render::Text::LineBuffer::Line *pTempLine; // eax
  bool wordWrap; // [esp+Bh] [ebp-C5h]
  Scaleform::Render::Text::LineBuffer::GlyphInserter ins; // [esp+10h] [ebp-C0h] BYREF
  Scaleform::Render::Text::GFxLineCursor v17; // [esp+24h] [ebp-ACh] BYREF

  Pass = this->Pass;
  if ( Pass == 1
    && (this->pDocView->Flags & 8) != 0
    && !this->isSpace
    && this->TextRectWidth - (double)this->LineCursor.RightMargin < (double)(this->LineCursor.Indent
                                                                           + this->LineCursor.LeftMargin
                                                                           + this->AdjLineWidth
                                                                           + this->NewLineWidth)
    || Pass == 2 && this->LineCursor.NumChars == this->RequestedWordWrapPos )
  {
    if ( Scaleform::Render::Text::ParagraphFormatter::HandleCustomWordWrap(this) )
      return 1;
    this->NewLineWidth = 0;
    pText = this->WordWrapPoint.CharIter.pText;
    wordWrap = 0;
    if ( pText && this->WordWrapPoint.CharIter.CurTextIndex < pText->Size )
    {
      pGlyphs = this->WordWrapPoint.GlyphIns.pGlyphs;
      pNextFormatData = this->WordWrapPoint.GlyphIns.pNextFormatData;
      ins.GlyphIndex = this->WordWrapPoint.GlyphIns.GlyphIndex;
      ins.pGlyphs = pGlyphs;
      GlyphsCount = this->WordWrapPoint.GlyphIns.GlyphsCount;
      ins.pNextFormatData = pNextFormatData;
      FormatDataIndex = this->WordWrapPoint.GlyphIns.FormatDataIndex;
      ins.GlyphsCount = GlyphsCount;
      ins.FormatDataIndex = FormatDataIndex;
      Scaleform::Render::Text::LineBuffer::GlyphInserter::ResetTo(&this->LineCursor.GlyphIns, &ins);
      Scaleform::Render::Text::GFxLineCursor::operator=(&this->LineCursor, &this->WordWrapPoint);
      this->isSpace = 0;
      wordWrap = 1;
      this->DeltaText = 0;
    }
    Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&v17);
    Scaleform::Render::Text::GFxLineCursor::operator=(&this->WordWrapPoint, v8);
    Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&v17);
    StartIndex = this->pParagraph->StartIndex;
    Index = Scaleform::Render::Text::GFxLineCursor::operator*(&this->LineCursor)->Index;
    pPrevGrec = this->LineCursor.pPrevGrec;
    v12 = StartIndex + Index;
    if ( pPrevGrec )
      pPrevGrec->Flags |= 8u;
    Scaleform::Render::Text::ParagraphFormatter::FinalizeLine(this);
    Scaleform::Render::Text::GFxLineCursor::Reset(&this->LineCursor);
    pTempLine = this->pTempLine;
    this->TabStopsIndex = 0;
    if ( (pTempLine->MemSize & 0x80000000) == 0 )
      pTempLine->Data32.TextPos = v12;
    else
      pTempLine->Data32.TextPos ^= (unsigned int)&vostok::memory::s_CRT_arena[5574199]
                                 & (v12
                                  ^ pTempLine->Data32.TextPos);
    if ( wordWrap )
    {
      this->LineCursor.LineWidth = 0;
      return 1;
    }
  }
  return 0;
}
