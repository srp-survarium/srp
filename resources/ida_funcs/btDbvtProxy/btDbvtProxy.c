void __stdcall btDbvtProxy::btDbvtProxy(
        btDbvtProxy *this,
        void *userPtr,
        __int16 collisionFilterGroup,
        __int16 collisionFilterMask)
{
  const btVector3 *aabbMin; // edx
  const btVector3 *aabbMax; // ecx

  this->m_clientObject = userPtr;
  this->m_collisionFilterGroup = collisionFilterGroup;
  this->m_collisionFilterMask = collisionFilterMask;
  this->m_aabbMin = (btVector3)aabbMin->mVec128;
  this->m_aabbMax = (btVector3)aabbMax->mVec128;
  this->m_multiSapParentProxy = 0;
  this->links[1] = 0;
  this->links[0] = 0;
}
