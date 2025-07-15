void __stdcall btTriangleRaycastCallback::btTriangleRaycastCallback(
        btTriangleRaycastCallback *this,
        unsigned int flags)
{
  const btVector3 *from; // edx
  const btVector3 *to; // ecx
  const vostok::math::float4x4 *v4; // xmm0_4

  this->__vftable = (btTriangleRaycastCallback_vtbl *)&btTriangleRaycastCallback::`vftable';
  this->m_from = (btVector3)from->mVec128;
  this->m_to = (btVector3)to->mVec128;
  v4 = clear_value;
  this->m_flags = flags;
  LODWORD(this->m_hitFraction) = v4;
}
