void __usercall _vp_noisemask(vorbis_look_psy *p@<edi>, const float *logmdct, float *logmask)
{
  int n; // esi
  void *v4; // esp
  float *v5; // eax
  int v6; // edx
  int v7; // ebx
  const float *v8; // ebx
  float *v9; // eax
  int v10; // edx
  float *v11; // eax
  int v12; // ecx
  int v13; // [esp+8h] [ebp-Ch] BYREF
  const float *v14; // [esp+10h] [ebp-4h]

  n = p->n;
  v4 = alloca(4 * p->n);
  v14 = (const float *)&v13;
  bark_noise_hybridmp(n, p->bark, logmdct, logmask, 140.0, -1);
  if ( n > 0 )
  {
    v5 = logmask;
    v6 = (char *)v14 - (char *)logmask;
    v7 = n;
    do
    {
      *(float *)((char *)v5 + v6) = *(float *)((char *)v5 + (char *)logmdct - (char *)logmask) - *v5;
      ++v5;
      --v7;
    }
    while ( v7 );
  }
  v8 = v14;
  bark_noise_hybridmp(n, p->bark, v14, logmask, 0.0, p->vi->noisewindowfixed);
  if ( n > 0 )
  {
    v9 = (float *)v8;
    v10 = n;
    do
    {
      *v9 = *(float *)((char *)v9 + (char *)logmdct - (char *)v8) - *v9;
      ++v9;
      --v10;
    }
    while ( v10 );
    v11 = logmask;
    do
    {
      v12 = (int)(float)(*v11 + 0.5);
      if ( v12 >= 40 )
        v12 = 39;
      if ( v12 < 0 )
        v12 = 0;
      *v11 = p->vi->noisecompand[v12] + *(float *)((char *)v11 + (char *)v8 - (char *)logmask);
      ++v11;
      --n;
    }
    while ( n );
  }
}
