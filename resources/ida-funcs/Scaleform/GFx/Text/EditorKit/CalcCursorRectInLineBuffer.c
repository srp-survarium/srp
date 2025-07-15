char __thiscall Scaleform::GFx::Text::EditorKit::CalcCursorRectInLineBuffer(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned int charIndex,
        Scaleform::Render::Rect<float> *pcursorRect,
        unsigned int *plineIndex,
        unsigned int *pglyphIndex,
        bool avoidComposStr,
        Scaleform::Render::Text::LineBuffer::Line::Alignment *plineAlignment)
{
  unsigned int LineIndexOfChar; // eax
  Scaleform::Render::Text::LineBuffer::Line *v9; // ebp
  int TextPos; // eax
  unsigned int v11; // edi
  unsigned int GlyphsCount; // ebx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v13; // esi
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *FormatData; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // eax
  unsigned __int16 Flags; // cx
  int Advance; // eax
  unsigned int i; // esi
  unsigned __int16 v19; // dx
  int v20; // ecx
  double v21; // st7
  double v22; // st6
  double v23; // st7
  float w; // [esp+8h] [ebp-68h]
  unsigned int lineIndex; // [esp+Ch] [ebp-64h]
  Scaleform::Render::Text::LineBuffer::GlyphIterator git; // [esp+10h] [ebp-60h] BYREF
  int xoffset; // [esp+74h] [ebp+4h]
  int avoidComposStra; // [esp+84h] [ebp+14h]
  float avoidComposStrc; // [esp+84h] [ebp+14h]
  float avoidComposStrd; // [esp+84h] [ebp+14h]
  int avoidComposStrb; // [esp+84h] [ebp+14h]
  unsigned int nGlyph; // [esp+88h] [ebp+18h]

  Scaleform::Render::Text::DocView::ForceReformat(this->pDocView.pObject);
  LineIndexOfChar = Scaleform::Render::Text::DocView::GetLineIndexOfChar(this->pDocView.pObject, charIndex);
  lineIndex = LineIndexOfChar;
  if ( LineIndexOfChar == -1 )
    return 0;
  v9 = this->pDocView.pObject->mLineBuffer.Lines.Data.Data[LineIndexOfChar];
  if ( plineAlignment )
    *plineAlignment = (v9->MemSize >> 28) & 3;
  TextPos = v9->Data32.TextPos;
  if ( (v9->MemSize & 0x80000000) != 0 )
  {
    TextPos &= (unsigned int)&vostok::memory::s_CRT_arena[5574199];
    if ( (unsigned __int8 *)TextPos == &vostok::memory::s_CRT_arena[5574199] )
      TextPos = -1;
  }
  v11 = charIndex - TextPos;
  xoffset = 0;
  if ( (v9->MemSize & 0x80000000) == 0 )
    GlyphsCount = v9->Data32.GlyphsCount;
  else
    GlyphsCount = v9->Data8.GlyphsCount;
  v13 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&v9->Data8.Leading + 1);
  if ( (v9->MemSize & 0x80000000) == 0 )
    v13 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&v9->Data8 + 38);
  FormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(v9);
  Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(&git, v13, GlyphsCount, FormatData);
  for ( nGlyph = 0; ; ++nGlyph )
  {
    pGlyphs = git.pGlyphs;
    if ( !git.pGlyphs )
      break;
    if ( git.pGlyphs >= git.pEndGlyphs )
      break;
    if ( (git.pGlyphs->LenAndFontSize & 0xF000) != 0 )
      break;
    Flags = git.pGlyphs->Flags;
    if ( (Flags & 0x100) != 0 )
      break;
    Advance = git.pGlyphs->Advance;
    if ( (Flags & 0x40) != 0 )
      Advance = -Advance;
    xoffset += Advance;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&git);
  }
  for ( i = 0; i < v11; pGlyphs = git.pGlyphs )
  {
    if ( !pGlyphs || pGlyphs >= git.pEndGlyphs )
      break;
    v19 = pGlyphs->Flags;
    v20 = pGlyphs->Advance;
    if ( (v19 & 0x40) != 0 )
      v20 = -v20;
    xoffset += v20;
    if ( !avoidComposStr || (v19 & 4) == 0 )
      i += pGlyphs->LenAndFontSize >> 12;
    ++nGlyph;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&git);
  }
  w = 0.0;
  if ( pGlyphs && pGlyphs < git.pEndGlyphs )
  {
    if ( (pGlyphs->Flags & 0x40) != 0 )
      avoidComposStra = -pGlyphs->Advance;
    else
      avoidComposStra = pGlyphs->Advance;
    w = (float)avoidComposStra;
  }
  avoidComposStrc = (double)v9->Data32.OffsetX + (double)xoffset;
  v21 = avoidComposStrc;
  pcursorRect->x1 = avoidComposStrc;
  avoidComposStrd = (float)v9->Data32.OffsetY;
  pcursorRect->y1 = avoidComposStrd;
  v22 = v21 + w;
  v23 = avoidComposStrd;
  pcursorRect->x2 = v22;
  if ( (v9->MemSize & 0x80000000) == 0 )
    avoidComposStrb = v9->Data32.Height;
  else
    avoidComposStrb = v9->Data8.Height;
  pcursorRect->y2 = v23 + (double)avoidComposStrb;
  if ( plineIndex )
    *plineIndex = lineIndex;
  if ( pglyphIndex )
    *pglyphIndex = nGlyph;
  if ( git.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release(git.pImage.pObject);
  if ( git.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)git.pFontHandle.pObject);
  return 1;
}
