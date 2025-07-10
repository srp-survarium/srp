bool __thiscall btClosestNotMeConvexResultCallback::needsCollision(
        btClosestNotMeConvexResultCallback *this,
        btBroadphaseProxy *proxy0)
{
  btCollisionObject *m_me; // edx

  m_me = this->m_me;
  return proxy0->m_clientObject != m_me
      && (proxy0->m_collisionFilterGroup & this->m_collisionFilterMask) != 0
      && (proxy0->m_collisionFilterMask & this->m_collisionFilterGroup) != 0
      && this->m_dispatcher->needsResponse(this->m_dispatcher, m_me, (btCollisionObject *)proxy0->m_clientObject);
}
