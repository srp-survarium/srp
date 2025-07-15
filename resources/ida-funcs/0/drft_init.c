void __usercall drft_init(int n@<esi>, vostok::memory::doug_lea_mt_allocator *a2@<ecx>, drft_lookup *l)
{
  float *v3; // ebx
  vostok::memory::doug_lea_mt_allocator *v4; // ecx
  int *v5; // edi
  vostok::memory *v6; // [esp+0h] [ebp-10h]

  l->n = n;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v6);
  v3 = (float *)vostok::memory::doug_lea_mt_allocator::malloc_impl(a2, 12 * n);
  memset((int)v3, 0, 12 * n);
  l->trigcache = v3;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v6);
  v5 = (int *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v4, 0x80u);
  memset((int)v5, 0, 0x80u);
  l->splitcache = v5;
  if ( n != 1 )
    drfti1(n, &l->trigcache[n], v5);
}
