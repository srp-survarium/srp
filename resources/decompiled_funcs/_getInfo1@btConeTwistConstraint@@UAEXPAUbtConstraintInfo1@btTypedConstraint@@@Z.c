void __thiscall btConeTwistConstraint::getInfo1(
        btConeTwistConstraint *this,
        btTypedConstraint::btConstraintInfo1 *info)
{
  float m_fixThresh; // xmm0_4
  int nub; // ecx

  if ( this->m_useSolveConstraintObsolete )
  {
    info->m_numConstraintRows = 0;
    info->nub = 0;
  }
  else
  {
    info->m_numConstraintRows = 3;
    info->nub = 3;
    btConeTwistConstraint::calcAngleInfo2(
      &this->m_rbA->m_worldTransform,
      (float *)this,
      this,
      &this->m_rbB->m_worldTransform,
      &this->m_rbA->m_invInertiaTensorWorld,
      &this->m_rbB->m_invInertiaTensorWorld);
    if ( this->m_solveSwingLimit )
    {
      ++info->m_numConstraintRows;
      --info->nub;
      m_fixThresh = this->m_fixThresh;
      nub = info->nub;
      if ( m_fixThresh > this->m_swingSpan1 && m_fixThresh > this->m_swingSpan2 )
      {
        ++info->m_numConstraintRows;
        info->nub = nub - 1;
      }
    }
    if ( this->m_solveTwistLimit )
    {
      ++info->m_numConstraintRows;
      --info->nub;
    }
  }
}
