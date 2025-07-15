btNullPairCache *__thiscall btNullPairCache::`scalar deleting destructor'(btNullPairCache *this, char a2)
{
  btBroadphasePair *m_data; // eax

  m_data = this->m_overlappingPairArray.m_data;
  if ( m_data )
  {
    if ( this->m_overlappingPairArray.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_overlappingPairArray.m_data = 0;
  }
  this->m_overlappingPairArray.m_ownsMemory = 1;
  this->m_overlappingPairArray.m_data = 0;
  this->m_overlappingPairArray.m_size = 0;
  this->m_overlappingPairArray.m_capacity = 0;
  this->__vftable = (btNullPairCache_vtbl *)&btOverlappingPairCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
