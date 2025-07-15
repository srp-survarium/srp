char __thiscall btSingleRayCallback::process(btSingleRayCallback *this, const btBroadphaseProxy *proxy)
{
  char *m_clientObject; // esi

  if ( this->m_resultCallback->m_closestHitFraction == 0.0 )
    return 0;
  m_clientObject = (char *)proxy->m_clientObject;
  if ( this->m_resultCallback->needsCollision(
         this->m_resultCallback,
         (btBroadphaseProxy *)*((_DWORD *)proxy->m_clientObject + 50)) )
  {
    btCollisionWorld::rayTestSingle(
      &this->m_rayFromTrans,
      &this->m_rayToTrans,
      (btCollisionObject *)m_clientObject,
      *((btVoronoiSimplexSolver **)m_clientObject + 51),
      (const btTransform *)(m_clientObject + 16),
      this->m_resultCallback);
  }
  return 1;
}
