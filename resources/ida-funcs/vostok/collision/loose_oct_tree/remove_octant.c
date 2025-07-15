void __userpurge vostok::collision::loose_oct_tree::remove_octant(
        vostok::collision::loose_oct_tree *this@<ecx>,
        vostok::collision::oct_node *node@<eax>,
        vostok::collision::oct_node *const child)
{
  int v5; // ebx
  vostok::collision::oct_node *v6; // eax
  vostok::collision::oct_node *v7; // ecx
  vostok::collision::oct_node *m_root; // eax
  vostok::collision::oct_node *m_head; // ecx
  vostok::collision::loose_oct_tree *v10; // ecx
  vostok::math::float3 *v11; // eax
  float m_aabb_extents; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  vostok::collision::oct_node *v17; // eax
  vostok::collision::oct_node *v18; // eax
  vostok::collision::oct_node *v19; // eax
  vostok::collision::loose_oct_tree *v20; // [esp-4h] [ebp-24h]
  vostok::math::float3 v21; // [esp+Ch] [ebp-14h] BYREF
  int v22; // [esp+18h] [ebp-8h]
  unsigned int v23; // [esp+1Ch] [ebp-4h]

  while ( 1 )
  {
    if ( !node )
    {
      m_root = this->m_root;
      m_head = this->m_head;
      --this->m_allocated_nodes_count;
      m_root->parent = m_head;
      this->m_root = 0;
      this->m_head = m_root;
      this->m_initialized = 0;
      return;
    }
    v23 = 0;
    v5 = -1;
    v6 = node;
    v22 = 0;
    do
    {
      if ( v6->octants[0] )
      {
        if ( v6->octants[0] == child )
        {
          v6->octants[0] = 0;
          v7 = this->m_head;
          --this->m_allocated_nodes_count;
          child->parent = v7;
          this->m_head = child;
          if ( node->objects )
            return;
        }
        else
        {
          ++v23;
          v5 = v22 >> 2;
        }
      }
      v22 += 4;
      v6 = (vostok::collision::oct_node *)((char *)v6 + 4);
    }
    while ( v6 != (vostok::collision::oct_node *)&node->parent );
    if ( node->objects )
      return;
    if ( v23 )
      break;
    if ( !node->parent )
      return;
    child = node;
    node = node->parent;
  }
  if ( v23 <= 1 )
  {
    if ( node->parent )
    {
      if ( !vostok::collision::loose_oct_tree::try_collapse_bottom_top(this, node->parent) )
        return;
    }
    else
    {
      this->m_aabb_extents = this->m_aabb_extents * 0.5;
      v11 = vostok::collision::octant_vector(&v21, (vostok::math::float3 *)v5);
      m_aabb_extents = this->m_aabb_extents;
      v13 = v11->y * m_aabb_extents;
      v14 = v11->z * m_aabb_extents;
      v15 = this->m_aabb_center.x + (float)(v11->x * m_aabb_extents);
      this->m_aabb_center.y = this->m_aabb_center.y + v13;
      v16 = this->m_aabb_center.z + v14;
      v10 = v20;
      this->m_aabb_center.x = v15;
      this->m_aabb_center.z = v16;
    }
    v17 = node->octants[v5];
    this->m_root = v17;
    v17->parent = 0;
    v18 = this->m_head;
    --this->m_allocated_nodes_count;
    node->parent = v18;
    v19 = this->m_root;
    this->m_head = node;
    if ( !v19->objects )
      vostok::collision::loose_oct_tree::try_collapse_top_bottom(v10, (int)this);
  }
}
