double __thiscall Scaleform::GFx::FontDataCompactedGfx::GetGlyphWidth(
        Scaleform::GFx::FontDataCompactedGfx *this,
        unsigned int glyphIndex)
{
  unsigned int NominalSize; // esi
  double result; // st7

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
  {
    this->GetNominalGlyphWidth(this);
  }
  else
  {
    NominalSize = this->CompactedFontValue.NominalSize;
    return (float)(Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphWidth(
                     &this->CompactedFontValue,
                     glyphIndex)
                 * 1024.0
                 / (double)NominalSize);
  }
  return result;
}
