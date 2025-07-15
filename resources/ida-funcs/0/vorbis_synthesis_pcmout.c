int __cdecl vorbis_synthesis_pcmout(vorbis_dsp_state *v, float ***pcm)
{
  int pcm_returned; // eax
  vorbis_info *vi; // edx
  int v4; // eax

  pcm_returned = v->pcm_returned;
  vi = v->vi;
  if ( pcm_returned <= -1 || pcm_returned >= v->pcm_current )
    return 0;
  v4 = 0;
  if ( pcm )
  {
    if ( vi->channels > 0 )
    {
      do
      {
        v->pcmret[v4] = &v->pcm[v4][v->pcm_returned];
        ++v4;
      }
      while ( v4 < vi->channels );
    }
    *pcm = v->pcmret;
  }
  return v->pcm_current - v->pcm_returned;
}
