btVector3 *__userpurge btRigidBody::getVelocityInLocalPoint@<eax>(
        const btVector3 *rel_pos@<edx>,
        btVector3 *result@<eax>,
        btRigidBody *this)
{
  float v3; // xmm6_4
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm6_4
  float v9; // xmm0_4

  v3 = this->m_angularVelocity.mVec128.m128_f32[2];
  v4 = this->m_angularVelocity.mVec128.m128_f32[1];
  v5 = rel_pos->mVec128.m128_f32[2];
  v6 = (float)(v5 * v4) - (float)(rel_pos->mVec128.m128_f32[1] * v3);
  v7 = rel_pos->mVec128.m128_f32[0] * v3;
  v8 = this->m_angularVelocity.mVec128.m128_f32[0];
  v9 = (float)(v8 * rel_pos->mVec128.m128_f32[1]) - (float)(rel_pos->mVec128.m128_f32[0] * v4);
  result->mVec128.m128_f32[0] = this->m_linearVelocity.mVec128.m128_f32[0] + v6;
  result->mVec128.m128_f32[1] = this->m_linearVelocity.mVec128.m128_f32[1] + (float)(v7 - (float)(v8 * v5));
  result->mVec128.m128_f32[2] = this->m_linearVelocity.mVec128.m128_f32[2] + v9;
  result->mVec128.m128_i32[3] = 0;
  return result;
}
