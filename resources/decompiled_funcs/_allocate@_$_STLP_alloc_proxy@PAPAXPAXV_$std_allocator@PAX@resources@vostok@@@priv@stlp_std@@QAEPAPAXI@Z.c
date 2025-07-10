void **__usercall stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::resources::std_allocator<void *>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::resources::std_allocator<void *> > *this)
{
  bool v2; // cf
  unsigned int *v3; // eax
  void **result; // eax
  int v5; // [esp+0h] [ebp-8h] BYREF
  unsigned int v6; // [esp+4h] [ebp-4h] BYREF

  v6 = __n;
  v2 = __n == 0;
  v5 = 1;
  v3 = (unsigned int *)&v5;
  if ( !v2 )
    v3 = &v6;
  result = (void **)(4 * *v3);
  if ( vostok::memory::g_resources_helper_allocator.m_out_of_memory )
  {
    vostok::memory::g_resources_helper_allocator.m_out_of_memory = 1;
    if ( result )
      return (void **)vostok_mspace_malloc(vostok::memory::g_resources_helper_allocator.m_arena, (unsigned int)result);
  }
  vostok::memory::g_resources_helper_allocator.m_out_of_memory = 0;
  if ( result )
    return (void **)vostok_mspace_malloc(vostok::memory::g_resources_helper_allocator.m_arena, (unsigned int)result);
  return result;
}
