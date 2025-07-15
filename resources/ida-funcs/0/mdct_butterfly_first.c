void __usercall mdct_butterfly_first(float *T@<edx>, float *x@<edi>, int points@<ecx>)
{
  float *v3; // eax
  float *v4; // ecx
  float v5; // xmm4_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm2_4

  v3 = &x[(points >> 1) - 8];
  v4 = &v3[points - (points >> 1) + 7];
  do
  {
    v5 = v3[6];
    v6 = *v4;
    v7 = *(v4 - 1);
    v8 = *v4 - v3[7];
    *(v4 - 1) = v7 + v5;
    *v4 = v6 + v3[7];
    v9 = v7 - v5;
    v10 = v3[4];
    v3[6] = (float)(T[1] * v8) + (float)(*T * v9);
    v3[7] = (float)(*T * v8) - (float)(T[1] * v9);
    v11 = *(v4 - 2);
    v12 = *(v4 - 3) - v10;
    v13 = v11 - v3[5];
    *(v4 - 3) = *(v4 - 3) + v10;
    *(v4 - 2) = v11 + v3[5];
    v14 = v3[2];
    v3[4] = (float)(v13 * T[5]) + (float)(v12 * T[4]);
    v3[5] = (float)(v13 * T[4]) - (float)(v12 * T[5]);
    v15 = *(v4 - 4);
    v16 = *(v4 - 5);
    v17 = v15 - v3[3];
    *(v4 - 5) = v16 + v14;
    *(v4 - 4) = v15 + v3[3];
    v18 = v16 - v14;
    v19 = *v3;
    v3[2] = (float)(T[9] * v17) + (float)(T[8] * v18);
    v3[3] = (float)(T[8] * v17) - (float)(T[9] * v18);
    v20 = *(v4 - 6);
    v21 = *(v4 - 7);
    v22 = v20 - v3[1];
    *(v4 - 7) = v21 + v19;
    *(v4 - 6) = v20 + v3[1];
    v23 = v21 - v19;
    *v3 = (float)(T[13] * v22) + (float)(T[12] * v23);
    v3[1] = (float)(T[12] * v22) - (float)(T[13] * v23);
    v3 -= 8;
    v4 -= 8;
    T += 16;
  }
  while ( v3 >= x );
}
