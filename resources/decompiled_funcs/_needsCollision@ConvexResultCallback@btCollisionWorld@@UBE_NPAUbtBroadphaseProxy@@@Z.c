bool __thiscall btCollisionWorld::ConvexResultCallback::needsCollision(
        btCollisionWorld::ConvexResultCallback *this,
        btBroadphaseProxy *proxy0)
{
  return (proxy0->m_collisionFilterGroup & this->m_collisionFilterMask) != 0
      && (proxy0->m_collisionFilterMask & this->m_collisionFilterGroup) != 0;
}
