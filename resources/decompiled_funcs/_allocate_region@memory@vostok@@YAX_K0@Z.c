void __cdecl vostok::memory::allocate_region(
        unsigned __int64 additional_memory_size,
        unsigned __int64 additional_address_space)
{
  unsigned int v2; // ebx
  int v3; // eax
  void *v4; // esp
  vostok::memory::platform::region *v5; // edi
  allocator_data *m_begin; // eax
  allocator_data *m_end; // esi
  unsigned int arena_size; // ecx
  unsigned int arena_size_high; // edx
  int v10; // et0
  allocator_data **p_m_end; // eax
  allocator_data *v12; // ecx
  vostok::memory::platform::region *v13; // eax
  allocator_data **v14; // ecx
  allocator_data *v15; // edx
  vostok::memory::platform::region *v16; // eax
  vostok::memory::platform::region *v17; // eax
  void **p_data; // ecx
  _DWORD *v19; // edx
  int v20; // esi
  _BYTE v21[16]; // [esp+0h] [ebp-58h] BYREF
  __int64 v22; // [esp+10h] [ebp-48h]
  vostok::memory::platform::region value; // [esp+18h] [ebp-40h]
  vostok::memory::platform::region unmanaged_arena; // [esp+28h] [ebp-30h] BYREF
  vostok::memory::platform::region managed_arena; // [esp+38h] [ebp-20h] BYREF
  vostok::buffer_vector<vostok::memory::platform::region> regions; // [esp+4Ch] [ebp-Ch] BYREF
  allocator_data *e; // [esp+54h] [ebp-4h]

  v2 = 0;
  v3 = 16
     * ((vostok::memory::g_use_resources_manager ? 2 : 0)
      + s_allocators.m_variable->m_end
      - s_allocators.m_variable->m_begin);
  s_arena_size = 0;
  v4 = alloca(v3);
  v5 = (vostok::memory::platform::region *)v21;
  regions.m_begin = (vostok::memory::platform::region *)v21;
  m_begin = s_allocators.m_variable->m_begin;
  m_end = s_allocators.m_variable->m_end;
  regions.m_end = (vostok::memory::platform::region *)v21;
  e = m_end;
  if ( m_begin != m_end )
  {
    do
    {
      if ( m_begin->arena_size )
      {
        arena_size = m_begin->arena_size;
        arena_size_high = HIDWORD(m_begin->arena_size);
        v10 = (__PAIR64__(arena_size_high, arena_size) + __PAIR64__(HIDWORD(s_arena_size), v2)) >> 32;
        v2 += arena_size;
        HIDWORD(s_arena_size) = v10;
        value.size = __PAIR64__(arena_size_high, arena_size);
        value.address = 0;
        value.data = m_begin;
        if ( v5 )
          *v5 = value;
        m_end = e;
        ++v5;
      }
      ++m_begin;
    }
    while ( m_begin != m_end );
    regions.m_end = v5;
    LODWORD(s_arena_size) = v2;
  }
  unmanaged_arena.data = &unmanaged_arena;
  managed_arena.data = &managed_arena;
  memset(&managed_arena, 0, 12);
  memset(&unmanaged_arena, 0, 12);
  vostok::memory::platform::allocate_arenas(
    additional_memory_size,
    additional_address_space,
    &regions,
    &managed_arena,
    &unmanaged_arena);
  if ( vostok::memory::g_use_resources_manager )
  {
    value.size = managed_arena.size;
    p_m_end = &s_allocators.m_variable->m_end;
    v12 = s_allocators.m_variable->m_end;
    LODWORD(v22) = &vostok::memory::g_resources_managed_allocator;
    value.address = 0;
    value.data = "resources (managed) allocator";
    if ( v12 )
    {
      *(_QWORD *)&v12->allocator = v22;
      *(vostok::memory::platform::region *)&v12->arena_size = value;
    }
    ++*p_m_end;
    managed_arena.data = &s_allocators.m_variable->m_end[-1];
    v13 = regions.m_end;
    if ( regions.m_end )
    {
      regions.m_end->size = managed_arena.size;
      *(_QWORD *)&v13->address = *(_QWORD *)&managed_arena.address;
    }
    value.size = unmanaged_arena.size;
    v14 = &s_allocators.m_variable->m_end;
    v15 = s_allocators.m_variable->m_end;
    v16 = v13 + 1;
    LODWORD(v22) = &vostok::memory::g_resources_unmanaged_allocator;
    value.address = 0;
    value.data = "resources (unmanaged) allocator";
    if ( v15 )
    {
      *(_QWORD *)&v15->allocator = v22;
      *(vostok::memory::platform::region *)&v15->arena_size = value;
    }
    ++*v14;
    unmanaged_arena.data = &s_allocators.m_variable->m_end[-1];
    if ( v16 )
      *v16 = unmanaged_arena;
    v17 = v16 + 1;
  }
  else
  {
    v17 = regions.m_end;
  }
  if ( regions.m_begin != v17 )
  {
    p_data = &regions.m_begin->data;
    do
    {
      v19 = *p_data;
      v20 = (int)*(p_data - 1);
      p_data += 4;
      v19[4] = v20;
    }
    while ( p_data - 3 != (void **)v17 );
  }
  vostok::memory::initialize();
}
