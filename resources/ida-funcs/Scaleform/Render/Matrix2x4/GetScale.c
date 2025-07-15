double __thiscall Scaleform::Render::Matrix2x4<float>::GetScale(Scaleform::Render::Matrix2x4<float> *this)
{
  float v2; // [esp+0h] [ebp-8h]
  float v3; // [esp+4h] [ebp-4h]
  float v4; // [esp+4h] [ebp-4h]

  v3 = this->M[0][1] * 0.7071067690849304 + this->M[0][0] * 0.7071067690849304;
  v2 = 0.7071067690849304 * this->M[1][0] + this->M[1][1] * 0.7071067690849304;
  v4 = v2 * v2 + v3 * v3;
  return (float)sqrt(v4);
}
