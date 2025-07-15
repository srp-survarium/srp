void __usercall mdct_butterfly_16(float *x@<eax>)
{
  float v1; // xmm1_4
  float v2; // xmm6_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm2_4
  float v18; // xmm6_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm2_4
  float v23; // xmm5_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v26; // xmm4_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float *v30; // ecx

  v1 = x[9];
  v2 = x[10];
  v3 = x[1] - v1;
  v4 = v1 + x[1];
  v5 = x[8];
  v6 = *x - v5;
  v7 = x[3];
  x[8] = v5 + *x;
  v8 = v6 + v3;
  x[9] = v4;
  v9 = hsqt2;
  v10 = (float)(v3 - v6) * hsqt2;
  *x = v8 * hsqt2;
  v11 = x[2];
  x[1] = v10;
  v12 = x[11];
  v13 = v7 - v12;
  v14 = v12 + v7;
  v15 = x[12];
  v16 = v2 - v11;
  v17 = v11 + v2;
  v18 = x[13];
  x[10] = v17;
  v19 = x[4];
  x[11] = v14;
  x[3] = v16;
  x[2] = v13;
  v20 = x[5];
  v21 = v15 - v19;
  v22 = v19 + v15;
  v23 = x[15];
  x[12] = v22;
  v24 = (float)(v21 - (float)(v18 - v20)) * v9;
  v25 = (float)(v18 - v20) + v21;
  v26 = x[14];
  v27 = v25 * v9;
  v28 = x[7];
  x[13] = v20 + v18;
  x[4] = v24;
  x[5] = v27;
  v29 = x[6];
  x[14] = v29 + v26;
  x[15] = v28 + v23;
  x[6] = v26 - v29;
  x[7] = v23 - v28;
  mdct_butterfly_8(x);
  mdct_butterfly_8(v30);
}
