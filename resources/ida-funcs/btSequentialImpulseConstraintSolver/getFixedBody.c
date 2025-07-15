btRigidBody *__usercall btSequentialImpulseConstraintSolver::getFixedBody@<eax>(
        btRigidBody *a1@<ecx>,
        float a2@<xmm10>)
{
  int v2; // ecx
  btVector3 motionState; // [esp+0h] [ebp-10h] BYREF

  if ( (_S1_9 & 1) == 0 )
  {
    _S1_9 |= 1u;
    motionState.mVec128.m128_i32[3] = 0;
    btRigidBody::btRigidBody(a1, COERCE_FLOAT(&motionState), 0, 0, 0);
    atexit(btSequentialImpulseConstraintSolver::getFixedBody_::_2_::_dynamic_atexit_destructor_for__s_fixed__);
  }
  memset(&motionState, 0, sizeof(motionState));
  btRigidBody::setMassProps(&s_fixed, a2, &motionState);
  return (btRigidBody *)v2;
}
