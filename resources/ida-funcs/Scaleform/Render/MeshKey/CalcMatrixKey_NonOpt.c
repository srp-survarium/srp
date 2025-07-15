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
  float v12; // [esp+18h] [ebp-38h]
  float v13; // [esp+18h] [ebp-38h]
  float v14; // [esp+1Ch] [ebp-34h]
  float v15; // [esp+20h] [ebp-30h]
  float v16; // [esp+24h] [ebp-2Ch]
  float v17; // [esp+24h] [ebp-2Ch]
  float v18; // [esp+24h] [ebp-2Ch]
  float v19; // [esp+24h] [ebp-2Ch]
  float v20; // [esp+28h] [ebp-28h]
  float v21; // [esp+2Ch] [ebp-24h]
  float v22; // [esp+2Ch] [ebp-24h]
  float v23; // [esp+30h] [ebp-20h] BYREF
  float v24; // [esp+34h] [ebp-1Ch]
  float v25; // [esp+38h] [ebp-18h]
  float v26; // [esp+3Ch] [ebp-14h]
  float v27; // [esp+40h] [ebp-10h]
  float v28; // [esp+44h] [ebp-Ch]
  float v29; // [esp+48h] [ebp-8h]
  float v30; // [esp+4Ch] [ebp-4h]
  float v31; // [esp+54h] [ebp+4h]
  float v32; // [esp+54h] [ebp+4h]
  float v33; // [esp+54h] [ebp+4h]
  float v34; // [esp+54h] [ebp+4h]
  float radians; // [esp+54h] [ebp+4h]

  v15 = m->M[0][0];
  v14 = m->M[1][0];
  v16 = m->M[0][1];
  v12 = m->M[1][1];
  v31 = v14 * v14 + v15 * v15;
  v20 = v12 * v12 + v16 * v16;
  if ( v31 == 0.0 || 0.0 == v20 )
    return 0;
  v21 = sqrt(v31);
  v3 = v12;
  v4 = v16;
  v17 = (v12 - v14) * v15 - (v16 - v15) * v14;
  v18 = fabs(v17);
  v13 = v18 / v21;
  if ( v13 < 0.0000000099999999 )
    return 0;
  v19 = (v4 * v15 + v14 * v3) * v21 / v31;
  *key = v21;
  v32 = sqrt(v20);
  key[1] = v32;
  v6 = v19;
  if ( v19 < 0.0 )
    v7 = v13 / (v13 - v6);
  else
    v7 = v6 / v13 + 1.0;
  key[2] = v7;
  if ( !m2 )
    return 1;
  v23 = 0.0;
  v29 = 0.0;
  v24 = 0.0;
  v30 = 0.0;
  v25 = v21;
  v26 = 0.0;
  v27 = v21 + v6;
  v28 = v13;
  Scaleform::Render::Matrix2x4<float>::SetRectToParl(m2, 0.0, 0.0, 1.0, 1.0, &v23);
  v8 = 4;
  v23 = 1.0;
  v9 = 0;
  v24 = 0.0;
  v25 = 0.70710677;
  v26 = 0.70710677;
  v27 = 0.0;
  v28 = 1.05;
  v29 = -0.70710677;
  v30 = 0.70710677;
  v22 = 0.0;
  do
  {
    v10 = *(&v24 + v9);
    v11 = *(&v23 + v9);
    *(&v23 + v9) = m2->M[0][1] * v10 + v11 * m2->M[0][0];
    *(&v24 + v9) = v11 * m2->M[1][0] + v10 * m2->M[1][1];
    v33 = *(&v24 + v9) * *(&v24 + v9) + *(&v23 + v9) * *(&v23 + v9);
    if ( v22 < (double)v33 )
    {
      v22 = *(&v24 + v9) * *(&v24 + v9) + *(&v23 + v9) * *(&v23 + v9);
      v8 = v9;
    }
    v9 += 2;
  }
  while ( v9 < 8 );
  v34 = atan2(*(&v24 + v8), *(&v23 + v8));
  radians = 1.570796370506287 - v34;
  Scaleform::Render::Matrix2x4<float>::AppendRotation(m2, radians);
  return 1;
}
