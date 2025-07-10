BOOL __usercall vostok::collision::colliders::aabb_geometry::test_triangle@<eax>(
        vostok::collision::colliders::aabb_geometry *this@<edi>,
        unsigned int triangle_id@<edx>)
{
  const unsigned int *v2; // esi
  const vostok::math::float3 *v3; // eax
  __int64 v4; // xmm0_8
  float z; // edx
  unsigned int v6; // ecx
  unsigned int v7; // esi
  __int64 v8; // xmm0_8
  float v9; // edx
  float v10; // edx
  const vostok::math::aabb *m_aabb; // eax
  unsigned int v12; // xmm1_4
  unsigned int v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  vostok::math::float3 boxcenter; // [esp+4h] [ebp-3Ch] BYREF
  vostok::math::float3 boxhalfsize; // [esp+10h] [ebp-30h] BYREF
  vostok::math::float3 triangle_vertices[3]; // [esp+1Ch] [ebp-24h] BYREF

  v2 = this->m_geometry->indices(this->m_geometry, triangle_id);
  v3 = this->m_geometry->vertices(this->m_geometry);
  v4 = *(_QWORD *)&v3[*v2].x;
  z = v3[*v2].z;
  v6 = v2[1];
  v7 = v2[2];
  *(_QWORD *)&triangle_vertices[0].x = v4;
  v8 = *(_QWORD *)&v3[v6].x;
  triangle_vertices[0].z = z;
  v9 = v3[v6].z;
  *(_QWORD *)&triangle_vertices[1].x = v8;
  *(_QWORD *)&triangle_vertices[2].x = *(_QWORD *)&v3[v7].x;
  triangle_vertices[1].z = v9;
  v10 = v3[v7].z;
  m_aabb = this->m_aabb;
  *(float *)&v12 = (float)(this->m_aabb->max.y - this->m_aabb->min.y) * 0.5;
  *(float *)&v13 = (float)(this->m_aabb->max.z - this->m_aabb->min.z) * 0.5;
  boxhalfsize.x = (float)(this->m_aabb->max.x - this->m_aabb->min.x) * 0.5;
  *(float *)&v8 = m_aabb->min.x + m_aabb->max.x;
  *(_QWORD *)&boxhalfsize.elements[1] = __PAIR64__(v13, v12);
  v14 = m_aabb->max.y + m_aabb->min.y;
  v15 = m_aabb->max.z + m_aabb->min.z;
  triangle_vertices[2].z = v10;
  boxcenter.x = *(float *)&v8 * 0.5;
  boxcenter.y = v14 * 0.5;
  boxcenter.z = v15 * 0.5;
  return triBoxOverlap(&boxhalfsize, (const vostok::math::float3 (*)[3])triangle_vertices, &boxcenter);
}
