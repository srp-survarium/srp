btRigidBody *__usercall btSequentialImpulseConstraintSolver::getFixedBody@<eax>(
        btRigidBody *this@<ecx>,
        float a2@<xmm4>)
{
  int v2; // ecx
  btVector3 v4; // [esp+0h] [ebp-10h] BYREF

  if ( (_S1_9 & 1) == 0 )
  {
    _S1_9 |= 1u;
    v4.mVec128.m128_i32[3] = 0;
    btRigidBody::btRigidBody(this, a2, (btRigidBody::btRigidBodyConstructionInfo *)&v4, 0, 0, 0);
    atexit((int (__cdecl *)())btSequentialImpulseConstraintSolver::getFixedBody_::_2_::_dynamic_atexit_destructor_for__s_fixed__);
  }
  *(unsigned __int64 *)((char *)v4.mVec128.m128_u64 + 4) = 0;
  btRigidBody::setMassProps(&s_fixed, &v4, 0.0);
  return (btRigidBody *)v2;
}
