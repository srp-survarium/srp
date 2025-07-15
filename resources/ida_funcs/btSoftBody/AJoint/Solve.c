void __thiscall btSoftBody::AJoint::Solve(btSoftBody::AJoint *this, float dt, float sor)
{
  btSoftBody::Body *m_bodies; // edi
  btSoftBody::Body *v5; // ebx
  btSoftBody::Body *v6; // ecx
  float v7; // xmm3_4
  float (__thiscall *Speed)(btSoftBody::AJoint::IControl *, btSoftBody::AJoint *, float); // edx
  float v9; // xmm2_4
  float m_cfm; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm5_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm5_4
  float v20; // xmm4_4
  btSoftBody::Impulse *v21; // esi
  float *m_rigid; // eax
  float *v23; // eax
  float v24; // [esp+240h] [ebp-94h]
  float v25; // [esp+244h] [ebp-90h] BYREF
  float v26; // [esp+248h] [ebp-8Ch]
  btSoftBody::Impulse v27; // [esp+24Ch] [ebp-88h] BYREF
  btVector3 v28; // [esp+284h] [ebp-50h] BYREF
  btVector3 v29; // [esp+294h] [ebp-40h] BYREF
  btSoftBody::Impulse v30; // [esp+2A4h] [ebp-30h] BYREF

  m_bodies = this->m_bodies;
  btSoftBody::Body::angularVelocity((btSoftBody::Body *)this, &v28, (int *)this->m_bodies);
  v5 = &this->m_bodies[1];
  btSoftBody::Body::angularVelocity(v6, &v29, (int *)&this->m_bodies[1]);
  v7 = this->m_axis[0].mVec128.m128_f32[2];
  Speed = this->m_icontrol->Speed;
  v27.m_velocity.mVec128.m128_f32[0] = v28.mVec128.m128_f32[2] - v29.mVec128.m128_f32[2];
  v9 = this->m_axis[0].mVec128.m128_f32[1] * (float)(v28.mVec128.m128_f32[1] - v29.mVec128.m128_f32[1]);
  v26 = v28.mVec128.m128_f32[1] - v29.mVec128.m128_f32[1];
  v24 = (float)((float)(v7 * (float)(v28.mVec128.m128_f32[2] - v29.mVec128.m128_f32[2])) + v9)
      + (float)(this->m_axis[0].mVec128.m128_f32[0] * (float)(v28.mVec128.m128_f32[0] - v29.mVec128.m128_f32[0]));
  v25 = v28.mVec128.m128_f32[0] - v29.mVec128.m128_f32[0];
  v24 = ((double (__stdcall *)(btSoftBody::AJoint *, _DWORD))Speed)(this, LODWORD(v24));
  m_cfm = this->m_cfm;
  v11 = this->m_drift.mVec128.m128_f32[0]
      + (float)(m_cfm * (float)(v25 - (float)(this->m_axis[0].mVec128.m128_f32[0] * v24)));
  v12 = this->m_drift.mVec128.m128_f32[2]
      + (float)(m_cfm * (float)(v27.m_velocity.mVec128.m128_f32[0] - (float)(this->m_axis[0].mVec128.m128_f32[2] * v24)));
  v13 = this->m_drift.mVec128.m128_f32[1]
      + (float)(m_cfm * (float)(v26 - (float)(this->m_axis[0].mVec128.m128_f32[1] * v24)));
  v14 = (float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[2] * v12)
      + (float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[1] * v13);
  v15 = this->m_massmatrix.m_el[0].mVec128.m128_f32[0];
  memset(&v27.m_drift.m_floats[2], 0, 16);
  *((_DWORD *)&v27 + 10) = *((_DWORD *)&v27 + 10) & 0xFFFFFFFC | 1;
  v16 = v14 + (float)(v15 * v11);
  v17 = (float)((float)(this->m_massmatrix.m_el[1].mVec128.m128_f32[2] * v12)
              + (float)(this->m_massmatrix.m_el[1].mVec128.m128_f32[1] * v13))
      + (float)(this->m_massmatrix.m_el[1].mVec128.m128_f32[0] * v11);
  v18 = this->m_massmatrix.m_el[2].mVec128.m128_f32[2] * v12;
  v19 = this->m_massmatrix.m_el[2].mVec128.m128_f32[1] * v13;
  v20 = this->m_massmatrix.m_el[2].mVec128.m128_f32[0] * v11;
  v25 = v16 * sor;
  v26 = v17 * sor;
  v27.m_velocity.mVec128.m128_u64[0] = COERCE_UNSIGNED_INT((float)((float)(v18 + v19) + v20) * sor);
  *(__m128i *)((char *)&v27.m_velocity + 8) = _mm_load_si128((const __m128i *)&v25);
  v21 = btSoftBody::Impulse::operator-((btSoftBody::Impulse *)&v27.m_velocity.m_floats[2], &v30);
  if ( (*((_BYTE *)v21 + 32) & 1) != 0 )
  {
    m_rigid = (float *)m_bodies->m_rigid;
    if ( m_rigid )
      btRigidBody::applyTorqueImpulse((btRigidBody *)v21, m_rigid);
    if ( m_bodies->m_soft )
      btSoftBody::clusterVAImpulse(m_bodies->m_soft, &v21->m_velocity);
  }
  if ( (*((_BYTE *)v21 + 32) & 2) != 0 )
    btSoftBody::Body::applyDAImpulse(m_bodies, (btRigidBody *)&v21->m_drift);
  if ( (*((_BYTE *)&v27 + 40) & 1) != 0 )
  {
    v23 = (float *)v5->m_rigid;
    if ( v23 )
      btRigidBody::applyTorqueImpulse((btRigidBody *)&v27.m_velocity.m_floats[2], v23);
    if ( v5->m_soft )
      btSoftBody::clusterVAImpulse(v5->m_soft, (const btVector3 *)&v27.m_velocity.m_floats[2]);
  }
  if ( (*((_BYTE *)&v27 + 40) & 2) != 0 )
    btSoftBody::Body::applyDAImpulse(v5, (btRigidBody *)&v27.m_drift.m_floats[2]);
}
