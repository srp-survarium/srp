void __usercall _vorbis_apply_window(int *blocksizes@<edx>, int W@<eax>, float *d, int *winno, int lW, int nW)
{
  int v7; // eax
  int v8; // ecx
  int v9; // ebx
  int v10; // kr04_4
  int v11; // esi
  int v12; // ecx
  int v13; // edx
  int v14; // eax
  float *v15; // ebx
  float *v16; // edi
  float v17; // xmm0_4
  int v18; // ecx
  float *v19; // edx
  float *v20; // eax
  float v21; // xmm0_4
  const float *v22; // [esp+Ch] [ebp-Ch]
  const float *v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+24h] [ebp+Ch]

  v7 = W != 0 ? lW : 0;
  v8 = W != 0 ? nW : 0;
  v23 = vwin[winno[v7]];
  v22 = vwin[winno[v8]];
  v24 = blocksizes[W];
  v9 = v24 / 4 - blocksizes[v7] / 4;
  v10 = blocksizes[v8];
  v11 = v24 / 4 + v24 / 2 - v10 / 4;
  v12 = v9 + blocksizes[v7] / 2;
  v13 = v10 / 2;
  v14 = 0;
  if ( v9 > 0 )
  {
    memset(d, 0, 4 * v9);
    v14 = v9;
  }
  if ( v14 < v12 )
  {
    v15 = (float *)v23;
    do
    {
      v16 = &d[v14];
      v17 = *v16 * *v15;
      ++v14;
      ++v15;
      *v16 = v17;
    }
    while ( v14 < v12 );
  }
  v18 = v13 + v11;
  if ( v11 < v13 + v11 )
  {
    v19 = (float *)&v22[v13 - 1];
    do
    {
      v20 = &d[v11];
      v21 = *v19 * *v20;
      ++v11;
      --v19;
      *v20 = v21;
    }
    while ( v11 < v18 );
  }
  if ( v11 < v24 )
    memset(&d[v11], 0, 4 * (v24 - v11));
}
