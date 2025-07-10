void __thiscall btCompoundCollisionAlgorithm::~btCompoundCollisionAlgorithm(btCompoundCollisionAlgorithm *this)
{
  btCollisionAlgorithm **m_data; // eax

  this->__vftable = (btCompoundCollisionAlgorithm_vtbl *)&btCompoundCollisionAlgorithm::`vftable';
  btCompoundCollisionAlgorithm::removeChildAlgorithms(this, (int)this);
  m_data = this->m_childCollisionAlgorithms.m_data;
  if ( m_data )
  {
    if ( this->m_childCollisionAlgorithms.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_childCollisionAlgorithms.m_data = 0;
  }
  this->m_childCollisionAlgorithms.m_data = 0;
  this->m_childCollisionAlgorithms.m_size = 0;
  this->m_childCollisionAlgorithms.m_capacity = 0;
  this->m_childCollisionAlgorithms.m_ownsMemory = 1;
  this->__vftable = (btCompoundCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
}
