void __thiscall btTriangleMeshShape::setLocalScaling(btTriangleMeshShape *this, const btVector3 *scaling)
{
  btVector3 *p_m_scaling; // edi

  p_m_scaling = &this->m_meshInterface->m_scaling;
  p_m_scaling->mVec128.m128_i32[0] = scaling->mVec128.m128_i32[0];
  p_m_scaling = (btVector3 *)((char *)p_m_scaling + 4);
  p_m_scaling->mVec128.m128_i32[0] = scaling->mVec128.m128_i32[1];
  *(unsigned __int64 *)((char *)p_m_scaling->mVec128.m128_u64 + 4) = scaling->mVec128.m128_u64[1];
  btTriangleMeshShape::recalcLocalAabb(this, (float *)this);
}
