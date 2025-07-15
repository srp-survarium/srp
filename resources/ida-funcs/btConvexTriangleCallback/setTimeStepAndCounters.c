void __userpurge btConvexTriangleCallback::setTimeStepAndCounters(
        const btDispatcherInfo *dispatchInfo@<eax>,
        btConvexTriangleCallback *this,
        float collisionMarginTriangle,
        btManifoldResult *resultOut)
{
  btTransform *p_m_worldTransform; // eax
  btTransform v5; // [esp+B4h] [ebp-40h] BYREF

  this->m_dispatchInfoPtr = dispatchInfo;
  this->m_resultOut = resultOut;
  p_m_worldTransform = &this->m_triBody->m_worldTransform;
  this->m_collisionMarginTriangle = collisionMarginTriangle;
  btTransform::inverse(&v5, (int)p_m_worldTransform, &v5);
  JUMPOUT(0x96B77);
}
