char __thiscall btSingleRayCallback::process(btSingleRayCallback *this, const btBroadphaseProxy *proxy)
{
  btCollisionObject *m_clientObject; // esi

  if ( this->m_resultCallback->m_closestHitFraction == 0.0 )
    return 0;
  m_clientObject = (btCollisionObject *)proxy->m_clientObject;
  if ( this->m_resultCallback->needsCollision(
         this->m_resultCallback,
         (btBroadphaseProxy *)*((_DWORD *)proxy->m_clientObject + 50)) )
  {
    btCollisionWorld::rayTestSingle(
      &this->m_rayFromTrans,
      &this->m_rayToTrans,
      m_clientObject,
      m_clientObject->m_collisionShape,
      &m_clientObject->m_worldTransform,
      this->m_resultCallback);
  }
  return 1;
}
