void __usercall btRigidBody::applyImpulse(
        btRigidBody *this@<edx>,
        const btVector3 *impulse@<ecx>,
        const btVector3 *rel_pos@<esi>)
{
  float m_inverseMass; // xmm0_4
  float v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14[4]; // [esp+0h] [ebp-10h] BYREF

  m_inverseMass = this->m_inverseMass;
  if ( m_inverseMass != 0.0 )
  {
    v4 = this->m_linearFactor.mVec128.m128_f32[2] * impulse->mVec128.m128_f32[2];
    v5 = m_inverseMass * (float)(this->m_linearFactor.mVec128.m128_f32[1] * impulse->mVec128.m128_f32[1]);
    this->m_linearVelocity.mVec128.m128_f32[0] = this->m_linearVelocity.mVec128.m128_f32[0]
                                               + (float)(m_inverseMass
                                                       * (float)(impulse->mVec128.m128_f32[0]
                                                               * this->m_linearFactor.mVec128.m128_f32[0]));
    v6 = this->m_linearVelocity.mVec128.m128_f32[1] + v5;
    v7 = this->m_linearVelocity.mVec128.m128_f32[2] + (float)(m_inverseMass * v4);
    this->m_linearVelocity.mVec128.m128_f32[1] = v6;
    this->m_linearVelocity.mVec128.m128_f32[2] = v7;
    if ( this != (btRigidBody *)-576 )
    {
      v8 = rel_pos->mVec128.m128_f32[1];
      v9 = rel_pos->mVec128.m128_f32[2];
      v10 = this->m_linearFactor.mVec128.m128_f32[1] * impulse->mVec128.m128_f32[1];
      v11 = this->m_linearFactor.mVec128.m128_f32[2] * impulse->mVec128.m128_f32[2];
      v12 = this->m_linearFactor.mVec128.m128_f32[0] * impulse->mVec128.m128_f32[0];
      v14[0] = (float)(v8 * v11) - (float)(v9 * v10);
      v13 = (float)(rel_pos->mVec128.m128_f32[0] * v10) - (float)(v8 * v12);
      v14[1] = (float)(v9 * v12) - (float)(rel_pos->mVec128.m128_f32[0] * v11);
      v14[2] = v13;
      v14[3] = 0.0;
      btRigidBody::applyTorqueImpulse((btRigidBody *)v14, (float *)this);
    }
  }
}
