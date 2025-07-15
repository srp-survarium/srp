void __thiscall Scaleform::Render::Text::LineBuffer::Line::Release(Scaleform::Render::Text::LineBuffer::Line *this)
{
  bool v2; // al
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v3; // edi
  unsigned int GlyphsCount; // edx
  char *v5; // ecx
  unsigned int v6; // eax

  if ( (this->MemSize & 0x40000000) != 0 )
  {
    v2 = (this->MemSize & 0x80000000) != 0;
    v3 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&this->Data8.Leading + 1);
    if ( (this->MemSize & 0x80000000) != 0 )
    {
      GlyphsCount = this->Data8.GlyphsCount;
    }
    else
    {
      v3 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&this->Data8 + 38);
      GlyphsCount = this->Data32.GlyphsCount;
    }
    v5 = &this->Data8.Leading + 1;
    if ( v2 )
    {
      v6 = this->Data8.GlyphsCount;
    }
    else
    {
      v6 = this->Data32.GlyphsCount;
      v5 = (char *)&this->Data8 + 38;
    }
    Scaleform::Render::Text::LineBuffer::ReleasePartOfLine(
      v3,
      GlyphsCount,
      (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((unsigned int)&v5[8 * v6 + 3] & 0xFFFFFFFC));
    if ( (this->MemSize & 0x80000000) == 0 )
      this->Data32.GlyphsCount = 0;
    else
      this->Data8.GlyphsCount = 0;
  }
}
