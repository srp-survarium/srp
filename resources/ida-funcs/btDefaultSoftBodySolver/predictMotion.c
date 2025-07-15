void __thiscall btDefaultSoftBodySolver::predictMotion(btDefaultSoftBodySolver *this, float timeStep)
{
  int i; // esi
  btSoftBody *v4; // ecx
  int m_activationState1; // eax

  for ( i = 0; i < this->m_softBodySet.m_size; ++i )
  {
    v4 = this->m_softBodySet.m_data[i];
    m_activationState1 = v4->m_activationState1;
    if ( m_activationState1 != 2 && m_activationState1 != 5 )
      btSoftBody::predictMotion(v4, v4, timeStep);
  }
}
