Scaleform::Render::GradientRecord *__thiscall Scaleform::Render::GradientRecord::LerpTo(
        Scaleform::Render::GradientRecord *this,
        Scaleform::Render::GradientRecord *result,
        const Scaleform::Render::GradientRecord *r2,
        float ratio)
{
  unsigned int Raw; // edx
  Scaleform::Render::GradientRecord *v6; // eax
  float v7; // [esp+Ch] [ebp-8h]
  Scaleform::Render::Color resulta; // [esp+10h] [ebp-4h] BYREF

  Scaleform::Render::Color::Blend(&resulta, this->ColorV, r2->ColorV, ratio);
  Raw = resulta.Raw;
  v7 = (float)this->Ratio;
  v6 = result;
  result->Ratio = (int)(((double)r2->Ratio - v7) * ratio + v7);
  result->ColorV.Raw = Raw;
  return v6;
}
