btVector3 *__cdecl btSoftBody::clusterCom(btVector3 *result, const btSoftBody::Cluster *cluster)
{
  const btSoftBody::Cluster *v2; // esi
  int m_size; // eax
  int v4; // ebx
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float *m_data; // edx
  btSoftBody::Node **v9; // ebx
  btSoftBody::Node **v10; // esi
  int v11; // ebx
  unsigned int v12; // edi
  float *v13; // ecx
  float v14; // xmm6_4
  float *v15; // edx
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float *v19; // edx
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm6_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float *m128_f32; // edx
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  float v34; // xmm5_4
  float *v35; // ecx
  char *v36; // edi
  float *v37; // edx
  int v38; // eax
  float *v39; // ecx
  float v40; // xmm6_4
  float v41; // xmm0_4
  float m_imass; // xmm0_4
  btVector3 *v43; // eax
  int i; // [esp+0h] [ebp-4h]

  v2 = cluster;
  m_size = cluster->m_nodes.m_size;
  v4 = 0;
  v5 = 0.0;
  v6 = 0.0;
  v7 = 0.0;
  if ( m_size >= 4 )
  {
    m_data = cluster->m_masses.m_data;
    v9 = cluster->m_nodes.m_data;
    v10 = v9 + 3;
    v11 = (char *)v9 - (char *)m_data;
    v12 = ((unsigned int)(m_size - 4) >> 2) + 1;
    v13 = m_data + 1;
    i = 4 * v12;
    do
    {
      v14 = *(v13 - 1);
      v15 = (float *)*(v10 - 3);
      v16 = v15[5];
      v17 = v15[6];
      v18 = v14 * v15[4];
      v19 = *(float **)((char *)v13 + v11);
      v20 = (float)(v16 * v14) + v6;
      v21 = (float)(v17 * v14) + v7;
      v22 = v13[1];
      v23 = (float)(*v13 * v19[4]) + (float)(v18 + v5);
      v24 = (float)(v19[5] * *v13) + v20;
      v25 = (float)(v19[6] * *v13) + v21;
      m128_f32 = (*v10)->m_x.mVec128.m128_f32;
      v27 = (*(v10 - 1))->m_x.mVec128.m128_f32[1] * v22;
      v28 = (*(v10 - 1))->m_x.mVec128.m128_f32[2] * v22;
      v29 = v13[2];
      v30 = (float)(v13[1] * (*(v10 - 1))->m_x.mVec128.m128_f32[0]) + v23;
      v31 = v27 + v24;
      v32 = (*v10)->m_x.mVec128.m128_f32[1];
      v33 = v28 + v25;
      v34 = (*v10)->m_x.mVec128.m128_f32[2];
      v13 += 4;
      v10 += 4;
      --v12;
      v5 = (float)(v29 * *m128_f32) + v30;
      v6 = (float)(v32 * v29) + v31;
      v7 = (float)(v34 * v29) + v33;
    }
    while ( v12 );
    v2 = cluster;
    v4 = i;
  }
  if ( v4 < m_size )
  {
    v35 = v2->m_masses.m_data;
    v36 = (char *)((char *)v2->m_nodes.m_data - (char *)v35);
    v37 = &v35[v4];
    v38 = m_size - v4;
    do
    {
      v39 = *(float **)&v36[(_DWORD)v37];
      v40 = *v37;
      v41 = *v37++;
      --v38;
      v5 = (float)(v41 * v39[4]) + v5;
      v6 = (float)(v39[5] * v40) + v6;
      v7 = (float)(v39[6] * v40) + v7;
    }
    while ( v38 );
  }
  m_imass = v2->m_imass;
  v43 = result;
  result->mVec128.m128_f32[0] = m_imass * v5;
  result->mVec128.m128_f32[1] = m_imass * v6;
  result->mVec128.m128_f32[2] = m_imass * v7;
  result->mVec128.m128_i32[3] = 0;
  return v43;
}
