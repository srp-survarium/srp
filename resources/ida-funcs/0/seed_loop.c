void __usercall seed_loop(
        vorbis_look_psy *p@<eax>,
        const float ***curves,
        const float *f,
        const float *flr,
        float *seed,
        float specmax)
{
  float v6; // xmm2_4
  int n; // ebx
  int v8; // ecx
  int *octave; // edi
  float v10; // xmm1_4
  int v11; // edx
  int v12; // edx
  const float **v13; // esi
  int v14; // ecx
  int eighth_octave_lines; // edi
  int v16; // edx
  float *v17; // edx
  int v18; // esi
  int j; // ecx
  float *v20; // ebx
  float v21; // xmm0_4
  int i; // [esp+0h] [ebp-4h]
  int v23; // [esp+1Ch] [ebp+18h]

  v6 = p->vi->max_curve_dB - specmax;
  n = p->n;
  v8 = 0;
  for ( i = 0; v8 < p->n; i = v8 )
  {
    octave = p->octave;
    v10 = f[v8];
    v11 = octave[v8];
    if ( v8 + 1 < n )
    {
      v23 = v8 + 1;
      do
      {
        if ( octave[v8 + 1] != v11 )
          break;
        ++v8;
        ++v23;
        i = v8;
        if ( f[v8] > v10 )
          v10 = f[v8];
      }
      while ( v23 < n );
    }
    if ( (float)(v10 + 6.0) > flr[v8] )
    {
      v12 = v11 >> p->shiftoc;
      if ( v12 >= 17 )
        v12 = 16;
      if ( v12 < 0 )
        v12 = 0;
      v13 = curves[v12];
      v14 = octave[v8] - p->firstoc;
      eighth_octave_lines = p->eighth_octave_lines;
      v16 = (int)(((float)(v10 + v6) - 30.0) * 0.1000000014901161);
      if ( v16 <= 0 )
        v16 = 0;
      if ( v16 >= 7 )
        v16 = 7;
      v17 = (float *)v13[v16];
      v18 = (int)(float)((float)((float)((float)(*v17 - 16.0) * (float)eighth_octave_lines) + (float)v14)
                       - (float)(eighth_octave_lines >> 1));
      for ( j = (int)*v17; j < (int)v17[1]; ++j )
      {
        if ( v18 > 0 )
        {
          v20 = &seed[v18];
          v21 = v17[j + 2] + v10;
          if ( v21 > *v20 )
            *v20 = v21;
        }
        v18 += eighth_octave_lines;
        if ( v18 >= p->total_octave_lines )
          break;
      }
      v8 = i;
    }
    n = p->n;
    ++v8;
  }
}
