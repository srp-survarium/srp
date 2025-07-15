int __thiscall Scaleform::GFx::FontDataCompactedSwf::GetCharValue(
        Scaleform::GFx::FontDataCompactedSwf *this,
        unsigned int glyphIndex)
{
  unsigned int GlyphInfoTablePos; // edx

  if ( glyphIndex >= this->CompactedFontValue.NumGlyphs )
    return -1;
  GlyphInfoTablePos = this->CompactedFontValue.GlyphInfoTablePos;
  return this->CompactedFontValue.Decoder.Data->Pages[(GlyphInfoTablePos + 8 * glyphIndex) >> 12][(GlyphInfoTablePos
                                                                                                 + 8 * glyphIndex)
                                                                                                & 0xFFF]
       | (this->CompactedFontValue.Decoder.Data->Pages[(GlyphInfoTablePos + 8 * glyphIndex + 1) >> 12][(GlyphInfoTablePos + 8 * glyphIndex + 1) & 0xFFF] << 8);
}
