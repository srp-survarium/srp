int __cdecl ogg_stream_clear(ogg_stream_state *os)
{
  vostok::memory::doug_lea_mt_allocator *v1; // ecx
  unsigned __int8 *body_data; // esi
  int *lacing_vals; // esi
  __int64 *granule_vals; // esi
  vostok::memory *v6; // [esp+0h] [ebp-8h]

  if ( os )
  {
    body_data = os->body_data;
    if ( os->body_data )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v6);
      vostok::memory::doug_lea_mt_allocator::free_impl(v1, body_data);
    }
    lacing_vals = os->lacing_vals;
    if ( lacing_vals )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v6);
      vostok::memory::doug_lea_mt_allocator::free_impl(v1, lacing_vals);
    }
    granule_vals = os->granule_vals;
    if ( granule_vals )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v6);
      vostok::memory::doug_lea_mt_allocator::free_impl(v1, granule_vals);
    }
    memset((int)os, 0, sizeof(ogg_stream_state));
  }
  return 0;
}
