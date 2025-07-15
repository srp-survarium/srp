int __cdecl ogg_stream_clear(ogg_stream_state *os)
{
  if ( os )
  {
    if ( os->body_data )
      ogg_free_impl(os->body_data);
    if ( os->lacing_vals )
      ogg_free_impl(os->lacing_vals);
    if ( os->granule_vals )
      ogg_free_impl(os->granule_vals);
    memset((int)os, 0, sizeof(ogg_stream_state));
  }
  return 0;
}
