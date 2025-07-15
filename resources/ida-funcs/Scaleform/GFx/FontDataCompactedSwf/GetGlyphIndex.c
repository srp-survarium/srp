int __thiscall Scaleform::GFx::FontDataCompactedSwf::GetGlyphIndex(
        Scaleform::GFx::FontDataCompactedSwf *this,
        unsigned __int16 code)
{
  return Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphIndex(
           &this->CompactedFontValue,
           code);
}
