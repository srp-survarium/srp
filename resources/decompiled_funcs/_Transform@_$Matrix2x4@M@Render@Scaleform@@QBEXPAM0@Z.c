void __thiscall Scaleform::Render::Matrix2x4<float>::Transform(
        Scaleform::Render::Matrix2x4<float> *this,
        float *x,
        float *y)
{
  double v3; // st6
  float tx; // [esp+0h] [ebp-4h]

  tx = *x;
  v3 = *y;
  *x = this->M[0][0] * tx + this->M[0][1] * v3 + this->M[0][3];
  *y = tx * this->M[1][0] + v3 * this->M[1][1] + this->M[1][3];
}
