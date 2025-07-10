void __usercall vorbis_bitrate_clear(bitrate_manager_state *bm@<eax>)
{
  memset((int)bm, 0, sizeof(bitrate_manager_state));
}
