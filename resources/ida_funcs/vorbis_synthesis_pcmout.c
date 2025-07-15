int __cdecl vorbis_synthesis_pcmout(vorbis_dsp_state *v, float ***pcm)
{
  int pcm_returned; // eax
  vorbis_info *vi; // edx
  int i; // eax

  pcm_returned = v->pcm_returned;
  vi = v->vi;
  if ( pcm_returned <= -1 || pcm_returned >= v->pcm_current )
    return 0;
  if ( pcm )
  {
    for ( i = 0; i < vi->channels; ++i )
      v->pcmret[i] = &v->pcm[i][v->pcm_returned];
    *pcm = v->pcmret;
  }
  return v->pcm_current - v->pcm_returned;
}
