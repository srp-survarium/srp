btVector3 *__thiscall btSoftClusterCollisionShape::localGetSupportingVertex(
        btSoftClusterCollisionShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  const btSoftBody::Cluster *m_cluster; // ecx
  float v4; // xmm2_4
  float v5; // xmm3_4
  btSoftBody::Node **m_data; // esi
  int m_size; // ecx
  int v8; // edx
  int v9; // edi
  float i; // xmm1_4
  btVector3 *v11; // eax
  int p_m_x; // esi

  m_cluster = this->m_cluster;
  v4 = vec->mVec128.m128_f32[2];
  v5 = vec->mVec128.m128_f32[1];
  m_data = m_cluster->m_nodes.m_data;
  m_size = m_cluster->m_nodes.m_size;
  v8 = 1;
  v9 = 0;
  for ( i = (float)((float)((*m_data)->m_x.mVec128.m128_f32[1] * v5) + (float)((*m_data)->m_x.mVec128.m128_f32[2] * v4))
          + (float)((*m_data)->m_x.mVec128.m128_f32[0] * vec->mVec128.m128_f32[0]); v8 < m_size; ++v8 )
  {
    if ( (float)((float)((float)(m_data[v8]->m_x.mVec128.m128_f32[1] * v5)
                       + (float)(m_data[v8]->m_x.mVec128.m128_f32[2] * v4))
               + (float)(m_data[v8]->m_x.mVec128.m128_f32[0] * vec->mVec128.m128_f32[0])) > i )
    {
      i = (float)((float)(m_data[v8]->m_x.mVec128.m128_f32[1] * v5) + (float)(m_data[v8]->m_x.mVec128.m128_f32[2] * v4))
        + (float)(m_data[v8]->m_x.mVec128.m128_f32[0] * vec->mVec128.m128_f32[0]);
      v9 = v8;
    }
  }
  v11 = result;
  p_m_x = (int)&m_data[v9]->m_x;
  result->mVec128.m128_i32[0] = *(_DWORD *)p_m_x;
  p_m_x += 4;
  result->mVec128.m128_i32[1] = *(_DWORD *)p_m_x;
  result->mVec128.m128_u64[1] = *(_QWORD *)(p_m_x + 4);
  return v11;
}
