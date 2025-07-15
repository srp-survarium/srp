vostok::memory::managed_node *__userpurge vostok::memory::managed_allocator_base::allocate_in_node@<eax>(
        vostok::memory::managed_node *node@<esi>,
        vostok::memory::managed_node *this,
        unsigned int full_size,
        vostok::memory::managed_node *offset_in_node,
        vostok::memory::managed_node *prev_free_node)
{
  vostok::memory::managed_node *i; // eax
  unsigned int m_size; // ebx
  vostok::memory::managed_node *v8; // edi
  vostok::memory::managed_node *v9; // ecx
  unsigned int v10; // edx
  vostok::memory::managed_node *v11; // eax
  vostok::memory::managed_node *v12; // eax
  vostok::memory::managed_node *m_prev; // [esp+0h] [ebp-Ch]
  vostok::memory::managed_node *m_next_free; // [esp+4h] [ebp-8h]
  vostok::memory::managed_node *m_next; // [esp+8h] [ebp-4h]

  if ( node->m_size < full_size )
    return 0;
  if ( node != (vostok::memory::managed_node *)this->m_owner && !offset_in_node )
  {
    for ( i = node->m_prev; i && i->m_type != 1; i = i->m_prev )
      ;
    offset_in_node = i;
  }
  if ( LOBYTE(this->m_prev) && node == this->m_next_free )
  {
    this->m_next_free = 0;
    LOBYTE(this->m_prev) = 0;
  }
  m_size = node->m_size;
  m_next_free = node->m_next_free;
  m_next = node->m_next;
  v8 = 0;
  m_prev = node->m_prev;
  vostok::memory::managed_node::managed_node(this, (int)node, managed_node_allocated, full_size);
  v10 = full_size;
  if ( m_size > full_size )
  {
    v8 = (vostok::memory::managed_node *)((char *)node + full_size);
    if ( (vostok::memory::managed_node *)((char *)node + full_size) )
    {
      vostok::memory::managed_node::managed_node(v9, (int)node + full_size, managed_node_free, m_size - full_size);
      v10 = full_size;
    }
  }
  node->m_prev = m_prev;
  v11 = v8;
  if ( !v8 )
    v11 = m_next;
  node->m_next = v11;
  if ( v8 )
  {
    v8->m_next = m_next;
    if ( m_next )
      m_next->m_prev = v8;
    v8->m_prev = node;
    v8->m_next_free = m_next_free;
  }
  if ( m_next )
  {
    v12 = v8;
    if ( !v8 )
      v12 = node;
    m_next->m_prev = v12;
  }
  this->m_place_pos -= v10;
  if ( !v8 )
    v8 = m_next_free;
  if ( node == (vostok::memory::managed_node *)this->m_owner )
    this->m_owner = (vostok::memory::managed_node_owner *)v8;
  else
    offset_in_node->m_next_free = v8;
  node->m_next_free = 0;
  return node;
}
