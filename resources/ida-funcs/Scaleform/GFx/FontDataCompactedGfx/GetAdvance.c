double __thiscall Scaleform::GFx::FontDataCompactedGfx::GetAdvance(
        Scaleform::GFx::FontDataCompactedGfx *this,
        unsigned int glyphIndex)
{
  unsigned __int8 *v2; // eax
  double result; // st7

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
  {
    this->GetNominalGlyphWidth(this);
  }
  else
  {
    v2 = &this->CompactedFontValue.Decoder.Data->Data[8 * glyphIndex + 2 + this->CompactedFontValue.GlyphInfoTablePos];
    return (float)((double)(*v2 | (unsigned int)(__int16)(v2[1] << 8))
                 * 1024.0
                 / (double)this->CompactedFontValue.NominalSize);
  }
  return result;
}
