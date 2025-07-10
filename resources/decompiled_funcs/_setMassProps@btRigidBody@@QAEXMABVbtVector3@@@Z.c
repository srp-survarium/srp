void __usercall btRigidBody::setMassProps(btRigidBody *this@<ecx>, const btVector3 *inertia@<edx>, float a3@<xmm1>)
{
  const vostok::math::float4x4 *v4; // xmm2_4
  unsigned int v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float m_inverseMass; // xmm1_4
  unsigned __int64 v12; // [esp+0h] [ebp-10h]
  btVector3 v13; // [esp+0h] [ebp-10h]

  v4 = clear_value;
  if ( a3 == 0.0 )
  {
    this->m_collisionFlags |= 1u;
    this->m_inverseMass = 0.0;
  }
  else
  {
    this->m_collisionFlags &= ~1u;
    this->m_inverseMass = *(float *)&v4 / a3;
  }
  *(float *)&v12 = this->m_gravity_acceleration.mVec128.m128_f32[0] * a3;
  *((float *)&v12 + 1) = this->m_gravity_acceleration.mVec128.m128_f32[1] * a3;
  *(float *)&v5 = this->m_gravity_acceleration.mVec128.m128_f32[2] * a3;
  this->m_gravity.mVec128.m128_u64[0] = v12;
  this->m_gravity.mVec128.m128_u64[1] = v5;
  v6 = inertia->mVec128.m128_f32[2];
  if ( v6 == 0.0 )
    v7 = 0.0;
  else
    v7 = *(float *)&v4 / v6;
  v8 = inertia->mVec128.m128_f32[1];
  if ( v8 == 0.0 )
    v9 = 0.0;
  else
    v9 = *(float *)&v4 / v8;
  if ( inertia->mVec128.m128_f32[0] == 0.0 )
    v10 = 0.0;
  else
    v10 = *(float *)&v4 / inertia->mVec128.m128_f32[0];
  this->m_invInertiaLocal.mVec128.m128_f32[0] = v10;
  this->m_invInertiaLocal.mVec128.m128_i32[3] = 0;
  this->m_invInertiaLocal.mVec128.m128_f32[1] = v9;
  this->m_invInertiaLocal.mVec128.m128_f32[2] = v7;
  m_inverseMass = this->m_inverseMass;
  v13.mVec128.m128_f32[0] = this->m_linearFactor.mVec128.m128_f32[0] * m_inverseMass;
  v13.mVec128.m128_f32[1] = this->m_linearFactor.mVec128.m128_f32[1] * m_inverseMass;
  v13.mVec128.m128_i32[3] = 0;
  v13.mVec128.m128_f32[2] = this->m_linearFactor.mVec128.m128_f32[2] * m_inverseMass;
  this->m_invMass = (btVector3)v13.mVec128;
}
