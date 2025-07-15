void __cdecl seed_loop(
        vorbis_look_psy *p,
        const float ***curves,
        const float *f,
        const float *flr,
        float *seed,
        float specmax)
{
  int v7; // esi
  int *octave; // edi
  int v9; // edx
  int v10; // ecx
  double v11; // st7
  int v12; // edx
  float max; // [esp+28h] [ebp+4h]
  float dBoffset; // [esp+3Ch] [ebp+18h]

  v7 = 0;
  for ( dBoffset = p->vi->max_curve_dB - specmax; v7 < p->n; ++v7 )
  {
    octave = p->octave;
    v9 = octave[v7];
    max = f[v7];
    if ( v7 + 1 < p->n )
    {
      v10 = v7 + 1;
      do
      {
        if ( octave[v7 + 1] != v9 )
          break;
        v11 = f[++v7];
        ++v10;
        if ( max < v11 )
          max = f[v7];
      }
      while ( v10 < p->n );
    }
    if ( flr[v7] < max + 6.0 )
    {
      v12 = v9 >> p->shiftoc;
      if ( v12 < 17 )
      {
        if ( v12 < 0 )
          v12 = 0;
      }
      else
      {
        v12 = 16;
      }
      seed_curve(
        seed,
        curves[v12],
        max,
        octave[v7] - p->firstoc,
        p->total_octave_lines,
        p->eighth_octave_lines,
        dBoffset);
    }
  }
}
