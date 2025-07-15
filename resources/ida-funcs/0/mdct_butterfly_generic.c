void __fastcall mdct_butterfly_generic(int points, float *T, float *x, unsigned int trigint)
{
  unsigned int v4; // edi
  float *v5; // eax
  float *v6; // ecx
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  float *v18; // edx
  float v19; // xmm4_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float *v23; // edx
  float v24; // xmm1_4
  float v25; // xmm3_4
  float *v26; // edx
  float v27; // xmm2_4

  v4 = trigint;
  v5 = &x[(points >> 1) - 8];
  v6 = &v5[points - (points >> 1) + 7];
  do
  {
    v7 = *v6;
    v8 = v5[6];
    v9 = *(v6 - 1);
    v10 = v9 + v8;
    v11 = v9 - v8;
    v12 = *v6 - v5[7];
    *(v6 - 1) = v10;
    *v6 = v5[7] + v7;
    v13 = v5[4];
    v5[6] = (float)(T[1] * v12) + (float)(*T * v11);
    v5[7] = (float)(*T * v12) - (float)(T[1] * v11);
    v14 = *(v6 - 2);
    v15 = *(v6 - 3);
    v16 = v14 - v5[5];
    *(v6 - 3) = v15 + v13;
    *(v6 - 2) = v14 + v5[5];
    v17 = v15 - v13;
    v18 = &T[v4];
    v5[4] = (float)(v18[1] * v16) + (float)(*v18 * v17);
    v5[5] = (float)(*v18 * v16) - (float)(v18[1] * v17);
    v19 = *(v6 - 4);
    v20 = v5[2];
    v21 = *(v6 - 5) - v20;
    v22 = v19 - v5[3];
    *(v6 - 5) = v20 + *(v6 - 5);
    *(v6 - 4) = v5[3] + v19;
    v23 = &v18[v4];
    v5[2] = (float)(v23[1] * v22) + (float)(*v23 * v21);
    v5[3] = (float)(*v23 * v22) - (float)(v23[1] * v21);
    v24 = *(v6 - 6);
    v25 = v24 - v5[1];
    v26 = &v23[v4];
    v27 = *(v6 - 7) - *v5;
    *(v6 - 7) = *v5 + *(v6 - 7);
    *(v6 - 6) = v24 + v5[1];
    *v5 = (float)(v26[1] * v25) + (float)(*v26 * v27);
    v5[1] = (float)(*v26 * v25) - (float)(v26[1] * v27);
    v5 -= 8;
    T = &v26[v4];
    v6 -= 8;
  }
  while ( v5 >= x );
}
