void __thiscall btGeneric6DofConstraint::getInfo1(
        btGeneric6DofConstraint *this,
        btTypedConstraint::btConstraintInfo1 *info)
{
  int v3; // ebx

  v3 = 0;
  if ( this->m_useSolveConstraintObsolete )
  {
    info->m_numConstraintRows = 0;
    info->nub = 0;
  }
  else
  {
    btGeneric6DofConstraint::calculateTransforms(
      this,
      (btGeneric6DofConstraint *)&this->m_rbA->m_worldTransform,
      &this->m_rbB->m_worldTransform);
    info->m_numConstraintRows = 0;
    info->nub = 6;
    if ( this->m_linearLimits.m_currentLimit[0] || this->m_linearLimits.m_enableMotor[0] )
    {
      ++info->m_numConstraintRows;
      --info->nub;
    }
    if ( this->m_linearLimits.m_currentLimit[1] || this->m_linearLimits.m_enableMotor[1] )
    {
      ++info->m_numConstraintRows;
      --info->nub;
    }
    if ( this->m_linearLimits.m_currentLimit[2] || this->m_linearLimits.m_enableMotor[2] )
    {
      ++info->m_numConstraintRows;
      --info->nub;
    }
    do
    {
      if ( btGeneric6DofConstraint::testAngularLimitMotor(this, v3) )
      {
        ++info->m_numConstraintRows;
        --info->nub;
      }
      ++v3;
    }
    while ( v3 < 3 );
  }
}
