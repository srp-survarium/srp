double __thiscall Scaleform::GFx::FontDataCompactedSwf::GetKerningAdjustment(
        Scaleform::GFx::FontDataCompactedSwf *this,
        unsigned int lastCode,
        unsigned int thisCode)
{
  return (float)(Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetKerningAdjustment(
                   &this->CompactedFontValue,
                   lastCode,
                   thisCode)
               * 1024.0
               / (double)this->CompactedFontValue.NominalSize);
}
