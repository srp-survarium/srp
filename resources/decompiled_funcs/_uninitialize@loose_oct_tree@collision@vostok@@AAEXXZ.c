void __thiscall vostok::collision::loose_oct_tree::uninitialize(vostok::collision::loose_oct_tree *this)
{
  vostok::collision::vertex_allocator *m_allocator; // eax
  vostok::collision::oct_node *m_root; // edx

  m_allocator = this->m_allocator;
  m_root = this->m_root;
  --m_allocator->m_node_count;
  m_root->parent = m_allocator->m_nodes;
  m_allocator->m_nodes = m_root;
  this->m_root = 0;
  this->m_initialized = 0;
}
