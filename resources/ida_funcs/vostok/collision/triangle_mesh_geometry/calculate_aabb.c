void __usercall vostok::collision::triangle_mesh_geometry::calculate_aabb(
        vostok::collision::triangle_mesh_geometry *this@<edi>,
        const vostok::math::float3 *const vertices@<eax>,
        const unsigned int vertex_count@<ecx>)
{
  __int64 v3; // xmm4_8
  float z; // esi
  const vostok::math::float3 *v5; // edx
  const vostok::math::float3 *v6; // eax
  float v7; // ecx
  __int64 v8; // xmm0_8
  float x; // xmm0_4
  float y; // xmm3_4
  float v11; // xmm2_4
  _BYTE v12[12]; // [esp+8h] [ebp-30h]
  vostok::math::float3 v13; // [esp+14h] [ebp-24h]
  vostok::math::float3 min; // [esp+20h] [ebp-18h]
  vostok::math::float3 max; // [esp+2Ch] [ebp-Ch]

  if ( vertex_count )
  {
    v3 = *(_QWORD *)&vertices->x;
    z = vertices->z;
    v5 = &vertices[vertex_count];
    v6 = vertices + 1;
    v7 = z;
    v8 = v3;
    *(_QWORD *)&min.x = v3;
    min.z = z;
    *(_QWORD *)&max.x = v3;
    for ( max.z = z; v6 != v5; max = v13 )
    {
      x = v6->x;
      if ( v6->x <= min.x )
        *(float *)v12 = v6->x;
      else
        *(float *)v12 = min.x;
      y = v6->y;
      if ( y <= min.y )
        *(float *)&v12[4] = v6->y;
      else
        *(float *)&v12[4] = min.y;
      v11 = v6->z;
      if ( v11 <= min.z )
        *(float *)&v12[8] = v6->z;
      else
        *(float *)&v12[8] = min.z;
      z = *(float *)&v12[8];
      v3 = *(_QWORD *)v12;
      min = *(vostok::math::float3 *)v12;
      if ( max.x <= x )
        v13.x = x;
      else
        v13.x = max.x;
      if ( max.y <= y )
        v13.y = y;
      else
        v13.y = max.y;
      if ( max.z <= v11 )
        v13.z = v11;
      else
        v13.z = max.z;
      v7 = v13.z;
      v8 = *(_QWORD *)&v13.x;
      ++v6;
    }
    *(_QWORD *)&this->m_bounding_aabb.min.x = v3;
    *(_QWORD *)&this->m_bounding_aabb.max.x = v8;
    this->m_bounding_aabb.min.z = z;
    this->m_bounding_aabb.max.z = v7;
  }
}
