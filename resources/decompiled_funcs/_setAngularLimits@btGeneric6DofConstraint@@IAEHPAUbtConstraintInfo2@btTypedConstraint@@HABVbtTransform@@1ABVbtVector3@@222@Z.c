int __userpurge btGeneric6DofConstraint::setAngularLimits@<eax>(
        btTypedConstraint::btConstraintInfo2 *info@<eax>,
        int row_offset@<ecx>,
        btGeneric6DofConstraint *this,
        const btTransform *transA,
        const btTransform *transB,
        const btVector3 *linVelA,
        const btVector3 *linVelB,
        const btVector3 *angVelA,
        const btVector3 *angVelB)
{
  btGeneric6DofConstraint *v10; // eax
  int v12; // ecx
  btVector3 *m_calculatedAxis; // edx
  bool *p_m_enableMotor; // ebx
  unsigned __int64 v15; // xmm0_8
  int v16; // edx
  int v18; // [esp+40h] [ebp-1Ch]
  btVector3 *v19; // [esp+44h] [ebp-18h]
  int v20; // [esp+48h] [ebp-14h]
  btVector3 ax1; // [esp+4Ch] [ebp-10h] BYREF

  v10 = this;
  v12 = 9;
  m_calculatedAxis = this->m_calculatedAxis;
  v18 = row_offset;
  v20 = 9;
  v19 = this->m_calculatedAxis;
  p_m_enableMotor = &this->m_angularLimits[0].m_enableMotor;
  do
  {
    if ( *((_DWORD *)p_m_enableMotor + 3) || *p_m_enableMotor )
    {
      ax1.mVec128.m128_u64[0] = m_calculatedAxis->mVec128.m128_u64[0];
      v15 = m_calculatedAxis->mVec128.m128_u64[1];
      v16 = v10->m_flags >> v12;
      ax1.mVec128.m128_u64[1] = v15;
      if ( (v16 & 1) == 0 )
        *((float *)p_m_enableMotor - 4) = *info->cfm;
      if ( (v16 & 2) == 0 )
        *((float *)p_m_enableMotor - 2) = *info->cfm;
      if ( (v16 & 4) == 0 )
        *((float *)p_m_enableMotor - 3) = info->erp;
      v18 += btGeneric6DofConstraint::get_limit_motor_info2(
               v10,
               (btRotationalLimitMotor *)(p_m_enableMotor - 44),
               info,
               transA,
               transB,
               linVelA,
               linVelB,
               angVelA,
               angVelB,
               row_offset,
               &ax1,
               1,
               0);
      m_calculatedAxis = v19;
      v12 = v20;
      row_offset = v18;
      v10 = this;
    }
    v12 += 3;
    ++m_calculatedAxis;
    p_m_enableMotor += 64;
    v19 = m_calculatedAxis;
    v20 = v12;
  }
  while ( v12 < 18 );
  return row_offset;
}
