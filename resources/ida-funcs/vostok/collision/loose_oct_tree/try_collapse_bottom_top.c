char __thiscall vostok::collision::loose_oct_tree::try_collapse_bottom_top(
        vostok::collision::loose_oct_tree *this,
        vostok::collision::oct_node *node)
{
  vostok::collision::oct_node **p_parent; // edi
  vostok::collision::oct_node *v5; // ecx
  int v6; // edx
  vostok::math::float3 *v7; // eax
  float m_aabb_extents; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float x; // xmm3_4
  vostok::collision::oct_node *m_head; // eax
  vostok::math::float3 v15; // [esp+Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp+8h]

  v16 = -1;
  p_parent = &node->parent;
  v5 = node;
  v6 = 0;
  do
  {
    if ( v5->octants[0] )
    {
      if ( v16 != -1 )
        return 0;
      v16 = v6 >> 2;
    }
    v5 = (vostok::collision::oct_node *)((char *)v5 + 4);
    v6 += 4;
  }
  while ( v5 != (vostok::collision::oct_node *)p_parent );
  if ( (!*p_parent || vostok::collision::loose_oct_tree::try_collapse_bottom_top(this, *p_parent)) && !node->objects )
  {
    this->m_aabb_extents = this->m_aabb_extents * 0.5;
    v7 = vostok::collision::octant_vector(&v15, (vostok::math::float3 *)v16);
    m_aabb_extents = this->m_aabb_extents;
    v9 = (float)(v7->y * m_aabb_extents) + this->m_aabb_center.y;
    v10 = (float)(v7->z * m_aabb_extents) + this->m_aabb_center.z;
    v11 = v7->x * m_aabb_extents;
    x = this->m_aabb_center.x;
    this->m_aabb_center.y = v9;
    this->m_aabb_center.z = v10;
    this->m_aabb_center.x = x + v11;
    m_head = this->m_head;
    --this->m_allocated_nodes_count;
    *p_parent = m_head;
    this->m_head = node;
    return 1;
  }
  return 0;
}
