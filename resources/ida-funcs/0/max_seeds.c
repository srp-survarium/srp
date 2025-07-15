void __usercall max_seeds(vorbis_look_psy *p@<esi>, float *seed, float *flr)
{
  int eighth_octave_lines; // edi
  int v4; // ebx
  int v5; // ecx
  int n; // edi
  int v7; // ecx
  float v8; // xmm1_4
  vorbis_info_psy *vi; // eax
  int v10; // edx
  float tone_abs_limit; // xmm0_4
  int v12; // edx
  float *v13; // eax
  float v14; // xmm0_4
  float *v15; // eax
  int v16; // [esp+8h] [ebp-4h]

  eighth_octave_lines = p->eighth_octave_lines;
  v4 = 0;
  seed_chase(seed, eighth_octave_lines, p->total_octave_lines);
  v5 = *p->octave - (eighth_octave_lines >> 1);
  n = p->n;
  v7 = v5 - p->firstoc;
  if ( p->n > 1 )
  {
    v8 = seed[v7];
    do
    {
      vi = p->vi;
      v10 = ((p->octave[v4] + p->octave[v4 + 1]) >> 1) - p->firstoc;
      tone_abs_limit = v8;
      if ( v8 > vi->tone_abs_limit )
        tone_abs_limit = vi->tone_abs_limit;
      if ( v7 + 1 <= v10 )
      {
        v16 = v7 + 1;
        do
        {
          ++v7;
          ++v16;
          v8 = seed[v7];
          if ( v8 > -9999.0 && tone_abs_limit > v8 || tone_abs_limit == -9999.0 )
            tone_abs_limit = seed[v7];
        }
        while ( v16 <= v10 );
      }
      v12 = p->firstoc + v7;
      if ( v4 < n )
      {
        do
        {
          if ( p->octave[v4] > v12 )
            break;
          v13 = &flr[v4];
          if ( tone_abs_limit > *v13 )
            *v13 = tone_abs_limit;
          ++v4;
        }
        while ( v4 < p->n );
      }
      n = p->n;
    }
    while ( v4 + 1 < p->n );
  }
  v14 = seed[p->total_octave_lines - 1];
  while ( v4 < p->n )
  {
    v15 = &flr[v4];
    if ( v14 > *v15 )
      *v15 = v14;
    ++v4;
  }
}
