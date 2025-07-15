void __thiscall Scaleform::Render::Matrix3x4<float>::SetZScale(Scaleform::Render::Matrix3x4<float> *this, float s)
{
  double v2; // [esp+4h] [ebp-8h]
  float sa; // [esp+10h] [ebp+4h]
  float sb; // [esp+10h] [ebp+4h]
  float sc; // [esp+10h] [ebp+4h]

  v2 = s;
  sa = this->M[1][2] * this->M[1][2] + this->M[0][2] * this->M[0][2] + this->M[2][2] * this->M[2][2];
  sb = sqrt(sa);
  sc = v2 / sb;
  this->M[0][2] = this->M[0][2] * sc;
  this->M[1][2] = this->M[1][2] * sc;
  this->M[2][2] = sc * this->M[2][2];
}
