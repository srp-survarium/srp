void __thiscall btGhostObject::~btGhostObject(btGhostObject *this)
{
  btCollisionObject **m_data; // eax

  this->__vftable = (btGhostObject_vtbl *)&btGhostObject::`vftable';
  m_data = this->m_overlappingObjects.m_data;
  if ( m_data )
  {
    if ( this->m_overlappingObjects.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_overlappingObjects.m_data = 0;
  }
  this->m_overlappingObjects.m_data = 0;
  this->m_overlappingObjects.m_size = 0;
  this->m_overlappingObjects.m_capacity = 0;
  this->m_overlappingObjects.m_ownsMemory = 1;
  this->__vftable = (btGhostObject_vtbl *)&btCollisionObject::`vftable';
}
