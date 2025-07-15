void __thiscall btDiscreteDynamicsWorld::setConstraintSolver(btDiscreteDynamicsWorld *this, btConstraintSolver *solver)
{
  bool *p_m_ownsConstraintSolver; // esi

  p_m_ownsConstraintSolver = &this->m_ownsConstraintSolver;
  if ( this->m_ownsConstraintSolver )
    btAlignedFreeInternal(this->m_constraintSolver);
  this->m_constraintSolver = solver;
  *p_m_ownsConstraintSolver = 0;
}
