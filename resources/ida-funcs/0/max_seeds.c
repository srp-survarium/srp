void __usercall max_seeds(vorbis_look_psy *p@<edi>, float *seed, float *flr)
{
  int eighth_octave_lines; // ebx
  int v4; // esi
  int v5; // edx
  double v6; // st7
  double tone_abs_limit; // st6
  int v8; // ecx
  vorbis_info_psy *vi; // ebx
  int i; // ebx
  double v11; // rt0
  double v12; // st6
  double v13; // st7
  double v14; // rt1
  int j; // ebx
  float minV; // [esp+10h] [ebp+4h]

  eighth_octave_lines = p->eighth_octave_lines;
  v4 = 0;
  seed_chase(seed, eighth_octave_lines, p->total_octave_lines);
  v5 = *p->octave - (eighth_octave_lines >> 1) - p->firstoc;
  if ( p->n > 1 )
  {
    v6 = -9999.0;
    do
    {
      tone_abs_limit = seed[v5];
      v8 = ((p->octave[v4] + p->octave[v4 + 1]) >> 1) - p->firstoc;
      vi = p->vi;
      if ( vi->tone_abs_limit < tone_abs_limit )
        tone_abs_limit = vi->tone_abs_limit;
      for ( i = v5 + 1; i <= v8; ++i )
      {
        ++v5;
        v11 = tone_abs_limit;
        v12 = v6;
        v13 = v11;
        if ( v12 < seed[v5] && seed[v5] < v13 || v12 == v13 )
        {
          v6 = v12;
          tone_abs_limit = seed[v5];
        }
        else
        {
          v14 = v12;
          tone_abs_limit = v13;
          v6 = v14;
        }
      }
      for ( j = p->firstoc + v5; v4 < p->n; ++v4 )
      {
        if ( p->octave[v4] > j )
          break;
        if ( flr[v4] < tone_abs_limit )
          flr[v4] = tone_abs_limit;
      }
    }
    while ( v4 + 1 < p->n );
  }
  if ( v4 < p->n )
  {
    minV = seed[p->total_octave_lines - 1];
    do
    {
      if ( flr[v4] < (double)minV )
        flr[v4] = minV;
      ++v4;
    }
    while ( v4 < p->n );
  }
}
