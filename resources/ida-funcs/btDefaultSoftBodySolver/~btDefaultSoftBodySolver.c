void __thiscall btDefaultSoftBodySolver::~btDefaultSoftBodySolver(btDefaultSoftBodySolver *this)
{
  btSoftBody **m_data; // eax

  this->__vftable = (btDefaultSoftBodySolver_vtbl *)&btDefaultSoftBodySolver::`vftable';
  m_data = this->m_softBodySet.m_data;
  if ( m_data )
  {
    if ( this->m_softBodySet.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_softBodySet.m_data = 0;
  }
  this->m_softBodySet.m_data = 0;
  this->m_softBodySet.m_size = 0;
  this->m_softBodySet.m_capacity = 0;
  this->m_softBodySet.m_ownsMemory = 1;
  this->__vftable = (btDefaultSoftBodySolver_vtbl *)&btSoftBodySolver::`vftable';
}
