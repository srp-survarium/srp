void __thiscall btSoftBody::CJoint::Solve(btSoftBody::CJoint *this, float dt, float sor)
{
  int *m_bodies; // ebx
  btVector3 *v5; // esi
  btSoftBody::Body *v6; // ecx
  btVector3 *v7; // eax
  int v8; // xmm0_4
  btSoftBody::Body *v9; // esi
  btSoftBody::Body *v10; // ecx
  btVector3 *v11; // eax
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float m_friction; // xmm0_4
  int v20; // xmm6_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  int v31; // edi
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  btSoftBody::Impulse *v35; // eax
  btSoftBody::Impulse *v36; // eax
  btSoftBody::Impulse *v37; // eax
  btSoftBody::Impulse *v38; // eax
  btSoftBody::Impulse *_X; // [esp+27Ch] [ebp-F4h]
  float v40; // [esp+280h] [ebp-F0h]
  float v41; // [esp+280h] [ebp-F0h]
  __m128i v42; // [esp+290h] [ebp-E0h] BYREF
  btVector3 *v43; // [esp+2A4h] [ebp-CCh]
  btVector3 *rpos; // [esp+2A8h] [ebp-C8h]
  btVector3 *v45; // [esp+2ACh] [ebp-C4h]
  btSoftBody::Impulse v46; // [esp+2B0h] [ebp-C0h] BYREF
  btVector3 v47; // [esp+2E0h] [ebp-90h] BYREF
  btVector3 v48; // [esp+2F0h] [ebp-80h] BYREF
  btSoftBody::Impulse v49; // [esp+300h] [ebp-70h] BYREF
  btVector3 v50; // [esp+330h] [ebp-40h] BYREF
  btSoftBody::Impulse v51; // [esp+340h] [ebp-30h] BYREF

  m_bodies = (int *)this->m_bodies;
  rpos = this->m_rpos;
  v5 = btSoftBody::Body::angularVelocity(this->m_bodies, this->m_rpos, &v48);
  v7 = btSoftBody::Body::linearVelocity(v6, &v47, m_bodies);
  *(float *)v42.m128i_i32 = v7->mVec128.m128_f32[0] + v5->mVec128.m128_f32[0];
  *(float *)&v42.m128i_i32[1] = v7->mVec128.m128_f32[1] + v5->mVec128.m128_f32[1];
  *(float *)&v8 = v7->mVec128.m128_f32[2] + v5->mVec128.m128_f32[2];
  v9 = &this->m_bodies[1];
  v42.m128i_i32[2] = v8;
  v43 = &this->m_rpos[1];
  v45 = btSoftBody::Body::angularVelocity(&this->m_bodies[1], &this->m_rpos[1], &v47);
  v11 = btSoftBody::Body::linearVelocity(v10, &v50, (int *)&this->m_bodies[1]);
  v12 = *(float *)&v42.m128i_i32[1] - (float)(v45->mVec128.m128_f32[1] + v11->mVec128.m128_f32[1]);
  v13 = *(float *)v42.m128i_i32 - (float)(v45->mVec128.m128_f32[0] + v11->mVec128.m128_f32[0]);
  v14 = *(float *)&v8 - (float)(v45->mVec128.m128_f32[2] + v11->mVec128.m128_f32[2]);
  v15 = (float)((float)(this->m_normal.mVec128.m128_f32[2] * v14) + (float)(this->m_normal.mVec128.m128_f32[1] * v12))
      + (float)(v13 * this->m_normal.mVec128.m128_f32[0]);
  v46.m_velocity.mVec128.m128_u64[0] = this->m_drift.mVec128.m128_u64[0];
  memset(&v46.m_drift, 0, sizeof(v46.m_drift));
  *((_DWORD *)&v46 + 8) = *((_DWORD *)&v46 + 8) & 0xFFFFFFFC | 1;
  v46.m_velocity.mVec128.m128_u64[1] = this->m_drift.mVec128.m128_u64[1];
  if ( v15 >= 0.0 )
  {
    v26 = v46.m_velocity.mVec128.m128_f32[2];
    v25 = v46.m_velocity.mVec128.m128_f32[1];
    v24 = v46.m_velocity.mVec128.m128_f32[0];
  }
  else
  {
    v16 = this->m_normal.mVec128.m128_f32[0] * v15;
    v17 = this->m_normal.mVec128.m128_f32[1] * v15;
    v18 = this->m_normal.mVec128.m128_f32[2] * v15;
    m_friction = this->m_friction;
    *(float *)v42.m128i_i32 = v13 - v16;
    *(float *)&v42.m128i_i32[1] = v12 - v17;
    *(float *)&v20 = v14 - v18;
    v21 = (float)((float)(m_friction * (float)(v13 - v16)) + v16) + v46.m_velocity.mVec128.m128_f32[0];
    v22 = (float)((float)(m_friction * (float)(v12 - v17)) + v17) + v46.m_velocity.mVec128.m128_f32[1];
    v23 = (float)((float)(m_friction * *(float *)&v20) + v18) + v46.m_velocity.mVec128.m128_f32[2];
    v42.m128i_i32[2] = v20;
    v24 = v21;
    v25 = v22;
    v26 = v23;
  }
  v27 = (float)((float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[2] * v26)
              + (float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[1] * v25))
      + (float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[0] * v24);
  v28 = (float)((float)(this->m_massmatrix.m_el[1].mVec128.m128_f32[2] * v26)
              + (float)(this->m_massmatrix.m_el[1].mVec128.m128_f32[1] * v25))
      + (float)(this->m_massmatrix.m_el[1].mVec128.m128_f32[0] * v24);
  v29 = (float)(this->m_massmatrix.m_el[2].mVec128.m128_f32[2] * v26)
      + (float)(this->m_massmatrix.m_el[2].mVec128.m128_f32[1] * v25);
  v30 = this->m_massmatrix.m_el[2].mVec128.m128_f32[0];
  v31 = *m_bodies;
  v32 = v27 * sor;
  v33 = v28 * sor;
  v34 = (float)(v29 + (float)(v30 * v24)) * sor;
  v42.m128i_i64[0] = __PAIR64__(LODWORD(v33), LODWORD(v32));
  v42.m128i_i64[1] = LODWORD(v34);
  v46.m_velocity = (btVector3)_mm_load_si128(&v42);
  if ( (btSoftBody::Cluster *)v31 == v9->m_soft )
  {
    if ( (*((_BYTE *)&v46 + 32) & 1) != 0
      && *(float *)(v31 + 388) <= sqrtf((float)((float)(v34 * v34) + (float)(v33 * v33)) + (float)(v32 * v32)) )
    {
      _X = *(btSoftBody::Impulse **)(v31 + 392);
      v35 = btSoftBody::Impulse::operator-(&v46, &v51);
      v36 = btSoftBody::Impulse::operator*(v35, &v49, _X, v40);
      btSoftBody::Body::applyImpulse(v36, rpos, (btSoftBody::Body *)m_bodies);
      v37 = btSoftBody::Impulse::operator*(&v46, &v49, COERCE_BTSOFTBODY_IMPULSE_(*(float *)(*m_bodies + 392)), v41);
      btSoftBody::Body::applyImpulse(v37, v43, v9);
    }
  }
  else
  {
    v38 = btSoftBody::Impulse::operator-(&v46, &v49);
    btSoftBody::Body::applyImpulse(v38, rpos, (btSoftBody::Body *)m_bodies);
    btSoftBody::Body::applyImpulse(&v46, v43, v9);
  }
}
