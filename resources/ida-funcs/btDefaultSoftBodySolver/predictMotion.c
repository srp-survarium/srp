void __thiscall btDefaultSoftBodySolver::predictMotion(btDefaultSoftBodySolver *this, float timeStep)
{
  int i; // edi
  btSoftBody *v4; // eax
  btSoftBody *m_activationState1; // ecx

  for ( i = 0; i < this->m_softBodySet.m_size; ++i )
  {
    v4 = this->m_softBodySet.m_data[i];
    m_activationState1 = (btSoftBody *)v4->m_activationState1;
    if ( m_activationState1 != (btSoftBody *)2 && m_activationState1 != (btSoftBody *)5 )
      btSoftBody::predictMotion(m_activationState1, *(float *)&v4, timeStep);
  }
}
