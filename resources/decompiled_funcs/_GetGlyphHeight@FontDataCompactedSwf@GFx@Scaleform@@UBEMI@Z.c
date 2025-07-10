double __thiscall Scaleform::GFx::FontDataCompactedSwf::GetGlyphHeight(
        Scaleform::GFx::FontDataCompactedSwf *this,
        unsigned int glyphIndex)
{
  unsigned int NominalSize; // esi
  double result; // st7

  if ( (unsigned __int16)glyphIndex == 0xFFFF || glyphIndex >= this->CompactedFontValue.NumGlyphs )
  {
    this->GetNominalGlyphHeight(this);
  }
  else
  {
    NominalSize = this->CompactedFontValue.NominalSize;
    return (float)(Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphHeight(
                     &this->CompactedFontValue,
                     glyphIndex)
                 * 1024.0
                 / (double)NominalSize);
  }
  return result;
}
