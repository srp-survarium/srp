int __usercall btPersistentManifold::addManifoldPoint@<eax>(
        btPersistentManifold *this@<ecx>,
        btPersistentManifold *newPoint@<eax>)
{
  int m_cachedPoints; // ebx
  void *m_userPersistentData; // eax

  m_cachedPoints = this->m_cachedPoints;
  if ( m_cachedPoints == 4 )
  {
    m_cachedPoints = btPersistentManifold::sortCachedPoints(newPoint, (float *)&this->m_objectType);
    m_userPersistentData = this->m_pointCache[m_cachedPoints].m_userPersistentData;
    if ( m_userPersistentData && gContactDestroyedCallback )
    {
      gContactDestroyedCallback(m_userPersistentData);
      this->m_pointCache[m_cachedPoints].m_userPersistentData = 0;
    }
  }
  else
  {
    this->m_cachedPoints = m_cachedPoints + 1;
  }
  if ( m_cachedPoints < 0 )
    m_cachedPoints = 0;
  qmemcpy(&this->m_pointCache[m_cachedPoints], newPoint, sizeof(this->m_pointCache[m_cachedPoints]));
  return m_cachedPoints;
}
