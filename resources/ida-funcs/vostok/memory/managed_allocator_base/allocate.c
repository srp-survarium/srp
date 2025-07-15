vostok::memory::managed_node *__userpurge vostok::memory::managed_allocator_base::allocate@<eax>(
        vostok::memory::managed_allocator_base *this@<ecx>,
        vostok::memory::managed_allocator_base *requested_size,
        vostok::memory::managed_node *start_free_node)
{
  unsigned int p_m_know_largest_free_block; // ecx
  unsigned int m_granularity; // esi
  vostok::memory::managed_node *m_first_free; // edx
  vostok::memory::managed_node *v6; // eax
  vostok::memory::managed_node *v7; // esi
  unsigned int v8; // edi
  vostok::memory::managed_node *result; // eax
  vostok::memory::managed_node *v10; // edx
  vostok::memory::managed_node *v11; // [esp+0h] [ebp-Ch]

  p_m_know_largest_free_block = (unsigned int)&this[1].m_know_largest_free_block;
  m_granularity = requested_size->m_granularity;
  if ( p_m_know_largest_free_block % m_granularity )
    p_m_know_largest_free_block = m_granularity
                                + p_m_know_largest_free_block
                                - p_m_know_largest_free_block % m_granularity;
  m_first_free = requested_size->m_first_free;
  v6 = 0;
  v7 = 0;
  v8 = p_m_know_largest_free_block;
  if ( requested_size->m_first_free )
  {
    while ( 1 )
    {
      result = vostok::memory::managed_allocator_base::allocate_in_node(
                 v8,
                 m_first_free,
                 (vostok::memory::managed_node *)p_m_know_largest_free_block,
                 requested_size,
                 v6,
                 v11);
      if ( result )
        break;
      if ( !v7 || v7->m_size < v10->m_size )
        v7 = v10;
      v6 = v10;
      m_first_free = v10->m_next_free;
      if ( !m_first_free )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    requested_size->m_know_largest_free_block = 1;
    requested_size->m_largest_free_block = v7;
    return 0;
  }
  return result;
}
