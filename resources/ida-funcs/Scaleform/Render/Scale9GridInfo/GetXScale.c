double __thiscall Scaleform::Render::Scale9GridInfo::GetXScale(Scaleform::Render::Scale9GridInfo *this)
{
  Scaleform::Render::Matrix2x4<float> *ResultingMatrices; // esi
  int v2; // edi
  float v4; // [esp+8h] [ebp-8h]
  float v5; // [esp+Ch] [ebp-4h]
  float v6; // [esp+Ch] [ebp-4h]

  v4 = 0.0;
  ResultingMatrices = this->ResultingMatrices;
  v2 = 3;
  do
  {
    v5 = ResultingMatrices->M[1][0] * ResultingMatrices->M[1][0]
       + ResultingMatrices->M[0][0] * ResultingMatrices->M[0][0];
    v6 = sqrt(v5);
    ++ResultingMatrices;
    --v2;
    v4 = v6 + v4;
  }
  while ( v2 );
  return (float)(v4 / 3.0);
}
