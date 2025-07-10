btVector3 *__usercall btSoftBody::Body::angularVelocity@<eax>(
        btSoftBody::Body *this@<esi>,
        const btVector3 *rpos@<edx>,
        btVector3 *result@<eax>)
{
  btRigidBody *m_rigid; // ecx
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm6_4
  float v10; // xmm4_4
  btSoftBody::Cluster *m_soft; // ecx
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm5_4
  float v17; // xmm1_4

  m_rigid = this->m_rigid;
  if ( m_rigid )
  {
    v4 = rpos->mVec128.m128_f32[2];
    v5 = m_rigid->m_angularVelocity.mVec128.m128_f32[2];
    v6 = rpos->mVec128.m128_f32[1];
    v7 = m_rigid->m_angularVelocity.mVec128.m128_f32[1];
    v8 = rpos->mVec128.m128_f32[0];
    result->mVec128.m128_f32[0] = (float)(v4 * v7) - (float)(v6 * v5);
    v9 = v8 * v5;
    v10 = m_rigid->m_angularVelocity.mVec128.m128_f32[0];
    result->mVec128.m128_f32[2] = (float)(v10 * v6) - (float)(v8 * v7);
    result->mVec128.m128_f32[1] = v9 - (float)(v10 * v4);
    result->mVec128.m128_i32[3] = 0;
  }
  else
  {
    m_soft = this->m_soft;
    if ( this->m_soft )
    {
      v12 = rpos->mVec128.m128_f32[2];
      v13 = rpos->mVec128.m128_f32[1];
      v14 = m_soft->m_av.mVec128.m128_f32[1];
      v15 = m_soft->m_av.mVec128.m128_f32[2];
      v16 = rpos->mVec128.m128_f32[0];
      result->mVec128.m128_f32[0] = (float)(v12 * v14) - (float)(v13 * v15);
      v17 = m_soft->m_av.mVec128.m128_f32[0];
      result->mVec128.m128_f32[1] = (float)(v15 * v16) - (float)(v17 * v12);
      result->mVec128.m128_f32[2] = (float)(v17 * v13) - (float)(v14 * v16);
    }
    else
    {
      result->mVec128.m128_i32[0] = 0;
      result->mVec128.m128_i32[1] = 0;
      result->mVec128.m128_i32[2] = 0;
    }
    result->mVec128.m128_i32[3] = 0;
  }
  return result;
}
