Scaleform::Render::Text::LineBuffer::FormatDataEntry *__thiscall Scaleform::Render::Text::LineBuffer::Line::GetFormatData(
        Scaleform::Render::Text::LineBuffer::Line *this)
{
  char *v1; // edx
  unsigned int GlyphsCount; // ecx

  v1 = &this->Data8.Leading + 1;
  if ( (this->MemSize & 0x80000000) != 0 )
  {
    GlyphsCount = this->Data8.GlyphsCount;
  }
  else
  {
    v1 = (char *)&this->Data8 + 38;
    GlyphsCount = this->Data32.GlyphsCount;
  }
  return (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((unsigned int)&v1[8 * GlyphsCount + 3] & 0xFFFFFFFC);
}
