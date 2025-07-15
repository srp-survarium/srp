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
  Scaleform::Render::Text::LineBuffer::GlyphIterator git; // [esp+4h] [ebp-60h] BYREF
  int xoffset; // [esp+68h] [ebp+4h]
  float xoffInLine; // [esp+6Ch] [ebp+8h]

  if ( lineIndex >= this->mLineBuffer.Lines.Data.Size )
    return -1;
  v4 = this->mLineBuffer.Lines.Data.Data[lineIndex];
  v5 = 0;
  xoffset = 0;
  xoffInLine = relativeOffsetX - (double)v4->Data32.OffsetX + (double)this->mLineBuffer.Geom.HScrollOffset;
  if ( (v4->MemSize & 0x80000000) == 0 )
    GlyphsCount = v4->Data32.GlyphsCount;
  else
    GlyphsCount = v4->Data8.GlyphsCount;
  v7 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&v4->Data8.Leading + 1);
  if ( (v4->MemSize & 0x80000000) == 0 )
    v7 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&v4->Data8 + 38);
  FormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(v4);
  Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(&git, v7, GlyphsCount, FormatData);
  v9 = 0;
  while ( git.pGlyphs && git.pGlyphs < git.pEndGlyphs )
  {
    Flags = git.pGlyphs->Flags;
    Advance = git.pGlyphs->Advance;
    if ( (Flags & 0x40) != 0 )
      Advance = -Advance;
    v5 += Advance;
    if ( xoffInLine < (double)v5 )
    {
      if ( (double)(Advance >> 1) < xoffInLine - (double)xoffset )
        v9 += git.pGlyphs->LenAndFontSize >> 12;
      break;
    }
    xoffset = v5;
    if ( (Flags & 0x100) == 0 )
      v9 += git.pGlyphs->LenAndFontSize >> 12;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&git);
  }
  TextPos = v4->Data32.TextPos;
  if ( (v4->MemSize & 0x80000000) != 0 )
  {
    TextPos &= (unsigned int)&vostok::memory::s_CRT_arena[5574199];
    if ( (unsigned __int8 *)TextPos == &vostok::memory::s_CRT_arena[5574199] )
      TextPos = -1;
  }
  v13 = TextPos + v9;
  if ( git.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release(git.pImage.pObject);
  if ( git.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)git.pFontHandle.pObject);
  return v13;
}
