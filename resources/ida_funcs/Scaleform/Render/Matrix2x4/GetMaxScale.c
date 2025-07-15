double __thiscall Scaleform::Render::Matrix2x4<float>::GetMaxScale(Scaleform::Render::Matrix2x4<float> *this)
{
  double v1; // st7
  float basis1Length2; // [esp+0h] [ebp-8h]
  float basis1Length2a; // [esp+0h] [ebp-8h]
  float basis0Length2; // [esp+4h] [ebp-4h]

  basis0Length2 = this->M[1][0] * this->M[1][0] + this->M[0][0] * this->M[0][0];
  basis1Length2 = this->M[1][1] * this->M[1][1] + this->M[0][1] * this->M[0][1];
  v1 = basis1Length2;
  if ( basis0Length2 > (double)basis1Length2 )
    v1 = basis0Length2;
  basis1Length2a = v1;
  return (float)sqrt(basis1Length2a);
}
