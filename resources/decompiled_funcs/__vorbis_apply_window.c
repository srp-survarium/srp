void __usercall _vorbis_apply_window(int *blocksizes@<eax>, int W@<edx>, float *d, int *winno, int lW, const float *nW)
{
  int v7; // eax
  int v8; // ecx
  int v9; // kr00_4
  int v10; // ebx
  int v11; // kr04_4
  float *v12; // edx
  int v13; // edi
  int v14; // esi
  int v15; // ebp
  int v16; // ecx
  int v17; // eax
  unsigned int v18; // ebx
  float *v19; // ecx
  const float *v20; // edi
  double v21; // st7
  double v22; // st7
  float *v23; // ecx
  double v24; // st7
  double v25; // st7
  int v26; // ebp
  unsigned int v27; // ecx
  int v28; // eax
  float *v29; // edi
  double v30; // st7
  double v31; // st7
  float *v32; // eax
  double v33; // st7
  int p; // [esp+10h] [ebp-Ch]
  const float *windowNW; // [esp+14h] [ebp-8h]
  int n; // [esp+18h] [ebp-4h]
  int rightend; // [esp+24h] [ebp+8h]
  const float *windowLW; // [esp+2Ch] [ebp+10h]

  v7 = W != 0 ? lW : 0;
  v8 = W != 0 ? (unsigned int)nW : 0;
  n = blocksizes[W];
  windowNW = vwin[winno[v8]];
  v9 = blocksizes[v7];
  windowLW = vwin[winno[v7]];
  v10 = n / 4 - v9 / 4;
  v11 = blocksizes[v8];
  v12 = d;
  v13 = v11 / 2;
  v14 = n / 4 + n / 2 - v11 / 4;
  v15 = v10 + v9 / 2;
  v16 = v11 / 2 + v14;
  v17 = 0;
  rightend = v16;
  if ( v10 > 0 )
  {
    memset(d, 0, 4 * v10);
    v16 = v11 / 2 + v14;
    v13 = v11 / 2;
    v17 = n / 4 - v9 / 4;
  }
  p = 0;
  if ( v17 < v15 )
  {
    if ( v15 - v17 >= 4 )
    {
      v18 = ((unsigned int)(v15 - v17 - 4) >> 2) + 1;
      v19 = &d[v17 + 2];
      v20 = windowLW + 2;
      v17 += 4 * v18;
      p = 4 * v18;
      do
      {
        v21 = *(v20 - 2);
        v20 += 4;
        v22 = v21 * *(v19 - 2);
        v19 += 4;
        --v18;
        *(v19 - 6) = v22;
        *(v19 - 5) = *(v20 - 5) * *(v19 - 5);
        *(v19 - 4) = *(v19 - 4) * *(v20 - 4);
        *(v19 - 3) = *(v20 - 3) * *(v19 - 3);
      }
      while ( v18 );
      v12 = d;
      v16 = v11 / 2 + v14;
      v13 = v11 / 2;
    }
    if ( v17 < v15 )
    {
      v23 = (float *)&windowLW[p];
      do
      {
        v24 = v12[v17++];
        v25 = v24 * *v23++;
        v12[v17 - 1] = v25;
      }
      while ( v17 < v15 );
      v16 = v11 / 2 + v14;
    }
  }
  v26 = v13 - 1;
  if ( v14 < v16 )
  {
    if ( v16 - v14 >= 4 )
    {
      v27 = ((unsigned int)(v16 - v14 - 4) >> 2) + 1;
      v28 = (int)&v12[v14 + 2];
      v29 = (float *)&windowNW[v26 - 2];
      v14 += 4 * v27;
      v26 -= 4 * v27;
      do
      {
        v30 = v29[2];
        v29 -= 4;
        v31 = v30 * *(float *)(v28 - 8);
        v28 += 16;
        --v27;
        *(float *)(v28 - 24) = v31;
        *(float *)(v28 - 20) = v29[5] * *(float *)(v28 - 20);
        *(float *)(v28 - 16) = *(float *)(v28 - 16) * v29[4];
        *(float *)(v28 - 12) = v29[3] * *(float *)(v28 - 12);
      }
      while ( v27 );
      v16 = rightend;
    }
    if ( v14 < v16 )
    {
      v32 = (float *)&windowNW[v26];
      do
      {
        v33 = *v32-- * v12[v14++];
        v12[v14 - 1] = v33;
      }
      while ( v14 < v16 );
    }
  }
  if ( v14 < n )
    memset(&v12[v14], 0, 4 * (n - v14));
}
