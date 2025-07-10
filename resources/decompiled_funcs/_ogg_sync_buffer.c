char *__usercall ogg_sync_buffer@<eax>(
        vostok::memory *a1@<edi>,
        ogg_sync_state *oy,
        vostok::memory::doug_lea_mt_allocator *size)
{
  int returned; // eax
  int fill; // eax
  vostok::memory::doug_lea_mt_allocator *v6; // ecx
  unsigned __int8 *data; // edi
  int v8; // ebx
  unsigned __int8 *v9; // eax
  vostok::memory::doug_lea_mt_allocator *v10; // ecx
  vostok::memory *v11; // [esp-8h] [ebp-Ch]

  if ( oy->storage < 0 )
    return 0;
  returned = oy->returned;
  if ( returned )
  {
    oy->fill -= returned;
    if ( oy->fill > 0 )
      memmove(oy->data, &oy->data[returned], oy->fill);
    oy->returned = 0;
  }
  fill = oy->fill;
  v6 = size;
  if ( (int)size > oy->storage - fill )
  {
    v11 = a1;
    data = oy->data;
    v8 = (int)&size[36].m_mutex.m_mutex.m_mutex[1] + fill;
    if ( oy->data )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v11);
      v9 = (unsigned __int8 *)vostok::memory::doug_lea_mt_allocator::realloc_impl(v6, data, v8);
    }
    else
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v11);
      v9 = (unsigned __int8 *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v6, v8);
    }
    if ( !v9 )
    {
      ogg_sync_clear(v10, v11, oy);
      return 0;
    }
    oy->data = v9;
    oy->storage = v8;
  }
  return (char *)&oy->data[oy->fill];
}
