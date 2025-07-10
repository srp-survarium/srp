btCollisionAlgorithmCreateFunc *__thiscall btSoftBodyRigidBodyCollisionConfiguration::getCollisionAlgorithmCreateFunc(
        btSoftBodyRigidBodyCollisionConfiguration *this,
        int proxyType0,
        int proxyType1)
{
  bool v4; // cc

  if ( proxyType0 == 32 )
  {
    if ( proxyType1 == 32 )
      return this->m_softSoftCreateFunc;
    if ( proxyType1 < 20 )
      return this->m_softRigidConvexCreateFunc;
    if ( (unsigned int)(proxyType1 - 21) <= 8 )
      return this->m_softRigidConcaveCreateFunc;
  }
  else
  {
    v4 = proxyType0 <= 20;
    if ( proxyType0 < 20 )
    {
      if ( proxyType1 == 32 )
        return this->m_swappedSoftRigidConvexCreateFunc;
      v4 = proxyType0 <= 20;
    }
    if ( !v4 && proxyType0 < 30 && proxyType1 == 32 )
      return this->m_swappedSoftRigidConcaveCreateFunc;
  }
  return btDefaultCollisionConfiguration::getCollisionAlgorithmCreateFunc(this, proxyType0, proxyType1);
}
