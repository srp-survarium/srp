void __thiscall btAxisSweep3Internal<unsigned short>::setAabb(
        btAxisSweep3Internal<unsigned short> *this,
        btBroadphaseProxy *proxy,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        btDispatcher *dispatcher)
{
  unsigned __int16 m_uniqueId; // ax

  proxy->m_aabbMin.mVec128.m128_u64[0] = aabbMin->mVec128.m128_u64[0];
  m_uniqueId = proxy->m_uniqueId;
  proxy->m_aabbMin.mVec128.m128_u64[1] = aabbMin->mVec128.m128_u64[1];
  proxy->m_aabbMax = (btVector3)aabbMax->mVec128;
  btAxisSweep3Internal<unsigned short>::updateHandle(this, m_uniqueId, aabbMin, aabbMax, dispatcher);
  if ( this->m_raycastAccelerator )
    this->m_raycastAccelerator->setAabb(
      this->m_raycastAccelerator,
      (btBroadphaseProxy *)proxy[1].m_uniqueId,
      aabbMin,
      aabbMax,
      dispatcher);
}
