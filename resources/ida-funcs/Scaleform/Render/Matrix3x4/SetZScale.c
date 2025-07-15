void __thiscall Scaleform::Render::Matrix3x4<float>::SetZScale(Scaleform::Render::Matrix3x4<float> *this, float s)
{
  double v2; // [esp+4h] [ebp-8h]
  float v3; // [esp+10h] [ebp+4h]
  float v4; // [esp+10h] [ebp+4h]
  float v5; // [esp+10h] [ebp+4h]

  v2 = s;
  v3 = this->M[1][2] * this->M[1][2] + this->M[0][2] * this->M[0][2] + this->M[2][2] * this->M[2][2];
  v4 = sqrt(v3);
  v5 = v2 / v4;
  this->M[0][2] = this->M[0][2] * v5;
  this->M[1][2] = this->M[1][2] * v5;
  this->M[2][2] = v5 * this->M[2][2];
}
