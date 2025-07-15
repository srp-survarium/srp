void __fastcall btCollisionWorld::rayTestSingle_::_31_::LocalInfoAdder2::LocalInfoAdder2(
        btCollisionWorld::RayResultCallback *user,
        unsigned int i,
        btCollisionWorld::rayTestSingle::__l31::LocalInfoAdder2 *this)
{
  const vostok::math::float4x4 *v3; // xmm0_4

  v3 = clear_value;
  this->m_collisionFilterGroup = 1;
  LODWORD(this->m_closestHitFraction) = v3;
  this->m_collisionFilterMask = -1;
  this->m_collisionObject = 0;
  this->m_flags = 0;
  this->__vftable = (btCollisionWorld::rayTestSingle::__l31::LocalInfoAdder2_vtbl *)&`btCollisionWorld::rayTestSingle'::`31'::LocalInfoAdder2::`vftable';
  this->m_userCallback = user;
  this->m_i = i;
  this->m_shape_id = i;
  this->m_closestHitFraction = user->m_closestHitFraction;
}
