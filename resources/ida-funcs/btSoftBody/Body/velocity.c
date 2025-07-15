btVector3 *__userpurge btSoftBody::Body::velocity@<eax>(
        btSoftBody::Body *this@<ecx>,
        btVector3 *a2@<eax>,
        btVector3 *result,
        const btVector3 *rpos)
{
  float *v4; // edx
  float v5; // xmm7_4
  float v6; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  btRigidBody *m_rigid; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float *v15; // esi
  float v16; // xmm2_4
  float *v17; // esi
  float *v18; // esi
  float v19; // xmm6_4
  float v20; // xmm5_4
  float v21; // xmm4_4
  float v22; // [esp+0h] [ebp-10h]

  v4 = (float *)result->mVec128.m128_i32[1];
  if ( v4 )
  {
    v5 = v4[86];
    v6 = v4[85];
    v7 = *(float *)&this->m_soft;
    v8 = v4[84];
    v9 = (float)(*(float *)&this->m_collisionObject * v6) - (float)(*(float *)&this->m_rigid * v5);
    v10 = *(float *)&this->m_soft * v5;
    v11 = v8 * *(float *)&this->m_collisionObject;
    m_rigid = this->m_rigid;
LABEL_3:
    v13 = v10 - v11;
    v14 = (float)(v8 * *(float *)&m_rigid) - (float)(v7 * v6);
    goto LABEL_7;
  }
  v15 = (float *)result->mVec128.m128_i32[0];
  if ( result->mVec128.m128_i32[0] )
  {
    v16 = v15[90];
    m_rigid = this->m_rigid;
    v7 = v15[89];
    v9 = (float)(*(float *)&this->m_collisionObject * v7) - (float)(*(float *)&m_rigid * v16);
    v8 = v15[88];
    v10 = v16 * *(float *)&this->m_soft;
    v11 = v8 * *(float *)&this->m_collisionObject;
    v6 = *(float *)&this->m_soft;
    goto LABEL_3;
  }
  v9 = 0.0;
  v13 = 0.0;
  v14 = 0.0;
LABEL_7:
  if ( v4 )
  {
    v17 = v4 + 80;
  }
  else
  {
    if ( !result->mVec128.m128_i32[0] )
    {
      v21 = 0.0;
      v20 = 0.0;
      v19 = 0.0;
      goto LABEL_13;
    }
    v17 = (float *)(result->mVec128.m128_i32[0] + 336);
  }
  v22 = *v17;
  v18 = v17 + 1;
  v19 = v18[1];
  v20 = *v18;
  v21 = v22;
LABEL_13:
  a2->mVec128.m128_f32[0] = v21 + v9;
  a2->mVec128.m128_f32[1] = v20 + v13;
  a2->mVec128.m128_f32[2] = v19 + v14;
  a2->mVec128.m128_i32[3] = 0;
  return a2;
}
