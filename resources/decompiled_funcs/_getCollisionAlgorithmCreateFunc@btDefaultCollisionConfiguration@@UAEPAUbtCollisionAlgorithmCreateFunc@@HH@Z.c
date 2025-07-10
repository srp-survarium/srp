btCollisionAlgorithmCreateFunc *__thiscall btDefaultCollisionConfiguration::getCollisionAlgorithmCreateFunc(
        btDefaultCollisionConfiguration *this,
        int proxyType0,
        int proxyType1)
{
  switch ( proxyType0 )
  {
    case 8:
      if ( proxyType1 == 8 )
        return this->m_sphereSphereCF;
      if ( proxyType1 == 1 )
        return this->m_sphereTriangleCF;
      goto LABEL_13;
    case 1:
      if ( proxyType1 == 8 )
        return this->m_triangleSphereCF;
      goto LABEL_13;
    case 0:
      if ( !proxyType1 )
        return this->m_boxBoxCF;
LABEL_13:
      if ( proxyType1 == 28 )
        return this->m_convexPlaneCF;
      goto LABEL_15;
  }
  if ( proxyType0 < 20 )
    goto LABEL_13;
LABEL_15:
  if ( proxyType1 < 20 && proxyType0 == 28 )
    return this->m_planeConvexCF;
  if ( proxyType0 >= 20 )
    goto LABEL_24;
  if ( proxyType1 < 20 )
    return this->m_convexConvexCreateFunc;
  if ( (unsigned int)(proxyType1 - 21) <= 8 )
    return this->m_convexConcaveCreateFunc;
LABEL_24:
  if ( proxyType1 < 20 && (unsigned int)(proxyType0 - 21) <= 8 )
    return this->m_swappedConvexConcaveCreateFunc;
  if ( proxyType0 == 31 )
    return this->m_compoundCreateFunc;
  if ( proxyType1 == 31 )
    return this->m_swappedCompoundCreateFunc;
  return this->m_emptyCreateFunc;
}
