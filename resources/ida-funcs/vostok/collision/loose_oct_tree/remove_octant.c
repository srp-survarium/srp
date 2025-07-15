void __usercall vostok::collision::loose_oct_tree::remove_octant(
        vostok::collision::loose_oct_tree *this@<edi>,
        vostok::collision::oct_node *node@<eax>,
        vostok::collision::oct_node *const child@<edx>)
{
  vostok::collision::oct_node *v3; // esi
  int v4; // ebp
  vostok::collision::oct_node *v5; // ecx
  vostok::collision::vertex_allocator *m_allocator; // eax
  vostok::collision::oct_node *m_nodes; // ebx
  vostok::collision::vertex_allocator *v8; // eax
  vostok::collision::oct_node *m_root; // ecx
  vostok::collision::oct_node *v10; // edx
  vostok::math::float3 *v11; // eax
  float m_aabb_extents; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  vostok::collision::oct_node *v15; // ebp
  vostok::collision::vertex_allocator *v16; // eax
  int v17; // [esp+Ch] [ebp-14h]
  unsigned int count; // [esp+10h] [ebp-10h]
  vostok::math::float3 v19; // [esp+14h] [ebp-Ch] BYREF

  v3 = node;
  if ( node )
  {
    while ( 1 )
    {
      v4 = -1;
      v5 = v3;
      count = 0;
      v17 = 0;
      do
      {
        if ( v5->octants[0] )
        {
          if ( v5->octants[0] == child )
          {
            v5->octants[0] = 0;
            m_allocator = this->m_allocator;
            m_nodes = m_allocator->m_nodes;
            --m_allocator->m_node_count;
            child->parent = m_nodes;
            m_allocator->m_nodes = child;
            if ( v3->objects )
              return;
          }
          else
          {
            ++count;
            v4 = v17 >> 2;
          }
        }
        v17 += 4;
        v5 = (vostok::collision::oct_node *)((char *)v5 + 4);
      }
      while ( v5 != (vostok::collision::oct_node *)&v3->parent );
      if ( v3->objects )
        break;
      if ( count )
      {
        if ( count > 1 )
          return;
        if ( v3->parent )
        {
          if ( !vostok::collision::loose_oct_tree::try_collapse_bottom_top(this, v3->parent) )
            return;
        }
        else
        {
          this->m_aabb_extents = this->m_aabb_extents * 0.5;
          v11 = vostok::collision::octant_vector(&v19, (vostok::math::float3 *)v4);
          m_aabb_extents = this->m_aabb_extents;
          v13 = v11->y * m_aabb_extents;
          v14 = v11->z * m_aabb_extents;
          this->m_aabb_center.x = this->m_aabb_center.x + (float)(v11->x * m_aabb_extents);
          this->m_aabb_center.y = this->m_aabb_center.y + v13;
          this->m_aabb_center.z = this->m_aabb_center.z + v14;
        }
        v15 = v3->octants[v4];
        this->m_root = v15;
        v15->parent = 0;
        v16 = this->m_allocator;
        --v16->m_node_count;
        v3->parent = v16->m_nodes;
        v16->m_nodes = v3;
        if ( !this->m_root->objects )
          vostok::collision::loose_oct_tree::try_collapse_top_bottom(this);
        return;
      }
      if ( !v3->parent )
        return;
      child = v3;
      v3 = v3->parent;
    }
  }
  else
  {
    v8 = this->m_allocator;
    m_root = this->m_root;
    v10 = v8->m_nodes;
    --v8->m_node_count;
    m_root->parent = v10;
    v8->m_nodes = m_root;
    this->m_root = 0;
    this->m_initialized = 0;
  }
}
