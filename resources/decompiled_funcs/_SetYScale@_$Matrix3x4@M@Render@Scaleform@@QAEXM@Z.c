void __thiscall Scaleform::Render::Matrix3x4<float>::SetYScale(Scaleform::Render::Matrix3x4<float> *this, float s)
{
  double v2; // [esp+4h] [ebp-8h]
  float sa; // [esp+10h] [ebp+4h]
  float sb; // [esp+10h] [ebp+4h]
  float sc; // [esp+10h] [ebp+4h]

  v2 = s;
  sa = this->M[1][1] * this->M[1][1] + this->M[0][1] * this->M[0][1] + this->M[2][1] * this->M[2][1];
  sb = sqrt(sa);
  sc = v2 / sb;
  this->M[0][1] = this->M[0][1] * sc;
  this->M[1][1] = this->M[1][1] * sc;
  this->M[2][1] = sc * this->M[2][1];
}
