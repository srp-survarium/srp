int __thiscall Scaleform::Render::HAL::SetUserMatrix(
        btCollisionWorld::rayTestSingle::__l42::LocalInfoAdder2 *this,
        btBroadphaseProxy *p)
{
  return ((int (__thiscall *)(btCollisionWorld::RayResultCallback *, btBroadphaseProxy *))this->m_userCallback->needsCollision)(
           this->m_userCallback,
           p);
}
