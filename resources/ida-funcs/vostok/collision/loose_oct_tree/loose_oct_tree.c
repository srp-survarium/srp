void __userpurge vostok::collision::loose_oct_tree::loose_oct_tree(
        vostok::collision::oct_node *nodes@<edx>,
        unsigned int nodes_count@<ecx>,
        vostok::collision::loose_oct_tree *this,
        float min_aabb_extents)
{
  float v4; // xmm0_4
  vostok::collision::oct_node *v5; // ecx
  vostok::collision::oct_node *v6; // esi

  v4 = s_bm_current_air_resistance;
  this->m_nodes_count = nodes_count;
  v5 = &nodes[nodes_count];
  this->__vftable = (vostok::collision::loose_oct_tree_vtbl *)&vostok::collision::loose_oct_tree::`vftable';
  this->m_root = 0;
  this->m_nodes = nodes;
  this->m_min_aabb_extents = v4;
  this->m_objects_count = 0;
  this->m_allocated_nodes_count = 0;
  this->m_initialized = 0;
  v6 = 0;
  while ( nodes != v5 )
  {
    if ( v6 )
      v6->parent = nodes;
    v6 = nodes++;
  }
  this->m_nodes[this->m_nodes_count - 1].parent = 0;
  this->m_head = this->m_nodes;
}
