char __thiscall btSingleSweepCallback::process(btSingleSweepCallback *this, const btBroadphaseProxy *proxy)
{
  btCollisionObject *m_clientObject; // edi

  if ( this->m_resultCallback->m_closestHitFraction == 0.0 )
    return 0;
  m_clientObject = (btCollisionObject *)proxy->m_clientObject;
  if ( this->m_resultCallback->needsCollision(
         this->m_resultCallback,
         (btBroadphaseProxy *)*((_DWORD *)proxy->m_clientObject + 50)) )
  {
    btCollisionWorld::objectQuerySingle(
      this->m_castShape,
      &this->m_convexFromTrans,
      &this->m_convexToTrans,
      m_clientObject,
      m_clientObject->m_collisionShape,
      &m_clientObject->m_worldTransform,
      this->m_resultCallback,
      this->m_allowedCcdPenetration);
  }
  return 1;
}
