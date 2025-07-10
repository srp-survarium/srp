int __thiscall btCollisionWorld::objectQuerySingle_::_46_::LocalInfoAdder::needsCollision(
        btCollisionWorld::objectQuerySingle::__l46::LocalInfoAdder *this,
        btBroadphaseProxy *p)
{
  return ((int (__thiscall *)(btCollisionWorld::ConvexResultCallback *, btBroadphaseProxy *))this->m_userCallback->needsCollision)(
           this->m_userCallback,
           p);
}
