void __usercall vostok::memory::register_allocator(
        vostok::memory::base_allocator *allocator@<eax>,
        unsigned __int64 arena_size,
        const char *description)
{
  allocator_data **p_m_end; // eax
  allocator_data *m_end; // ecx
  __int64 temp; // [esp+0h] [ebp-18h]
  __int64 temp_16; // [esp+10h] [ebp-8h]

  LODWORD(temp) = allocator;
  HIDWORD(temp_16) = description;
  p_m_end = &s_allocators.m_variable->m_end;
  m_end = s_allocators.m_variable->m_end;
  LODWORD(temp_16) = 0;
  if ( m_end )
  {
    *(_QWORD *)&m_end->allocator = temp;
    m_end->arena_size = arena_size;
    *(_QWORD *)&m_end->arena_address = temp_16;
  }
  ++*p_m_end;
}
