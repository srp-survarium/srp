void __cdecl vostok::memory::allocate_region(
        unsigned __int64 additional_memory_size,
        unsigned __int64 additional_address_space)
{
  int v2; // eax
  int v3; // edi
  void *v4; // esp
  allocator_data *m_begin; // edi
  allocator_data *m_end; // esi
  int arena_size; // eax
  bool v8; // cf
  vostok::buffer_vector<vostok::memory::platform::region> *arena_size_high; // ecx
  vostok::memory::base_allocator *v10; // ecx
  vostok::buffer_vector<vostok::memory::platform::region> *v11; // ecx
  vostok::memory::base_allocator *v12; // ecx
  vostok::buffer_vector<vostok::memory::platform::region> *v13; // ecx
  int *v14; // eax
  int v15; // ecx
  int v16; // edx
  _BYTE v17[16]; // [esp+0h] [ebp-50h] BYREF
  _DWORD v18[4]; // [esp+10h] [ebp-40h] BYREF
  vostok::memory::platform::region unmanaged_arena; // [esp+20h] [ebp-30h] BYREF
  vostok::memory::platform::region managed_arena; // [esp+30h] [ebp-20h] BYREF
  vostok::memory::platform::region value; // [esp+44h] [ebp-Ch] BYREF

  v2 = s_allocators.m_variable->m_end - s_allocators.m_variable->m_begin;
  s_arena_size = 0;
  v3 = 16 * ((vostok::memory::g_use_resources_manager ? 2 : 0) + v2);
  v4 = alloca(v3);
  value.address = &v17[v3];
  m_begin = s_allocators.m_variable->m_begin;
  m_end = s_allocators.m_variable->m_end;
  LODWORD(value.size) = v17;
  HIDWORD(value.size) = v17;
  while ( m_begin != m_end )
  {
    if ( m_begin->arena_size )
    {
      arena_size = m_begin->arena_size;
      v8 = __CFADD__(arena_size, (_DWORD)s_arena_size);
      LODWORD(s_arena_size) = arena_size + s_arena_size;
      arena_size_high = (vostok::buffer_vector<vostok::memory::platform::region> *)HIDWORD(m_begin->arena_size);
      v18[0] = arena_size;
      HIDWORD(s_arena_size) += (char *)arena_size_high + v8;
      v18[1] = arena_size_high;
      v18[2] = 0;
      v18[3] = m_begin;
      vostok::buffer_vector<vostok::memory::platform::region>::push_back(arena_size_high, &value, v18);
    }
    ++m_begin;
  }
  managed_arena.data = &managed_arena;
  unmanaged_arena.data = &unmanaged_arena;
  memset(&managed_arena, 0, 12);
  memset(&unmanaged_arena, 0, 12);
  vostok::memory::platform::allocate_arenas(
    additional_memory_size,
    additional_address_space,
    (vostok::buffer_vector<vostok::memory::platform::region> *)&value,
    &managed_arena,
    &unmanaged_arena);
  if ( vostok::memory::g_use_resources_manager )
  {
    vostok::memory::base_allocator::do_register(
      v10,
      (int)&vostok::memory::g_resources_managed_allocator,
      managed_arena.size,
      "resources (managed) allocator");
    managed_arena.data = &s_allocators.m_variable->m_end[-1];
    vostok::buffer_vector<vostok::memory::platform::region>::push_back(v11, &value, &managed_arena);
    vostok::memory::base_allocator::do_register(
      v12,
      (int)&vostok::memory::g_resources_unmanaged_allocator,
      unmanaged_arena.size,
      "resources (unmanaged) allocator");
    unmanaged_arena.data = &s_allocators.m_variable->m_end[-1];
    vostok::buffer_vector<vostok::memory::platform::region>::push_back(v13, &value, &unmanaged_arena);
  }
  if ( LODWORD(value.size) != HIDWORD(value.size) )
  {
    v14 = (int *)(LODWORD(value.size) + 12);
    do
    {
      v15 = *v14;
      v16 = *(v14 - 1);
      v14 += 4;
      *(_DWORD *)(v15 + 16) = v16;
    }
    while ( v14 - 3 != (int *)HIDWORD(value.size) );
  }
  vostok::memory::initialize();
}
