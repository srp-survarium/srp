bool __thiscall Scaleform::Render::Text::LineBuffer::Line::HasNewLine(Scaleform::Render::Text::LineBuffer::Line *this)
{
  unsigned int GlyphsCount; // edx
  char *v2; // eax

  if ( (this->MemSize & 0x80000000) == 0 )
    GlyphsCount = this->Data32.GlyphsCount;
  else
    GlyphsCount = this->Data8.GlyphsCount;
  if ( !GlyphsCount )
    return 0;
  v2 = &this->Data8.Leading + 1;
  if ( (this->MemSize & 0x80000000) == 0 )
    v2 = (char *)&this->Data8 + 38;
  return (v2[8 * GlyphsCount - 1] & 1) != 0 && (*(_WORD *)&v2[8 * GlyphsCount - 4] & 0xF000) != 0;
}
