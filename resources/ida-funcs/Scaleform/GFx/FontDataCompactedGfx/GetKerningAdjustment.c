double __thiscall Scaleform::GFx::FontDataCompactedGfx::GetKerningAdjustment(
        Scaleform::GFx::FontDataCompactedGfx *this,
        unsigned int lastCode,
        unsigned int thisCode)
{
  return (float)(Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::GetKerningAdjustment(
                   &this->CompactedFontValue,
                   lastCode,
                   thisCode)
               * 1024.0
               / (double)this->CompactedFontValue.NominalSize);
}
