void __usercall _vp_tonemask(
        vorbis_look_psy *p@<eax>,
        const float *logfft,
        float *logmask,
        float global_specmax,
        float local_specmax)
{
  int n; // ebx
  signed int total_octave_lines; // edi
  void *v8; // esp
  vorbis_info_psy *vi; // edx
  float ath_maxatt; // xmm0_4
  int i; // eax
  _BYTE v12[12]; // [esp+4h] [ebp-10h] BYREF
  float *v13; // [esp+10h] [ebp-4h]

  n = p->n;
  total_octave_lines = p->total_octave_lines;
  v8 = alloca(4 * total_octave_lines);
  vi = p->vi;
  ath_maxatt = vi->ath_adjatt + local_specmax;
  v13 = (float *)v12;
  if ( total_octave_lines > 0 )
    memset32(v12, -971228160, total_octave_lines);
  if ( vi->ath_maxatt > ath_maxatt )
    ath_maxatt = vi->ath_maxatt;
  for ( i = 0; i < n; ++i )
    logmask[i] = p->ath[i] + ath_maxatt;
  seed_loop(p, (const float ***)p->tonecurves, logfft, logmask, v13, global_specmax);
  max_seeds(p, v13, logmask);
}
