void __userpurge vostok::collision::loose_oct_tree::update_bounds(
        vostok::collision::loose_oct_tree *this@<esi>,
        const vostok::math::float3 *aabb_extents@<eax>,
        const vostok::math::float3 *aabb_center)
{
  float v3; // xmm1_4
  float v4; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float m_aabb_extents; // xmm4_4
  float v8; // xmm0_4
  unsigned int v9; // edi
  long double v10; // st7
  float v11; // xmm3_4
  float v12; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  char v16; // al
  float v17; // xmm6_4
  char v18; // al
  float v19; // xmm4_4
  char v20; // al
  float v21; // xmm2_4
  vostok::collision::vertex_allocator *m_allocator; // ecx
  int m_nodes; // eax
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm4_4
  float v28; // xmm1_4
  float value; // [esp+4h] [ebp-3Ch]
  float valuea; // [esp+4h] [ebp-3Ch]
  long double v31; // [esp+8h] [ebp-38h]
  long double v32; // [esp+8h] [ebp-38h]
  float new_radius; // [esp+18h] [ebp-28h]
  float radius; // [esp+20h] [ebp-20h]

  v3 = aabb_extents->z + fabs(aabb_center->z - this->m_aabb_center.z);
  v4 = aabb_extents->y + fabs(aabb_center->y - this->m_aabb_center.y);
  v5 = aabb_extents->x + fabs(aabb_center->x - this->m_aabb_center.x);
  if ( v4 <= v3 )
    v6 = v3;
  else
    v6 = v4;
  if ( v5 < v6 )
  {
    if ( v5 <= v3 )
      v5 = v3;
    m_aabb_extents = this->m_aabb_extents;
    if ( v4 < v5 )
      v8 = m_aabb_extents + v3;
    else
      v8 = m_aabb_extents + v4;
  }
  else
  {
    m_aabb_extents = this->m_aabb_extents;
    v8 = m_aabb_extents + v5;
  }
  __libm_sse2_log(v31);
  __libm_sse2_log(v32);
  v9 = vostok::math::floor((float)((float)(v8 * 0.5) / m_aabb_extents) / (float)2.0);
  value = (float)v9;
  v10 = powf(2.0, value) * m_aabb_extents;
  new_radius = v10;
  if ( (float)(v8 * 0.5) > v10 )
  {
    valuea = (float)(v9 + 1);
    new_radius = powf(2.0, valuea) * m_aabb_extents;
  }
  v11 = m_aabb_extents * 2.0;
  radius = m_aabb_extents * 2.0;
  if ( new_radius >= (float)(m_aabb_extents * 2.0) )
  {
    v12 = epsilon_5_210;
    do
    {
      v13 = this->m_aabb_center.z - aabb_center->z;
      v14 = this->m_aabb_center.x - aabb_center->x;
      v15 = this->m_aabb_center.y - aabb_center->y;
      if ( v13 <= 0.0 )
      {
        if ( v13 >= 0.0 )
          v16 = 0;
        else
          v16 = -1;
      }
      else
      {
        v16 = 1;
      }
      v17 = (float)v16;
      if ( v12 > fabs(v17) )
        v17 = *(float *)&clear_value;
      if ( v15 <= 0.0 )
      {
        if ( v15 >= 0.0 )
          v18 = 0;
        else
          v18 = -1;
      }
      else
      {
        v18 = 1;
      }
      v19 = (float)v18;
      if ( v12 > fabs(v19) )
        v19 = *(float *)&clear_value;
      if ( v14 <= 0.0 )
      {
        if ( v14 >= 0.0 )
          v20 = 0;
        else
          v20 = -1;
      }
      else
      {
        v20 = 1;
      }
      v21 = (float)v20;
      if ( v12 > fabs(v21) )
        v21 = *(float *)&clear_value;
      m_allocator = this->m_allocator;
      ++m_allocator->m_node_count;
      m_nodes = (int)m_allocator->m_nodes;
      if ( m_nodes )
      {
        m_allocator->m_nodes = *(vostok::collision::oct_node **)(m_nodes + 32);
      }
      else
      {
        m_nodes = (int)m_allocator->m_allocator->call_malloc(m_allocator->m_allocator, 40u);
        v11 = radius;
      }
      v12 = epsilon_5_210;
      *(_DWORD *)(m_nodes + 36) = 0;
      *(_DWORD *)(m_nodes + 32) = 0;
      *(_QWORD *)m_nodes = 0;
      *(_QWORD *)(m_nodes + 8) = 0;
      *(_QWORD *)(m_nodes + 16) = 0;
      *(_QWORD *)(m_nodes + 24) = 0;
      *(_DWORD *)(m_nodes + 4 * ((v21 >= 0.0) | (unsigned __int8)(2 * ((v19 >= 0.0) | (2 * (v17 >= 0.0)))))) = this->m_root;
      this->m_root->parent = (vostok::collision::oct_node *)m_nodes;
      this->m_root = (vostok::collision::oct_node *)m_nodes;
      v24 = this->m_aabb_extents;
      v25 = v24 * v21;
      v26 = v24 * v19;
      v27 = this->m_aabb_center.x - v25;
      this->m_aabb_center.y = this->m_aabb_center.y - v26;
      v28 = this->m_aabb_center.z - (float)(v24 * v17);
      this->m_aabb_center.x = v27;
      this->m_aabb_center.z = v28;
      this->m_aabb_extents = v11;
      v11 = v11 * 2.0;
      radius = v11;
    }
    while ( new_radius >= v11 );
  }
}
