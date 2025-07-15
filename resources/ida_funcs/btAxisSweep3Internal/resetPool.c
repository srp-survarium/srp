void __thiscall btAxisSweep3Internal<unsigned short>::resetPool(
        btAxisSweep3Internal<unsigned short> *this,
        btDispatcher *dispatcher)
{
  unsigned __int16 v2; // ax

  if ( !this->m_numHandles )
  {
    v2 = 1;
    for ( this->m_firstFreeHandle = 1; v2 < this->m_maxHandles; ++v2 )
      this->m_pHandles[v2].m_minEdges[0] = v2 + 1;
    this->m_pHandles[this->m_maxHandles - 1].m_minEdges[0] = 0;
  }
}
