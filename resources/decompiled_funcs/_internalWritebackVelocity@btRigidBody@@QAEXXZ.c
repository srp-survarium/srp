void __thiscall btRigidBody::internalWritebackVelocity(btRigidBody *this)
{
  unsigned int v1; // xmm1_4
  btVector3 v2; // [esp+0h] [ebp-10h]

  if ( this->m_inverseMass != 0.0 )
  {
    v2.mVec128.m128_f32[0] = this->m_linearVelocity.mVec128.m128_f32[0]
                           + this->m_deltaLinearVelocity.mVec128.m128_f32[0];
    v2.mVec128.m128_f32[1] = this->m_linearVelocity.mVec128.m128_f32[1]
                           + this->m_deltaLinearVelocity.mVec128.m128_f32[1];
    v2.mVec128.m128_f32[2] = this->m_linearVelocity.mVec128.m128_f32[2]
                           + this->m_deltaLinearVelocity.mVec128.m128_f32[2];
    v2.mVec128.m128_i32[3] = 0;
    this->m_linearVelocity = (btVector3)v2.mVec128;
    v2.mVec128.m128_f32[0] = this->m_angularVelocity.mVec128.m128_f32[0]
                           + this->m_deltaAngularVelocity.mVec128.m128_f32[0];
    v2.mVec128.m128_f32[1] = this->m_deltaAngularVelocity.mVec128.m128_f32[1]
                           + this->m_angularVelocity.mVec128.m128_f32[1];
    *(float *)&v1 = this->m_deltaAngularVelocity.mVec128.m128_f32[2] + this->m_angularVelocity.mVec128.m128_f32[2];
    this->m_angularVelocity.mVec128.m128_u64[0] = v2.mVec128.m128_u64[0];
    this->m_angularVelocity.mVec128.m128_u64[1] = v1;
  }
}
