void __thiscall vostok::collision::loose_oct_tree::try_collapse_top_bottom(vostok::collision::loose_oct_tree *this)
{
  const vostok::math::float4x4 *v1; // xmm5_4
  vostok::collision::oct_node *m_root; // esi
  vostok::collision::oct_node *v3; // eax
  int v4; // edx
  int v5; // ebx
  vostok::collision::vertex_allocator *m_allocator; // eax
  vostok::collision::oct_node *v7; // edi
  float v8; // xmm4_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float m_aabb_extents; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float z; // xmm1_4

  v1 = clear_value;
  do
  {
    m_root = this->m_root;
    v3 = m_root;
    v4 = -1;
    v5 = 0;
    do
    {
      if ( v3->octants[0] )
      {
        if ( v4 != -1 )
          return;
        v4 = v5 >> 2;
      }
      v3 = (vostok::collision::oct_node *)((char *)v3 + 4);
      v5 += 4;
    }
    while ( v3 != (vostok::collision::oct_node *)&m_root->parent );
    m_allocator = this->m_allocator;
    v7 = m_root->octants[v4];
    --m_allocator->m_node_count;
    m_root->parent = m_allocator->m_nodes;
    m_allocator->m_nodes = m_root;
    this->m_root = v7;
    v7->parent = 0;
    this->m_aabb_extents = this->m_aabb_extents * 0.5;
    if ( (v4 & 4) != 0 )
      v8 = *(float *)&v1;
    else
      v8 = -1.0;
    if ( (v4 & 2) != 0 )
      v9 = *(float *)&v1;
    else
      v9 = -1.0;
    if ( (v4 & 1) != 0 )
      v10 = *(float *)&v1;
    else
      v10 = -1.0;
    m_aabb_extents = this->m_aabb_extents;
    v12 = m_aabb_extents * v10;
    v13 = m_aabb_extents * v9;
    v14 = this->m_aabb_center.x + v12;
    this->m_aabb_center.y = this->m_aabb_center.y + v13;
    z = this->m_aabb_center.z;
    this->m_aabb_center.x = v14;
    this->m_aabb_center.z = z + (float)(m_aabb_extents * v8);
  }
  while ( !this->m_root->objects );
}
