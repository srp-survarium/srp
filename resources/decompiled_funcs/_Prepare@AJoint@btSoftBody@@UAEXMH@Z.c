void __thiscall btSoftBody::AJoint::Prepare(btSoftBody::AJoint *this, float dt, int iterations)
{
  btSoftBody::Body *v4; // ecx
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
  float v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  unsigned int v31; // xmm0_4
  btVector3 *v32; // eax
  const vostok::math::float4x4 *v33; // xmm2_4
  float v34; // xmm0_4
  long double v35; // st7
  float *p_v; // eax
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  const btMatrix3x3 *v40; // esi
  const btMatrix3x3 *v41; // eax
  float m_split; // xmm4_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm6_4
  float v47; // xmm3_4
  float v48; // xmm2_4
  float v49; // xmm1_4
  unsigned int v50; // xmm3_4
  const vostok::math::float4x4 *v51; // xmm1_4
  float v52; // xmm1_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v; // [esp+14h] [ebp-54h] BYREF
  btVector3 v_4; // [esp+18h] [ebp-50h] BYREF
  btVector3 v57; // [esp+28h] [ebp-40h] BYREF
  _BYTE v58[48]; // [esp+38h] [ebp-30h] BYREF

  this->m_icontrol->Prepare(this->m_icontrol, this);
  btSoftBody::Body::activate(v4, (int)this->m_bodies);
  btSoftBody::Body::activate(v5, (int)&this->m_bodies[1]);
  v7 = (float *)btSoftBody::Body::xform(v6, &this->m_bodies[0].m_soft);
  v8 = this->m_refs[0].mVec128.m128_f32[1];
  v9 = this->m_refs[0].mVec128.m128_f32[2];
  v10 = this->m_refs[0].mVec128.m128_f32[0];
  v11 = v7[6];
  v_4.mVec128.m128_f32[0] = (float)((float)(v7[1] * v8) + (float)(v7[2] * v9)) + (float)(v10 * *v7);
  v12 = (float)(v7[5] * v8) + (float)(v11 * v9);
  v13 = v10 * v7[4];
  v14 = v10 * v7[8];
  v_4.mVec128.m128_f32[1] = v12 + v13;
  v15 = (float)((float)(v7[9] * v8) + (float)(v7[10] * v9)) + v14;
  v_4.mVec128.m128_i32[3] = 0;
  this->m_axis[0].mVec128.m128_u64[0] = v_4.mVec128.m128_u64[0];
  v_4.mVec128.m128_f32[2] = v15;
  this->m_axis[0].mVec128.m128_u64[1] = v_4.mVec128.m128_u64[1];
  v17 = (float *)btSoftBody::Body::xform(v16, &this->m_bodies[1].m_soft);
  v18 = this->m_refs[1].mVec128.m128_f32[1];
  v19 = this->m_refs[1].mVec128.m128_f32[2];
  v20 = this->m_refs[1].mVec128.m128_f32[0];
  v21 = v17[6];
  v_4.mVec128.m128_f32[0] = (float)((float)(v17[1] * v18) + (float)(v17[2] * v19)) + (float)(v20 * *v17);
  v22 = (float)(v17[5] * v18) + (float)(v21 * v19);
  v23 = v20 * v17[4];
  v24 = v20 * v17[8];
  v_4.mVec128.m128_f32[1] = v22 + v23;
  *(float *)&v25 = (float)((float)(v17[9] * v18) + (float)(v17[10] * v19)) + v24;
  this->m_axis[1].mVec128.m128_u64[0] = v_4.mVec128.m128_u64[0];
  v_4.mVec128.m128_u64[1] = v25;
  this->m_axis[1].mVec128.m128_u64[1] = v25;
  v26 = this->m_axis[0].mVec128.m128_f32[2];
  v27 = this->m_axis[1].mVec128.m128_f32[2];
  v28 = this->m_axis[0].mVec128.m128_f32[1];
  v29 = this->m_axis[1].mVec128.m128_f32[1];
  v30 = this->m_axis[0].mVec128.m128_f32[0];
  v_4.mVec128.m128_f32[0] = (float)(v26 * v29) - (float)(v28 * v27);
  *(float *)&v31 = (float)(this->m_axis[1].mVec128.m128_f32[0] * v28) - (float)(v30 * v29);
  v_4.mVec128.m128_f32[1] = (float)(v30 * v27) - (float)(this->m_axis[1].mVec128.m128_f32[0] * v26);
  v_4.mVec128.m128_u64[1] = v31;
  v32 = NormalizeAny(&v_4, &v57);
  v33 = clear_value;
  this->m_drift = (btVector3)v32->mVec128;
  v34 = (float)((float)(this->m_axis[0].mVec128.m128_f32[2] * this->m_axis[1].mVec128.m128_f32[2])
              + (float)(this->m_axis[0].mVec128.m128_f32[1] * this->m_axis[1].mVec128.m128_f32[1]))
      + (float)(this->m_axis[1].mVec128.m128_f32[0] * this->m_axis[0].mVec128.m128_f32[0]);
  if ( v34 < -1.0 )
  {
    v = -1.0;
    goto LABEL_8;
  }
  if ( v34 > *(float *)&v33 )
    goto LABEL_7;
  v = (float)((float)(this->m_axis[0].mVec128.m128_f32[2] * this->m_axis[1].mVec128.m128_f32[2])
            + (float)(this->m_axis[0].mVec128.m128_f32[1] * this->m_axis[1].mVec128.m128_f32[1]))
    + (float)(this->m_axis[1].mVec128.m128_f32[0] * this->m_axis[0].mVec128.m128_f32[0]);
  if ( v34 < -1.0 )
  {
    v = -1.0;
    goto LABEL_8;
  }
  if ( v34 > *(float *)&v33 )
LABEL_7:
    v = *(float *)&v33;
LABEL_8:
  v35 = acosf(v);
  v = v35;
  p_v = (float *)&maxdrift;
  if ( v35 <= 0.19634955 )
    p_v = &v;
  this->m_drift.mVec128.m128_f32[0] = *p_v * this->m_drift.mVec128.m128_f32[0];
  this->m_drift.mVec128.m128_f32[1] = *p_v * this->m_drift.mVec128.m128_f32[1];
  this->m_drift.mVec128.m128_f32[2] = *p_v * this->m_drift.mVec128.m128_f32[2];
  v37 = this->m_erp / dt;
  this->m_drift.mVec128.m128_f32[0] = this->m_drift.mVec128.m128_f32[0] * v37;
  v38 = v37 * this->m_drift.mVec128.m128_f32[1];
  v39 = v37 * this->m_drift.mVec128.m128_f32[2];
  this->m_drift.mVec128.m128_f32[1] = v38;
  this->m_drift.mVec128.m128_f32[2] = v39;
  v40 = btSoftBody::Body::invWorldInertia(&this->m_bodies[1]);
  v41 = btSoftBody::Body::invWorldInertia(this->m_bodies);
  this->m_massmatrix = *AngularImpulseMatrix(v41, v40, (int)v58);
  m_split = this->m_split;
  if ( m_split <= 0.0 )
  {
    v51 = clear_value;
  }
  else
  {
    v43 = this->m_drift.mVec128.m128_f32[2] * m_split;
    v44 = this->m_drift.mVec128.m128_f32[1] * m_split;
    v45 = m_split * this->m_drift.mVec128.m128_f32[0];
    v46 = this->m_massmatrix.m_el[1].mVec128.m128_f32[1];
    v_4.mVec128.m128_f32[0] = (float)((float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[2] * v43)
                                    + (float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[1] * v44))
                            + (float)(v45 * this->m_massmatrix.m_el[0].mVec128.m128_f32[0]);
    v_4.mVec128.m128_f32[1] = (float)((float)(this->m_massmatrix.m_el[1].mVec128.m128_f32[2] * v43) + (float)(v46 * v44))
                            + (float)(v45 * this->m_massmatrix.m_el[1].mVec128.m128_f32[0]);
    v47 = this->m_massmatrix.m_el[2].mVec128.m128_f32[2] * v43;
    v48 = this->m_massmatrix.m_el[2].mVec128.m128_f32[1] * v44;
    v49 = this->m_massmatrix.m_el[2].mVec128.m128_f32[0] * v45;
    this->m_sdrift.mVec128.m128_u64[0] = v_4.mVec128.m128_u64[0];
    *(float *)&v50 = (float)(v47 + v48) + v49;
    v51 = clear_value;
    v_4.mVec128.m128_u64[1] = v50;
    this->m_sdrift.mVec128.m128_u64[1] = v50;
    this->m_drift.mVec128.m128_f32[0] = this->m_drift.mVec128.m128_f32[0] * (float)(*(float *)&v51 - m_split);
    this->m_drift.mVec128.m128_f32[1] = this->m_drift.mVec128.m128_f32[1] * (float)(*(float *)&v51 - m_split);
    this->m_drift.mVec128.m128_f32[2] = this->m_drift.mVec128.m128_f32[2] * (float)(*(float *)&v51 - m_split);
  }
  v52 = *(float *)&v51 / (float)iterations;
  this->m_drift.mVec128.m128_f32[0] = v52 * this->m_drift.mVec128.m128_f32[0];
  v53 = v52 * this->m_drift.mVec128.m128_f32[1];
  v54 = v52 * this->m_drift.mVec128.m128_f32[2];
  this->m_drift.mVec128.m128_f32[1] = v53;
  this->m_drift.mVec128.m128_f32[2] = v54;
}
