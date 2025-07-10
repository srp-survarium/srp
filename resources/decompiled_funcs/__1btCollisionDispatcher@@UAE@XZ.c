void __thiscall btCollisionDispatcher::~btCollisionDispatcher(btCollisionDispatcher *this)
{
  btPersistentManifold **m_data; // eax

  this->__vftable = (btCollisionDispatcher_vtbl *)&btCollisionDispatcher::`vftable';
  this->m_defaultManifoldResult.__vftable = (btManifoldResult_vtbl *)&btDiscreteCollisionDetectorInterface::Result::`vftable';
  m_data = this->m_manifoldsPtr.m_data;
  if ( m_data )
  {
    if ( this->m_manifoldsPtr.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_manifoldsPtr.m_data = 0;
  }
  this->m_manifoldsPtr.m_data = 0;
  this->m_manifoldsPtr.m_size = 0;
  this->m_manifoldsPtr.m_capacity = 0;
  this->m_manifoldsPtr.m_ownsMemory = 1;
  this->__vftable = (btCollisionDispatcher_vtbl *)&btDispatcher::`vftable';
}
