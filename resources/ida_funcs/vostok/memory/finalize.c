void __cdecl vostok::memory::finalize()
{
  vostok::fixed_vector<allocator_data,32> *m_variable; // eax
  allocator_data *m_end; // edi
  allocator_data *m_begin; // ebp
  vostok::memory::base_allocator *allocator; // esi
  const char *m_arena_id; // eax
  unsigned int v5; // ecx
  void *arena_address; // edx

  vostok::core::logging_finalize();
  m_variable = s_allocators.m_variable;
  m_end = s_allocators.m_variable->m_end;
  m_begin = s_allocators.m_variable->m_begin;
  if ( m_end != s_allocators.m_variable->m_begin )
  {
    while ( 1 )
    {
      if ( m_end[-1].arena_size )
      {
        allocator = m_end[-1].allocator;
        allocator->finalize_impl(allocator);
        m_arena_id = s_crt_allocator_creation.m_arena_id;
        v5 = *(_DWORD *)&s_crt_allocator_creation.m_use_memory_monitor;
        allocator->m_arena_start = 0;
        allocator->m_arena_end = 0;
        allocator->m_arena_id = 0;
        arena_address = m_end[-1].arena_address;
        if ( !(v5 | (unsigned int)m_arena_id) )
          goto LABEL_6;
        *(_QWORD *)&s_crt_allocator_creation.m_arena_id = __PAIR64__(v5, (unsigned int)m_arena_id)
                                                        - m_end[-1].arena_size;
        if ( !*(_QWORD *)&s_crt_allocator_creation.m_arena_id )
          break;
      }
LABEL_7:
      if ( --m_end == m_begin )
      {
        m_variable = s_allocators.m_variable;
        goto LABEL_9;
      }
    }
    arena_address = s_crt_allocator_creation.m_arena_start;
LABEL_6:
    VirtualFree(arena_address, 0, 0x8000u);
    goto LABEL_7;
  }
LABEL_9:
  m_variable->m_end = m_variable->m_begin;
  s_allocators.m_initialized = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)s_process_heap_walk.m_variable);
  s_process_heap_walk.m_initialized = 0;
}
