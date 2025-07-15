void __usercall btRigidBody::setupRigidBody(
        btRigidBody *this@<esi>,
        const btRigidBody::btRigidBodyConstructionInfo *constructionInfo@<edi>)
{
  const vostok::math::float4x4 *v2; // xmm0_4
  btTransform *p_m_worldTransform; // ebx
  btMotionState *m_optionalMotionState; // ecx
  btRigidBody_vtbl *v5; // edx
  void (__thiscall *setCollisionShape)(struct btRigidBody *, btCollisionShape *); // edx
  int v7; // eax
  float m_mass; // xmm1_4
  btRigidBody *v9; // ecx
  float m_inverseMass; // xmm1_4
  unsigned int v11; // xmm2_4
  unsigned __int64 v12; // [esp+18h] [ebp-10h]

  v2 = clear_value;
  this->m_internalType = 2;
  this->m_linearVelocity.mVec128.m128_u64[0] = 0;
  this->m_linearVelocity.mVec128.m128_u64[1] = 0;
  this->m_angularVelocity.mVec128.m128_u64[0] = 0;
  this->m_angularVelocity.mVec128.m128_u64[1] = 0;
  this->m_angularFactor.mVec128.m128_i32[0] = (int)v2;
  this->m_angularFactor.mVec128.m128_i32[1] = (int)v2;
  this->m_angularFactor.mVec128.m128_u64[1] = (unsigned int)v2;
  this->m_linearFactor.mVec128.m128_i32[0] = (int)v2;
  this->m_linearFactor.mVec128.m128_i32[1] = (int)v2;
  this->m_linearFactor.mVec128.m128_u64[1] = (unsigned int)v2;
  this->m_gravity.mVec128.m128_u64[0] = 0;
  this->m_gravity.mVec128.m128_u64[1] = 0;
  this->m_gravity_acceleration.mVec128.m128_u64[0] = 0;
  this->m_gravity_acceleration.mVec128.m128_u64[1] = 0;
  this->m_totalForce.mVec128.m128_u64[0] = 0;
  this->m_totalForce.mVec128.m128_u64[1] = 0;
  this->m_totalTorque.mVec128.m128_u64[0] = 0;
  this->m_totalTorque.mVec128.m128_u64[1] = 0;
  btRigidBody::setDamping(this, constructionInfo->m_linearDamping, constructionInfo->m_angularDamping);
  p_m_worldTransform = &this->m_worldTransform;
  this->m_linearSleepingThreshold = constructionInfo->m_linearSleepingThreshold;
  this->m_angularSleepingThreshold = constructionInfo->m_angularSleepingThreshold;
  this->m_optionalMotionState = constructionInfo->m_motionState;
  this->m_contactSolverType = 0;
  this->m_frictionSolverType = 0;
  this->m_additionalDamping = constructionInfo->m_additionalDamping;
  m_optionalMotionState = this->m_optionalMotionState;
  this->m_additionalDampingFactor = constructionInfo->m_additionalDampingFactor;
  this->m_additionalLinearDampingThresholdSqr = constructionInfo->m_additionalLinearDampingThresholdSqr;
  this->m_additionalAngularDampingThresholdSqr = constructionInfo->m_additionalAngularDampingThresholdSqr;
  this->m_additionalAngularDampingFactor = constructionInfo->m_additionalAngularDampingFactor;
  if ( m_optionalMotionState )
  {
    m_optionalMotionState->getWorldTransform(m_optionalMotionState, &this->m_worldTransform);
  }
  else
  {
    p_m_worldTransform->m_basis.m_el[0].mVec128.m128_u64[0] = constructionInfo->m_startWorldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
    this->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1] = constructionInfo->m_startWorldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
    this->m_worldTransform.m_basis.m_el[1] = constructionInfo->m_startWorldTransform.m_basis.m_el[1];
    this->m_worldTransform.m_basis.m_el[2] = constructionInfo->m_startWorldTransform.m_basis.m_el[2];
    this->m_worldTransform.m_origin = constructionInfo->m_startWorldTransform.m_origin;
  }
  this->m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_u64[0] = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_u64[0];
  this->m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_u64[1] = this->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
  this->m_interpolationWorldTransform.m_basis.m_el[1] = this->m_worldTransform.m_basis.m_el[1];
  this->m_interpolationWorldTransform.m_basis.m_el[2] = this->m_worldTransform.m_basis.m_el[2];
  this->m_interpolationWorldTransform.m_origin = this->m_worldTransform.m_origin;
  this->m_interpolationLinearVelocity.mVec128.m128_u64[0] = 0;
  this->m_interpolationLinearVelocity.mVec128.m128_u64[1] = 0;
  this->m_interpolationAngularVelocity.mVec128.m128_u64[0] = 0;
  this->m_interpolationAngularVelocity.mVec128.m128_u64[1] = 0;
  v5 = this->__vftable;
  this->m_friction = constructionInfo->m_friction;
  setCollisionShape = v5->setCollisionShape;
  this->m_restitution = constructionInfo->m_restitution;
  setCollisionShape(this, constructionInfo->m_collisionShape);
  v7 = uniqueId;
  this->m_debugBodyId = uniqueId;
  m_mass = constructionInfo->m_mass;
  uniqueId = v7 + 1;
  btRigidBody::setMassProps(this, &constructionInfo->m_localInertia, m_mass);
  btRigidBody::updateInertiaTensor(v9, (int)this);
  this->m_rigidbodyFlags = 0;
  this->m_deltaLinearVelocity.mVec128.m128_u64[0] = 0;
  this->m_deltaLinearVelocity.mVec128.m128_u64[1] = 0;
  this->m_deltaAngularVelocity.mVec128.m128_u64[0] = 0;
  this->m_deltaAngularVelocity.mVec128.m128_u64[1] = 0;
  m_inverseMass = this->m_inverseMass;
  *(float *)&v12 = m_inverseMass * this->m_linearFactor.mVec128.m128_f32[0];
  *((float *)&v12 + 1) = this->m_linearFactor.mVec128.m128_f32[1] * m_inverseMass;
  *(float *)&v11 = this->m_linearFactor.mVec128.m128_f32[2] * m_inverseMass;
  this->m_invMass.mVec128.m128_u64[0] = v12;
  this->m_invMass.mVec128.m128_u64[1] = v11;
  this->m_pushVelocity.mVec128.m128_u64[0] = 0;
  this->m_pushVelocity.mVec128.m128_u64[1] = 0;
  this->m_turnVelocity.mVec128.m128_u64[0] = 0;
  this->m_turnVelocity.mVec128.m128_u64[1] = 0;
}
