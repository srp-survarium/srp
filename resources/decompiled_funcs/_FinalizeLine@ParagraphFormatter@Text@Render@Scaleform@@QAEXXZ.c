void __thiscall Scaleform::Render::Text::ParagraphFormatter::FinalizeLine(
        Scaleform::Render::Text::ParagraphFormatter *this)
{
  double LastAdvance; // st6
  double v3; // st6
  int LastGlyphWidth; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pPrevGrec; // ecx
  const Scaleform::Render::Text::ParagraphFormat *pParaFormat; // eax
  int RightMargin; // ecx
  double MaxFontLeading; // st5
  double v9; // st5
  double v10; // st5
  double v11; // st7
  double v12; // st7
  unsigned int GlyphIndex; // ebx
  int v14; // ecx
  int LineWidthWithoutTrailingSpaces; // eax
  Scaleform::Render::Text::DocView *pDocView; // edx
  Scaleform::Render::Text::LineBuffer::Line *inserted; // eax
  Scaleform::Render::Text::LineBuffer::Iterator *pLinesIter; // ebp
  signed int CurrentPos; // eax
  unsigned int UniqueId; // ecx
  Scaleform::Render::Text::LineBuffer::Line *v21; // edi
  bool v22; // al
  unsigned __int16 ModCounter; // cx
  Scaleform::Render::Text::LineBuffer::Line *pTempLine; // ecx
  unsigned __int8 *v25; // ecx
  bool v26; // zf
  unsigned __int8 *v27; // eax
  unsigned __int8 *v28; // eax
  Scaleform::Render::Text::LineBuffer::Line *v29; // eax
  int MemSize; // edx
  int TextPos; // eax
  unsigned int LineLength; // eax
  unsigned int v33; // ebx
  const Scaleform::Render::Text::ParagraphFormat *v34; // eax
  int v35; // ebp
  int v36; // ebx
  unsigned __int16 Flags; // ax
  int Advance; // eax
  Scaleform::Render::Text::ImageDesc *pObject; // ecx
  int v40; // edx
  int NextOffsetY; // eax
  unsigned int v42; // eax
  int v43; // ebx
  double v44; // st7
  signed int v45; // eax
  int LineWidth; // ecx
  signed int v47; // eax
  int v48; // ecx
  double v49; // st6
  double v50; // st6
  signed int v51; // eax
  int v52; // ecx
  double TextRectWidth; // st7
  double v54; // st7
  double v55; // st6
  int ParaWidth; // eax
  int v57; // edi
  double v58; // st6
  double v59; // st7
  Scaleform::RefCountVImpl *v60; // ecx
  unsigned __int8 *FormatData; // [esp-4h] [ebp-84h]
  int lineHeight; // [esp+14h] [ebp-6Ch]
  float lineHeighta; // [esp+14h] [ebp-6Ch]
  float lineHeightb; // [esp+14h] [ebp-6Ch]
  float leadinga; // [esp+18h] [ebp-68h]
  int leading; // [esp+18h] [ebp-68h]
  float fleading; // [esp+1Ch] [ebp-64h]
  unsigned int fleadinga; // [esp+1Ch] [ebp-64h]
  Scaleform::Render::Text::LineBuffer::GlyphIterator git; // [esp+20h] [ebp-60h] BYREF

  LastAdvance = this->LineCursor.LastAdvance;
  if ( LastAdvance <= 0.0 )
    v3 = LastAdvance - 0.5;
  else
    v3 = LastAdvance + 0.5;
  LastGlyphWidth = (int)v3;
  pPrevGrec = this->LineCursor.pPrevGrec;
  if ( pPrevGrec )
  {
    if ( LastGlyphWidth < 0 )
    {
      pPrevGrec->Flags |= 0x40u;
      pPrevGrec->Advance = -(__int16)LastGlyphWidth;
    }
    else
    {
      pPrevGrec->Flags &= ~0x40u;
      pPrevGrec->Advance = LastGlyphWidth;
    }
  }
  if ( this->LineCursor.pLastFont.pObject )
    LastGlyphWidth = this->LineCursor.LastGlyphWidth;
  this->LineCursor.LineWidth += LastGlyphWidth;
  pParaFormat = this->pParaFormat;
  if ( (pParaFormat->PresentMask & 1) != 0
    && ((pParaFormat->PresentMask & 0x600) == 0x200
     || (pParaFormat->PresentMask & 1) != 0 && (pParaFormat->PresentMask & 0x600) == 0x600) )
  {
    RightMargin = this->LineCursor.RightMargin;
    this->LineCursor.LineWidth += RightMargin;
    this->LineCursor.LineWidthWithoutTrailingSpaces += RightMargin;
  }
  if ( (pParaFormat->PresentMask & 8) != 0 )
    MaxFontLeading = (double)pParaFormat->Leading * 20.0;
  else
    MaxFontLeading = this->LineCursor.MaxFontLeading;
  fleading = MaxFontLeading;
  leadinga = this->LineCursor.MaxFontDescent + this->LineCursor.MaxFontAscent;
  v9 = leadinga;
  if ( leadinga <= 0.0 )
    v10 = v9 - 0.5;
  else
    v10 = v9 + 0.5;
  lineHeight = (int)v10;
  v11 = fleading;
  if ( fleading <= 0.0 )
    v12 = v11 - 0.5;
  else
    v12 = v11 + 0.5;
  leading = (int)v12;
  GlyphIndex = this->LineCursor.GlyphIns.GlyphIndex;
  v14 = this->LineCursor.LineWidth < 0 ? 0 : this->LineCursor.LineWidth;
  LineWidthWithoutTrailingSpaces = this->LineCursor.LineWidthWithoutTrailingSpaces;
  this->LineCursor.LineWidth = v14;
  pDocView = this->pDocView;
  this->LineCursor.LineWidthWithoutTrailingSpaces = LineWidthWithoutTrailingSpaces < 0
                                                  ? 0
                                                  : LineWidthWithoutTrailingSpaces;
  fleadinga = this->LineCursor.GlyphIns.FormatDataIndex;
  if ( (pDocView->AlignProps & 0x30) != 0
    || this->LineCursor.LineLength > 0xFF
    || GlyphIndex > 0xFF
    || (unsigned int)(leading + 128) > 0xFF
    || (unsigned int)(int)v10 > 0xFFFF
    || v14 < 0
    || v14 >= (int)&_sbh_sizeHeaderList )
  {
    pLinesIter = this->pLinesIter;
    CurrentPos = pLinesIter->CurrentPos;
    if ( CurrentPos < 0 )
      CurrentPos = pLinesIter->pLineBuffer->Lines.Data.Size;
    inserted = Scaleform::Render::Text::LineBuffer::InsertNewLine(
                 pLinesIter->pLineBuffer,
                 CurrentPos,
                 GlyphIndex,
                 fleadinga,
                 Line32);
    ++pLinesIter->CurrentPos;
  }
  else
  {
    inserted = Scaleform::Render::Text::LineBuffer::Iterator::InsertNewLine(
                 this->pLinesIter,
                 GlyphIndex,
                 this->LineCursor.GlyphIns.FormatDataIndex,
                 Line8);
  }
  UniqueId = this->LineCursor.pParagraph->UniqueId;
  v21 = inserted;
  v22 = (inserted->MemSize & 0x80000000) != 0;
  if ( v22 )
    v21->Data32.GlyphsCount = UniqueId;
  else
    v21->Data32.ParagraphId = UniqueId;
  ModCounter = this->LineCursor.pParagraph->ModCounter;
  if ( v22 )
    v21->Data8.ParagraphModId = ModCounter;
  else
    v21->Data32.ParagraphModId = ModCounter;
  pTempLine = this->pTempLine;
  if ( (pTempLine->MemSize & 0x80000000) == 0 )
    v25 = (unsigned __int8 *)&pTempLine->Data8 + 38;
  else
    v25 = (unsigned __int8 *)(&pTempLine->Data8.Leading + 1);
  v26 = !v22;
  v27 = (unsigned __int8 *)(&v21->Data8.Leading + 1);
  if ( v26 )
    v27 = (unsigned __int8 *)&v21->Data8 + 38;
  memcpy(v27, v25, 8 * GlyphIndex);
  FormatData = (unsigned __int8 *)Scaleform::Render::Text::LineBuffer::Line::GetFormatData(this->pTempLine);
  v28 = (unsigned __int8 *)Scaleform::Render::Text::LineBuffer::Line::GetFormatData(v21);
  memcpy(v28, FormatData, 4 * fleadinga);
  v29 = this->pTempLine;
  MemSize = v29->MemSize;
  TextPos = v29->Data32.TextPos;
  if ( MemSize < 0 )
  {
    TextPos &= (unsigned int)&vostok::memory::s_CRT_arena[5574199];
    if ( (unsigned __int8 *)TextPos == &vostok::memory::s_CRT_arena[5574199] )
      TextPos = -1;
  }
  if ( (v21->MemSize & 0x80000000) == 0 )
    v21->Data32.TextPos = TextPos;
  else
    v21->Data32.TextPos ^= (unsigned int)&vostok::memory::s_CRT_arena[5574199] & (TextPos ^ v21->Data32.TextPos);
  LineLength = this->LineCursor.LineLength;
  if ( (v21->MemSize & 0x80000000) == 0 )
    v21->Data32.TextLength = LineLength;
  else
    HIBYTE(v21->Data8.TextPosAndLength) = LineLength;
  Scaleform::Render::Text::LineBuffer::Line::SetBaseLineOffset(v21, this->LineCursor.MaxFontAscent);
  if ( !this->LineCursor.LineHasNewLine && (this->pDocView->Flags & 8) != 0 )
  {
    v33 = this->LineCursor.NumOfSpaces - this->LineCursor.NumOfTrailingSpaces;
    if ( v33 )
    {
      v34 = this->pParaFormat;
      if ( (v34->PresentMask & 1) != 0 && (v34->PresentMask & 0x600) == 0x400 )
      {
        v35 = (int)(this->TextRectWidth - 30.0)
            - this->LineCursor.RightMargin
            - this->LineCursor.LeftMargin
            - this->LineCursor.Indent
            - this->LineCursor.LineWidthWithoutTrailingSpaces;
        if ( v35 > 0 )
        {
          v36 = v35 / v33;
          Scaleform::Render::Text::LineBuffer::Line::Begin(v21, &git);
          while ( git.pGlyphs && git.pGlyphs < git.pEndGlyphs )
          {
            Flags = git.pGlyphs->Flags;
            if ( (Flags & 2) != 0 )
            {
              v26 = (Flags & 0x40) == 0;
              Advance = git.pGlyphs->Advance;
              if ( !v26 )
                Advance = -Advance;
              Scaleform::Render::Text::LineBuffer::GlyphEntry::SetAdvance(git.pGlyphs, v36 + Advance);
            }
            Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&git);
          }
          pObject = git.pImage.pObject;
          this->LineCursor.LineWidth += v35;
          if ( pObject )
            Scaleform::RefCountNTSImpl::Release(pObject);
          if ( git.pFontHandle.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)git.pFontHandle.pObject);
        }
      }
    }
  }
  v40 = this->LineCursor.Indent + this->LineCursor.LeftMargin;
  NextOffsetY = this->NextOffsetY;
  v21->Data32.OffsetX = v40;
  v21->Data32.OffsetY = NextOffsetY;
  v42 = v21->MemSize;
  if ( (v21->MemSize & 0x80000000) == 0 )
    v21->Data32.Leading = leading;
  else
    v21->Data8.Leading = leading;
  v43 = (int)v10;
  if ( ((this->pParaFormat->PresentMask >> 9) & 3) == 1 )
  {
    v51 = v42 & 0xCFFFFFFF | 0x10000000;
    v21->MemSize = v51;
    v52 = this->LineCursor.LineWidthWithoutTrailingSpaces;
    if ( v51 >= 0 )
    {
      v21->Data32.Width = v52;
      v21->Data32.Height = lineHeight;
    }
    else
    {
      v21->Data8.Width = v52;
      v21->Data8.Height = lineHeight;
    }
    TextRectWidth = this->TextRectWidth;
    if ( TextRectWidth <= 0.0 )
      v54 = TextRectWidth - 0.5;
    else
      v54 = TextRectWidth + 0.5;
    v55 = v54;
    v44 = 0.5;
    v21->Data32.OffsetX = (int)v55 - this->LineCursor.LineWidthWithoutTrailingSpaces < 0
                        ? 0
                        : (int)v55 - this->LineCursor.LineWidthWithoutTrailingSpaces;
    if ( (this->pDocView->Flags & 1) != 0 || (this->pDocView->AlignProps & 0x30) != 0 )
      this->NeedRecenterLines = 1;
  }
  else if ( ((this->pParaFormat->PresentMask >> 9) & 3) == 3 )
  {
    v47 = v42 & 0xCFFFFFFF | 0x20000000;
    v21->MemSize = v47;
    v48 = this->LineCursor.LineWidthWithoutTrailingSpaces;
    if ( v47 >= 0 )
    {
      v21->Data32.Width = v48;
      v21->Data32.Height = lineHeight;
    }
    else
    {
      v21->Data8.Width = v48;
      v21->Data8.Height = lineHeight;
    }
    lineHeighta = this->TextRectWidth - (double)this->LineCursor.LeftMargin;
    v44 = 0.5;
    lineHeightb = lineHeighta * 0.5 - (double)(this->LineCursor.LineWidthWithoutTrailingSpaces / 2);
    v49 = lineHeightb;
    if ( lineHeightb <= 0.0 )
      v50 = v49 - 0.5;
    else
      v50 = v49 + 0.5;
    v21->Data32.OffsetX = this->LineCursor.LeftMargin + (int)v50 < 0 ? 0 : this->LineCursor.LeftMargin + (int)v50;
    if ( (this->pDocView->Flags & 1) != 0 || (this->pDocView->AlignProps & 0x30) != 0 )
      this->NeedRecenterLines = 1;
  }
  else
  {
    v44 = 0.5;
    v45 = v42 & 0xCFFFFFFF;
    v21->MemSize = v45;
    LineWidth = this->LineCursor.LineWidth;
    if ( v45 >= 0 )
    {
      v21->Data32.Width = LineWidth;
      v21->Data32.Height = lineHeight;
    }
    else
    {
      v21->Data8.Width = LineWidth;
      v21->Data8.Height = lineHeight;
    }
  }
  ParaWidth = v40 + this->LineCursor.LineWidth;
  if ( ParaWidth < this->ParaWidth )
    ParaWidth = this->ParaWidth;
  v57 = this->NextOffsetY;
  this->ParaWidth = ParaWidth;
  v58 = (double)(v43 + leading);
  this->ParaHeight = v43 + v57 - this->ParaYOffset;
  if ( v58 <= 0.0 )
    v59 = v58 - v44;
  else
    v59 = v44 + v58;
  this->NextOffsetY = v57 + (int)v59;
  this->LineCursor.Indent = 0;
  this->LineCursor.GlyphIns.FormatDataIndex = 0;
  this->LineCursor.GlyphIns.GlyphIndex = 0;
  this->LineCursor.LastColor = 0;
  v60 = (Scaleform::RefCountVImpl *)this->LineCursor.pLastFont.pObject;
  if ( v60 )
    Scaleform::RefCountImpl::Release(v60);
  this->LineCursor.pLastFont.pObject = 0;
}
