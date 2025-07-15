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
  unsigned int j; // esi
  unsigned __int16 v19; // dx
  int v20; // ecx
  double v21; // st7
  double v22; // st6
  double v23; // st7
  float v25; // [esp+8h] [ebp-68h]
  unsigned int v26; // [esp+Ch] [ebp-64h]
  Scaleform::Render::Text::LineBuffer::GlyphIterator v27; // [esp+10h] [ebp-60h] BYREF
  signed int indexOfChar; // [esp+74h] [ebp+4h]
  int v29; // [esp+84h] [ebp+14h]
  float v30; // [esp+84h] [ebp+14h]
  float OffsetY; // [esp+84h] [ebp+14h]
  int Height; // [esp+84h] [ebp+14h]
  unsigned int i; // [esp+88h] [ebp+18h]

  Scaleform::Render::Text::DocView::ForceReformat(this->pDocView.pObject);
  LineIndexOfChar = Scaleform::Render::Text::DocView::GetLineIndexOfChar(this->pDocView.pObject, charIndex);
  v26 = LineIndexOfChar;
  if ( LineIndexOfChar == -1 )
    return 0;
  v9 = this->pDocView.pObject->mLineBuffer.Lines.Data.Data[LineIndexOfChar];
  if ( plineAlignment )
    *plineAlignment = (v9->MemSize >> 28) & 3;
  TextPos = v9->Data32.TextPos;
  if ( (v9->MemSize & 0x80000000) != 0 )
  {
    TextPos &= 0xFFFFFFu;
    if ( TextPos == 0xFFFFFF )
      TextPos = -1;
  }
  v11 = charIndex - TextPos;
  indexOfChar = 0;
  if ( (v9->MemSize & 0x80000000) == 0 )
    GlyphsCount = v9->Data32.GlyphsCount;
  else
    GlyphsCount = v9->Data8.GlyphsCount;
  v13 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&v9->Data8.Leading + 1);
  if ( (v9->MemSize & 0x80000000) == 0 )
    v13 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&v9->Data8 + 38);
  FormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(v9);
  Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(&v27, v13, GlyphsCount, FormatData);
  for ( i = 0; ; ++i )
  {
    pGlyphs = v27.pGlyphs;
    if ( !v27.pGlyphs )
      break;
    if ( v27.pGlyphs >= v27.pEndGlyphs )
      break;
    if ( (v27.pGlyphs->LenAndFontSize & 0xF000) != 0 )
      break;
    Flags = v27.pGlyphs->Flags;
    if ( (Flags & 0x100) != 0 )
      break;
    Advance = v27.pGlyphs->Advance;
    if ( (Flags & 0x40) != 0 )
      Advance = -Advance;
    indexOfChar += Advance;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&v27);
  }
  for ( j = 0; j < v11; pGlyphs = v27.pGlyphs )
  {
    if ( !pGlyphs || pGlyphs >= v27.pEndGlyphs )
      break;
    v19 = pGlyphs->Flags;
    v20 = pGlyphs->Advance;
    if ( (v19 & 0x40) != 0 )
      v20 = -v20;
    indexOfChar += v20;
    if ( !avoidComposStr || (v19 & 4) == 0 )
      j += pGlyphs->LenAndFontSize >> 12;
    ++i;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&v27);
  }
  v25 = 0.0;
  if ( pGlyphs && pGlyphs < v27.pEndGlyphs )
  {
    if ( (pGlyphs->Flags & 0x40) != 0 )
      v29 = -pGlyphs->Advance;
    else
      v29 = pGlyphs->Advance;
    v25 = (float)v29;
  }
  v30 = (double)v9->Data32.OffsetX + (double)indexOfChar;
  v21 = v30;
  pcursorRect->x1 = v30;
  OffsetY = (float)v9->Data32.OffsetY;
  pcursorRect->y1 = OffsetY;
  v22 = v21 + v25;
  v23 = OffsetY;
  pcursorRect->x2 = v22;
  if ( (v9->MemSize & 0x80000000) == 0 )
    Height = v9->Data32.Height;
  else
    Height = v9->Data8.Height;
  pcursorRect->y2 = v23 + (double)Height;
  if ( plineIndex )
    *plineIndex = v26;
  if ( pglyphIndex )
    *pglyphIndex = i;
  if ( v27.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release(v27.pImage.pObject);
  if ( v27.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v27.pFontHandle.pObject);
  return 1;
}
