vostok::memory::managed_node *__userpurge vostok::memory::managed_allocator_base::allocate_in_node@<eax>(
        unsigned int full_size@<edi>,
        vostok::memory::managed_node *node@<edx>,
        vostok::memory::managed_node *a3@<ecx>,
        vostok::memory::managed_allocator_base *this,
        vostok::memory::managed_node *offset_in_node,
        vostok::memory::managed_node *prev_free_node)
{
  unsigned int m_size; // esi
  vostok::memory::managed_node *m_prev; // ebp
  vostok::memory::managed_node *m_next; // eax
  vostok::memory::managed_node *v10; // ecx
  vostok::memory::managed_node *v11; // esi
  vostok::memory::managed_node *v12; // esi
  vostok::memory::managed_node *node_next_free; // [esp+0h] [ebp-4h]

  if ( node->m_size < full_size )
    return 0;
  if ( node != this->m_first_free && !offset_in_node )
    offset_in_node = vostok::memory::managed_node::find_prev_free(a3, (int)node);
  if ( this->m_know_largest_free_block && node == this->m_largest_free_block )
  {
    this->m_know_largest_free_block = 0;
    this->m_largest_free_block = 0;
  }
  m_size = node->m_size;
  m_prev = node->m_prev;
  node_next_free = node->m_next_free;
  m_next = node->m_next;
  v10 = 0;
  node->m_is_unmovable = 0;
  node->m_pin_count = 0;
  node->m_type = 0;
  node->m_size = full_size;
  node->m_next = 0;
  node->m_prev = 0;
  node->m_next_free = 0;
  node->m_owner = 0;
  node->m_next_pinned = 0;
  node->m_next_wait_for_free = 0;
  node->m_defrag_iteration = 0;
  node->m_place_pos = 0;
  node->m_unpin_notify_allocator = 0;
  if ( m_size > full_size )
  {
    v10 = (vostok::memory::managed_node *)((char *)node + full_size);
    if ( (vostok::memory::managed_node *)((char *)node + full_size) )
    {
      v10->m_is_unmovable = 0;
      v10->m_pin_count = 0;
      v10->m_type = 1;
      v10->m_size = m_size - full_size;
      v10->m_next = 0;
      v10->m_prev = 0;
      v10->m_next_free = 0;
      v10->m_owner = 0;
      v10->m_next_pinned = 0;
      v10->m_next_wait_for_free = 0;
      v10->m_defrag_iteration = 0;
      v10->m_place_pos = 0;
      v10->m_unpin_notify_allocator = 0;
    }
  }
  node->m_prev = m_prev;
  v11 = v10;
  if ( !v10 )
    v11 = m_next;
  node->m_next = v11;
  if ( v10 )
  {
    v10->m_next = m_next;
    if ( m_next )
      m_next->m_prev = v10;
    v10->m_prev = node;
    v10->m_next_free = node_next_free;
  }
  if ( m_next )
  {
    v12 = v10;
    if ( !v10 )
      v12 = node;
    m_next->m_prev = v12;
  }
  this->m_free_size -= full_size;
  if ( !v10 )
    v10 = node_next_free;
  if ( node == this->m_first_free )
    this->m_first_free = v10;
  else
    offset_in_node->m_next_free = v10;
  node->m_next_free = 0;
  return node;
}
