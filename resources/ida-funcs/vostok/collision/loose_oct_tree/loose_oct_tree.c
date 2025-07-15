void __userpurge vostok::collision::loose_oct_tree::loose_oct_tree(
        vostok::collision::loose_oct_tree *this@<esi>,
        vostok::memory::base_allocator *allocator@<edi>,
        unsigned int min_aabb_extents,
        unsigned int reserve_item_count)
{
  vostok::collision::vertex_allocator *v4; // eax

  this->__vftable = (vostok::collision::loose_oct_tree_vtbl *)&vostok::collision::loose_oct_tree::`vftable';
  v4 = (vostok::collision::vertex_allocator *)allocator->call_malloc(allocator, 12);
  if ( v4 )
  {
    v4->m_allocator = allocator;
    v4->m_nodes = 0;
    v4->m_node_count = 0;
  }
  else
  {
    v4 = 0;
  }
  this->m_allocator = v4;
  this->m_root = 0;
  *(_QWORD *)&this->m_min_aabb_extents = min_aabb_extents;
  this->m_initialized = 0;
}
