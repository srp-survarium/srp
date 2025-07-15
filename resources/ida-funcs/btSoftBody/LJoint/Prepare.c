void __thiscall btSoftBody::LJoint::Prepare(btSoftBody::LJoint *this, float dt, int iterations)
{
  btSoftBody::Body *m_bodies; // esi
  btSoftBody::Body *v5; // ecx
  btSoftBody::Body *v6; // ecx
  float *v7; // eax
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  btSoftBody::Body *v16; // ecx
  float *v17; // eax
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm4_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm0_4
  unsigned int v25; // xmm3_4
  btVector3 *v26; // eax
  float m_erp; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm2_4
  btSoftBody::Body *v31; // ecx
  const btTransform *v32; // eax
  float v33; // xmm0_4
  btSoftBody::Body *v34; // ecx
  const btTransform *v35; // eax
  float v36; // xmm0_4
  btSoftBody::Body *v37; // ecx
  btRigidBody *m_rigid; // eax
  float m_inverseMass; // xmm0_4
  btRigidBody *v40; // eax
  unsigned int ima; // xmm0_4
  btSoftBody::Cluster *m_soft; // eax
  const btMatrix3x3 *v43; // eax
  float m_split; // xmm4_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  float v47; // xmm0_4
  float v48; // xmm6_4
  float v49; // xmm3_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  unsigned int v52; // xmm3_4
  const vostok::math::float4x4 *v53; // xmm1_4
  float v54; // xmm1_4
  btMatrix3x3 *iib; // [esp+28h] [ebp-58h]
  btVector3 v; // [esp+30h] [ebp-50h] BYREF
  btVector3 v57; // [esp+40h] [ebp-40h] BYREF
  _BYTE v58[48]; // [esp+50h] [ebp-30h] BYREF

  m_bodies = this->m_bodies;
  btSoftBody::Body::activate((btSoftBody::Body *)this, (int)this->m_bodies);
  btSoftBody::Body::activate(v5, (int)&this->m_bodies[1]);
  v7 = (float *)btSoftBody::Body::xform(v6, m_bodies);
  v8 = this->m_refs[0].mVec128.m128_f32[1];
  v9 = this->m_refs[0].mVec128.m128_f32[2];
  v10 = this->m_refs[0].mVec128.m128_f32[0];
  v11 = v7[6];
  v.mVec128.m128_f32[0] = (float)((float)((float)(v7[1] * v8) + (float)(v7[2] * v9)) + (float)(v10 * *v7)) + v7[12];
  v12 = (float)(v7[5] * v8) + (float)(v11 * v9);
  v13 = v10 * v7[4];
  v14 = v10 * v7[8];
  v.mVec128.m128_f32[1] = (float)(v12 + v13) + v7[13];
  v15 = (float)((float)((float)(v7[9] * v8) + (float)(v7[10] * v9)) + v14) + v7[14];
  v.mVec128.m128_i32[3] = 0;
  this->m_rpos[0].mVec128.m128_u64[0] = v.mVec128.m128_u64[0];
  v.mVec128.m128_f32[2] = v15;
  this->m_rpos[0].mVec128.m128_u64[1] = v.mVec128.m128_u64[1];
  v17 = (float *)btSoftBody::Body::xform(v16, &this->m_bodies[1].m_soft);
  v18 = this->m_refs[1].mVec128.m128_f32[1];
  v19 = this->m_refs[1].mVec128.m128_f32[2];
  v20 = this->m_refs[1].mVec128.m128_f32[0];
  v21 = v17[6];
  v.mVec128.m128_f32[0] = (float)((float)((float)(v17[1] * v18) + (float)(v17[2] * v19)) + (float)(v20 * *v17))
                        + v17[12];
  v22 = (float)(v17[5] * v18) + (float)(v21 * v19);
  v23 = v20 * v17[4];
  v24 = v20 * v17[8];
  v.mVec128.m128_f32[1] = (float)(v22 + v23) + v17[13];
  *(float *)&v25 = (float)((float)((float)(v17[9] * v18) + (float)(v17[10] * v19)) + v24) + v17[14];
  this->m_rpos[1].mVec128.m128_u64[0] = v.mVec128.m128_u64[0];
  v.mVec128.m128_u64[1] = v25;
  this->m_rpos[1].mVec128.m128_u64[1] = v25;
  v.mVec128.m128_f32[0] = this->m_rpos[0].mVec128.m128_f32[0] - this->m_rpos[1].mVec128.m128_f32[0];
  v.mVec128.m128_f32[1] = this->m_rpos[0].mVec128.m128_f32[1] - this->m_rpos[1].mVec128.m128_f32[1];
  v.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(this->m_rpos[0].mVec128.m128_f32[2] - this->m_rpos[1].mVec128.m128_f32[2]);
  v26 = Clamp(&v, &v57);
  m_erp = this->m_erp;
  v28 = v26->mVec128.m128_f32[1] * m_erp;
  v29 = v26->mVec128.m128_f32[2] * m_erp;
  v.mVec128.m128_f32[0] = (float)(m_erp * v26->mVec128.m128_f32[0]) * (float)(*(float *)&clear_value / dt);
  v.mVec128.m128_i32[3] = 0;
  v.mVec128.m128_f32[1] = v28 * (float)(*(float *)&clear_value / dt);
  v30 = v29 * (float)(*(float *)&clear_value / dt);
  this->m_drift.mVec128.m128_u64[0] = v.mVec128.m128_u64[0];
  v.mVec128.m128_f32[2] = v30;
  this->m_drift.mVec128.m128_u64[1] = v.mVec128.m128_u64[1];
  v32 = btSoftBody::Body::xform(v31, &this->m_bodies[0].m_soft);
  v33 = this->m_rpos[0].mVec128.m128_f32[0] - v32->m_origin.mVec128.m128_f32[0];
  v32 = (const btTransform *)((char *)v32 + 48);
  this->m_rpos[0].mVec128.m128_f32[0] = v33;
  this->m_rpos[0].mVec128.m128_f32[1] = this->m_rpos[0].mVec128.m128_f32[1] - v32->m_basis.m_el[0].mVec128.m128_f32[1];
  this->m_rpos[0].mVec128.m128_f32[2] = this->m_rpos[0].mVec128.m128_f32[2] - v32->m_basis.m_el[0].mVec128.m128_f32[2];
  v35 = btSoftBody::Body::xform(v34, &this->m_bodies[1].m_soft);
  v36 = this->m_rpos[1].mVec128.m128_f32[0] - v35->m_origin.mVec128.m128_f32[0];
  v35 = (const btTransform *)((char *)v35 + 48);
  this->m_rpos[1].mVec128.m128_f32[0] = v36;
  this->m_rpos[1].mVec128.m128_f32[1] = this->m_rpos[1].mVec128.m128_f32[1] - v35->m_basis.m_el[0].mVec128.m128_f32[1];
  v37 = &this->m_bodies[1];
  this->m_rpos[1].mVec128.m128_f32[2] = this->m_rpos[1].mVec128.m128_f32[2] - v35->m_basis.m_el[0].mVec128.m128_f32[2];
  m_rigid = this->m_bodies[1].m_rigid;
  if ( m_rigid )
  {
    m_inverseMass = m_rigid->m_inverseMass;
  }
  else if ( v37->m_soft )
  {
    m_inverseMass = v37->m_soft->m_imass;
  }
  else
  {
    m_inverseMass = 0.0;
  }
  v40 = this->m_bodies[0].m_rigid;
  iib = (btMatrix3x3 *)LODWORD(m_inverseMass);
  if ( v40 )
  {
    ima = LODWORD(v40->m_inverseMass);
  }
  else
  {
    m_soft = this->m_bodies[0].m_soft;
    if ( m_soft )
      ima = LODWORD(m_soft->m_imass);
    else
      ima = 0;
  }
  btSoftBody::Body::invWorldInertia(v37);
  v43 = btSoftBody::Body::invWorldInertia(this->m_bodies);
  this->m_massmatrix = *ImpulseMatrix(&this->m_rpos[1], (int)v58, ima, v43, this->m_rpos, (unsigned int)iib);
  m_split = this->m_split;
  if ( m_split <= 0.0 )
  {
    v53 = clear_value;
  }
  else
  {
    v45 = this->m_drift.mVec128.m128_f32[2] * m_split;
    v46 = this->m_drift.mVec128.m128_f32[1] * m_split;
    v47 = m_split * this->m_drift.mVec128.m128_f32[0];
    v48 = this->m_massmatrix.m_el[1].mVec128.m128_f32[1];
    v.mVec128.m128_f32[0] = (float)((float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[2] * v45)
                                  + (float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[1] * v46))
                          + (float)(v47 * this->m_massmatrix.m_el[0].mVec128.m128_f32[0]);
    v.mVec128.m128_f32[1] = (float)((float)(this->m_massmatrix.m_el[1].mVec128.m128_f32[2] * v45) + (float)(v48 * v46))
                          + (float)(this->m_massmatrix.m_el[1].mVec128.m128_f32[0] * v47);
    v49 = this->m_massmatrix.m_el[2].mVec128.m128_f32[2] * v45;
    v50 = this->m_massmatrix.m_el[2].mVec128.m128_f32[1] * v46;
    v51 = this->m_massmatrix.m_el[2].mVec128.m128_f32[0] * v47;
    this->m_sdrift.mVec128.m128_u64[0] = v.mVec128.m128_u64[0];
    *(float *)&v52 = (float)(v49 + v50) + v51;
    v53 = clear_value;
    v.mVec128.m128_u64[1] = v52;
    this->m_sdrift.mVec128.m128_u64[1] = v52;
    this->m_drift.mVec128.m128_f32[0] = this->m_drift.mVec128.m128_f32[0] * (float)(*(float *)&v53 - m_split);
    this->m_drift.mVec128.m128_f32[1] = this->m_drift.mVec128.m128_f32[1] * (float)(*(float *)&v53 - m_split);
    this->m_drift.mVec128.m128_f32[2] = this->m_drift.mVec128.m128_f32[2] * (float)(*(float *)&v53 - m_split);
  }
  v54 = *(float *)&v53 / (float)iterations;
  this->m_drift.mVec128.m128_f32[0] = v54 * this->m_drift.mVec128.m128_f32[0];
  this->m_drift.mVec128.m128_f32[1] = this->m_drift.mVec128.m128_f32[1] * v54;
  this->m_drift.mVec128.m128_f32[2] = this->m_drift.mVec128.m128_f32[2] * v54;
}
