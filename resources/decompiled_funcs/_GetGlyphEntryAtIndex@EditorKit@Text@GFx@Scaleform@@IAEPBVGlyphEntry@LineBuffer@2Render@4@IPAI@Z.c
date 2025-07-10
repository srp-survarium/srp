const Scaleform::Render::Text::LineBuffer::GlyphEntry *__thiscall Scaleform::GFx::Text::EditorKit::GetGlyphEntryAtIndex(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned int charIndex,
        unsigned int *ptextPos)
{
  unsigned int LineIndexOfChar; // eax
  Scaleform::Render::Text::LineBuffer::Line *Line; // eax
  int TextPos; // ecx
  unsigned int v7; // ebp
  unsigned int GlyphsCount; // edi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v9; // esi
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *FormatData; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v11; // ebx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // eax
  int v13; // esi
  unsigned int v14; // edi
  Scaleform::Render::Text::LineBuffer::GlyphIterator git; // [esp+8h] [ebp-60h] BYREF
  unsigned int posInLine; // [esp+6Ch] [ebp+4h]

  LineIndexOfChar = Scaleform::Render::Text::DocView::GetLineIndexOfChar(this->pDocView.pObject, charIndex);
  if ( LineIndexOfChar == -1 )
    return 0;
  Line = (Scaleform::Render::Text::LineBuffer::Line *)Scaleform::Render::Text::LineBuffer::GetLine(
                                                        &this->pDocView.pObject->mLineBuffer,
                                                        LineIndexOfChar);
  if ( !Line )
    return 0;
  TextPos = Line->Data32.TextPos;
  if ( (Line->MemSize & 0x80000000) != 0 )
  {
    TextPos &= (unsigned int)&vostok::memory::s_CRT_arena[5574199];
    if ( (unsigned __int8 *)TextPos == &vostok::memory::s_CRT_arena[5574199] )
      TextPos = -1;
  }
  v7 = TextPos;
  posInLine = charIndex - TextPos;
  if ( (Line->MemSize & 0x80000000) == 0 )
    GlyphsCount = Line->Data32.GlyphsCount;
  else
    GlyphsCount = Line->Data8.GlyphsCount;
  v9 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&Line->Data8.Leading + 1);
  if ( (Line->MemSize & 0x80000000) == 0 )
    v9 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&Line->Data8 + 38);
  FormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(Line);
  Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(&git, v9, GlyphsCount, FormatData);
  v11 = 0;
  while ( 1 )
  {
    pGlyphs = git.pGlyphs;
    if ( !git.pGlyphs
      || git.pGlyphs >= git.pEndGlyphs
      || (git.pGlyphs->LenAndFontSize & 0xF000) != 0
      || (git.pGlyphs->Flags & 0x100) != 0 )
    {
      break;
    }
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&git);
  }
  v13 = 0;
  v14 = 0;
  while ( 1 )
  {
    v7 += v13;
    if ( !pGlyphs )
      break;
    if ( pGlyphs >= git.pEndGlyphs )
      break;
    v13 = pGlyphs->LenAndFontSize >> 12;
    v11 = pGlyphs;
    v14 += v13;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&git);
    if ( v14 > posInLine )
      break;
    pGlyphs = git.pGlyphs;
  }
  if ( ptextPos )
    *ptextPos = v7;
  if ( git.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release(git.pImage.pObject);
  if ( git.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)git.pFontHandle.pObject);
  return v11;
}
