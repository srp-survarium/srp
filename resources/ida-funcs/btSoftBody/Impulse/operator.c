btSoftBody::Impulse *__usercall btSoftBody::Impulse::operator-@<eax>(
        btSoftBody::Impulse *this@<ecx>,
        btSoftBody::Impulse *a2@<eax>,
        const void *a3@<edx>)
{
  unsigned __int64 v3; // [esp+14h] [ebp-Ch]

  qmemcpy(a2, a3, sizeof(btSoftBody::Impulse));
  LODWORD(v3) = a2->m_velocity.mVec128.m128_i32[1] ^ _mask__NegFloat_;
  HIDWORD(v3) = a2->m_velocity.mVec128.m128_i32[2] ^ _mask__NegFloat_;
  a2->m_velocity.mVec128.m128_i32[0] ^= _mask__NegFloat_;
  *(unsigned __int64 *)((char *)a2->m_velocity.mVec128.m128_u64 + 4) = v3;
  a2->m_velocity.mVec128.m128_i32[3] = 0;
  LODWORD(v3) = a2->m_drift.mVec128.m128_i32[1] ^ _mask__NegFloat_;
  HIDWORD(v3) = a2->m_drift.mVec128.m128_i32[2] ^ _mask__NegFloat_;
  a2->m_drift.mVec128.m128_i32[0] ^= _mask__NegFloat_;
  *(unsigned __int64 *)((char *)a2->m_drift.mVec128.m128_u64 + 4) = v3;
  a2->m_drift.mVec128.m128_i32[3] = 0;
  return a2;
}
