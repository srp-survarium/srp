void __thiscall btDefaultSoftBodySolver::updateSoftBodies(btDefaultSoftBodySolver *this)
{
  int i; // edi
  btSoftBody *m_activationState1; // ecx

  for ( i = 0; i < this->m_softBodySet.m_size; ++i )
  {
    m_activationState1 = (btSoftBody *)this->m_softBodySet.m_data[i]->m_activationState1;
    if ( m_activationState1 != (btSoftBody *)2 && m_activationState1 != (btSoftBody *)5 )
      btSoftBody::updateNormals(m_activationState1, &this->m_softBodySet.m_data[i]->__vftable);
  }
}
