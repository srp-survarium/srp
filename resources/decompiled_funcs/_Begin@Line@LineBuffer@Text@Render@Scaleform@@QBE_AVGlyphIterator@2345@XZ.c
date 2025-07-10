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
