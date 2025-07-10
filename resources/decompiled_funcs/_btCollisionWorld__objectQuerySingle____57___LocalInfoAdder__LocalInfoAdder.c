void __userpurge btCollisionWorld::objectQuerySingle_::_57_::LocalInfoAdder::LocalInfoAdder(
        btCollisionWorld::objectQuerySingle::__l57::LocalInfoAdder *this@<eax>,
        btCollisionWorld::ConvexResultCallback *user@<ecx>,
        int i)
{
  const vostok::math::float4x4 *v3; // xmm0_4

  v3 = clear_value;
  this->m_collisionFilterGroup = 1;
  this->m_collisionFilterMask = -1;
  LODWORD(this->m_closestHitFraction) = v3;
  this->__vftable = (btCollisionWorld::objectQuerySingle::__l57::LocalInfoAdder_vtbl *)&`btCollisionWorld::objectQuerySingle'::`57'::LocalInfoAdder::`vftable';
  this->m_userCallback = user;
  this->m_i = i;
  this->m_closestHitFraction = user->m_closestHitFraction;
}
