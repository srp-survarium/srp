void __thiscall btGeneric6DofConstraint::buildJacobian(btGeneric6DofConstraint *this)
{
  int v2; // edi
  btJacobianEntry *m_jacLinear; // ebx
  __m128 v4; // xmm0
  int v5; // edi
  btVector3 *m_calculatedAxis; // ebx
  btJacobianEntry *jacAngular; // [esp+8Ch] [ebp-54h]
  btVector3 jointAxisW; // [esp+90h] [ebp-50h] BYREF
  __m128i v9; // [esp+A0h] [ebp-40h] BYREF
  __m128i v10; // [esp+B0h] [ebp-30h] BYREF
  btVector3 v11; // [esp+C0h] [ebp-20h] BYREF
  btVector3 v12; // [esp+D0h] [ebp-10h] BYREF

  if ( this->m_useSolveConstraintObsolete )
  {
    this->m_linearLimits.m_accumulatedImpulse.mVec128.m128_u64[0] = 0;
    this->m_linearLimits.m_accumulatedImpulse.mVec128.m128_u64[1] = 0;
    this->m_angularLimits[0].m_accumulatedImpulse = 0.0;
    this->m_angularLimits[1].m_accumulatedImpulse = 0.0;
    this->m_angularLimits[2].m_accumulatedImpulse = 0.0;
    btGeneric6DofConstraint::calculateTransforms(
      this,
      (btGeneric6DofConstraint *)&this->m_rbA->m_worldTransform,
      &this->m_rbB->m_worldTransform);
    this->calcAnchorPos(this);
    v11.mVec128 = (__m128)this->m_AnchorPos;
    v12.mVec128 = (__m128)this->m_AnchorPos;
    v2 = 4;
    m_jacLinear = this->m_jacLinear;
    do
    {
      if ( this->m_linearLimits.m_lowerLimit.mVec128.m128_f32[v2] >= *(float *)((char *)&this->m_jacAng[2].m_Adiag
                                                                              + v2 * 4) )
      {
        if ( this->m_useLinearReferenceFrameA )
        {
          v9.m128i_i32[0] = *(_DWORD *)((char *)&this->m_angularLimits[3].m_loLimit + v2 * 4);
          v9.m128i_i32[1] = this->m_calculatedTransformA.m_basis.m_el[0].mVec128.m128_i32[v2];
          v9.m128i_i64[1] = this->m_calculatedTransformA.m_basis.m_el[1].mVec128.m128_u32[v2];
          v4 = (__m128)_mm_load_si128(&v9);
        }
        else
        {
          v10.m128i_i32[0] = this->m_calculatedTransformA.m_origin.mVec128.m128_i32[v2];
          v10.m128i_i32[1] = this->m_calculatedTransformB.m_basis.m_el[0].mVec128.m128_i32[v2];
          v10.m128i_i64[1] = this->m_calculatedTransformB.m_basis.m_el[1].mVec128.m128_u32[v2];
          v4 = (__m128)_mm_load_si128(&v10);
        }
        jointAxisW.mVec128 = v4;
        btGeneric6DofConstraint::buildLinearJacobian(this, &v12, m_jacLinear, &jointAxisW, &v11);
      }
      ++v2;
      ++m_jacLinear;
    }
    while ( v2 < 7 );
    v5 = 0;
    jacAngular = this->m_jacAng;
    m_calculatedAxis = this->m_calculatedAxis;
    do
    {
      if ( btGeneric6DofConstraint::testAngularLimitMotor(this, v5) )
      {
        jointAxisW.mVec128 = m_calculatedAxis->mVec128;
        btGeneric6DofConstraint::buildAngularJacobian(this, jacAngular, &jointAxisW);
      }
      ++jacAngular;
      ++v5;
      ++m_calculatedAxis;
    }
    while ( v5 < 3 );
  }
}
