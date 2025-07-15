void __thiscall Scaleform::Render::Text::LineBuffer::GlyphEntry::SetFontSize(
        Scaleform::Render::Text::LineBuffer::GlyphEntry *this,
        float fs)
{
  double v2; // st7
  int v3; // eax
  unsigned __int16 LenAndFontSize; // dx

  v2 = fs;
  if ( fs < 256.0 && (v3 = (__int64)(16.0 * v2), (v3 & 0xF) != 0) )
  {
    LenAndFontSize = this->LenAndFontSize;
    this->Flags |= 0x10u;
    this->LenAndFontSize ^= (v3 ^ LenAndFontSize) & 0xFFF;
  }
  else
  {
    this->Flags &= ~0x10u;
    this->LenAndFontSize ^= (this->LenAndFontSize ^ (int)v2) & 0xFFF;
  }
}
