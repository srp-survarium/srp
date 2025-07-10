int __thiscall btCollisionWorld::objectQuerySingle_::_57_::LocalInfoAdder::needsCollision(
        btCollisionWorld::objectQuerySingle::__l57::LocalInfoAdder *this,
        btBroadphaseProxy *p)
{
  return ((int (__thiscall *)(btCollisionWorld::ConvexResultCallback *, btBroadphaseProxy *))this->m_userCallback->needsCollision)(
           this->m_userCallback,
           p);
}
