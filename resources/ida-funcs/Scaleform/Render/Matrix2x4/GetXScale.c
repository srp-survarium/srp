long double __thiscall Scaleform::Render::Matrix2x4<float>::GetXScale(Scaleform::Render::Matrix2x4<float> *this)
{
  return sqrt(this->M[1][0] * this->M[1][0] + this->M[0][0] * this->M[0][0]);
}
