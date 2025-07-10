void __userpurge vostok::physics::character_move_test_callback::character_move_test_callback(
        vostok::physics::character_move_test_callback *this@<eax>,
        const btVector3 *up_vector@<ecx>,
        btCollisionObject *self,
        float minSlopeDot)
{
  LODWORD(this->m_closestHitFraction) = clear_value;
  this->m_convexFromWorld.mVec128.m128_u64[0] = 0;
  this->m_convexFromWorld.mVec128.m128_u64[1] = 0;
  this->m_convexToWorld.mVec128.m128_u64[0] = 0;
  this->m_collisionFilterGroup = 1;
  this->m_convexToWorld.mVec128.m128_u64[1] = 0;
  this->m_collisionFilterMask = -1;
  this->m_hitCollisionObject = 0;
  this->__vftable = (vostok::physics::character_move_test_callback_vtbl *)&vostok::physics::character_move_test_callback::`vftable';
  this->m_up_vector = (const btVector3)up_vector->mVec128;
  this->m_self = self;
  this->m_minSlopeDot = minSlopeDot;
}
