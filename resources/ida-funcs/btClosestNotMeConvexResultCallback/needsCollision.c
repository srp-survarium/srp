bool __thiscall btClosestNotMeConvexResultCallback::needsCollision(
        btClosestNotMeConvexResultCallback *this,
        btBroadphaseProxy *proxy0)
{
  btCollisionObject *m_me; // ebx
  btCollisionObject *m_clientObject; // edi

  m_me = this->m_me;
  m_clientObject = (btCollisionObject *)proxy0->m_clientObject;
  return proxy0->m_clientObject != m_me
      && btCollisionWorld::ConvexResultCallback::needsCollision(this, proxy0)
      && this->m_dispatcher->needsResponse(this->m_dispatcher, m_me, m_clientObject);
}
