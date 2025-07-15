int __thiscall Scaleform::GFx::FontDataCompactedGfx::GetGlyphIndex(
        Scaleform::GFx::FontDataCompactedGfx *this,
        unsigned __int16 code)
{
  return Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphIndex(
           &this->CompactedFontValue,
           code);
}
