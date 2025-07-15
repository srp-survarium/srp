void __userpurge vostok::collision::triangle_mesh_geometry::calculate_aabb(
        const vostok::math::float3 *const vertices@<ecx>,
        const unsigned int vertex_count@<eax>,
        vostok::collision::triangle_mesh_geometry *this,
        const unsigned int *const indices,
        const unsigned int index_count)
{
  const vostok::math::float3 *v5; // eax
  const vostok::math::float3 *i; // esi
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  _DWORD *p_y; // esi
  _BYTE v11[12]; // [esp+0h] [ebp-30h]
  vostok::math::float3 v12; // [esp+Ch] [ebp-24h]
  float v13; // [esp+18h] [ebp-18h] BYREF
  float v14; // [esp+1Ch] [ebp-14h]
  float v15; // [esp+20h] [ebp-10h]
  vostok::math::float3 v16; // [esp+24h] [ebp-Ch]

  if ( vertex_count )
  {
    v12 = *vertices;
    v5 = &vertices[vertex_count];
    for ( i = vertices; ; i = (const vostok::math::float3 *)&v13 )
    {
      *(float *)v11 = i->x;
      p_y = (_DWORD *)&i->y;
      *(_DWORD *)&v11[4] = *p_y;
      ++vertices;
      *(_DWORD *)&v11[8] = p_y[1];
      if ( vertices == v5 )
        break;
      x = vertices->x;
      if ( vertices->x <= v12.x )
        v16.x = vertices->x;
      else
        v16.x = v12.x;
      y = vertices->y;
      if ( y <= v12.y )
        v16.y = vertices->y;
      else
        v16.y = v12.y;
      z = vertices->z;
      if ( z <= v12.z )
        v16.z = vertices->z;
      else
        v16.z = v12.z;
      v12 = v16;
      if ( *(float *)v11 <= x )
        v13 = x;
      else
        v13 = *(float *)v11;
      if ( *(float *)&v11[4] <= y )
        v14 = y;
      else
        v14 = *(float *)&v11[4];
      if ( *(float *)&v11[8] <= z )
        v15 = z;
      else
        v15 = *(float *)&v11[8];
    }
    this->m_bounding_aabb.min = v12;
    this->m_bounding_aabb.max = *(vostok::math::float3 *)v11;
  }
}
