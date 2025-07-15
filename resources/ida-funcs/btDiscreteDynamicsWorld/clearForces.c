void __thiscall btDiscreteDynamicsWorld::clearForces(btDiscreteDynamicsWorld *this)
{
  int i; // esi
  btRigidBody *v2; // edx

  for ( i = 0; i < this->m_nonStaticRigidBodies.m_size; v2->m_totalTorque.mVec128.m128_i32[3] = 0 )
  {
    v2 = this->m_nonStaticRigidBodies.m_data[i];
    v2->m_totalForce.mVec128.m128_i32[0] = 0;
    v2->m_totalForce.mVec128.m128_i32[1] = 0;
    v2->m_totalForce.mVec128.m128_i32[2] = 0;
    v2->m_totalForce.mVec128.m128_i32[3] = 0;
    ++i;
    v2->m_totalTorque.mVec128.m128_i32[0] = 0;
    v2->m_totalTorque.mVec128.m128_i32[1] = 0;
    v2->m_totalTorque.mVec128.m128_i32[2] = 0;
  }
}
