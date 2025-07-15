int __usercall ogg_stream_init@<eax>(vostok::memory *a1@<edi>, ogg_stream_state *os, int serialno)
{
  vostok::memory::doug_lea_mt_allocator *v3; // ecx
  unsigned __int8 *v4; // eax
  vostok::memory::doug_lea_mt_allocator *v5; // ecx
  int v6; // edi
  unsigned int v7; // edi
  int *v8; // eax
  vostok::memory::doug_lea_mt_allocator *v9; // ecx
  int v10; // edi
  unsigned int v11; // edi
  __int64 *v12; // eax
  bool v13; // zf
  vostok::memory *v15; // [esp-4h] [ebp-8h]
  vostok::memory *v16; // [esp+0h] [ebp-4h]

  if ( os )
  {
    memset((int)os, 0, sizeof(ogg_stream_state));
    os->body_storage = 0x4000;
    os->lacing_storage = 1024;
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v16);
    v15 = a1;
    v4 = (unsigned __int8 *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v3, 0x4000u);
    v6 = 2 * os->lacing_storage;
    os->body_data = v4;
    v7 = 2 * v6;
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v15);
    v8 = (int *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v5, v7);
    v10 = 4 * os->lacing_storage;
    os->lacing_vals = v8;
    v11 = 2 * v10;
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v15);
    v12 = (__int64 *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v9, v11);
    v13 = os->body_data == 0;
    os->granule_vals = v12;
    if ( !v13 && os->lacing_vals && v12 )
    {
      os->serialno = serialno;
      return 0;
    }
    ogg_stream_clear(os);
  }
  return -1;
}
