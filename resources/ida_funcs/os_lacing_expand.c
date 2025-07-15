int __usercall os_lacing_expand@<eax>(ogg_stream_state *os@<esi>, int needed@<eax>)
{
  int lacing_storage; // eax
  vostok::memory::doug_lea_mt_allocator *v4; // ecx
  int *lacing_vals; // ebp
  unsigned int v6; // ebx
  int *v7; // eax
  vostok::memory::doug_lea_mt_allocator *v8; // ecx
  __int64 *granule_vals; // ebp
  int v11; // ebx
  unsigned int v12; // ebx
  __int64 *v13; // eax
  vostok::memory *v14; // [esp+0h] [ebp-Ch]

  lacing_storage = os->lacing_storage;
  v4 = (vostok::memory::doug_lea_mt_allocator *)(needed + os->lacing_fill);
  if ( lacing_storage <= (int)v4 )
  {
    lacing_vals = os->lacing_vals;
    v6 = 4 * (lacing_storage + needed) + 128;
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v14);
    v7 = (int *)vostok::memory::doug_lea_mt_allocator::realloc_impl(v4, lacing_vals, v6);
    if ( !v7 )
      goto LABEL_5;
    granule_vals = os->granule_vals;
    v11 = needed + os->lacing_storage;
    os->lacing_vals = v7;
    v12 = 8 * v11 + 256;
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v14);
    v13 = (__int64 *)vostok::memory::doug_lea_mt_allocator::realloc_impl(v8, granule_vals, v12);
    if ( !v13 )
    {
LABEL_5:
      ogg_stream_clear(os);
      return -1;
    }
    os->lacing_storage += needed + 32;
    os->granule_vals = v13;
  }
  return 0;
}
