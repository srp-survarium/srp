void __userpurge vostok::memory::managed_allocator_base::resize_down(
        vostok::memory::managed_node *node@<edi>,
        unsigned int new_lesser_size@<eax>,
        vostok::memory::managed_allocator_base *this)
{
  unsigned int m_granularity; // ecx
  unsigned int v5; // ecx
  vostok::memory::managed_node *m_next; // esi
  vostok::memory::managed_node *v7; // eax
  unsigned int v8; // ecx
  char v9; // dl
  vostok::memory::managed_node *v10; // ecx
  vostok::memory::managed_node *m_prev; // ecx
  unsigned int size_diff; // [esp+10h] [ebp+4h]

  m_granularity = this->m_granularity;
  if ( new_lesser_size % m_granularity )
    v5 = new_lesser_size + m_granularity - new_lesser_size % m_granularity;
  else
    v5 = new_lesser_size;
  size_diff = node->m_size - v5;
  if ( size_diff )
  {
    m_next = node->m_next;
    node->m_size = v5;
    v7 = (vostok::memory::managed_node *)((char *)node + v5);
    if ( m_next && m_next->m_type == 1 )
    {
      v8 = size_diff + m_next->m_size;
      v9 = 1;
    }
    else
    {
      v8 = size_diff;
      v9 = 0;
    }
    if ( v7 )
    {
      v7->m_is_unmovable = 0;
      v7->m_pin_count = 0;
      v7->m_type = 1;
      v7->m_size = v8;
      v7->m_next = 0;
      v7->m_prev = 0;
      v7->m_next_free = 0;
      v7->m_owner = 0;
      v7->m_next_pinned = 0;
      v7->m_next_wait_for_free = 0;
      v7->m_defrag_iteration = 0;
      v7->m_place_pos = 0;
      v7->m_unpin_notify_allocator = 0;
    }
    if ( v9 )
    {
      v7->m_next = m_next->m_next;
      v10 = m_next->m_next;
      if ( v10 )
        v10->m_prev = v7;
    }
    else
    {
      v7->m_next = m_next;
      if ( m_next )
        m_next->m_prev = v7;
    }
    v7->m_prev = node;
    m_prev = node->m_prev;
    for ( node->m_next = v7; m_prev; m_prev = m_prev->m_prev )
    {
      if ( m_prev->m_type == 1 )
        break;
    }
    if ( v9 )
    {
      if ( m_prev )
        m_prev->m_next_free = v7;
      else
        this->m_first_free = v7;
      v7->m_next_free = m_next->m_next_free;
    }
    else if ( m_prev )
    {
      v7->m_next_free = m_prev->m_next_free;
      m_prev->m_next_free = v7;
    }
    else
    {
      v7->m_next_free = this->m_first_free;
      this->m_first_free = v7;
    }
    if ( this->m_know_largest_free_block && v7->m_size > this->m_largest_free_block->m_size )
      this->m_largest_free_block = v7;
    this->m_free_size += size_diff;
  }
}
