void __usercall mdct_bitreverse(mdct_lookup *init@<eax>, float *x@<ecx>)
{
  int *bitrev; // esi
  float *v3; // edi
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  float v7; // xmm1_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm7_4
  float v18; // xmm3_4
  float v19; // xmm5_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // [esp+0h] [ebp-10h]
  float *v23; // [esp+8h] [ebp-8h]
  float *v24; // [esp+8h] [ebp-8h]
  float *v25; // [esp+Ch] [ebp-4h]
  float *v26; // [esp+Ch] [ebp-4h]

  bitrev = init->bitrev;
  v3 = x;
  v4 = &x[init->n >> 1];
  v5 = &init->trig[init->n];
  v6 = v4 + 3;
  do
  {
    v25 = &v4[*bitrev];
    v23 = &v4[bitrev[1]];
    v7 = v23[1];
    v8 = v25[1] - v7;
    v9 = v5[1];
    v10 = (float)(v9 * (float)(*v25 + *v23)) - (float)(*v5 * v8);
    v11 = *v25 - *v23;
    v12 = (float)(*v5 * (float)(*v25 + *v23)) + (float)(v9 * v8);
    v13 = (float)(v7 + v25[1]) * 0.5;
    *v3 = v12 + v13;
    *(v6 - 5) = v13 - v12;
    v6 -= 4;
    v14 = v11 * 0.5;
    v3[1] = v10 + v14;
    *v6 = v10 - v14;
    v15 = v5[2];
    v26 = &v4[bitrev[2]];
    v24 = &v4[bitrev[3]];
    v16 = v24[1];
    v17 = *v26 + *v24;
    v22 = v26[1] - v16;
    v18 = (float)(v5[3] * v17) - (float)(v15 * v22);
    v19 = (float)(v5[3] * v22) + (float)(v15 * v17);
    v20 = (float)(v16 + v26[1]) * 0.5;
    v21 = (float)(*v26 - *v24) * 0.5;
    v3[2] = v19 + v20;
    *(v6 - 3) = v20 - v19;
    v3[3] = v18 + v21;
    v3 += 4;
    v5 += 4;
    bitrev += 4;
    *(v6 - 2) = v18 - v21;
  }
  while ( v3 < v6 - 3 );
}
