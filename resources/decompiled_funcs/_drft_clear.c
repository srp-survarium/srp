void __usercall drft_clear(drft_lookup *l@<esi>, vostok::memory::doug_lea_mt_allocator *a2@<ecx>)
{
  float *trigcache; // edi
  int *splitcache; // edi
  vostok::memory *v4; // [esp+0h] [ebp-4h]

  if ( l )
  {
    trigcache = l->trigcache;
    if ( trigcache )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v4);
      vostok::memory::doug_lea_mt_allocator::free_impl(a2, trigcache);
    }
    splitcache = l->splitcache;
    if ( splitcache )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v4);
      vostok::memory::doug_lea_mt_allocator::free_impl(a2, splitcache);
    }
    l->n = 0;
    l->trigcache = 0;
    l->splitcache = 0;
  }
}
