long double __thiscall Scaleform::Render::Matrix2x4<float>::GetYScale(Scaleform::Render::Matrix2x4<float> *this)
{
  return sqrt(this->M[1][1] * this->M[1][1] + this->M[0][1] * this->M[0][1]);
}
