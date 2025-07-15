void __thiscall btSoftBody::updateNormals(btSoftBody *this, _DWORD *a2)
{
  int v2; // ecx
  int v3; // eax
  int v4; // edx
  _DWORD *v5; // edi
  int v6; // ecx
  float *v7; // eax
  float *v8; // edx
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm5_4
  float *v12; // edx
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm6_4
  float v17; // xmm4_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float *v21; // eax
  float *v22; // ecx
  bool v23; // zf
  float v24; // xmm2_4
  float v25; // xmm1_4
  int v26; // ecx
  int v27; // edx
  float *v28; // eax
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  int v33; // [esp+Ch] [ebp-18h]
  int v34; // [esp+10h] [ebp-14h]

  v2 = a2[180];
  if ( v2 > 0 )
  {
    v3 = 0;
    do
    {
      v4 = a2[182];
      *(_DWORD *)(v3 + v4 + 80) = 0;
      *(_DWORD *)(v3 + v4 + 84) = 0;
      *(_DWORD *)(v3 + v4 + 88) = 0;
      v5 = (_DWORD *)(v3 + v4 + 92);
      v3 += 112;
      --v2;
      *v5 = 0;
    }
    while ( v2 );
  }
  if ( (int)a2[190] > 0 )
  {
    v33 = 0;
    v34 = a2[190];
    do
    {
      v6 = v33 + a2[192];
      v7 = *(float **)(v6 + 8);
      v8 = *(float **)(v6 + 16);
      v9 = v8[6] - v7[6];
      v10 = v8[5] - v7[5];
      v11 = v8[4];
      v12 = *(float **)(v6 + 12);
      v13 = v11 - v7[4];
      v14 = v12[5] - v7[5];
      v15 = v12[6] - v7[6];
      v16 = v12[4] - v7[4];
      v17 = (float)(v14 * v9) - (float)(v15 * v10);
      v18 = (float)(v15 * v13) - (float)(v9 * v16);
      v19 = (float)(v10 * v16) - (float)(v14 * v13);
      v20 = s_bm_current_air_resistance / fsqrt((float)((float)(v19 * v19) + (float)(v18 * v18)) + (float)(v17 * v17));
      *(float *)(v6 + 32) = v17 * v20;
      *(float *)(v6 + 36) = v18 * v20;
      *(float *)(v6 + 40) = v19 * v20;
      *(_DWORD *)(v6 + 44) = 0;
      v7[20] = v7[20] + v17;
      v7[21] = v7[21] + v18;
      v7[22] = v7[22] + v19;
      v21 = (float *)(*(_DWORD *)(v6 + 12) + 80);
      *v21 = *v21 + v17;
      v21[1] = v21[1] + v18;
      v21[2] = v21[2] + v19;
      v22 = (float *)(*(_DWORD *)(v6 + 16) + 80);
      *v22 = *v22 + v17;
      v33 += 64;
      v23 = v34-- == 1;
      v24 = v22[1] + v18;
      v25 = v22[2] + v19;
      v22[1] = v24;
      v22[2] = v25;
    }
    while ( !v23 );
  }
  if ( (int)a2[180] > 0 )
  {
    v26 = 0;
    v27 = a2[180];
    do
    {
      v28 = (float *)(v26 + a2[182] + 80);
      v29 = *(float *)(v26 + a2[182] + 88);
      v30 = *(float *)(v26 + a2[182] + 84);
      v31 = fsqrt((float)((float)(*v28 * *v28) + (float)(v30 * v30)) + (float)(v29 * v29));
      if ( v31 > 0.00000011920929 )
      {
        v32 = s_bm_current_air_resistance / v31;
        *v28 = *v28 * (float)(s_bm_current_air_resistance / v31);
        v28[1] = v28[1] * v32;
        v28[2] = v28[2] * v32;
      }
      v26 += 112;
      --v27;
    }
    while ( v27 );
  }
}
