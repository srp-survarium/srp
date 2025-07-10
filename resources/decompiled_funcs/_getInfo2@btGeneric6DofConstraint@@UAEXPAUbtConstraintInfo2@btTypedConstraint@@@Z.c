void __thiscall btGeneric6DofConstraint::getInfo2(
        btGeneric6DofConstraint *this,
        btTypedConstraint::btConstraintInfo2 *info)
{
  btRigidBody *m_rbA; // eax
  btRigidBody *m_rbB; // ecx
  const btTransform *p_m_worldTransform; // ebx
  const btTransform *v6; // edi
  const btTransform *v7; // eax
  const btTransform *v8; // eax
  const btVector3 *p_m_linearVelocity; // [esp-Ch] [ebp-2Ch]
  const btVector3 *v10; // [esp-8h] [ebp-28h]
  const btVector3 *p_m_angularVelocity; // [esp-4h] [ebp-24h]
  btVector3 *linVelA; // [esp+10h] [ebp-10h]
  const btVector3 *angVelB; // [esp+14h] [ebp-Ch]
  const btVector3 *angVelA; // [esp+18h] [ebp-8h]
  btGeneric6DofConstraint *linVelB; // [esp+1Ch] [ebp-4h]

  m_rbA = this->m_rbA;
  m_rbB = this->m_rbB;
  linVelA = &m_rbA->m_linearVelocity;
  p_m_worldTransform = &m_rbB->m_worldTransform;
  v6 = &m_rbA->m_worldTransform;
  p_m_angularVelocity = &m_rbB->m_angularVelocity;
  v10 = &m_rbA->m_angularVelocity;
  linVelB = (btGeneric6DofConstraint *)&m_rbB->m_linearVelocity;
  angVelA = &m_rbA->m_angularVelocity;
  angVelB = &m_rbB->m_angularVelocity;
  p_m_linearVelocity = &m_rbB->m_linearVelocity;
  if ( this->m_useOffsetForConstraintFrame )
  {
    v7 = (const btTransform *)btGeneric6DofConstraint::setAngularLimits(
                                info,
                                0,
                                this,
                                v6,
                                &m_rbB->m_worldTransform,
                                linVelA,
                                p_m_linearVelocity,
                                v10,
                                p_m_angularVelocity);
    btGeneric6DofConstraint::setLinearLimits(
      linVelB,
      this,
      info,
      v7,
      v6,
      p_m_worldTransform,
      linVelA,
      (const btVector3 *)linVelB,
      angVelA,
      angVelB);
  }
  else
  {
    v8 = btGeneric6DofConstraint::setLinearLimits(
           (btGeneric6DofConstraint *)linVelA,
           this,
           info,
           0,
           v6,
           p_m_worldTransform,
           linVelA,
           p_m_linearVelocity,
           v10,
           p_m_angularVelocity);
    btGeneric6DofConstraint::setAngularLimits(
      info,
      (int)v8,
      this,
      v6,
      p_m_worldTransform,
      linVelA,
      (const btVector3 *)linVelB,
      angVelA,
      angVelB);
  }
}
