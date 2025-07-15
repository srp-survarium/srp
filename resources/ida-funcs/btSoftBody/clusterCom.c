btVector3 *__usercall btSoftBody::clusterCom@<eax>(const btSoftBody::Cluster *cluster@<esi>, btVector3 *result@<eax>)
{
  float v2; // xmm5_4
  float v3; // xmm6_4
  float v4; // xmm7_4
  float *m_data; // edx
  char *v6; // edi
  int m_size; // ebx
  float *v8; // ecx
  float v9; // xmm4_4
  float v10; // xmm2_4
  float m_imass; // xmm0_4

  v2 = 0.0;
  v3 = 0.0;
  v4 = 0.0;
  if ( cluster->m_nodes.m_size > 0 )
  {
    m_data = cluster->m_masses.m_data;
    v6 = (char *)((char *)cluster->m_nodes.m_data - (char *)m_data);
    m_size = cluster->m_nodes.m_size;
    do
    {
      v8 = *(float **)((char *)m_data + (_DWORD)v6);
      v9 = *m_data;
      v10 = *m_data++;
      --m_size;
      v2 = (float)(v10 * v8[4]) + v2;
      v3 = (float)(v8[5] * v9) + v3;
      v4 = (float)(v8[6] * v9) + v4;
    }
    while ( m_size );
  }
  m_imass = cluster->m_imass;
  result->mVec128.m128_f32[0] = m_imass * v2;
  result->mVec128.m128_f32[1] = m_imass * v3;
  result->mVec128.m128_f32[2] = m_imass * v4;
  result->mVec128.m128_i32[3] = 0;
  return result;
}
