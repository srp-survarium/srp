void __usercall _vp_noisemask(const float *logmdct@<eax>, vorbis_look_psy *p, float *logmask)
{
  float *v3; // ebx
  int v5; // edi
  int v6; // eax
  void *v7; // esp
  int v8; // edx
  float *v9; // ecx
  float *v10; // eax
  char *v11; // ebx
  double v12; // st7
  float *v13; // eax
  int v14; // ecx
  double v15; // st7
  int v16; // eax
  float *v17; // eax
  unsigned int v18; // edx
  int v19; // ebx
  float *v20; // ecx
  double v21; // st7
  float *v22; // edx
  int v23; // esi
  int v24; // ecx
  float *v25; // eax
  double v26; // st7
  int v27; // esi
  int v28; // eax
  int v29; // [esp+8h] [ebp-20h] BYREF
  int n; // [esp+14h] [ebp-14h]
  int v31; // [esp+18h] [ebp-10h]
  char *v32; // [esp+1Ch] [ebp-Ch]
  char *v33; // [esp+20h] [ebp-8h]
  float *f; // [esp+24h] [ebp-4h]

  v3 = logmask;
  v6 = 4 * p->n;
  n = p->n;
  v5 = n;
  v7 = alloca(v6);
  f = (float *)&v29;
  bark_noise_hybridmp(n, p->bark, logmdct, logmask, 140.0, -1);
  v8 = 0;
  if ( v5 >= 4 )
  {
    v33 = (char *)((char *)logmdct - (char *)logmask);
    v32 = (char *)((char *)f - (char *)logmask);
    v9 = f + 2;
    v10 = logmask + 1;
    v31 = (char *)logmdct - (char *)f;
    v5 = n;
    do
    {
      v11 = v33;
      v12 = logmdct[v8] - *(v10 - 1);
      v8 += 4;
      v10 += 4;
      v9 += 4;
      *(v9 - 6) = v12;
      *(float *)((char *)v10 + (_DWORD)v32 - 16) = *(float *)((char *)v10 + (_DWORD)v11 - 16) - *(v10 - 4);
      *(v9 - 4) = *(float *)((char *)v9 + v31 - 16) - *(v10 - 3);
      *(v9 - 3) = logmdct[v8 - 1] - *(v10 - 2);
    }
    while ( v8 < v5 - 3 );
    v3 = logmask;
  }
  if ( v8 < v5 )
  {
    v33 = (char *)((char *)logmdct - (char *)v3);
    v32 = (char *)((char *)f - (char *)v3);
    v13 = &v3[v8];
    v14 = v5 - v8;
    do
    {
      v15 = *(float *)((char *)v13 + (_DWORD)v33) - *v13;
      ++v13;
      --v14;
      *(float *)((char *)v13 + (_DWORD)v32 - 4) = v15;
    }
    while ( v14 );
  }
  bark_noise_hybridmp(v5, p->bark, f, v3, 0.0, p->vi->noisewindowfixed);
  v16 = 0;
  v32 = 0;
  if ( v5 >= 4 )
  {
    v17 = f + 1;
    v31 = (char *)logmdct - (char *)f;
    v18 = ((unsigned int)(v5 - 4) >> 2) + 1;
    v32 = (char *)(4 * v18);
    v19 = (char *)logmdct - (char *)f;
    v20 = (float *)(logmdct + 3);
    do
    {
      v17 += 4;
      v21 = *(v20 - 3) - *(v17 - 5);
      v20 += 4;
      --v18;
      *(v17 - 5) = v21;
      *(v17 - 4) = *(float *)((char *)v17 + v19 - 16) - *(v17 - 4);
      *(v17 - 3) = *(v20 - 5) - *(v17 - 3);
      *(v17 - 2) = *(v20 - 4) - *(v17 - 2);
    }
    while ( v18 );
    v16 = (int)v32;
    v3 = logmask;
  }
  v22 = f;
  if ( v16 < v5 )
  {
    v23 = (char *)logmdct - (char *)f;
    v24 = v5 - (_DWORD)v32;
    v25 = &f[v16];
    do
    {
      v26 = *(float *)((char *)v25++ + v23);
      --v24;
      *(v25 - 1) = v26 - *(v25 - 1);
    }
    while ( v24 );
  }
  if ( v5 > 0 )
  {
    v27 = (char *)v22 - (char *)v3;
    do
    {
      v28 = (int)(*v3 + 0.5);
      if ( v28 < 40 )
      {
        if ( v28 < 0 )
          v28 = 0;
      }
      else
      {
        v28 = 39;
      }
      ++v3;
      --v5;
      *(v3 - 1) = p->vi->noisecompand[v28] + *(float *)((char *)v3 + v27 - 4);
    }
    while ( v5 );
  }
}
