void __thiscall btDiscreteDynamicsWorld::applyGravity(btDiscreteDynamicsWorld *this)
{
  int i; // esi
  btRigidBody *v2; // eax
  int m_activationState1; // edx
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4

  for ( i = 0; i < this->m_nonStaticRigidBodies.m_size; ++i )
  {
    v2 = this->m_nonStaticRigidBodies.m_data[i];
    m_activationState1 = v2->m_activationState1;
    if ( m_activationState1 != 2 && m_activationState1 != 5 && (v2->m_collisionFlags & 3) == 0 )
    {
      v4 = v2->m_linearFactor.mVec128.m128_f32[2] * v2->m_gravity.mVec128.m128_f32[2];
      v5 = v2->m_totalForce.mVec128.m128_f32[0]
         + (float)(v2->m_linearFactor.mVec128.m128_f32[0] * v2->m_gravity.mVec128.m128_f32[0]);
      v2->m_totalForce.mVec128.m128_f32[1] = v2->m_totalForce.mVec128.m128_f32[1]
                                           + (float)(v2->m_linearFactor.mVec128.m128_f32[1]
                                                   * v2->m_gravity.mVec128.m128_f32[1]);
      v6 = v2->m_totalForce.mVec128.m128_f32[2] + v4;
      v2->m_totalForce.mVec128.m128_f32[0] = v5;
      v2->m_totalForce.mVec128.m128_f32[2] = v6;
    }
  }
}
