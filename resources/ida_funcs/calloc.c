void *__cdecl calloc(unsigned int count, unsigned int element_size)
{
  vostok::memory::doug_lea_mt_allocator *v2; // ecx
  void *v3; // edi
  vostok::memory *v5; // [esp+0h] [ebp-Ch]

  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v5);
  v3 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v2, element_size * count);
  memset((int)v3, 0, element_size * count);
  return v3;
}
