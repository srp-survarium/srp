double __thiscall Scaleform::Render::Scale9GridInfo::GetScale(Scaleform::Render::Scale9GridInfo *this)
{
  float *v1; // esi
  int v2; // edi
  float scale; // [esp+8h] [ebp-Ch]
  float v5; // [esp+Ch] [ebp-8h]
  float v6; // [esp+10h] [ebp-4h]
  float v7; // [esp+10h] [ebp-4h]
  float v8; // [esp+10h] [ebp-4h]

  scale = 0.0;
  v1 = &this->ResultingMatrices[0].M[1][1];
  v2 = 9;
  do
  {
    v6 = *(v1 - 5) * 0.7071067690849304 + *(v1 - 4) * 0.7071067690849304;
    v5 = 0.7071067690849304 * *v1 + *(v1 - 1) * 0.7071067690849304;
    v7 = v5 * v5 + v6 * v6;
    v8 = sqrt(v7);
    v1 += 8;
    --v2;
    scale = v8 + scale;
  }
  while ( v2 );
  return (float)(scale / 9.0);
}
