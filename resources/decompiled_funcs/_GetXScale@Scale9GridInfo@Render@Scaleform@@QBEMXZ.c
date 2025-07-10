double __thiscall Scaleform::Render::Scale9GridInfo::GetXScale(Scaleform::Render::Scale9GridInfo *this)
{
  Scaleform::Render::Matrix2x4<float> *ResultingMatrices; // esi
  int v2; // edi
  float scale; // [esp+8h] [ebp-8h]
  float v5; // [esp+Ch] [ebp-4h]
  float v6; // [esp+Ch] [ebp-4h]

  scale = 0.0;
  ResultingMatrices = this->ResultingMatrices;
  v2 = 3;
  do
  {
    v5 = ResultingMatrices->M[1][0] * ResultingMatrices->M[1][0]
       + ResultingMatrices->M[0][0] * ResultingMatrices->M[0][0];
    v6 = sqrt(v5);
    ++ResultingMatrices;
    --v2;
    scale = v6 + scale;
  }
  while ( v2 );
  return (float)(scale / 3.0);
}
