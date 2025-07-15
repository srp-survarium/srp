void __thiscall Scaleform::Render::Matrix3x4<float>::SetXScale(Scaleform::Render::Matrix3x4<float> *this, float s)
{
  double v2; // [esp+4h] [ebp-8h]
  float v3; // [esp+10h] [ebp+4h]
  float v4; // [esp+10h] [ebp+4h]
  float v5; // [esp+10h] [ebp+4h]

  v2 = s;
  v3 = this->M[1][0] * this->M[1][0] + this->M[0][0] * this->M[0][0] + this->M[2][0] * this->M[2][0];
  v4 = sqrt(v3);
  v5 = v2 / v4;
  this->M[0][0] = this->M[0][0] * v5;
  this->M[1][0] = this->M[1][0] * v5;
  this->M[2][0] = v5 * this->M[2][0];
}
