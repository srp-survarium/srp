void __fastcall _vp_offset_and_mix(
        float *tone,
        int offset_select,
        vorbis_look_psy *p,
        float *noise,
        float *logmask,
        float *mdct,
        float *logmdct)
{
  float m_val; // xmm4_4
  float v9; // xmm5_4
  int v10; // ebx
  int v11; // esi
  vorbis_info_psy *vi; // edi
  float noisemaxsupp; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  bool v16; // cc
  double v17; // xmm0_8
  float v18; // xmm0_4
  int n; // [esp+0h] [ebp-Ch]
  int v20; // [esp+4h] [ebp-8h]
  int v21; // [esp+8h] [ebp-4h]
  int v22; // [esp+14h] [ebp+8h]

  m_val = p->m_val;
  v9 = p->vi->tone_masteratt[offset_select];
  v10 = 0;
  n = p->n;
  if ( p->n > 0 )
  {
    v22 = (char *)logmask - (char *)tone;
    v21 = (char *)logmdct - (char *)tone;
    v11 = (char *)noise - (char *)tone;
    v20 = (char *)mdct - (char *)tone;
    do
    {
      vi = p->vi;
      noisemaxsupp = p->noiseoffset[offset_select][v10] + *(float *)((char *)tone + v11);
      if ( noisemaxsupp > vi->noisemaxsupp )
        noisemaxsupp = vi->noisemaxsupp;
      v14 = v9 + *tone;
      if ( noisemaxsupp > v14 )
        v14 = noisemaxsupp;
      *(float *)((char *)tone + v22) = v14;
      if ( offset_select == 1 )
      {
        v15 = noisemaxsupp - *(float *)((char *)tone + v21);
        v16 = v15 <= -17.200001;
        v17 = (float)(v15 - -17.200001) * m_val;
        if ( v16 )
        {
          v18 = 1.0 - v17 * 0.0003;
        }
        else
        {
          v18 = 1.0 - v17 * 0.005;
          if ( v18 < 0.0 )
            v18 = FLOAT_0_000099999997;
        }
        *(float *)((char *)tone + v20) = *(float *)((char *)tone + v20) * v18;
      }
      ++v10;
      ++tone;
    }
    while ( v10 < n );
  }
}
