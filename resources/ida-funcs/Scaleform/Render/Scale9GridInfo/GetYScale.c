double __thiscall Scaleform::Render::Scale9GridInfo::GetYScale(Scaleform::Render::Scale9GridInfo *this)
{
  float *v1; // esi
  int v2; // edi
  float v4; // [esp+8h] [ebp-8h]
  float v5; // [esp+Ch] [ebp-4h]
  float v6; // [esp+Ch] [ebp-4h]

  v4 = 0.0;
  v1 = &this->ResultingMatrices[0].M[0][1];
  v2 = 3;
  do
  {
    v5 = v1[4] * v1[4] + *v1 * *v1;
    v6 = sqrt(v5);
    v1 += 24;
    --v2;
    v4 = v6 + v4;
  }
  while ( v2 );
  return (float)(v4 / 3.0);
}
