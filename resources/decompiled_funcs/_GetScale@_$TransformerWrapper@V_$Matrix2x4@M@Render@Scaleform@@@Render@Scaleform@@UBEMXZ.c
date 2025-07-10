double __thiscall Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::GetScale(
        Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float> > *this)
{
  float *Tr; // eax
  float v3; // [esp+0h] [ebp-8h]
  float v4; // [esp+4h] [ebp-4h]
  float v5; // [esp+4h] [ebp-4h]

  Tr = (float *)this->Tr;
  v4 = Tr[1] * 0.7071067690849304 + *Tr * 0.7071067690849304;
  v3 = 0.7071067690849304 * Tr[4] + Tr[5] * 0.7071067690849304;
  v5 = v3 * v3 + v4 * v4;
  return (float)sqrt(v5);
}
