void __userpurge vostok::memory::managed_allocator_base::resize_down(
        vostok::memory::managed_node *node@<eax>,
        vostok::memory::managed_allocator_base *this)
{
  unsigned int v4; // eax
  vostok::memory::managed_node *v5; // edx
  vostok::memory::managed_node *m_next; // edi
  vostok::memory::managed_node *v7; // eax
  vostok::memory::managed_node *v8; // ecx
  vostok::memory::managed_node *v9; // ecx
  vostok::memory::managed_allocator_base *p_m_next_free; // ecx
  vostok::memory::managed_node *v11; // [esp+8h] [ebp-4h]
  char v12; // [esp+17h] [ebp+Bh]

  v4 = vostok::math::align_up<unsigned long>(this->m_granularity);
  v5 = (vostok::memory::managed_node *)(node->m_size - v4);
  v11 = v5;
  if ( v5 )
  {
    m_next = node->m_next;
    node->m_size = v4;
    v7 = (vostok::memory::managed_node *)((char *)node + v4);
    if ( m_next && m_next->m_type == 1 )
    {
      v12 = 1;
      v8 = (vostok::memory::managed_node *)((char *)v5 + m_next->m_size);
    }
    else
    {
      v12 = 0;
      v8 = v5;
    }
    if ( v7 )
    {
      vostok::memory::managed_node::managed_node(v8, (int)v7, managed_node_free, (unsigned int)v8);
      v5 = v11;
    }
    if ( v12 )
    {
      v7->m_next = m_next->m_next;
      v9 = m_next->m_next;
      if ( v9 )
        v9->m_prev = v7;
    }
    else
    {
      v7->m_next = m_next;
      if ( m_next )
        m_next->m_prev = v7;
    }
    v7->m_prev = node;
    node->m_next = v7;
    do
      node = node->m_prev;
    while ( node && node->m_type != 1 );
    if ( v12 )
    {
      p_m_next_free = (vostok::memory::managed_allocator_base *)&node->m_next_free;
      if ( !node )
        p_m_next_free = this;
      p_m_next_free->m_first_free = v7;
      v7->m_next_free = m_next->m_next_free;
    }
    else if ( node )
    {
      v7->m_next_free = node->m_next_free;
      node->m_next_free = v7;
    }
    else
    {
      v7->m_next_free = this->m_first_free;
      this->m_first_free = v7;
    }
    if ( this->m_know_largest_free_block && v7->m_size > this->m_largest_free_block->m_size )
      this->m_largest_free_block = v7;
    this->m_free_size += (unsigned int)v5;
  }
}
