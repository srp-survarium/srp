void __thiscall vostok::collision::loose_oct_tree::remove_nodes(
        vostok::collision::loose_oct_tree *this,
        vostok::collision::oct_node *node)
{
  vostok::collision::oct_node **p_parent; // ebx
  vostok::collision::oct_node *v4; // ebp
  vostok::collision::oct_node *m_head; // eax

  p_parent = &node->parent;
  v4 = node;
  do
  {
    if ( v4->octants[0] )
      vostok::collision::loose_oct_tree::remove_nodes(this, v4->octants[0]);
    v4 = (vostok::collision::oct_node *)((char *)v4 + 4);
  }
  while ( v4 != (vostok::collision::oct_node *)p_parent );
  m_head = this->m_head;
  --this->m_allocated_nodes_count;
  *p_parent = m_head;
  this->m_head = node;
}
