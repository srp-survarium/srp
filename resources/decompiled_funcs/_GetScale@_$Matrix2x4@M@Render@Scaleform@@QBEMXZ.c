double __thiscall Scaleform::Render::Matrix2x4<float>::GetScale(Scaleform::Render::Matrix2x4<float> *this)
{
  float y; // [esp+0h] [ebp-8h]
  float x; // [esp+4h] [ebp-4h]
  float xa; // [esp+4h] [ebp-4h]

  x = this->M[0][1] * 0.7071067690849304 + this->M[0][0] * 0.7071067690849304;
  y = 0.7071067690849304 * this->M[1][0] + this->M[1][1] * 0.7071067690849304;
  xa = y * y + x * x;
  return (float)sqrt(xa);
}
