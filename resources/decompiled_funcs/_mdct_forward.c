void __usercall mdct_forward(mdct_lookup *init@<edi>, float *in, float *out)
{
  int n; // eax
  int v4; // ebx
  void *v5; // esp
  float *v6; // esi
  float *v7; // edx
  float *v8; // eax
  int v9; // ecx
  double v10; // st7
  float *v11; // edx
  double v12; // st7
  double v13; // st7
  float *v14; // edx
  double v15; // st6
  double v16; // st7
  float *v17; // ebx
  double v18; // st7
  float *v19; // edx
  bool v20; // cc
  double v21; // st6
  double v22; // st7
  float *v23; // ebx
  float *v24; // edx
  double v25; // st7
  double v26; // st7
  float *v27; // ebx
  double v28; // st6
  double v29; // st7
  unsigned int v30; // ebx
  float *v31; // eax
  float *v32; // ecx
  int v33; // edx
  float *v34; // edx
  unsigned int v35; // ebx
  double v36; // st7
  double v37; // st7
  double v38; // st6
  float v39[2]; // [esp+0h] [ebp-2Ch] BYREF
  int i; // [esp+8h] [ebp-24h]
  float *v41; // [esp+Ch] [ebp-20h]
  unsigned int v42; // [esp+10h] [ebp-1Ch]
  int n4; // [esp+14h] [ebp-18h]
  int n2; // [esp+18h] [ebp-14h]
  float r1; // [esp+1Ch] [ebp-10h]
  float r0; // [esp+20h] [ebp-Ch]
  float *x1; // [esp+24h] [ebp-8h]
  float *x0; // [esp+28h] [ebp-4h]

  n = init->n;
  n2 = init->n >> 1;
  n4 = n >> 2;
  v4 = n >> 3;
  i = 4 * n;
  v5 = alloca(4 * n);
  v6 = v39;
  v41 = &v39[n2];
  v7 = &in[n2 + (n >> 2)];
  x1 = v7 + 1;
  v8 = &init->trig[n2];
  v42 = 4 * n2;
  v9 = 0;
  x0 = &in[n2 + n4];
  if ( v4 > 0 )
  {
    while ( 1 )
    {
      v10 = *(v7 - 2);
      x0 = v7 - 4;
      v11 = x1;
      v12 = v10 + *x1;
      v8 -= 2;
      x1 += 4;
      v9 += 2;
      r0 = v12;
      v13 = v11[2] + *x0;
      v14 = v41;
      r1 = v13;
      v15 = r0;
      v16 = r1;
      v41[v9 - 2] = v8[1] * r1 + *v8 * r0;
      v14[v9 - 1] = v16 * *v8 - v15 * v8[1];
      if ( v9 >= v4 )
        break;
      v7 = x0;
    }
  }
  x1 = in + 1;
  v41 = (float *)(n2 - v4);
  if ( v9 < n2 - v4 )
  {
    v17 = x1;
    do
    {
      v18 = *(x0 - 2) - *v17;
      v8 -= 2;
      x0 -= 4;
      v9 += 2;
      r0 = v18;
      v17 += 4;
      v19 = &v39[v42 / 4];
      v20 = v9 < (int)v41;
      r1 = *x0 - *(v17 - 2);
      v21 = r0;
      v22 = r1;
      v19[v9 - 2] = v8[1] * r1 + *v8 * r0;
      v19[v9 - 1] = v22 * *v8 - v21 * v8[1];
    }
    while ( v20 );
    x1 = v17;
  }
  v23 = &in[i / 4u];
  if ( v9 < n2 )
  {
    v24 = x1;
    while ( 1 )
    {
      v8 -= 2;
      v25 = -*(v23 - 2) - *v24;
      x0 = v23 - 4;
      v9 += 2;
      v24 += 4;
      r0 = v25;
      v26 = *(v23 - 4);
      v27 = &v39[v42 / 4];
      v20 = v9 < n2;
      r1 = -v26 - *(v24 - 2);
      v28 = r0;
      v29 = r1;
      v27[v9 - 2] = v8[1] * r1 + *v8 * r0;
      v27[v9 - 1] = v29 * *v8 - v28 * v8[1];
      if ( !v20 )
        break;
      v23 = x0;
    }
  }
  v30 = v42;
  mdct_butterflies(init, &v39[v42 / 4], n2);
  mdct_bitreverse(init, v39);
  v31 = (float *)((char *)init->trig + v30);
  v32 = (float *)((char *)out + v30);
  v33 = 0;
  if ( n4 >= 4 )
  {
    v34 = out + 2;
    i = 4 * (((unsigned int)(n4 - 4) >> 2) + 1);
    v35 = ((unsigned int)(n4 - 4) >> 2) + 1;
    do
    {
      v6 += 8;
      v36 = *v31 * *(v6 - 8);
      v32 -= 4;
      v31 += 8;
      v34 += 4;
      --v35;
      *(v34 - 6) = (v36 + *(v6 - 7) * *(v31 - 7)) * init->scale;
      v32[3] = (*(v31 - 7) * *(v6 - 8) - *(v6 - 7) * *(v31 - 8)) * init->scale;
      *(v34 - 5) = (*(v31 - 5) * *(v6 - 5) + *(v31 - 6) * *(v6 - 6)) * init->scale;
      v32[2] = (*(v31 - 5) * *(v6 - 6) - *(v6 - 5) * *(v31 - 6)) * init->scale;
      *(v34 - 4) = (*(v31 - 3) * *(v6 - 3) + *(v31 - 4) * *(v6 - 4)) * init->scale;
      v32[1] = (*(v6 - 4) * *(v31 - 3) - *(v31 - 4) * *(v6 - 3)) * init->scale;
      *(v34 - 3) = (*(v31 - 2) * *(v6 - 2) + *(v31 - 1) * *(v6 - 1)) * init->scale;
      *v32 = (*(v6 - 2) * *(v31 - 1) - *(v31 - 2) * *(v6 - 1)) * init->scale;
    }
    while ( v35 );
    v33 = i;
  }
  if ( v33 < n4 )
  {
    do
    {
      v37 = *v31 * *v6;
      --v32;
      ++v33;
      v38 = v6[1] * v31[1];
      v6 += 2;
      v31 += 2;
      v20 = v33 < n4;
      out[v33 - 1] = (v37 + v38) * init->scale;
      *v32 = (*(v31 - 1) * *(v6 - 2) - *(v6 - 1) * *(v31 - 2)) * init->scale;
    }
    while ( v20 );
  }
}
