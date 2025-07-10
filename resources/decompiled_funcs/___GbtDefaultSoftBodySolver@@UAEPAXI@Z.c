btDefaultSoftBodySolver *__thiscall btDefaultSoftBodySolver::`scalar deleting destructor'(
        btDefaultSoftBodySolver *this,
        char a2)
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
  this->m_softBodySet.m_ownsMemory = 1;
  this->m_softBodySet.m_data = 0;
  this->m_softBodySet.m_size = 0;
  this->m_softBodySet.m_capacity = 0;
  this->__vftable = (btDefaultSoftBodySolver_vtbl *)&btSoftBodySolver::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
