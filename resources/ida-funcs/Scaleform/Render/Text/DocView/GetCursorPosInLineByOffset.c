unsigned int __thiscall Scaleform::Render::Text::DocView::GetCursorPosInLineByOffset(
        Scaleform::Render::Text::DocView *this,
        unsigned int lineIndex,
        float relativeOffsetX)
{
  Scaleform::Render::Text::LineBuffer::Line *v4; // ebx
  unsigned int v5; // esi
  unsigned int GlyphsCount; // ebp
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v7; // edi
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *FormatData; // eax
  int v9; // ebp
  unsigned __int16 Flags; // cx
  unsigned int Advance; // edx
  int TextPos; // eax
  int v13; // esi
  Scaleform::Render::Text::LineBuffer::GlyphIterator v14; // [esp+4h] [ebp-60h] BYREF
  int v15; // [esp+68h] [ebp+4h]
  float v16; // [esp+6Ch] [ebp+8h]

  if ( lineIndex >= this->mLineBuffer.Lines.Data.Size )
    return -1;
  v4 = this->mLineBuffer.Lines.Data.Data[lineIndex];
  v5 = 0;
  v15 = 0;
  v16 = relativeOffsetX - (double)v4->Data32.OffsetX + (double)this->mLineBuffer.Geom.HScrollOffset;
  if ( (v4->MemSize & 0x80000000) == 0 )
    GlyphsCount = v4->Data32.GlyphsCount;
  else
    GlyphsCount = v4->Data8.GlyphsCount;
  v7 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&v4->Data8.Leading + 1);
  if ( (v4->MemSize & 0x80000000) == 0 )
    v7 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&v4->Data8 + 38);
  FormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(v4);
  Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(&v14, v7, GlyphsCount, FormatData);
  v9 = 0;
  while ( v14.pGlyphs && v14.pGlyphs < v14.pEndGlyphs )
  {
    Flags = v14.pGlyphs->Flags;
    Advance = v14.pGlyphs->Advance;
    if ( (Flags & 0x40) != 0 )
      Advance = -Advance;
    v5 += Advance;
    if ( v16 < (double)v5 )
    {
      if ( (double)(Advance >> 1) < v16 - (double)v15 )
        v9 += v14.pGlyphs->LenAndFontSize >> 12;
      break;
    }
    v15 = v5;
    if ( (Flags & 0x100) == 0 )
      v9 += v14.pGlyphs->LenAndFontSize >> 12;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&v14);
  }
  TextPos = v4->Data32.TextPos;
  if ( (v4->MemSize & 0x80000000) != 0 )
  {
    TextPos &= 0xFFFFFFu;
    if ( TextPos == 0xFFFFFF )
      TextPos = -1;
  }
  v13 = TextPos + v9;
  if ( v14.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release(v14.pImage.pObject);
  if ( v14.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v14.pFontHandle.pObject);
  return v13;
}
