char __cdecl Scaleform::Render::MeshKey::CalcMatrixKey_NonOpt(
        const Scaleform::Render::Matrix2x4<float> *m,
        float *key,
        Scaleform::Render::Matrix2x4<float> *m2)
{
  double v3; // st7
  double v4; // st6
  double v6; // st6
  double v7; // st4
  int v8; // edx
  unsigned int v9; // ecx
  double v10; // st6
  double v11; // st7
  float h; // [esp+18h] [ebp-38h]
  float ha; // [esp+18h] [ebp-38h]
  float y2; // [esp+1Ch] [ebp-34h]
  float x2; // [esp+20h] [ebp-30h]
  float w; // [esp+24h] [ebp-2Ch]
  float wa; // [esp+24h] [ebp-2Ch]
  float wb; // [esp+24h] [ebp-2Ch]
  float wc; // [esp+24h] [ebp-2Ch]
  float d3; // [esp+28h] [ebp-28h]
  float maxLen; // [esp+2Ch] [ebp-24h]
  float maxLena; // [esp+2Ch] [ebp-24h]
  float p[8]; // [esp+30h] [ebp-20h] BYREF
  float d2; // [esp+54h] [ebp+4h]
  float d2a; // [esp+54h] [ebp+4h]
  float d2b; // [esp+54h] [ebp+4h]
  float d2c; // [esp+54h] [ebp+4h]
  float d2d; // [esp+54h] [ebp+4h]

  x2 = m->M[0][0];
  y2 = m->M[1][0];
  w = m->M[0][1];
  h = m->M[1][1];
  d2 = y2 * y2 + x2 * x2;
  d3 = h * h + w * w;
  if ( d2 == 0.0 || 0.0 == d3 )
    return 0;
  maxLen = sqrt(d2);
  v3 = h;
  v4 = w;
  wa = (h - y2) * x2 - (w - x2) * y2;
  wb = fabs(wa);
  ha = wb / maxLen;
  if ( ha < 0.0000000099999999 )
    return 0;
  wc = (v4 * x2 + y2 * v3) * maxLen / d2;
  *key = maxLen;
  d2a = sqrt(d3);
  key[1] = d2a;
  v6 = wc;
  if ( wc < 0.0 )
    v7 = ha / (ha - v6);
  else
    v7 = v6 / ha + 1.0;
  key[2] = v7;
  if ( !m2 )
    return 1;
  p[0] = 0.0;
  p[6] = 0.0;
  p[1] = 0.0;
  p[7] = 0.0;
  p[2] = maxLen;
  p[3] = 0.0;
  p[4] = maxLen + v6;
  p[5] = ha;
  Scaleform::Render::Matrix2x4<float>::SetRectToParl(m2, 0.0, 0.0, 1.0, 1.0, p);
  v8 = 4;
  p[0] = 1.0;
  v9 = 0;
  p[1] = 0.0;
  p[2] = 0.70710677;
  p[3] = 0.70710677;
  p[4] = 0.0;
  p[5] = 1.05;
  p[6] = -0.70710677;
  p[7] = 0.70710677;
  maxLena = 0.0;
  do
  {
    v10 = p[v9 + 1];
    v11 = p[v9];
    p[v9] = m2->M[0][1] * v10 + v11 * m2->M[0][0];
    p[v9 + 1] = v11 * m2->M[1][0] + v10 * m2->M[1][1];
    d2b = p[v9 + 1] * p[v9 + 1] + p[v9] * p[v9];
    if ( maxLena < (double)d2b )
    {
      maxLena = p[v9 + 1] * p[v9 + 1] + p[v9] * p[v9];
      v8 = v9;
    }
    v9 += 2;
  }
  while ( v9 < 8 );
  d2c = atan2(p[v8 + 1], p[v8]);
  d2d = 1.570796370506287 - d2c;
  Scaleform::Render::Matrix2x4<float>::AppendRotation(m2, d2d);
  return 1;
}
