int __usercall vorbis_synthesis_init@<eax>(__int128 a1@<xmm0>, vorbis_dsp_state *v, vorbis_info *vi)
{
  if ( vds_shared_init(a1, v, vi) )
  {
    vorbis_dsp_clear(v);
    return 1;
  }
  else
  {
    vorbis_synthesis_restart(v);
    return 0;
  }
}
