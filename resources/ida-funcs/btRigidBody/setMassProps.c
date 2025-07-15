void __usercall btRigidBody::setMassProps(btRigidBody *this@<ecx>, const btVector3 *inertia@<edx>, float a3@<xmm2>)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float m_inverseMass; // xmm1_4
  unsigned __int64 v10; // [esp+4h] [ebp-Ch]
  unsigned __int64 v11; // [esp+4h] [ebp-Ch]

  v3 = s_bm_current_air_resistance;
  if ( a3 == 0.0 )
  {
    this->m_collisionFlags |= 1u;
    this->m_inverseMass = 0.0;
  }
  else
  {
    this->m_collisionFlags &= ~1u;
    this->m_inverseMass = v3 / a3;
  }
  *(float *)&v10 = this->m_gravity_acceleration.mVec128.m128_f32[1] * a3;
  *((float *)&v10 + 1) = this->m_gravity_acceleration.mVec128.m128_f32[2] * a3;
  this->m_gravity.mVec128.m128_f32[0] = this->m_gravity_acceleration.mVec128.m128_f32[0] * a3;
  *(unsigned __int64 *)((char *)this->m_gravity.mVec128.m128_u64 + 4) = v10;
  this->m_gravity.mVec128.m128_i32[3] = 0;
  v4 = inertia->mVec128.m128_f32[2];
  if ( v4 == 0.0 )
    v5 = 0.0;
  else
    v5 = v3 / v4;
  v6 = inertia->mVec128.m128_f32[1];
  if ( v6 == 0.0 )
    v7 = 0.0;
  else
    v7 = v3 / v6;
  if ( inertia->mVec128.m128_f32[0] == 0.0 )
    v8 = 0.0;
  else
    v8 = v3 / inertia->mVec128.m128_f32[0];
  this->m_invInertiaLocal.mVec128.m128_f32[1] = v7;
  this->m_invInertiaLocal.mVec128.m128_f32[0] = v8;
  this->m_invInertiaLocal.mVec128.m128_u64[1] = LODWORD(v5);
  m_inverseMass = this->m_inverseMass;
  *(float *)&v11 = this->m_linearFactor.mVec128.m128_f32[1] * m_inverseMass;
  *((float *)&v11 + 1) = this->m_linearFactor.mVec128.m128_f32[2] * m_inverseMass;
  this->m_invMass.mVec128.m128_f32[0] = this->m_linearFactor.mVec128.m128_f32[0] * m_inverseMass;
  *(unsigned __int64 *)((char *)this->m_invMass.mVec128.m128_u64 + 4) = v11;
  this->m_invMass.mVec128.m128_i32[3] = 0;
}
