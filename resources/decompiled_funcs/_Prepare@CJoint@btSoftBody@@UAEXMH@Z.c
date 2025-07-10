void __thiscall btSoftBody::CJoint::Prepare(btSoftBody::CJoint *this, float dt, int iterations)
{
  btSoftBody::Body *v4; // ecx
  int m_life; // eax
  bool v6; // cl
  bool v7; // zf
  bool v8; // sf
  bool v9; // of
  float m_erp; // xmm3_4
  const vostok::math::float4x4 *v11; // xmm6_4
  float m_split; // xmm5_4
  unsigned int v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  unsigned int v17; // xmm3_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm6_4
  unsigned __int64 v21; // [esp+10h] [ebp-10h]
  unsigned __int64 v22; // [esp+10h] [ebp-10h]

  btSoftBody::Body::activate((btSoftBody::Body *)this, (int)this->m_bodies);
  btSoftBody::Body::activate(v4, (int)&this->m_bodies[1]);
  m_life = this->m_life;
  v6 = m_life++ == 0;
  v9 = __OFSUB__(m_life, this->m_maxlife);
  v7 = m_life == this->m_maxlife;
  v8 = m_life - this->m_maxlife < 0;
  this->m_life = m_life;
  this->m_delete = !(v8 ^ v9 | v7);
  if ( v6 )
  {
    m_erp = this->m_erp;
    v11 = clear_value;
    m_split = this->m_split;
    *(float *)&v21 = (float)(this->m_drift.mVec128.m128_f32[0] * m_erp) * (float)(*(float *)&clear_value / dt);
    *((float *)&v21 + 1) = (float)(this->m_drift.mVec128.m128_f32[1] * m_erp) * (float)(*(float *)&clear_value / dt);
    *(float *)&v13 = (float)(this->m_drift.mVec128.m128_f32[2] * m_erp) * (float)(*(float *)&clear_value / dt);
    this->m_drift.mVec128.m128_u64[0] = v21;
    this->m_drift.mVec128.m128_u64[1] = v13;
    if ( m_split > 0.0 )
    {
      v14 = this->m_drift.mVec128.m128_f32[1] * m_split;
      v15 = this->m_drift.mVec128.m128_f32[0] * m_split;
      v16 = this->m_drift.mVec128.m128_f32[2] * m_split;
      *(float *)&v22 = (float)((float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[2] * v16)
                             + (float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[1] * v14))
                     + (float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[0] * v15);
      *((float *)&v22 + 1) = (float)((float)(this->m_massmatrix.m_el[1].mVec128.m128_f32[2] * v16)
                                   + (float)(this->m_massmatrix.m_el[1].mVec128.m128_f32[1] * v14))
                           + (float)(v15 * this->m_massmatrix.m_el[1].mVec128.m128_f32[0]);
      *(float *)&v17 = (float)((float)(this->m_massmatrix.m_el[2].mVec128.m128_f32[2] * v16)
                             + (float)(this->m_massmatrix.m_el[2].mVec128.m128_f32[1] * v14))
                     + (float)(v15 * this->m_massmatrix.m_el[2].mVec128.m128_f32[0]);
      this->m_sdrift.mVec128.m128_u64[0] = v22;
      this->m_sdrift.mVec128.m128_u64[1] = v17;
      this->m_drift.mVec128.m128_f32[0] = (float)(*(float *)&v11 - m_split) * this->m_drift.mVec128.m128_f32[0];
      this->m_drift.mVec128.m128_f32[1] = this->m_drift.mVec128.m128_f32[1] * (float)(*(float *)&v11 - m_split);
      this->m_drift.mVec128.m128_f32[2] = this->m_drift.mVec128.m128_f32[2] * (float)(*(float *)&v11 - m_split);
    }
    v18 = *(float *)&v11 / (float)iterations;
    this->m_drift.mVec128.m128_f32[0] = this->m_drift.mVec128.m128_f32[0] * v18;
    v19 = v18 * this->m_drift.mVec128.m128_f32[1];
    v20 = v18 * this->m_drift.mVec128.m128_f32[2];
    this->m_drift.mVec128.m128_f32[1] = v19;
    this->m_drift.mVec128.m128_f32[2] = v20;
  }
  else
  {
    this->m_sdrift.mVec128.m128_u64[0] = 0;
    this->m_drift.mVec128.m128_u64[0] = 0;
    this->m_sdrift.mVec128.m128_u64[1] = 0;
    this->m_drift.mVec128.m128_u64[1] = 0;
  }
}
