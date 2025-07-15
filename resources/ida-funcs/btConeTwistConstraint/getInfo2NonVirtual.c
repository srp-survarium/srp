void __userpurge btConeTwistConstraint::getInfo2NonVirtual(
        btConeTwistConstraint *this@<esi>,
        btTypedConstraint::btConstraintInfo2 *info@<edi>,
        const btMatrix3x3 *invInertiaWorldA@<ecx>,
        const btMatrix3x3 *invInertiaWorldB@<eax>,
        const btTransform *transA,
        const btTransform *transB)
{
  const vostok::math::float4x4 *v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float *m_J1angularAxis; // eax
  int rowskip; // ecx
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm6_4
  float v17; // xmm5_4
  float v18; // xmm7_4
  float *m_J2angularAxis; // eax
  int v20; // ecx
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm7_4
  float v25; // xmm5_4
  float m_linERP; // xmm7_4
  float v27; // xmm6_4
  int v28; // eax
  float *v29; // ecx
  float m_fixThresh; // xmm4_4
  float *v31; // edx
  float v32; // xmm4_4
  float v33; // xmm2_4
  float v34; // xmm7_4
  int v35; // ecx
  float v36; // xmm3_4
  float v37; // xmm4_4
  float v38; // xmm5_4
  float v39; // xmm2_4
  float v40; // xmm4_4
  int v41; // ecx
  float m_relaxationFactor; // xmm4_4
  float v43; // xmm7_4
  float v44; // xmm6_4
  float v45; // xmm4_4
  float v46; // xmm5_4
  float v47; // xmm6_4
  float v48; // xmm5_4
  float v49; // xmm4_4
  float *v50; // ecx
  float *v51; // edx
  float v52; // xmm6_4
  float v53; // xmm7_4
  float v54; // xmm4_4
  float v55; // xmm5_4
  float v56; // xmm6_4
  float v57; // xmm5_4
  float *m_lowerLimit; // ecx
  float v59; // [esp+48h] [ebp-30h]
  float v60; // [esp+4Ch] [ebp-2Ch]
  float v61; // [esp+54h] [ebp-24h]
  float v62; // [esp+58h] [ebp-20h]
  float v63; // [esp+60h] [ebp-18h]
  float *v64; // [esp+64h] [ebp-14h]
  float v65; // [esp+64h] [ebp-14h]
  float v66; // [esp+6Ch] [ebp-Ch]
  float v67; // [esp+70h] [ebp-8h]
  float v68; // [esp+70h] [ebp-8h]

  btConeTwistConstraint::calcAngleInfo2(transA, &info->fps, this, transB, invInertiaWorldA, invInertiaWorldB);
  v7 = clear_value;
  *(_DWORD *)info->m_J1linearAxis = clear_value;
  LODWORD(info->m_J1linearAxis[info->rowskip + 1]) = v7;
  LODWORD(info->m_J1linearAxis[2 * info->rowskip + 2]) = v7;
  v8 = this->m_rbAFrame.m_origin.mVec128.m128_f32[2];
  v9 = this->m_rbAFrame.m_origin.mVec128.m128_f32[1];
  v10 = this->m_rbAFrame.m_origin.mVec128.m128_f32[0];
  m_J1angularAxis = info->m_J1angularAxis;
  rowskip = info->rowskip;
  v14 = (float)((float)(v9 * transA->m_basis.m_el[0].mVec128.m128_f32[1])
              + (float)(v8 * transA->m_basis.m_el[0].mVec128.m128_f32[2]))
      + (float)(transA->m_basis.m_el[0].mVec128.m128_f32[0] * v10);
  v15 = (float)((float)(transA->m_basis.m_el[2].mVec128.m128_f32[1] * v9)
              + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[2] * v8))
      + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[0] * v10);
  v66 = (float)((float)(transA->m_basis.m_el[1].mVec128.m128_f32[1] * v9)
              + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[2] * v8))
      + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[0] * v10);
  m_J1angularAxis[2] = -v66;
  *m_J1angularAxis = 0.0;
  m_J1angularAxis[3] = 0.0;
  m_J1angularAxis[1] = -COERCE_FLOAT(LODWORD(v15) ^ 0x80000000);
  LODWORD(m_J1angularAxis[rowskip]) = LODWORD(v15) ^ 0x80000000;
  m_J1angularAxis[rowskip + 1] = 0.0;
  m_J1angularAxis[rowskip + 3] = 0.0;
  m_J1angularAxis[rowskip + 2] = -COERCE_FLOAT(LODWORD(v14) ^ 0x80000000);
  LODWORD(m_J1angularAxis[2 * rowskip + 1]) = LODWORD(v14) ^ 0x80000000;
  m_J1angularAxis[2 * rowskip + 2] = 0.0;
  m_J1angularAxis[2 * rowskip + 3] = 0.0;
  m_J1angularAxis[2 * rowskip] = -(float)-v66;
  v16 = this->m_rbBFrame.m_origin.mVec128.m128_f32[2];
  v17 = this->m_rbBFrame.m_origin.mVec128.m128_f32[1];
  v18 = this->m_rbBFrame.m_origin.mVec128.m128_f32[0];
  m_J2angularAxis = info->m_J2angularAxis;
  v20 = info->rowskip;
  v21 = (float)((float)(transB->m_basis.m_el[0].mVec128.m128_f32[1] * v17)
              + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[2] * v16))
      + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * v18);
  v22 = (float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * v17)
              + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[2] * v16))
      + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[0] * v18);
  v23 = (float)(transB->m_basis.m_el[2].mVec128.m128_f32[1] * v17)
      + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2] * v16);
  v24 = transB->m_basis.m_el[2].mVec128.m128_f32[0] * v18;
  *m_J2angularAxis = 0.0;
  m_J2angularAxis[2] = v22;
  m_J2angularAxis[3] = 0.0;
  v25 = v23 + v24;
  *((_DWORD *)m_J2angularAxis + 1) = LODWORD(v25) ^ 0x80000000;
  m_J2angularAxis[v20] = v25;
  m_J2angularAxis[v20 + 1] = 0.0;
  LODWORD(m_J2angularAxis[v20 + 2]) = LODWORD(v21) ^ 0x80000000;
  m_J2angularAxis[v20 + 3] = 0.0;
  m_J2angularAxis[2 * v20] = -v22;
  m_J2angularAxis[2 * v20 + 1] = v21;
  m_J2angularAxis[2 * v20 + 2] = 0.0;
  m_J2angularAxis[2 * v20 + 3] = 0.0;
  if ( (this->m_flags & 2) != 0 )
    m_linERP = this->m_linERP;
  else
    m_linERP = info->erp;
  v27 = info->fps * m_linERP;
  *info->m_constraintError = (float)((float)((float)(transB->m_origin.mVec128.m128_f32[0] + v21) - v14)
                                   - transA->m_origin.mVec128.m128_f32[0])
                           * v27;
  *info->m_lowerLimit = -3.4028235e38;
  *info->m_upperLimit = 3.4028235e38;
  if ( (this->m_flags & 1) != 0 )
    *info->cfm = this->m_linCFM;
  info->m_constraintError[info->rowskip] = (float)((float)((float)(transB->m_origin.mVec128.m128_f32[1] + v22) - v66)
                                                 - transA->m_origin.mVec128.m128_f32[1])
                                         * v27;
  info->m_lowerLimit[info->rowskip] = -3.4028235e38;
  info->m_upperLimit[info->rowskip] = 3.4028235e38;
  if ( (this->m_flags & 1) != 0 )
    info->cfm[info->rowskip] = this->m_linCFM;
  info->m_constraintError[2 * info->rowskip] = (float)((float)((float)(transB->m_origin.mVec128.m128_f32[2] + v25) - v15)
                                                     - transA->m_origin.mVec128.m128_f32[2])
                                             * v27;
  info->m_lowerLimit[2 * info->rowskip] = -3.4028235e38;
  info->m_upperLimit[2 * info->rowskip] = 3.4028235e38;
  if ( (this->m_flags & 1) != 0 )
    info->cfm[2 * info->rowskip] = this->m_linCFM;
  v28 = 3 * info->rowskip;
  if ( this->m_solveSwingLimit )
  {
    v29 = info->m_J2angularAxis;
    m_fixThresh = this->m_fixThresh;
    v31 = info->m_J1angularAxis;
    v64 = v29;
    if ( m_fixThresh <= this->m_swingSpan1 || m_fixThresh <= this->m_swingSpan2 )
    {
      m_relaxationFactor = this->m_relaxationFactor;
      v43 = this->m_swingAxis.mVec128.m128_f32[1] * m_relaxationFactor;
      v67 = this->m_swingAxis.mVec128.m128_f32[2] * m_relaxationFactor;
      v44 = m_relaxationFactor;
      v45 = m_relaxationFactor * (float)(m_relaxationFactor * this->m_swingAxis.mVec128.m128_f32[0]);
      v31[3 * info->rowskip] = v45;
      v46 = v44;
      v47 = v44 * v67;
      v31[v28 + 2] = v47;
      v48 = v46 * v43;
      v31[v28 + 1] = v48;
      v29[v28] = -v45;
      v29[v28 + 1] = -v48;
      v29[v28 + 2] = -v47;
      info->m_constraintError[v28] = (float)(this->m_biasFactor * info->fps) * this->m_swingCorrection;
      if ( (this->m_flags & 4) != 0 )
        info->cfm[v28] = this->m_angCFM;
      info->m_lowerLimit[v28] = 0.0;
      info->m_upperLimit[v28] = 3.4028235e38;
      v28 += info->rowskip;
    }
    else
    {
      v32 = this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[2];
      v33 = this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[2];
      v62 = this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[1];
      v61 = this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[1];
      v60 = this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[2];
      v34 = transA->m_basis.m_el[1].mVec128.m128_f32[2] * v32;
      v35 = info->rowskip;
      v36 = (float)((float)(transA->m_basis.m_el[2].mVec128.m128_f32[1] * v60)
                  + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[2] * v32))
          + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[0] * v33);
      v37 = this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[1];
      v38 = (float)((float)(transA->m_basis.m_el[2].mVec128.m128_f32[1] * v61)
                  + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[2] * v62))
          + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[0] * v37);
      v59 = (float)((float)(transA->m_basis.m_el[1].mVec128.m128_f32[1] * v60) + v34)
          + (float)(v33 * transA->m_basis.m_el[1].mVec128.m128_f32[0]);
      v63 = (float)((float)(transA->m_basis.m_el[1].mVec128.m128_f32[1] * v61)
                  + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[2] * v62))
          + (float)(v37 * transA->m_basis.m_el[1].mVec128.m128_f32[0]);
      v39 = (float)((float)(v33 * transA->m_basis.m_el[0].mVec128.m128_f32[0])
                  + (float)(v60 * transA->m_basis.m_el[0].mVec128.m128_f32[1]))
          + (float)(this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[2] * transA->m_basis.m_el[0].mVec128.m128_f32[2]);
      v40 = (float)((float)(v37 * transA->m_basis.m_el[0].mVec128.m128_f32[0])
                  + (float)(v61 * transA->m_basis.m_el[0].mVec128.m128_f32[1]))
          + (float)(v62 * transA->m_basis.m_el[0].mVec128.m128_f32[2]);
      v31[3 * v35] = v40;
      v31[v28 + 1] = v63;
      v31[v28 + 2] = v38;
      v41 = v28 + v35;
      v31[v41 + 1] = v59;
      v31[v41] = v39;
      v31[v41 + 2] = v36;
      LODWORD(v64[v28]) = LODWORD(v40) ^ 0x80000000;
      LODWORD(v64[v28 + 1]) = LODWORD(v63) ^ 0x80000000;
      LODWORD(v64[v28 + 2]) = LODWORD(v38) ^ 0x80000000;
      LODWORD(v64[v41]) = LODWORD(v39) ^ 0x80000000;
      LODWORD(v64[v41 + 1]) = LODWORD(v59) ^ 0x80000000;
      LODWORD(v64[v41 + 2]) = LODWORD(v36) ^ 0x80000000;
      v65 = this->m_relaxationFactor * info->fps;
      info->m_constraintError[v28] = (float)((float)((float)(this->m_swingAxis.mVec128.m128_f32[1] * v63)
                                                   + (float)(this->m_swingAxis.mVec128.m128_f32[2] * v38))
                                           + (float)(v40 * this->m_swingAxis.mVec128.m128_f32[0]))
                                   * v65;
      info->m_constraintError[v41] = (float)((float)((float)(this->m_swingAxis.mVec128.m128_f32[1] * v59)
                                                   + (float)(this->m_swingAxis.mVec128.m128_f32[2] * v36))
                                           + (float)(v39 * this->m_swingAxis.mVec128.m128_f32[0]))
                                   * v65;
      info->m_lowerLimit[v28] = -3.4028235e38;
      info->m_upperLimit[v28] = 3.4028235e38;
      info->m_lowerLimit[v41] = -3.4028235e38;
      info->m_upperLimit[v41] = 3.4028235e38;
      v28 = v41 + info->rowskip;
    }
  }
  if ( this->m_solveTwistLimit )
  {
    v49 = this->m_relaxationFactor;
    v50 = info->m_J1angularAxis;
    v51 = info->m_J2angularAxis;
    v68 = this->m_twistAxis.mVec128.m128_f32[2] * v49;
    v52 = v49;
    v53 = this->m_twistAxis.mVec128.m128_f32[1] * v49;
    v54 = v49 * (float)(v49 * this->m_twistAxis.mVec128.m128_f32[0]);
    v50[v28] = v54;
    v55 = v52;
    v56 = v52 * v68;
    v50[v28 + 2] = v56;
    v57 = v55 * v53;
    v50[v28 + 1] = v57;
    v51[v28] = -v54;
    v51[v28 + 1] = -v57;
    v51[v28 + 2] = -v56;
    info->m_constraintError[v28] = (float)(this->m_biasFactor * info->fps) * this->m_twistCorrection;
    if ( (this->m_flags & 4) != 0 )
      info->cfm[v28] = this->m_angCFM;
    m_lowerLimit = info->m_lowerLimit;
    if ( this->m_twistSpan <= 0.0 )
    {
      m_lowerLimit[v28] = -3.4028235e38;
      info->m_upperLimit[v28] = 3.4028235e38;
    }
    else if ( this->m_twistCorrection <= 0.0 )
    {
      m_lowerLimit[v28] = -3.4028235e38;
      info->m_upperLimit[v28] = 0.0;
    }
    else
    {
      m_lowerLimit[v28] = 0.0;
      info->m_upperLimit[v28] = 3.4028235e38;
    }
  }
}
