int __thiscall btCollisionWorld::rayTestSingle_::_31_::LocalInfoAdder2::needsCollision(
        btCollisionWorld::rayTestSingle::__l31::LocalInfoAdder2 *this,
        btBroadphaseProxy *p)
{
  return ((int (__thiscall *)(btCollisionWorld::RayResultCallback *, btBroadphaseProxy *))this->m_userCallback->needsCollision)(
           this->m_userCallback,
           p);
}
