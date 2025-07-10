double __thiscall Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::GetXScale(
        Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float> > *this)
{
  float v2; // [esp+0h] [ebp-4h]

  v2 = this->Tr->M[1][0] * this->Tr->M[1][0] + this->Tr->M[0][0] * this->Tr->M[0][0];
  return (float)sqrt(v2);
}
