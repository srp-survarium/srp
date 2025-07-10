void __usercall btDiscreteDynamicsWorld::synchronizeSingleMotionState(
        btDiscreteDynamicsWorld *this@<ecx>,
        btRigidBody *body@<esi>)
{
  btTransform predictedTransform; // [esp+50h] [ebp-40h] BYREF

  if ( body->m_optionalMotionState )
  {
    if ( (body->m_collisionFlags & 3) == 0 )
    {
      btTransformUtil::integrateTransform(
        &body->m_interpolationWorldTransform,
        &body->m_interpolationLinearVelocity,
        &body->m_interpolationAngularVelocity,
        body->m_hitFraction * this->m_localTime,
        &predictedTransform);
      body->m_optionalMotionState->setWorldTransform(body->m_optionalMotionState, &predictedTransform);
    }
  }
}
