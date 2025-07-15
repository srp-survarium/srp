void __usercall mdct_backward(mdct_lookup *init@<eax>, float *in, float *out)
{
  int n; // esi
  int v6; // eax
  int v7; // esi
  float *v8; // ecx
  float *v9; // eax
  float *v10; // edx
  float *v11; // eax
  float *v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float *v15; // edx
  float *v16; // eax
  float *v17; // ecx
  float *v18; // eax
  float *v19; // ecx
  float *v20; // edx
  int v21; // xmm1_4
  int v22; // xmm1_4
  int v23; // xmm1_4
  float v24; // xmm1_4
  float *v25; // ecx
  float *v26; // eax
  double v27; // st7
  int v28; // [esp+0h] [ebp-8h]
  float *v29; // [esp+4h] [ebp-4h]
  float *v30; // [esp+10h] [ebp+8h]
  float *v31; // [esp+14h] [ebp+Ch]
  float *v32; // [esp+14h] [ebp+Ch]

  n = init->n;
  v6 = init->n >> 2;
  v7 = n >> 1;
  v29 = &out[v6 + v7];
  v31 = v29;
  v8 = &in[v7 - 7];
  v28 = v6;
  v9 = &init->trig[v6];
  do
  {
    v10 = v31 - 4;
    *v10 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v8[2] * v9[3]) ^ _mask__NegFloat_) - (float)(*v8 * v9[2]);
    v10[1] = (float)(*v8 * v9[3]) - (float)(v8[2] * v9[2]);
    v10[2] = COERCE_FLOAT(COERCE_UNSIGNED_INT(v9[1] * v8[6]) ^ _mask__NegFloat_) - (float)(v8[4] * *v9);
    v31 -= 4;
    v10[3] = (float)(v9[1] * v8[4]) - (float)(*v9 * v8[6]);
    v8 -= 8;
    v9 += 4;
  }
  while ( v8 >= in );
  v32 = v29;
  v11 = &init->trig[v28];
  v12 = &in[v7 - 8];
  do
  {
    *v32 = (float)(v12[4] * *(v11 - 1)) + (float)(*(v11 - 2) * v12[6]);
    v13 = v12[4] * *(v11 - 2);
    v14 = *(v11 - 1) * v12[6];
    v11 -= 4;
    v32[1] = v13 - v14;
    v32[2] = (float)(v12[2] * *v11) + (float)(*v12 * v11[1]);
    v32[3] = (float)(*v12 * *v11) - (float)(v11[1] * v12[2]);
    v12 -= 8;
    v32 += 4;
  }
  while ( v12 >= in );
  mdct_butterflies(init, &out[v7], v7);
  mdct_bitreverse(init, out);
  v15 = v29;
  v16 = &init->trig[v7];
  v30 = v29;
  v17 = out + 3;
  do
  {
    *(v15 - 1) = (float)(v16[1] * *(v17 - 3)) - (float)(*v16 * *(v17 - 2));
    *(_DWORD *)v30 = COERCE_UNSIGNED_INT((float)(v16[1] * *(v17 - 2)) + (float)(*(v17 - 3) * *v16)) ^ _mask__NegFloat_;
    *(v15 - 2) = (float)(*(v17 - 1) * v16[3]) - (float)(*v17 * v16[2]);
    v15 -= 4;
    *((_DWORD *)v30 + 1) = COERCE_UNSIGNED_INT((float)(*(v17 - 1) * v16[2]) + (float)(*v17 * v16[3])) ^ _mask__NegFloat_;
    v15[1] = (float)(v17[1] * v16[5]) - (float)(v17[2] * v16[4]);
    *((_DWORD *)v30 + 2) = COERCE_UNSIGNED_INT((float)(v17[2] * v16[5]) + (float)(v17[1] * v16[4])) ^ _mask__NegFloat_;
    *v15 = (float)(v17[3] * v16[7]) - (float)(v17[4] * v16[6]);
    *((_DWORD *)v30 + 3) = COERCE_UNSIGNED_INT((float)(v17[4] * v16[7]) + (float)(v17[3] * v16[6])) ^ _mask__NegFloat_;
    v17 += 8;
    v30 += 4;
    v16 += 8;
  }
  while ( v17 - 3 < v15 );
  v18 = v29;
  v19 = &out[v28 + 2];
  v20 = &v29[2 - v7];
  do
  {
    v21 = *((_DWORD *)v18 - 1);
    *((_DWORD *)v20 - 3) = v21;
    v18 -= 4;
    v20 -= 4;
    *((_DWORD *)v19 - 2) = v21 ^ _mask__NegFloat_;
    v22 = *((_DWORD *)v18 + 2);
    *(_DWORD *)v20 = v22;
    *((_DWORD *)v19 - 1) = v22 ^ _mask__NegFloat_;
    v23 = *((_DWORD *)v18 + 1);
    *((_DWORD *)v20 - 1) = v23;
    *(_DWORD *)v19 = v23 ^ _mask__NegFloat_;
    v24 = *v18;
    *(v20 - 2) = *v18;
    *((_DWORD *)v19 + 1) = LODWORD(v24) ^ _mask__NegFloat_;
    v19 += 4;
  }
  while ( v19 - 2 < v18 );
  v25 = v29;
  v26 = v29;
  do
  {
    v26 -= 4;
    *v26 = v25[3];
    v26[1] = v25[2];
    v26[2] = v25[1];
    v27 = *v25;
    v25 += 4;
    v26[3] = v27;
  }
  while ( v26 > &out[v7] );
}
