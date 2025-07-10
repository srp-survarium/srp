void **__usercall stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::input::std_allocator<void *>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::input::std_allocator<void *> > *this)
{
  bool v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // eax
  unsigned int v7; // ecx
  int v9; // [esp+0h] [ebp-8h] BYREF
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v10 = __n;
  v3 = __n == 0;
  v9 = 1;
  v4 = (unsigned int *)&v9;
  if ( !v3 )
    v4 = &v10;
  v5 = *v4;
  v6 = vostok::input::g_allocator;
  v7 = 4 * v5;
  if ( !vostok::input::g_allocator->m_out_of_memory || !v7 )
    v2 = 0;
  vostok::input::g_allocator->m_out_of_memory = v2;
  if ( v7 )
    return (void **)vostok_mspace_malloc(v6->m_arena, v7);
  else
    return 0;
}
