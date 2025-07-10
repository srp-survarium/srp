int __userpurge btGeneric6DofConstraint::get_limit_motor_info2@<eax>(
        btGeneric6DofConstraint *this@<eax>,
        btRotationalLimitMotor *limot@<edi>,
        btTypedConstraint::btConstraintInfo2 *info@<esi>,
        const btTransform *transA,
        const btTransform *transB,
        const btVector3 *linVelA,
        const btVector3 *linVelB,
        const btVector3 *angVelA,
        const btVector3 *angVelB,
        int row,
        btVector3 *ax1,
        int rotational,
        int rotAllowed)
{
  int v13; // ecx
  float *v15; // eax
  float v16; // xmm0_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm6_4
  float v22; // xmm5_4
  unsigned int v23; // xmm4_4
  unsigned int v24; // xmm3_4
  float v25; // xmm6_4
  float v26; // xmm2_4
  float v27; // xmm5_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm1_4
  float v31; // xmm5_4
  float v32; // xmm7_4
  float v33; // xmm1_4
  float m_factA; // xmm5_4
  float v35; // xmm6_4
  float v36; // xmm4_4
  float v37; // xmm7_4
  bool v38; // zf
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm3_4
  float m_factB; // xmm5_4
  float v43; // xmm3_4
  float v44; // xmm4_4
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm3_4
  float v48; // xmm6_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm6_4
  float v52; // xmm5_4
  float v53; // xmm7_4
  float v54; // xmm2_4
  float v55; // xmm1_4
  float v56; // xmm3_4
  float v57; // xmm4_4
  float v58; // xmm1_4
  float v59; // xmm2_4
  float v60; // xmm0_4
  float v61; // xmm6_4
  float v62; // xmm1_4
  float v63; // xmm2_4
  float v64; // xmm4_4
  float v65; // xmm5_4
  float v66; // xmm6_4
  float v67; // xmm7_4
  BOOL v68; // eax
  float m_targetVelocity; // xmm5_4
  float m_loLimit; // xmm0_4
  float m_hiLimit; // xmm1_4
  float m_currentPosition; // xmm3_4
  float v73; // xmm5_4
  float v74; // xmm0_4
  float *v75; // eax
  float v76; // xmm1_4
  float *m_lowerLimit; // eax
  float m_bounce; // xmm1_4
  float v79; // xmm3_4
  float v80; // xmm5_4
  float v81; // xmm6_4
  float v82; // xmm0_4
  float v83; // xmm7_4
  float v85; // xmm0_4
  float *v86; // eax
  float v87; // xmm1_4
  bool v88; // cc
  float *m_constraintError; // eax
  float v90; // xmm1_4
  float v91; // xmm0_4
  int m_currentLimit; // [esp+248h] [ebp-50h]
  float *m_J1angularAxis; // [esp+24Ch] [ebp-4Ch]
  float *m_J2angularAxis; // [esp+250h] [ebp-48h]
  BOOL m_enableMotor; // [esp+254h] [ebp-44h]
  float v96; // [esp+258h] [ebp-40h]
  __m128i v97; // [esp+258h] [ebp-40h]
  float v98; // [esp+25Ch] [ebp-3Ch]
  float v99; // [esp+260h] [ebp-38h]
  float v100; // [esp+268h] [ebp-30h]
  __m128i v101; // [esp+268h] [ebp-30h]
  float v102; // [esp+26Ch] [ebp-2Ch]
  float v103; // [esp+270h] [ebp-28h]
  __m128i v104; // [esp+278h] [ebp-20h] BYREF
  __m128i v105; // [esp+288h] [ebp-10h] BYREF

  v13 = row * info->rowskip;
  m_enableMotor = limot->m_enableMotor;
  m_currentLimit = limot->m_currentLimit;
  if ( !limot->m_enableMotor && !limot->m_currentLimit )
    return 0;
  if ( rotational )
  {
    m_J1angularAxis = info->m_J1angularAxis;
    m_J2angularAxis = info->m_J2angularAxis;
  }
  else
  {
    m_J1angularAxis = info->m_J1linearAxis;
    m_J2angularAxis = 0;
  }
  m_J1angularAxis[v13] = ax1->mVec128.m128_f32[0];
  m_J1angularAxis[v13 + 1] = ax1->mVec128.m128_f32[1];
  m_J1angularAxis[v13 + 2] = ax1->mVec128.m128_f32[2];
  if ( rotational )
  {
    v15 = m_J2angularAxis;
    m_J2angularAxis[v13] = -ax1->mVec128.m128_f32[0];
    m_J2angularAxis[v13 + 1] = -ax1->mVec128.m128_f32[1];
    v16 = ax1->mVec128.m128_f32[2];
  }
  else
  {
    v17 = ax1->mVec128.m128_f32[1];
    if ( this->m_useOffsetForConstraintFrame )
    {
      v18 = ax1->mVec128.m128_f32[2];
      v19 = ax1->mVec128.m128_f32[0];
      v20 = (float)((float)((float)(this->m_calculatedTransformB.m_origin.mVec128.m128_f32[2]
                                  - transB->m_origin.mVec128.m128_f32[2])
                          * v18)
                  + (float)((float)(this->m_calculatedTransformB.m_origin.mVec128.m128_f32[1]
                                  - transB->m_origin.mVec128.m128_f32[1])
                          * v17))
          + (float)((float)(this->m_calculatedTransformB.m_origin.mVec128.m128_f32[0]
                          - transB->m_origin.mVec128.m128_f32[0])
                  * ax1->mVec128.m128_f32[0]);
      v21 = v18 * v20;
      v22 = v17 * v20;
      *(float *)&v23 = (float)(this->m_calculatedTransformB.m_origin.mVec128.m128_f32[2]
                             - transB->m_origin.mVec128.m128_f32[2])
                     - v21;
      *(float *)&v24 = (float)(this->m_calculatedTransformB.m_origin.mVec128.m128_f32[1]
                             - transB->m_origin.mVec128.m128_f32[1])
                     - v22;
      v99 = v21;
      v25 = this->m_calculatedTransformA.m_origin.mVec128.m128_f32[1] - transA->m_origin.mVec128.m128_f32[1];
      v96 = ax1->mVec128.m128_f32[0] * v20;
      *(float *)v104.m128i_i32 = (float)(this->m_calculatedTransformB.m_origin.mVec128.m128_f32[0]
                                       - transB->m_origin.mVec128.m128_f32[0])
                               - v96;
      v26 = this->m_calculatedTransformA.m_origin.mVec128.m128_f32[2] - transA->m_origin.mVec128.m128_f32[2];
      v98 = v22;
      v27 = this->m_calculatedTransformA.m_origin.mVec128.m128_f32[0] - transA->m_origin.mVec128.m128_f32[0];
      *(__int64 *)((char *)v104.m128i_i64 + 4) = __PAIR64__(v23, v24);
      v28 = ax1->mVec128.m128_f32[1];
      v29 = ax1->mVec128.m128_f32[2];
      v30 = (float)((float)(v26 * v29) + (float)(v25 * v28)) + (float)(v27 * v19);
      *(float *)v105.m128i_i32 = v19 * v30;
      v31 = v27 - (float)(v19 * v30);
      *(float *)&v105.m128i_i32[1] = v28 * v30;
      v32 = v29 * v30;
      v33 = limot->m_currentPosition - limot->m_currentLimitError;
      v103 = v26 - v32;
      v100 = v31;
      v102 = v25 - *(float *)&v105.m128i_i32[1];
      m_factA = this->m_factA;
      v35 = (float)((float)(v29 * v33) + v32) - v99;
      v36 = (float)((float)(v19 * v33) + *(float *)v105.m128i_i32) - v96;
      v37 = (float)((float)(v28 * v33) + *(float *)&v105.m128i_i32[1]) - v98;
      v38 = !this->m_hasStaticBody;
      v39 = (float)(v36 * m_factA) + v100;
      v40 = (float)(v37 * m_factA) + v102;
      v41 = v35 * m_factA;
      m_factB = this->m_factB;
      v43 = v41 + v103;
      v44 = *(float *)v104.m128i_i32 - (float)(v36 * m_factB);
      *(float *)&v105.m128i_i32[1] = *(float *)&v104.m128i_i32[1] - (float)(v37 * m_factB);
      v45 = *(float *)&v104.m128i_i32[2] - (float)(v35 * m_factB);
      *(float *)v104.m128i_i32 = (float)(v40 * ax1->mVec128.m128_f32[2]) - (float)(v43 * ax1->mVec128.m128_f32[1]);
      v46 = ax1->mVec128.m128_f32[2];
      *(float *)&v104.m128i_i32[1] = (float)(v43 * v19) - (float)(v39 * v46);
      v104.m128i_i64[1] = COERCE_UNSIGNED_INT((float)(v39 * ax1->mVec128.m128_f32[1]) - (float)(v40 * v19));
      v101 = _mm_load_si128(&v104);
      v47 = v46;
      v48 = ax1->mVec128.m128_f32[1];
      v49 = (float)(*(float *)&v105.m128i_i32[1] * v47) - (float)(v45 * v48);
      *(float *)&v105.m128i_i32[2] = (float)(v44 * v48) - (float)(*(float *)&v105.m128i_i32[1] * v19);
      *(float *)v105.m128i_i32 = v49;
      *(float *)&v105.m128i_i32[1] = (float)(v45 * v19) - (float)(v44 * v47);
      v105.m128i_i32[3] = 0;
      v97 = _mm_load_si128(&v105);
      if ( v38 || rotAllowed )
      {
        v52 = *(float *)&v101.m128i_i32[2];
        v51 = *(float *)&v101.m128i_i32[1];
        v53 = *(float *)v101.m128i_i32;
        v16 = *(float *)&v97.m128i_i32[2];
        v56 = *(float *)&v97.m128i_i32[1];
        v55 = *(float *)v97.m128i_i32;
      }
      else
      {
        v50 = this->m_factA;
        v51 = *(float *)&v101.m128i_i32[1] * v50;
        v52 = *(float *)&v101.m128i_i32[2] * v50;
        v53 = *(float *)v104.m128i_i32 * v50;
        v54 = this->m_factB;
        v55 = v49 * v54;
        v56 = *(float *)&v97.m128i_i32[1] * v54;
        v16 = *(float *)&v97.m128i_i32[2] * v54;
      }
      info->m_J1angularAxis[v13] = v53;
      info->m_J1angularAxis[v13 + 1] = v51;
      info->m_J1angularAxis[v13 + 2] = v52;
      info->m_J2angularAxis[v13] = -v55;
      info->m_J2angularAxis[v13 + 1] = -v56;
    }
    else
    {
      v57 = ax1->mVec128.m128_f32[2];
      v58 = this->m_calculatedTransformB.m_origin.mVec128.m128_f32[2] - transA->m_origin.mVec128.m128_f32[2];
      v59 = this->m_calculatedTransformB.m_origin.mVec128.m128_f32[1] - transA->m_origin.mVec128.m128_f32[1];
      v60 = this->m_calculatedTransformB.m_origin.mVec128.m128_f32[0] - transA->m_origin.mVec128.m128_f32[0];
      v61 = ax1->mVec128.m128_f32[0];
      info->m_J1angularAxis[v13] = (float)(v59 * v57) - (float)(v58 * v17);
      info->m_J1angularAxis[v13 + 1] = (float)(v58 * v61) - (float)(v60 * v57);
      info->m_J1angularAxis[v13 + 2] = (float)(v60 * v17) - (float)(v59 * v61);
      v62 = this->m_calculatedTransformB.m_origin.mVec128.m128_f32[2] - transB->m_origin.mVec128.m128_f32[2];
      v63 = this->m_calculatedTransformB.m_origin.mVec128.m128_f32[1] - transB->m_origin.mVec128.m128_f32[1];
      v64 = ax1->mVec128.m128_f32[2];
      v65 = ax1->mVec128.m128_f32[1];
      v66 = ax1->mVec128.m128_f32[0];
      v67 = this->m_calculatedTransformB.m_origin.mVec128.m128_f32[0] - transB->m_origin.mVec128.m128_f32[0];
      v16 = (float)(v67 * v65) - (float)(v63 * ax1->mVec128.m128_f32[0]);
      info->m_J2angularAxis[v13] = -(float)((float)(v63 * v64) - (float)(v62 * v65));
      info->m_J2angularAxis[v13 + 1] = -(float)((float)(v62 * v66) - (float)(v67 * v64));
    }
    v15 = info->m_J2angularAxis;
  }
  v15[v13 + 2] = -v16;
  v68 = (!m_currentLimit || limot->m_loLimit != limot->m_hiLimit) && m_enableMotor;
  info->m_constraintError[v13] = 0.0;
  if ( v68 )
  {
    info->cfm[v13] = limot->m_normalCFM;
    if ( !m_currentLimit )
    {
      m_targetVelocity = limot->m_targetVelocity;
      if ( !rotational )
        m_targetVelocity = -m_targetVelocity;
      m_loLimit = limot->m_loLimit;
      m_hiLimit = limot->m_hiLimit;
      m_currentPosition = limot->m_currentPosition;
      if ( limot->m_loLimit <= m_hiLimit )
      {
        if ( m_loLimit == m_hiLimit )
          goto LABEL_39;
        v73 = m_targetVelocity / (float)(limot->m_stopERP * info->fps);
        if ( v73 < 0.0 )
        {
          if ( m_currentPosition >= m_loLimit && (float)(m_loLimit - v73) > m_currentPosition )
          {
            v74 = (float)(m_loLimit - m_currentPosition) / v73;
LABEL_40:
            info->m_constraintError[v13] = (float)(limot->m_targetVelocity * v74) + info->m_constraintError[v13];
            info->m_lowerLimit[v13] = -limot->m_maxMotorForce;
            info->m_upperLimit[v13] = limot->m_maxMotorForce;
            return 1;
          }
          if ( m_loLimit <= m_currentPosition )
          {
            v74 = *(float *)&clear_value;
            goto LABEL_40;
          }
LABEL_39:
          v74 = 0.0;
          goto LABEL_40;
        }
        if ( v73 <= 0.0 )
          goto LABEL_39;
        if ( m_hiLimit >= m_currentPosition && m_currentPosition > (float)(m_hiLimit - v73) )
        {
          v74 = (float)(m_hiLimit - m_currentPosition) / v73;
          goto LABEL_40;
        }
        if ( m_currentPosition > m_hiLimit )
          goto LABEL_39;
      }
      v74 = *(float *)&clear_value;
      goto LABEL_40;
    }
  }
  else if ( !m_currentLimit )
  {
    return 1;
  }
  v75 = &info->m_constraintError[v13];
  v76 = limot->m_currentLimitError * (float)(limot->m_stopERP * info->fps);
  if ( rotational )
    *v75 = *v75 - v76;
  else
    *v75 = v76 + *v75;
  info->cfm[v13] = limot->m_stopCFM;
  if ( limot->m_loLimit == limot->m_hiLimit )
  {
    info->m_lowerLimit[v13] = -3.4028235e38;
    info->m_upperLimit[v13] = 3.4028235e38;
    return 1;
  }
  m_lowerLimit = info->m_lowerLimit;
  if ( m_currentLimit == 1 )
  {
    m_lowerLimit[v13] = 0.0;
    info->m_upperLimit[v13] = 3.4028235e38;
  }
  else
  {
    m_lowerLimit[v13] = -3.4028235e38;
    info->m_upperLimit[v13] = 0.0;
  }
  m_bounce = limot->m_bounce;
  if ( m_bounce > 0.0 )
  {
    v79 = ax1->mVec128.m128_f32[2];
    v80 = ax1->mVec128.m128_f32[1];
    v81 = ax1->mVec128.m128_f32[0];
    if ( rotational )
    {
      v82 = (float)(angVelA->mVec128.m128_f32[1] * v80) + (float)(angVelA->mVec128.m128_f32[2] * v79);
      v83 = v81 * angVelA->mVec128.m128_f32[0];
    }
    else
    {
      v82 = (float)(linVelA->mVec128.m128_f32[1] * v80) + (float)(linVelA->mVec128.m128_f32[2] * v79);
      angVelB = linVelB;
      v83 = linVelA->mVec128.m128_f32[0] * v81;
    }
    v85 = (float)(v82 + v83)
        - (float)((float)((float)(angVelB->mVec128.m128_f32[1] * v80) + (float)(angVelB->mVec128.m128_f32[2] * v79))
                + (float)(angVelB->mVec128.m128_f32[0] * v81));
    if ( m_currentLimit == 1 )
    {
      if ( v85 < 0.0 )
      {
        v86 = &info->m_constraintError[v13];
        v87 = -(float)(m_bounce * v85);
        v88 = v87 <= *v86;
        goto LABEL_59;
      }
    }
    else if ( v85 > 0.0 )
    {
      m_constraintError = info->m_constraintError;
      v90 = m_bounce * v85;
      v91 = m_constraintError[v13];
      v86 = &m_constraintError[v13];
      v87 = -v90;
      v88 = v91 <= v87;
LABEL_59:
      if ( !v88 )
        *v86 = v87;
    }
  }
  return 1;
}
