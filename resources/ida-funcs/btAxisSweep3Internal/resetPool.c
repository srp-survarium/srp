void __thiscall btAxisSweep3Internal<unsigned short>::resetPool(
        btAxisSweep3Internal<unsigned short> *this,
        btDispatcher *dispatcher)
{
  btDbvtBroadphase *m_raycastAccelerator; // ecx
  unsigned __int16 v4; // ax

  m_raycastAccelerator = this->m_raycastAccelerator;
  if ( m_raycastAccelerator )
    m_raycastAccelerator->resetPool(m_raycastAccelerator, 0);
  if ( !this->m_numHandles )
  {
    v4 = 1;
    for ( this->m_firstFreeHandle = 1; v4 < this->m_maxHandles; ++v4 )
      this->m_pHandles[v4].m_minEdges[0] = v4 + 1;
    this->m_pHandles[this->m_maxHandles - 1].m_minEdges[0] = 0;
  }
}
