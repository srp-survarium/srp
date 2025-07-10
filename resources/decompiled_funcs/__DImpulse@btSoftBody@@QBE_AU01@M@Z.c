btSoftBody::Impulse *__userpurge btSoftBody::Impulse::operator*@<eax>(
        btSoftBody::Impulse *this@<ecx>,
        btSoftBody::Impulse *a2@<eax>,
        btSoftBody::Impulse *result,
        float x)
{
  *a2 = *this;
  a2->m_velocity.mVec128.m128_f32[0] = a2->m_velocity.mVec128.m128_f32[0] * *(float *)&result;
  a2->m_velocity.mVec128.m128_f32[1] = a2->m_velocity.mVec128.m128_f32[1] * *(float *)&result;
  a2->m_velocity.mVec128.m128_f32[2] = a2->m_velocity.mVec128.m128_f32[2] * *(float *)&result;
  a2->m_drift.mVec128.m128_f32[0] = a2->m_drift.mVec128.m128_f32[0] * *(float *)&result;
  a2->m_drift.mVec128.m128_f32[1] = a2->m_drift.mVec128.m128_f32[1] * *(float *)&result;
  a2->m_drift.mVec128.m128_f32[2] = a2->m_drift.mVec128.m128_f32[2] * *(float *)&result;
  return a2;
}
