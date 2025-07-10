double __thiscall Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::GetYScale(
        Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float> > *this)
{
  float v2; // [esp+0h] [ebp-4h]

  v2 = this->Tr->M[1][1] * this->Tr->M[1][1] + this->Tr->M[0][1] * this->Tr->M[0][1];
  return (float)sqrt(v2);
}
