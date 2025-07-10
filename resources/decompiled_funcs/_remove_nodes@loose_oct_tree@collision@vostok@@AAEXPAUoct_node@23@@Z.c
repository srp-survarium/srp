void __thiscall vostok::collision::loose_oct_tree::remove_nodes(
        vostok::collision::loose_oct_tree *this,
        vostok::collision::oct_node *node)
{
  vostok::collision::oct_node **p_parent; // edi
  vostok::collision::oct_node *v4; // esi
  vostok::collision::vertex_allocator *m_allocator; // eax
  vostok::collision::oct_node *m_nodes; // ecx

  p_parent = &node->parent;
  v4 = node;
  do
  {
    if ( v4->octants[0] )
      vostok::collision::loose_oct_tree::remove_nodes(this, v4->octants[0]);
    v4 = (vostok::collision::oct_node *)((char *)v4 + 4);
  }
  while ( v4 != (vostok::collision::oct_node *)p_parent );
  m_allocator = this->m_allocator;
  m_nodes = m_allocator->m_nodes;
  --m_allocator->m_node_count;
  *p_parent = m_nodes;
  m_allocator->m_nodes = node;
}
