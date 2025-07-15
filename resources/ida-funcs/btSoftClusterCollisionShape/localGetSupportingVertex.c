btVector3 *__thiscall btSoftClusterCollisionShape::localGetSupportingVertex(
        btSoftClusterCollisionShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  const btSoftBody::Cluster *m_cluster; // ecx
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  int m_size; // ebx
  btSoftBody::Node **m_data; // edi
  int v9; // esi
  int v10; // eax
  float v11; // xmm0_4
  _DWORD *v12; // edx
  btVector3 *v13; // eax

  m_cluster = this->m_cluster;
  v4 = vec->mVec128.m128_f32[2];
  v5 = vec->mVec128.m128_f32[1];
  v6 = vec->mVec128.m128_f32[0];
  m_size = m_cluster->m_nodes.m_size;
  m_data = m_cluster->m_nodes.m_data;
  v9 = 0;
  v10 = 1;
  v11 = (float)((float)((*m_data)->m_x.mVec128.m128_f32[1] * v5) + (float)((*m_data)->m_x.mVec128.m128_f32[2] * v4))
      + (float)((*m_data)->m_x.mVec128.m128_f32[0] * vec->mVec128.m128_f32[0]);
  if ( m_size > 1 )
  {
    if ( m_size - 1 >= 4 )
    {
      v12 = m_data + 3;
      do
      {
        if ( (float)((float)((float)(*(float *)(*(v12 - 2) + 20) * v5) + (float)(*(float *)(*(v12 - 2) + 24) * v4))
                   + (float)(v6 * *(float *)(*(v12 - 2) + 16))) > v11 )
        {
          v11 = (float)((float)(*(float *)(*(v12 - 2) + 20) * v5) + (float)(*(float *)(*(v12 - 2) + 24) * v4))
              + (float)(v6 * *(float *)(*(v12 - 2) + 16));
          v9 = v10;
        }
        if ( (float)((float)((float)(*(float *)(*(v12 - 1) + 20) * v5) + (float)(*(float *)(*(v12 - 1) + 24) * v4))
                   + (float)(v6 * *(float *)(*(v12 - 1) + 16))) > v11 )
        {
          v11 = (float)((float)(*(float *)(*(v12 - 1) + 20) * v5) + (float)(*(float *)(*(v12 - 1) + 24) * v4))
              + (float)(v6 * *(float *)(*(v12 - 1) + 16));
          v9 = v10 + 1;
        }
        if ( (float)((float)((float)(*(float *)(*v12 + 20) * v5) + (float)(*(float *)(*v12 + 24) * v4))
                   + (float)(v6 * *(float *)(*v12 + 16))) > v11 )
        {
          v11 = (float)((float)(*(float *)(*v12 + 20) * v5) + (float)(*(float *)(*v12 + 24) * v4))
              + (float)(v6 * *(float *)(*v12 + 16));
          v9 = v10 + 2;
        }
        if ( (float)((float)((float)(*(float *)(v12[1] + 20) * v5) + (float)(*(float *)(v12[1] + 24) * v4))
                   + (float)(v6 * *(float *)(v12[1] + 16))) > v11 )
        {
          v11 = (float)((float)(*(float *)(v12[1] + 20) * v5) + (float)(*(float *)(v12[1] + 24) * v4))
              + (float)(v6 * *(float *)(v12[1] + 16));
          v9 = v10 + 3;
        }
        v10 += 4;
        v12 += 4;
      }
      while ( v10 < m_size - 3 );
    }
    for ( ; v10 < m_size; ++v10 )
    {
      if ( (float)((float)((float)(m_data[v10]->m_x.mVec128.m128_f32[1] * v5)
                         + (float)(m_data[v10]->m_x.mVec128.m128_f32[2] * v4))
                 + (float)(v6 * m_data[v10]->m_x.mVec128.m128_f32[0])) > v11 )
      {
        v11 = (float)((float)(m_data[v10]->m_x.mVec128.m128_f32[1] * v5)
                    + (float)(m_data[v10]->m_x.mVec128.m128_f32[2] * v4))
            + (float)(v6 * m_data[v10]->m_x.mVec128.m128_f32[0]);
        v9 = v10;
      }
    }
  }
  v13 = result;
  *result = m_data[v9]->m_x;
  return v13;
}
