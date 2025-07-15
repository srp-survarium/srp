void __cdecl mdct_forward(mdct_lookup *init, float *in, float *out)
{
  int n; // ebx
  int v4; // eax
  int v5; // esi
  int v6; // ebx
  void *v7; // esp
  _DWORD *v8; // edx
  float *v9; // ecx
  float *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  int v13; // edi
  float v14; // xmm2_4
  float v15; // xmm1_4
  bool v16; // cc
  int v17; // ebx
  float *v18; // edi
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  _DWORD *v22; // ecx
  float *v23; // edi
  int v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float *v28; // esi
  float *v29; // eax
  float *v30; // ecx
  int v31; // edx
  float v32; // xmm0_4
  float v33; // xmm1_4
  _DWORD v34[3]; // [esp+0h] [ebp-28h] BYREF
  float *v35; // [esp+Ch] [ebp-1Ch]
  int v36; // [esp+10h] [ebp-18h]
  int v37; // [esp+14h] [ebp-14h]
  unsigned int v38; // [esp+18h] [ebp-10h]
  int v39; // [esp+1Ch] [ebp-Ch]
  int v40; // [esp+20h] [ebp-8h]
  float *v41; // [esp+24h] [ebp-4h]

  n = init->n;
  v4 = 4 * init->n;
  v5 = init->n >> 1;
  v37 = init->n >> 2;
  v6 = n >> 3;
  v36 = v4;
  v7 = alloca(v4);
  v40 = 0;
  v35 = (float *)v34;
  v38 = 4 * v5;
  v8 = &v34[v5];
  v9 = &in[v5 + v37];
  v41 = v9 + 1;
  v10 = &init->trig[v5];
  if ( v6 > 0 )
  {
    do
    {
      v11 = v41[2];
      v12 = *(v9 - 2) + *v41;
      v13 = v40;
      v14 = *(v10 - 1);
      v40 += 2;
      v41 += 4;
      v9 -= 4;
      v15 = v11 + *v9;
      v10 -= 2;
      v13 *= 4;
      v16 = v40 < v6;
      *(float *)((char *)v8 + v13) = (float)(v14 * v15) + (float)(*v10 * v12);
      *(float *)((char *)v8 + v13 + 4) = (float)(*v10 * v15) - (float)(v10[1] * v12);
    }
    while ( v16 );
  }
  v39 = v5 - v6;
  v17 = v40;
  v41 = in + 1;
  while ( v17 < v39 )
  {
    v18 = v41;
    v19 = *(v9 - 2) - *v41;
    v20 = *(v10 - 1);
    v41 += 4;
    v10 -= 2;
    v9 -= 4;
    v21 = *v9 - v18[2];
    *(float *)&v8[v17] = (float)(v20 * v21) + (float)(*v10 * v19);
    *(float *)&v8[v17 + 1] = (float)(*v10 * v21) - (float)(v10[1] * v19);
    v17 += 2;
  }
  v22 = (_DWORD *)((char *)in + v36);
  if ( v17 < v5 )
  {
    v23 = v41;
    do
    {
      v24 = *(v22 - 2);
      v25 = *(v10 - 1);
      v10 -= 2;
      v22 -= 4;
      v26 = COERCE_FLOAT(*v22 ^ _mask__NegFloat_) - v23[2];
      v27 = COERCE_FLOAT(v24 ^ _mask__NegFloat_) - *v23;
      *(float *)&v8[v17] = (float)(v25 * v26) + (float)(*v10 * v27);
      *(float *)&v8[v17 + 1] = (float)(*v10 * v26) - (float)(v10[1] * v27);
      v23 += 4;
      v17 += 2;
    }
    while ( v17 < v5 );
  }
  mdct_butterflies(init, (float *)&v34[v5], v5);
  v28 = v35;
  mdct_bitreverse(init, v35);
  v29 = &init->trig[v38 / 4];
  v30 = &out[v38 / 4];
  v31 = 0;
  if ( v37 > 0 )
  {
    do
    {
      out[v31] = (float)((float)(v29[1] * v28[1]) + (float)(*v29 * *v28)) * init->scale;
      v32 = v29[1] * *v28;
      v33 = *v29 * v28[1];
      --v30;
      v28 += 2;
      v29 += 2;
      v16 = ++v31 < v37;
      *v30 = (float)(v32 - v33) * init->scale;
    }
    while ( v16 );
  }
}
