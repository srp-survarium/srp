btVector3 *__usercall btSoftBody::evaluateCom@<eax>(btSoftBody *this@<ecx>, btVector3 *a2@<eax>)
{
  bool v2; // zf
  float v3; // xmm0_4
  int m_size; // esi
  float *m_data; // edx
  float v6; // xmm5_4
  float v7; // xmm6_4
  float *v8; // ecx
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4

  v2 = !this->m_pose.m_bframe;
  v3 = 0.0;
  a2->mVec128.m128_u64[0] = 0;
  a2->mVec128.m128_u64[1] = 0;
  if ( !v2 )
  {
    m_size = this->m_nodes.m_size;
    if ( m_size > 0 )
    {
      m_data = this->m_pose.m_wgh.m_data;
      v6 = 0.0;
      v7 = 0.0;
      v8 = &this->m_nodes.m_data->m_x.mVec128.m128_f32[2];
      do
      {
        v9 = *m_data;
        v10 = *(v8 - 2);
        v11 = *(v8 - 1);
        v12 = *v8;
        ++m_data;
        v8 += 28;
        --m_size;
        v6 = v6 + (float)(v10 * v9);
        v7 = v7 + (float)(v11 * v9);
        v3 = v3 + (float)(v12 * v9);
      }
      while ( m_size );
      a2->mVec128.m128_f32[0] = v6;
      a2->mVec128.m128_f32[1] = v7;
      a2->mVec128.m128_f32[2] = v3;
    }
  }
  return a2;
}
