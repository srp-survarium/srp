void __thiscall btDefaultSoftBodySolver::solveConstraints(btDefaultSoftBodySolver *this, float solverdt)
{
  int i; // edi
  btSoftBody *m_activationState1; // ecx

  for ( i = 0; i < this->m_softBodySet.m_size; ++i )
  {
    m_activationState1 = (btSoftBody *)this->m_softBodySet.m_data[i]->m_activationState1;
    if ( m_activationState1 != (btSoftBody *)2 && m_activationState1 != (btSoftBody *)5 )
      btSoftBody::solveConstraints(m_activationState1, (int)this->m_softBodySet.m_data[i]);
  }
}
