BOOL __thiscall Scaleform::Render::Matrix2x4<float>::IsFreeRotation(
        Scaleform::Render::Matrix2x4<float> *this,
        float epsilon)
{
  BOOL result; // eax
  float v3; // [esp+4h] [ebp-2Ch]
  float v4; // [esp+4h] [ebp-2Ch]
  float v5; // [esp+8h] [ebp-28h]
  float v6; // [esp+Ch] [ebp-24h]

  v5 = this->M[0][1] * 0.0 + this->M[0][0] + 0.0;
  v3 = fabs(v5);
  result = 0;
  if ( epsilon < (double)v3 )
  {
    v6 = this->M[1][1] * 0.0 + this->M[1][0] + 0.0;
    v4 = fabs(v6);
    if ( v4 > (double)epsilon )
      return 1;
  }
  return result;
}
