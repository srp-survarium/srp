void __thiscall btDefaultSoftBodySolver::updateSoftBodies(btDefaultSoftBodySolver *this)
{
  int i; // esi
  btSoftBody *v3; // ecx
  int m_activationState1; // eax

  for ( i = 0; i < this->m_softBodySet.m_size; ++i )
  {
    v3 = this->m_softBodySet.m_data[i];
    m_activationState1 = v3->m_activationState1;
    if ( m_activationState1 != 2 && m_activationState1 != 5 )
      btSoftBody::updateNormals(v3, this->m_softBodySet.m_data[i]);
  }
}
