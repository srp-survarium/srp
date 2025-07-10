int __cdecl vorbis_synthesis_read(vorbis_dsp_state *v, int n)
{
  if ( n && n + v->pcm_returned > v->pcm_current )
    return -131;
  v->pcm_returned += n;
  return 0;
}
