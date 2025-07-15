double __thiscall Scaleform::Render::Text::LineBuffer::GlyphEntry::GetFontSize(
        Scaleform::Render::Text::LineBuffer::GlyphEntry *this)
{
  int v1; // eax

  v1 = this->LenAndFontSize & 0xFFF;
  if ( (this->Flags & 0x10) == 0 )
    return (double)v1;
  return (float)((double)(unsigned int)v1 * 0.0625);
}
