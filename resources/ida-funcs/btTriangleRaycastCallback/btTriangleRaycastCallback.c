void __userpurge btTriangleRaycastCallback::btTriangleRaycastCallback(
        btTriangleRaycastCallback *this@<eax>,
        unsigned int flags@<ecx>,
        const btVector3 *from,
        const btVector3 *to)
{
  float v4; // xmm0_4

  this->__vftable = (btTriangleRaycastCallback_vtbl *)&btTriangleRaycastCallback::`vftable';
  this->m_from.mVec128.m128_u64[0] = from->mVec128.m128_u64[0];
  this->m_from.mVec128.m128_i32[2] = from->mVec128.m128_i32[2];
  v4 = s_bm_current_air_resistance;
  this->m_from.mVec128.m128_i32[3] = from->mVec128.m128_i32[3];
  this->m_to = (btVector3)to->mVec128;
  this->m_flags = flags;
  this->m_hitFraction = v4;
}
