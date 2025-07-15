double __thiscall Scaleform::Render::Matrix2x4<float>::GetMaxScale(Scaleform::Render::Matrix2x4<float> *this)
{
  double v1; // st7
  float v3; // [esp+0h] [ebp-8h]
  float v4; // [esp+0h] [ebp-8h]
  float v5; // [esp+4h] [ebp-4h]

  v5 = this->M[1][0] * this->M[1][0] + this->M[0][0] * this->M[0][0];
  v3 = this->M[1][1] * this->M[1][1] + this->M[0][1] * this->M[0][1];
  v1 = v3;
  if ( v5 > (double)v3 )
    v1 = v5;
  v4 = v1;
  return (float)sqrt(v4);
}
