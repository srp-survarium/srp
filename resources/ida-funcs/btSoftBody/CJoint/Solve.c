void __thiscall btSoftBody::CJoint::Solve(btSoftBody::CJoint *this, float dt, float sor)
{
  float v4; // xmm7_4
  float v5; // xmm3_4
  float v6; // xmm7_4
  float v7; // xmm3_4
  float v8; // xmm7_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float m_friction; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float *p_m_massmatrix; // ebx
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  btSoftBody::Body *v22; // ebx
  btSoftBody::Impulse *m_soft; // ecx
  float v24; // xmm2_4
  float m_selfCollisionImpulseFactor; // xmm0_4
  btSoftBody::Impulse *v26; // eax
  const btVector3 *v27; // [esp+0h] [ebp-D0h]
  const btVector3 *v28; // [esp+0h] [ebp-D0h]
  btSoftBody::Body *m_bodies; // [esp+10h] [ebp-C0h]
  float v30; // [esp+10h] [ebp-C0h]
  btVector3 *m_rpos; // [esp+14h] [ebp-BCh]
  const btVector3 *v32; // [esp+18h] [ebp-B8h]
  btSoftBody::Body *v33; // [esp+1Ch] [ebp-B4h]
  btVector3 v34; // [esp+20h] [ebp-B0h] BYREF
  btSoftBody::Impulse v35; // [esp+30h] [ebp-A0h] BYREF
  btSoftBody::Impulse v36; // [esp+60h] [ebp-70h] BYREF
  btVector3 v37; // [esp+90h] [ebp-40h] BYREF
  btSoftBody::Impulse v38; // [esp+A0h] [ebp-30h] BYREF

  m_bodies = this->m_bodies;
  m_rpos = this->m_rpos;
  btSoftBody::Body::velocity((btSoftBody::Body *)this->m_rpos, &v34, (btVector3 *)this->m_bodies, v27);
  v33 = &this->m_bodies[1];
  v32 = &this->m_rpos[1];
  btSoftBody::Body::velocity((btSoftBody::Body *)&this->m_rpos[1], &v37, (btVector3 *)&this->m_bodies[1], v28);
  v4 = this->m_normal.mVec128.m128_f32[2];
  v5 = this->m_normal.mVec128.m128_f32[1];
  memset(&v35.m_drift, 0, sizeof(v35.m_drift));
  *((_DWORD *)&v35 + 8) = *((_DWORD *)&v35 + 8) & 0xFFFFFFFC | 1;
  v35.m_velocity.mVec128.m128_u64[0] = this->m_drift.mVec128.m128_u64[0];
  v6 = (float)(v4 * (float)(v34.mVec128.m128_f32[2] - v37.mVec128.m128_f32[2]))
     + (float)(v5 * (float)(v34.mVec128.m128_f32[1] - v37.mVec128.m128_f32[1]));
  v7 = this->m_normal.mVec128.m128_f32[0];
  v35.m_velocity.mVec128.m128_i32[2] = this->m_drift.mVec128.m128_i32[2];
  v8 = v6 + (float)(v7 * (float)(v34.mVec128.m128_f32[0] - v37.mVec128.m128_f32[0]));
  v35.m_velocity.mVec128.m128_i32[3] = this->m_drift.mVec128.m128_i32[3];
  if ( v8 < 0.0 )
  {
    v9 = this->m_normal.mVec128.m128_f32[2] * v8;
    v10 = this->m_normal.mVec128.m128_f32[0] * v8;
    v11 = this->m_normal.mVec128.m128_f32[1] * v8;
    v37.mVec128.m128_f32[2] = (float)(v34.mVec128.m128_f32[2] - v37.mVec128.m128_f32[2]) - v9;
    m_friction = this->m_friction;
    v37.mVec128.m128_f32[1] = (float)(v34.mVec128.m128_f32[1] - v37.mVec128.m128_f32[1]) - v11;
    v35.m_velocity.mVec128.m128_f32[0] = (float)((float)(m_friction
                                                       * (float)((float)(v34.mVec128.m128_f32[0]
                                                                       - v37.mVec128.m128_f32[0])
                                                               - v10))
                                               + v10)
                                       + v35.m_velocity.mVec128.m128_f32[0];
    v35.m_velocity.mVec128.m128_f32[1] = (float)((float)(m_friction * v37.mVec128.m128_f32[1]) + v11)
                                       + v35.m_velocity.mVec128.m128_f32[1];
    v35.m_velocity.mVec128.m128_f32[2] = (float)((float)(m_friction * v37.mVec128.m128_f32[2]) + v9)
                                       + v35.m_velocity.mVec128.m128_f32[2];
  }
  v13 = this->m_massmatrix.m_el[0].mVec128.m128_f32[2];
  v14 = this->m_massmatrix.m_el[0].mVec128.m128_f32[1] * v35.m_velocity.mVec128.m128_f32[1];
  v15 = this->m_massmatrix.m_el[1].mVec128.m128_f32[1] * v35.m_velocity.mVec128.m128_f32[1];
  v16 = this->m_massmatrix.m_el[2].mVec128.m128_f32[1] * v35.m_velocity.mVec128.m128_f32[1];
  p_m_massmatrix = (float *)&this->m_massmatrix;
  v18 = (float)((float)((float)(v13 * v35.m_velocity.mVec128.m128_f32[2]) + v14)
              + (float)(*p_m_massmatrix * v35.m_velocity.mVec128.m128_f32[0]))
      * sor;
  v19 = (float)((float)((float)(p_m_massmatrix[6] * v35.m_velocity.mVec128.m128_f32[2]) + v15)
              + (float)(p_m_massmatrix[4] * v35.m_velocity.mVec128.m128_f32[0]))
      * sor;
  v20 = (float)(p_m_massmatrix[10] * v35.m_velocity.mVec128.m128_f32[2]) + v16;
  v21 = p_m_massmatrix[8] * v35.m_velocity.mVec128.m128_f32[0];
  v22 = m_bodies;
  m_soft = (btSoftBody::Impulse *)m_bodies->m_soft;
  v34.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v19), LODWORD(v18));
  v24 = (float)(v20 + v21) * sor;
  v34.mVec128.m128_u64[1] = LODWORD(v24);
  v35.m_velocity.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v19), LODWORD(v18));
  v35.m_velocity.mVec128.m128_u64[1] = LODWORD(v24);
  if ( m_soft == (btSoftBody::Impulse *)v33->m_soft )
  {
    if ( (*((_BYTE *)&v35 + 32) & 1) != 0
      && m_soft[8].m_velocity.mVec128.m128_f32[1] <= fsqrt(
                                                       (float)((float)(v24 * v24) + (float)(v19 * v19))
                                                     + (float)(v18 * v18)) )
    {
      v30 = m_soft[8].m_velocity.mVec128.m128_f32[2];
      qmemcpy(&v36, btSoftBody::Impulse::operator-(m_soft, &v38, &v35), sizeof(v36));
      v36.m_velocity.mVec128.m128_f32[0] = v36.m_velocity.mVec128.m128_f32[0] * v30;
      v36.m_velocity.mVec128.m128_f32[1] = v36.m_velocity.mVec128.m128_f32[1] * v30;
      v36.m_velocity.mVec128.m128_f32[2] = v36.m_velocity.mVec128.m128_f32[2] * v30;
      v36.m_drift.mVec128.m128_f32[0] = v36.m_drift.mVec128.m128_f32[0] * v30;
      v36.m_drift.mVec128.m128_f32[1] = v36.m_drift.mVec128.m128_f32[1] * v30;
      v36.m_drift.mVec128.m128_f32[2] = v36.m_drift.mVec128.m128_f32[2] * v30;
      btSoftBody::Body::applyImpulse(&v36, m_rpos, v22);
      m_selfCollisionImpulseFactor = v22->m_soft->m_selfCollisionImpulseFactor;
      qmemcpy(&v36, &v35, sizeof(v36));
      v36.m_velocity.mVec128.m128_f32[0] = m_selfCollisionImpulseFactor * v34.mVec128.m128_f32[0];
      v36.m_velocity.mVec128.m128_f32[1] = v36.m_velocity.mVec128.m128_f32[1] * m_selfCollisionImpulseFactor;
      v36.m_velocity.mVec128.m128_f32[2] = v36.m_velocity.mVec128.m128_f32[2] * m_selfCollisionImpulseFactor;
      v36.m_drift.mVec128.m128_f32[0] = v36.m_drift.mVec128.m128_f32[0] * m_selfCollisionImpulseFactor;
      v36.m_drift.mVec128.m128_f32[1] = v36.m_drift.mVec128.m128_f32[1] * m_selfCollisionImpulseFactor;
      v36.m_drift.mVec128.m128_f32[2] = v36.m_drift.mVec128.m128_f32[2] * m_selfCollisionImpulseFactor;
      btSoftBody::Body::applyImpulse(&v36, v32, v33);
    }
  }
  else
  {
    v26 = btSoftBody::Impulse::operator-(m_soft, &v38, &v35);
    btSoftBody::Body::applyImpulse(v26, m_rpos, m_bodies);
    btSoftBody::Body::applyImpulse(&v35, v32, v33);
  }
}
