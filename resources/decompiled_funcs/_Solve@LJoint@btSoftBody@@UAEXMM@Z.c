void __thiscall btSoftBody::LJoint::Solve(btSoftBody::LJoint *this, float dt, float sor)
{
  int *m_bodies; // ebx
  btVector3 *v5; // esi
  btSoftBody::Body *v6; // ecx
  btVector3 *v7; // eax
  btSoftBody::Body *v8; // ecx
  btVector3 *v9; // eax
  float v10; // xmm6_4
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  unsigned int v17; // xmm2_4
  btSoftBody::Impulse *v18; // eax
  __m128i v19; // [esp+150h] [ebp-B0h] BYREF
  btVector3 *v20; // [esp+164h] [ebp-9Ch]
  btVector3 *rpos; // [esp+168h] [ebp-98h]
  btVector3 *v22; // [esp+16Ch] [ebp-94h]
  btSoftBody::Impulse v23; // [esp+170h] [ebp-90h] BYREF
  btVector3 v24; // [esp+1A0h] [ebp-60h] BYREF
  btVector3 v25; // [esp+1B0h] [ebp-50h] BYREF
  btVector3 v26; // [esp+1C0h] [ebp-40h] BYREF
  btSoftBody::Impulse v27; // [esp+1D0h] [ebp-30h] BYREF

  m_bodies = (int *)this->m_bodies;
  rpos = this->m_rpos;
  v5 = btSoftBody::Body::angularVelocity(this->m_bodies, this->m_rpos, &v25);
  v7 = btSoftBody::Body::linearVelocity(v6, &v24, m_bodies);
  *(float *)v19.m128i_i32 = v7->mVec128.m128_f32[0] + v5->mVec128.m128_f32[0];
  *(float *)&v19.m128i_i32[1] = v7->mVec128.m128_f32[1] + v5->mVec128.m128_f32[1];
  *(float *)&v19.m128i_i32[2] = v7->mVec128.m128_f32[2] + v5->mVec128.m128_f32[2];
  v20 = &this->m_rpos[1];
  v22 = btSoftBody::Body::angularVelocity(&this->m_bodies[1], &this->m_rpos[1], &v24);
  v9 = btSoftBody::Body::linearVelocity(v8, &v26, (int *)&this->m_bodies[1]);
  v10 = (float)(this->m_cfm
              * (float)(*(float *)v19.m128i_i32 - (float)(v22->mVec128.m128_f32[0] + v9->mVec128.m128_f32[0])))
      + this->m_drift.mVec128.m128_f32[0];
  v11 = this->m_drift.mVec128.m128_f32[2]
      + (float)(this->m_cfm
              * (float)(*(float *)&v19.m128i_i32[2] - (float)(v22->mVec128.m128_f32[2] + v9->mVec128.m128_f32[2])));
  v12 = this->m_drift.mVec128.m128_f32[1]
      + (float)(this->m_cfm
              * (float)(*(float *)&v19.m128i_i32[1] - (float)(v22->mVec128.m128_f32[1] + v9->mVec128.m128_f32[1])));
  v13 = (float)((float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[2] * v11)
              + (float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[1] * v12))
      + (float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[0] * v10);
  v14 = this->m_massmatrix.m_el[1].mVec128.m128_f32[2];
  v15 = this->m_massmatrix.m_el[1].mVec128.m128_f32[1] * v12;
  memset(&v23.m_drift, 0, sizeof(v23.m_drift));
  *((_DWORD *)&v23 + 8) = *((_DWORD *)&v23 + 8) & 0xFFFFFFFC | 1;
  v16 = (float)((float)(v14 * v11) + v15) + (float)(v10 * this->m_massmatrix.m_el[1].mVec128.m128_f32[0]);
  *(float *)&v17 = (float)((float)((float)(this->m_massmatrix.m_el[2].mVec128.m128_f32[2] * v11)
                                 + (float)(this->m_massmatrix.m_el[2].mVec128.m128_f32[1] * v12))
                         + (float)(this->m_massmatrix.m_el[2].mVec128.m128_f32[0] * v10))
                 * sor;
  *(float *)v19.m128i_i32 = v13 * sor;
  *(float *)&v19.m128i_i32[1] = v16 * sor;
  v19.m128i_i64[1] = v17;
  v23.m_velocity = (btVector3)_mm_load_si128(&v19);
  v18 = btSoftBody::Impulse::operator-(&v23, &v27);
  btSoftBody::Body::applyImpulse(v18, rpos, (btSoftBody::Body *)m_bodies);
  btSoftBody::Body::applyImpulse(&v23, v20, &this->m_bodies[1]);
}
