void __cdecl res0_free_info(void *i)
{
  vostok::memory::doug_lea_mt_allocator *v1; // ecx
  vostok::memory *v2; // [esp+0h] [ebp-4h]

  if ( i )
  {
    memset((int)i, 0, 0xB18u);
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v2);
    vostok::memory::doug_lea_mt_allocator::free_impl(v1, i);
  }
}
