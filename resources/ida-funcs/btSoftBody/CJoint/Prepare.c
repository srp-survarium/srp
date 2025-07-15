void __thiscall btSoftBody::CJoint::Prepare(btSoftBody::CJoint *this, float dt, int iterations)
{
  int m_life; // esi
  bool v5; // zf
  bool v6; // sf
  bool v7; // of
  float m_erp; // xmm3_4
  float v9; // xmm4_4
  float m_split; // xmm5_4
  btVector3 *p_m_drift; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // [esp+1Ch] [ebp-Ch]
  float v18; // [esp+1Ch] [ebp-Ch]
  float v19; // [esp+20h] [ebp-8h]
  float v20; // [esp+20h] [ebp-8h]

  btSoftBody::Joint::Prepare(this, dt, iterations);
  m_life = this->m_life;
  v7 = __OFSUB__(m_life + 1, this->m_maxlife);
  v5 = m_life + 1 == this->m_maxlife;
  v6 = m_life + 1 - this->m_maxlife < 0;
  this->m_life = m_life + 1;
  this->m_delete = !(v6 ^ v7 | v5);
  if ( m_life )
  {
    this->m_sdrift.mVec128.m128_i32[0] = 0;
    this->m_sdrift.mVec128.m128_i32[1] = 0;
    this->m_sdrift.mVec128.m128_i32[2] = 0;
    this->m_sdrift.mVec128.m128_i32[3] = 0;
    this->m_drift.mVec128.m128_i32[0] = 0;
    this->m_drift.mVec128.m128_i32[1] = 0;
    this->m_drift.mVec128.m128_i32[2] = 0;
    this->m_drift.mVec128.m128_i32[3] = 0;
  }
  else
  {
    m_erp = this->m_erp;
    v9 = s_bm_current_air_resistance;
    m_split = this->m_split;
    p_m_drift = &this->m_drift;
    v17 = (float)(this->m_drift.mVec128.m128_f32[1] * m_erp) * (float)(s_bm_current_air_resistance / dt);
    v19 = (float)(this->m_drift.mVec128.m128_f32[2] * m_erp) * (float)(s_bm_current_air_resistance / dt);
    this->m_drift.mVec128.m128_f32[0] = (float)(m_erp * this->m_drift.mVec128.m128_f32[0])
                                      * (float)(s_bm_current_air_resistance / dt);
    this->m_drift.mVec128.m128_f32[1] = v17;
    this->m_drift.mVec128.m128_f32[2] = v19;
    this->m_drift.mVec128.m128_i32[3] = 0;
    if ( m_split > 0.0 )
    {
      v12 = p_m_drift->mVec128.m128_f32[0] * m_split;
      v13 = this->m_drift.mVec128.m128_f32[1] * m_split;
      v14 = this->m_drift.mVec128.m128_f32[2] * m_split;
      v18 = (float)((float)(this->m_massmatrix.m_el[1].mVec128.m128_f32[2] * v14)
                  + (float)(this->m_massmatrix.m_el[1].mVec128.m128_f32[1] * v13))
          + (float)(v12 * this->m_massmatrix.m_el[1].mVec128.m128_f32[0]);
      v20 = (float)((float)(this->m_massmatrix.m_el[2].mVec128.m128_f32[2] * v14)
                  + (float)(this->m_massmatrix.m_el[2].mVec128.m128_f32[1] * v13))
          + (float)(this->m_massmatrix.m_el[2].mVec128.m128_f32[0] * v12);
      this->m_sdrift.mVec128.m128_f32[0] = (float)((float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[2] * v14)
                                                 + (float)(this->m_massmatrix.m_el[0].mVec128.m128_f32[1] * v13))
                                         + (float)(v12 * this->m_massmatrix.m_el[0].mVec128.m128_f32[0]);
      this->m_sdrift.mVec128.m128_f32[1] = v18;
      this->m_sdrift.mVec128.m128_f32[2] = v20;
      this->m_sdrift.mVec128.m128_i32[3] = 0;
      p_m_drift->mVec128.m128_f32[0] = p_m_drift->mVec128.m128_f32[0] * (float)(v9 - m_split);
      v15 = (float)(v9 - m_split) * this->m_drift.mVec128.m128_f32[2];
      this->m_drift.mVec128.m128_f32[1] = (float)(v9 - m_split) * this->m_drift.mVec128.m128_f32[1];
      this->m_drift.mVec128.m128_f32[2] = v15;
    }
    v16 = v9 / (float)iterations;
    p_m_drift->mVec128.m128_f32[0] = p_m_drift->mVec128.m128_f32[0] * v16;
    this->m_drift.mVec128.m128_f32[1] = this->m_drift.mVec128.m128_f32[1] * v16;
    this->m_drift.mVec128.m128_f32[2] = this->m_drift.mVec128.m128_f32[2] * v16;
  }
}
