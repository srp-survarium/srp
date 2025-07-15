void __usercall _vp_tonemask(
        vorbis_look_psy *p@<esi>,
        float *logfft,
        float *logmask,
        float global_specmax,
        float local_specmax)
{
  float *v5; // ebx
  signed int total_octave_lines; // edi
  void *v7; // esp
  vorbis_info_psy *vi; // edx
  double ath_adjatt; // st7
  double ath_maxatt; // st7
  int v11; // ecx
  int v12; // edi
  int v13; // edx
  unsigned int v14; // ecx
  float *v15; // eax
  char *v16; // edx
  int v17; // ebx
  char *v18; // edx
  double v19; // st6
  _BYTE v20[8]; // [esp+4h] [ebp-18h] BYREF
  int v21; // [esp+Ch] [ebp-10h]
  int v22; // [esp+10h] [ebp-Ch]
  int n; // [esp+14h] [ebp-8h]
  float *seed; // [esp+18h] [ebp-4h]
  float v25; // [esp+30h] [ebp+14h]
  int v26; // [esp+30h] [ebp+14h]

  v5 = logmask;
  total_octave_lines = p->total_octave_lines;
  n = p->n;
  v7 = alloca(4 * total_octave_lines);
  vi = p->vi;
  ath_adjatt = vi->ath_adjatt;
  seed = (float *)v20;
  v25 = ath_adjatt + local_specmax;
  if ( total_octave_lines > 0 )
    memset32(v20, -971228160, total_octave_lines);
  ath_maxatt = v25;
  if ( vi->ath_maxatt > (double)v25 )
    ath_maxatt = vi->ath_maxatt;
  v11 = n;
  v12 = 0;
  if ( n >= 4 )
  {
    v21 = 4 - (_DWORD)logmask;
    v13 = -8 - (_DWORD)logmask;
    v14 = ((unsigned int)(n - 4) >> 2) + 1;
    v26 = 8;
    v15 = logmask + 2;
    v22 = -8 - (_DWORD)logmask;
    v12 = 4 * v14;
    while ( 1 )
    {
      v16 = (char *)v15 + v13;
      *(v15 - 2) = *(float *)&v16[(unsigned int)p->ath] + ath_maxatt;
      v17 = v26;
      v26 += 16;
      *(v15 - 1) = *(float *)&v16[(unsigned int)p->ath + 4] + ath_maxatt;
      v18 = (char *)v15 + v21;
      v15 += 4;
      --v14;
      *(v15 - 4) = *(float *)((char *)p->ath + v17) + ath_maxatt;
      *(v15 - 3) = *(float *)&v18[(unsigned int)p->ath] + ath_maxatt;
      if ( !v14 )
        break;
      v13 = v22;
    }
    v5 = logmask;
    v11 = n;
  }
  for ( ; v12 < v11; v5[v12 - 1] = v19 + ath_maxatt )
    v19 = p->ath[v12++];
  seed_loop(p, (const float ***)p->tonecurves, logfft, v5, seed, global_specmax);
  max_seeds(p, seed, v5);
}
