void __thiscall btDiscreteDynamicsWorld::setConstraintSolver(btDiscreteDynamicsWorld *this, btConstraintSolver *solver)
{
  btConstraintSolver *m_constraintSolver; // eax

  if ( this->m_ownsConstraintSolver )
  {
    m_constraintSolver = this->m_constraintSolver;
    if ( m_constraintSolver )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_constraintSolver);
      this->m_constraintSolver = solver;
      this->m_ownsConstraintSolver = 0;
    }
    else
    {
      this->m_constraintSolver = solver;
      this->m_ownsConstraintSolver = 0;
    }
  }
  else
  {
    this->m_constraintSolver = solver;
    this->m_ownsConstraintSolver = 0;
  }
}
