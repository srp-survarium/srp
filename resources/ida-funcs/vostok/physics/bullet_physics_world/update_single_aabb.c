void __thiscall vostok::physics::bullet_physics_world::update_single_aabb(
        vostok::physics::bullet_physics_world *this,
        btCollisionObject *o)
{
  btOverlappingPairCache *v3; // eax

  btCollisionWorld::updateSingleAabb(this->m_dynamicsWorld, o);
  v3 = this->m_dynamicsWorld->m_broadphasePairCache->getOverlappingPairCache(this->m_dynamicsWorld->m_broadphasePairCache);
  v3->cleanProxyFromPairs(v3, o->m_broadphaseHandle, this->m_dynamicsWorld->m_dispatcher1);
}
