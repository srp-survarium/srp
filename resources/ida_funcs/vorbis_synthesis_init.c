int __cdecl vorbis_synthesis_init(vostok::memory::doug_lea_mt_allocator *v, vorbis_info *vi)
{
  if ( vds_shared_init((vorbis_dsp_state *)v, vi) )
  {
    vorbis_dsp_clear(v);
    return 1;
  }
  else
  {
    vorbis_synthesis_restart((vorbis_dsp_state *)v);
    return 0;
  }
}
