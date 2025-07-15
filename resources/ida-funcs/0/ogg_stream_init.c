int __cdecl ogg_stream_init(ogg_stream_state *os, int serialno)
{
  __int64 *v2; // eax
  bool v3; // zf

  if ( os )
  {
    memset((int)os, 0, sizeof(ogg_stream_state));
    os->body_storage = 0x4000;
    os->lacing_storage = 1024;
    os->body_data = (unsigned __int8 *)ogg_malloc_impl(0x4000u);
    os->lacing_vals = (int *)ogg_malloc_impl(4 * os->lacing_storage);
    v2 = (__int64 *)ogg_malloc_impl(8 * os->lacing_storage);
    v3 = os->body_data == 0;
    os->granule_vals = v2;
    if ( !v3 && os->lacing_vals && v2 )
    {
      os->serialno = serialno;
      return 0;
    }
    ogg_stream_clear(os);
  }
  return -1;
}
