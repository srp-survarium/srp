btVector3 *__userpurge btRigidBody::getVelocityInLocalPoint@<eax>(
        const btVector3 *rel_pos@<edx>,
        btVector3 *result@<eax>,
        btRigidBody *this)
{
  float v3; // xmm6_4
  float v4; // xmm4_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm1_4

  v3 = this->m_angularVelocity.mVec128.m128_f32[2];
  v4 = this->m_angularVelocity.mVec128.m128_f32[1];
  v5 = (float)(rel_pos->mVec128.m128_f32[2] * v4) - (float)(rel_pos->mVec128.m128_f32[1] * v3);
  v6 = rel_pos->mVec128.m128_f32[0] * v3;
  v7 = this->m_angularVelocity.mVec128.m128_f32[0];
  v8 = (float)(v7 * rel_pos->mVec128.m128_f32[1]) - (float)(rel_pos->mVec128.m128_f32[0] * v4);
  v9 = this->m_linearVelocity.mVec128.m128_f32[0] + v5;
  result->mVec128.m128_f32[1] = this->m_linearVelocity.mVec128.m128_f32[1]
                              + (float)(v6 - (float)(v7 * rel_pos->mVec128.m128_f32[2]));
  v10 = this->m_linearVelocity.mVec128.m128_f32[2] + v8;
  result->mVec128.m128_f32[0] = v9;
  result->mVec128.m128_f32[2] = v10;
  result->mVec128.m128_i32[3] = 0;
  return result;
}
