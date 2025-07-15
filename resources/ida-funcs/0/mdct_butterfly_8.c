void __usercall mdct_butterfly_8(float *x@<eax>)
{
  float v1; // xmm1_4
  float v2; // xmm6_4
  float v3; // xmm7_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm5_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // [esp+0h] [ebp-4h]

  v1 = x[6];
  v2 = x[5];
  v3 = x[7];
  v4 = x[2] + v1;
  v5 = v1 - x[2];
  v6 = x[4];
  v7 = *x + v6;
  v8 = x[3];
  v18 = v6 - *x;
  v9 = v7 + v4;
  v10 = v4 - v7;
  v11 = x[1];
  x[4] = v10;
  x[6] = v9;
  v12 = v5;
  v13 = v2 - v11;
  x[2] = v5 - (float)(v2 - v11);
  v14 = v18 + (float)(v3 - v8);
  v15 = (float)(v3 - v8) - v18;
  v16 = v8 + v3;
  x[1] = v15;
  v17 = v11 + v2;
  *x = v12 + v13;
  x[3] = v14;
  x[7] = v16 + v17;
  x[5] = v16 - v17;
}
