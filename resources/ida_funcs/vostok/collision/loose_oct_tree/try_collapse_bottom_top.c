char __thiscall vostok::collision::loose_oct_tree::try_collapse_bottom_top(
        vostok::collision::loose_oct_tree *this,
        vostok::collision::oct_node *node)
{
  vostok::collision::oct_node **p_parent; // edi
  int v3; // ebx
  vostok::collision::oct_node *v5; // eax
  int v6; // ecx
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v10; // xmm3_4
  float m_aabb_extents; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float z; // xmm1_4
  vostok::collision::vertex_allocator *m_allocator; // esi
  vostok::collision::oct_node *m_nodes; // eax

  p_parent = &node->parent;
  v3 = -1;
  v5 = node;
  v6 = 0;
  do
  {
    if ( v5->octants[0] )
    {
      if ( v3 != -1 )
        return 0;
      v3 = v6 >> 2;
    }
    v5 = (vostok::collision::oct_node *)((char *)v5 + 4);
    v6 += 4;
  }
  while ( v5 != (vostok::collision::oct_node *)p_parent );
  if ( *p_parent && !vostok::collision::loose_oct_tree::try_collapse_bottom_top(this, *p_parent) || node->objects )
    return 0;
  v7 = *(float *)&clear_value;
  this->m_aabb_extents = this->m_aabb_extents * 0.5;
  if ( (v3 & 4) != 0 )
    v8 = v7;
  else
    v8 = -1.0;
  if ( (v3 & 2) != 0 )
    v10 = v7;
  else
    v10 = -1.0;
  if ( (v3 & 1) == 0 )
    v7 = -1.0;
  m_aabb_extents = this->m_aabb_extents;
  v12 = m_aabb_extents * v7;
  v13 = m_aabb_extents * v10;
  v14 = this->m_aabb_center.x + v12;
  this->m_aabb_center.y = this->m_aabb_center.y + v13;
  z = this->m_aabb_center.z;
  this->m_aabb_center.x = v14;
  this->m_aabb_center.z = z + (float)(m_aabb_extents * v8);
  m_allocator = this->m_allocator;
  m_nodes = m_allocator->m_nodes;
  --m_allocator->m_node_count;
  *p_parent = m_nodes;
  m_allocator->m_nodes = node;
  return 1;
}
