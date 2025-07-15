Scaleform::Render::Text::LineBuffer::GlyphIterator *__thiscall Scaleform::Render::Text::LineBuffer::Line::Begin(
        Scaleform::Render::Text::LineBuffer::Line *this,
        Scaleform::Render::Text::LineBuffer::GlyphIterator *result,
        Scaleform::Render::Text::Highlighter *phighlighter)
{
  unsigned int TextPos; // ebx
  char *v4; // esi
  unsigned int GlyphsCount; // eax
  char *v6; // esi
  unsigned int v7; // edi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v8; // ecx

  if ( phighlighter )
  {
    if ( (this->MemSize & 0x80000000) == 0 )
    {
      TextPos = this->Data32.TextPos;
    }
    else if ( (unsigned __int8 *)((unsigned int)&vostok::memory::s_CRT_arena[5574199] & this->Data32.TextPos) == &vostok::memory::s_CRT_arena[5574199] )
    {
      TextPos = -1;
    }
    else
    {
      TextPos = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & this->Data32.TextPos;
    }
    v4 = &this->Data8.Leading + 1;
    if ( (this->MemSize & 0x80000000) != 0 )
    {
      GlyphsCount = this->Data8.GlyphsCount;
    }
    else
    {
      GlyphsCount = this->Data32.GlyphsCount;
      v4 = (char *)&this->Data8 + 38;
    }
    v6 = &v4[8 * GlyphsCount];
    if ( (this->MemSize & 0x80000000) == 0 )
      v7 = this->Data32.GlyphsCount;
    else
      v7 = this->Data8.GlyphsCount;
    if ( (this->MemSize & 0x80000000) == 0 )
      v8 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&this->Data8 + 38);
    else
      v8 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&this->Data8.Leading + 1);
    Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(
      result,
      v8,
      v7,
      (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((unsigned int)(v6 + 3) & 0xFFFFFFFC),
      phighlighter,
      TextPos);
    return result;
  }
  else
  {
    Scaleform::Render::Text::LineBuffer::Line::Begin(this, result);
    return result;
  }
}


Scaleform::Render::Text::LineBuffer::GlyphIterator *__thiscall Scaleform::Render::Text::LineBuffer::Line::Begin(
        Scaleform::Render::Text::LineBuffer::Line *this,
        Scaleform::Render::Text::LineBuffer::GlyphIterator *result)
{
  unsigned int GlyphsCount; // edi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v3; // esi
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *FormatData; // eax

  if ( (this->MemSize & 0x80000000) == 0 )
    GlyphsCount = this->Data32.GlyphsCount;
  else
    GlyphsCount = this->Data8.GlyphsCount;
  v3 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&this->Data8.Leading + 1);
  if ( (this->MemSize & 0x80000000) == 0 )
    v3 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&this->Data8 + 38);
  FormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(this);
  Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(result, v3, GlyphsCount, FormatData);
  return result;
}
