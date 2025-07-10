btSoftBody::Impulse *__usercall btSoftBody::Impulse::operator-@<eax>(
        btSoftBody::Impulse *this@<ecx>,
        btSoftBody::Impulse *a2@<eax>)
{
  float v2; // xmm1_4
  unsigned int v3; // xmm2_4
  unsigned __int64 v4; // [esp+0h] [ebp-10h]

  *a2 = *this;
  *(float *)&v4 = -a2->m_velocity.mVec128.m128_f32[0];
  *((float *)&v4 + 1) = -a2->m_velocity.mVec128.m128_f32[1];
  v2 = a2->m_velocity.mVec128.m128_f32[2];
  a2->m_velocity.mVec128.m128_u64[0] = v4;
  a2->m_velocity.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(-v2);
  *(float *)&v4 = -a2->m_drift.mVec128.m128_f32[0];
  *((float *)&v4 + 1) = -a2->m_drift.mVec128.m128_f32[1];
  *(float *)&v3 = -a2->m_drift.mVec128.m128_f32[2];
  a2->m_drift.mVec128.m128_u64[0] = v4;
  a2->m_drift.mVec128.m128_u64[1] = v3;
  return a2;
}
