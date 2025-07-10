int __thiscall Scaleform::GFx::FontDataCompactedGfx::GetCharValue(
        Scaleform::GFx::FontDataCompactedGfx *this,
        unsigned int glyphIndex)
{
  if ( glyphIndex >= this->CompactedFontValue.NumGlyphs )
    return -1;
  else
    return *(unsigned __int16 *)&this->CompactedFontValue.Decoder.Data->Data[8 * glyphIndex
                                                                           + this->CompactedFontValue.GlyphInfoTablePos];
}
