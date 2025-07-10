const btTransform *__thiscall btGeneric6DofConstraint::setLinearLimits(
        btGeneric6DofConstraint *this,
        btGeneric6DofConstraint *info,
        btTypedConstraint::btConstraintInfo2 *row,
        const btTransform *transA,
        const btTransform *transB,
        const btTransform *linVelA,
        const btVector3 *linVelB,
        const btVector3 *angVelA,
        const btVector3 *angVelB,
        const btVector3 *angVelBa)
{
  int v10; // edx
  btTypedConstraint::btConstraintInfo2 *v11; // esi
  int v12; // eax
  btVector3 *p_m_currentLinearDiff; // edi
  int v14; // ecx
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // xmm1_4
  int v18; // eax
  float v19; // xmm0_4
  float v20; // xmm0_4
  float erp; // xmm0_4
  bool v22; // zf
  BOOL v23; // ecx
  int limit_motor_info2; // eax
  bool v25; // cc
  int v27; // [esp+104h] [ebp-6Ch]
  btVector3 *v28; // [esp+108h] [ebp-68h]
  int v29; // [esp+10Ch] [ebp-64h]
  btVector3 ax1; // [esp+120h] [ebp-50h] BYREF
  btRotationalLimitMotor v31; // [esp+130h] [ebp-40h] BYREF

  v31.m_maxMotorForce = FLOAT_0_1;
  v10 = 0;
  v11 = row;
  v31.m_maxLimitForce = 300.0;
  v12 = -912 - (_DWORD)info;
  LODWORD(v31.m_loLimit) = clear_value;
  v31.m_hiLimit = -1.0;
  LODWORD(v31.m_damping) = clear_value;
  p_m_currentLinearDiff = &info->m_linearLimits.m_currentLinearDiff;
  v31.m_accumulatedImpulse = 0.0;
  v31.m_targetVelocity = 0.0;
  v31.m_normalCFM = 0.0;
  v31.m_stopERP = 0.2;
  memset(&v31.m_stopCFM, 0, 9);
  v31.m_limitSoftness = FLOAT_0_5;
  v31.m_currentLimit = 0;
  v31.m_currentLimitError = 0.0;
  v27 = 0;
  v29 = 0;
  v28 = &info->m_linearLimits.m_currentLinearDiff;
  while ( 1 )
  {
    if ( p_m_currentLinearDiff[1].mVec128.m128_i32[0] || info->m_linearLimits.m_enableMotor[v10] )
    {
      v14 = p_m_currentLinearDiff[1].mVec128.m128_i32[0];
      LODWORD(v31.m_currentPosition) = p_m_currentLinearDiff->mVec128.m128_i32[0];
      LODWORD(v31.m_currentLimitError) = p_m_currentLinearDiff[-1].mVec128.m128_i32[0];
      v31.m_damping = info->m_linearLimits.m_damping;
      LODWORD(v31.m_hiLimit) = p_m_currentLinearDiff[-10].mVec128.m128_i32[0];
      v31.m_limitSoftness = info->m_linearLimits.m_limitSoftness;
      v15 = p_m_currentLinearDiff[-11].mVec128.m128_f32[0];
      v31.m_currentLimit = v14;
      LOBYTE(v14) = info->m_linearLimits.m_enableMotor[v10];
      v31.m_loLimit = v15;
      v16 = p_m_currentLinearDiff[-2].mVec128.m128_f32[0];
      v31.m_enableMotor = v14;
      v31.m_maxMotorForce = v16;
      LODWORD(v31.m_targetVelocity) = p_m_currentLinearDiff[-3].mVec128.m128_i32[0];
      ax1.mVec128.m128_i32[0] = p_m_currentLinearDiff[15].mVec128.m128_i32[0];
      ax1.mVec128.m128_i32[1] = *(int *)((char *)info->m_calculatedTransformA.m_basis.m_el[0].mVec128.m128_i32
                                       + (_DWORD)p_m_currentLinearDiff
                                       + v12);
      v17 = p_m_currentLinearDiff[17].mVec128.m128_i32[0];
      v18 = info->m_flags >> v29;
      v31.m_bounce = 0.0;
      v31.m_maxLimitForce = 0.0;
      ax1.mVec128.m128_u64[1] = (unsigned int)v17;
      if ( (v18 & 1) != 0 )
        v19 = p_m_currentLinearDiff[-7].mVec128.m128_f32[0];
      else
        v19 = *v11->cfm;
      v31.m_normalCFM = v19;
      if ( (v18 & 2) != 0 )
        v20 = p_m_currentLinearDiff[-5].mVec128.m128_f32[0];
      else
        v20 = *v11->cfm;
      v31.m_stopCFM = v20;
      if ( (v18 & 4) != 0 )
        erp = p_m_currentLinearDiff[-6].mVec128.m128_f32[0];
      else
        erp = v11->erp;
      v22 = !info->m_useOffsetForConstraintFrame;
      v31.m_stopERP = erp;
      if ( v22 )
      {
        limit_motor_info2 = btGeneric6DofConstraint::get_limit_motor_info2(
                              info,
                              &v31,
                              v11,
                              transB,
                              linVelA,
                              linVelB,
                              angVelA,
                              angVelB,
                              angVelBa,
                              (int)transA,
                              &ax1,
                              0,
                              0);
      }
      else
      {
        v23 = 1;
        if ( info->m_angularLimits[(v10 + 1) % 3].m_currentLimit )
          v23 = info->m_angularLimits[(v10 + 2) % 3].m_currentLimit == 0;
        v11 = row;
        limit_motor_info2 = btGeneric6DofConstraint::get_limit_motor_info2(
                              info,
                              &v31,
                              row,
                              transB,
                              linVelA,
                              linVelB,
                              angVelA,
                              angVelB,
                              angVelBa,
                              (int)transA,
                              &ax1,
                              0,
                              v23);
      }
      p_m_currentLinearDiff = v28;
      v10 = v27;
      transA = (const btTransform *)((char *)transA + limit_motor_info2);
    }
    ++v10;
    p_m_currentLinearDiff = (btVector3 *)((char *)p_m_currentLinearDiff + 4);
    v25 = v29 + 3 < 9;
    v27 = v10;
    v28 = p_m_currentLinearDiff;
    v29 += 3;
    if ( !v25 )
      break;
    v12 = -912 - (_DWORD)info;
  }
  return transA;
}
