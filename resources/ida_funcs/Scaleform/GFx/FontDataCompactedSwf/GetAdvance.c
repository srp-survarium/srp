double __thiscall Scaleform::GFx::FontDataCompactedSwf::GetAdvance(
        Scaleform::GFx::FontDataCompactedSwf *this,
        unsigned int glyphIndex)
{
  double result; // st7

  if ( (unsigned __int16)glyphIndex == 0xFFFF || glyphIndex >= this->CompactedFontValue.NumGlyphs )
    this->GetNominalGlyphWidth(this);
  else
    return (float)(Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetAdvance(
                     &this->CompactedFontValue,
                     glyphIndex)
                 * 1024.0
                 / (double)this->CompactedFontValue.NominalSize);
  return result;
}
