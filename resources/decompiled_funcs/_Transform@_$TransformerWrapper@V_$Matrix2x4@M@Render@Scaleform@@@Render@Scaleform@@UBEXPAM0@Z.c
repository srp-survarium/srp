void __thiscall Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::Transform(
        Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float> > *this,
        float *x,
        float *y)
{
  float *Tr; // eax
  double v4; // st6
  float v5; // [esp+0h] [ebp-4h]

  Tr = (float *)this->Tr;
  v5 = *x;
  v4 = *y;
  *x = *Tr * v5 + Tr[1] * v4 + Tr[3];
  *y = v5 * Tr[4] + v4 * Tr[5] + Tr[7];
}
