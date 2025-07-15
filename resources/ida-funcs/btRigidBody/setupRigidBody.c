void __thiscall btRigidBody::setupRigidBody(btRigidBody *this, btRigidBody *constructionInfo, int a4)
{
  float v4; // xmm1_4
  float v5; // xmm3_4
  float *v6; // ecx
  float *v7; // ecx
  btMotionState *v8; // ecx
  btMotionState *m_optionalMotionState; // ecx
  btRigidBody_vtbl *v10; // eax
  int v11; // eax
  btRigidBody *v12; // ecx
  float m_inverseMass; // xmm1_4
  float v14; // xmm2_4
  int v15; // [esp+4h] [ebp-20h] BYREF
  float v16; // [esp+8h] [ebp-1Ch] BYREF
  float v17; // [esp+Ch] [ebp-18h] BYREF
  float v18; // [esp+10h] [ebp-14h] BYREF
  btVector3 v19; // [esp+14h] [ebp-10h]

  v4 = s_bm_current_air_resistance;
  constructionInfo->m_internalType = 2;
  constructionInfo->m_linearVelocity.mVec128.m128_u64[0] = 0;
  constructionInfo->m_linearVelocity.mVec128.m128_u64[1] = 0;
  constructionInfo->m_angularVelocity.mVec128.m128_u64[0] = 0;
  constructionInfo->m_angularVelocity.mVec128.m128_u64[1] = 0;
  constructionInfo->m_angularFactor.mVec128.m128_f32[0] = v4;
  constructionInfo->m_angularFactor.mVec128.m128_f32[1] = v4;
  constructionInfo->m_angularFactor.mVec128.m128_u64[1] = LODWORD(v4);
  constructionInfo->m_linearFactor.mVec128.m128_f32[0] = v4;
  constructionInfo->m_linearFactor.mVec128.m128_f32[1] = v4;
  constructionInfo->m_linearFactor.mVec128.m128_u64[1] = LODWORD(v4);
  constructionInfo->m_gravity.mVec128.m128_u64[0] = 0;
  constructionInfo->m_gravity.mVec128.m128_u64[1] = 0;
  constructionInfo->m_gravity_acceleration.mVec128.m128_u64[0] = 0;
  constructionInfo->m_gravity_acceleration.mVec128.m128_u64[1] = 0;
  constructionInfo->m_totalForce.mVec128.m128_u64[0] = 0;
  constructionInfo->m_totalForce.mVec128.m128_u64[1] = 0;
  constructionInfo->m_totalTorque.mVec128.m128_u64[0] = 0;
  constructionInfo->m_totalTorque.mVec128.m128_u64[1] = 0;
  v5 = *(float *)(a4 + 116);
  v17 = *(float *)(a4 + 112);
  v18 = v5;
  v16 = v4;
  v15 = 0;
  if ( v17 >= 0.0 )
  {
    v6 = &v16;
    if ( v17 <= v4 )
      v6 = &v17;
  }
  else
  {
    v6 = (float *)&v15;
  }
  constructionInfo->m_linearDamping = *v6;
  v16 = v4;
  v17 = 0.0;
  if ( v5 >= 0.0 )
  {
    v7 = &v16;
    if ( v5 <= v4 )
      v7 = &v18;
  }
  else
  {
    v7 = &v17;
  }
  constructionInfo->m_angularDamping = *v7;
  constructionInfo->m_linearSleepingThreshold = *(float *)(a4 + 128);
  constructionInfo->m_angularSleepingThreshold = *(float *)(a4 + 132);
  v8 = *(btMotionState **)(a4 + 4);
  constructionInfo->m_contactSolverType = 0;
  constructionInfo->m_frictionSolverType = 0;
  constructionInfo->m_optionalMotionState = v8;
  constructionInfo->m_additionalDamping = *(_BYTE *)(a4 + 136);
  m_optionalMotionState = constructionInfo->m_optionalMotionState;
  constructionInfo->m_additionalDampingFactor = *(float *)(a4 + 140);
  constructionInfo->m_additionalLinearDampingThresholdSqr = *(float *)(a4 + 144);
  constructionInfo->m_additionalAngularDampingThresholdSqr = *(float *)(a4 + 148);
  constructionInfo->m_additionalAngularDampingFactor = *(float *)(a4 + 152);
  if ( m_optionalMotionState )
    m_optionalMotionState->getWorldTransform(m_optionalMotionState, &constructionInfo->m_worldTransform);
  else
    constructionInfo->m_worldTransform = *(btTransform *)(a4 + 16);
  constructionInfo->m_interpolationWorldTransform = constructionInfo->m_worldTransform;
  constructionInfo->m_interpolationLinearVelocity.mVec128.m128_u64[0] = 0;
  constructionInfo->m_interpolationLinearVelocity.mVec128.m128_u64[1] = 0;
  constructionInfo->m_interpolationAngularVelocity.mVec128.m128_u64[0] = 0;
  constructionInfo->m_interpolationAngularVelocity.mVec128.m128_u64[1] = 0;
  v10 = constructionInfo->__vftable;
  constructionInfo->m_friction = *(float *)(a4 + 120);
  constructionInfo->m_restitution = *(float *)(a4 + 124);
  v10->setCollisionShape(constructionInfo, *(btCollisionShape **)(a4 + 80));
  v11 = uniqueId++;
  constructionInfo->m_debugBodyId = v11;
  btRigidBody::setMassProps(constructionInfo, (const btVector3 *)(a4 + 96), *(float *)a4);
  btRigidBody::updateInertiaTensor(v12, (int)constructionInfo);
  constructionInfo->m_rigidbodyFlags = 0;
  constructionInfo->m_deltaLinearVelocity.mVec128.m128_u64[0] = 0;
  constructionInfo->m_deltaLinearVelocity.mVec128.m128_u64[1] = 0;
  constructionInfo->m_deltaAngularVelocity.mVec128.m128_u64[0] = 0;
  constructionInfo->m_deltaAngularVelocity.mVec128.m128_u64[1] = 0;
  m_inverseMass = constructionInfo->m_inverseMass;
  v19.mVec128.m128_f32[0] = m_inverseMass * constructionInfo->m_linearFactor.mVec128.m128_f32[0];
  v19.mVec128.m128_f32[1] = constructionInfo->m_linearFactor.mVec128.m128_f32[1] * m_inverseMass;
  v14 = constructionInfo->m_linearFactor.mVec128.m128_f32[2];
  v19.mVec128.m128_i32[3] = 0;
  v19.mVec128.m128_f32[2] = v14 * m_inverseMass;
  constructionInfo->m_invMass = (btVector3)v19.mVec128;
  constructionInfo->m_pushVelocity.mVec128.m128_u64[0] = 0;
  constructionInfo->m_pushVelocity.mVec128.m128_u64[1] = 0;
  constructionInfo->m_turnVelocity.mVec128.m128_u64[0] = 0;
  constructionInfo->m_turnVelocity.mVec128.m128_u64[1] = 0;
}
