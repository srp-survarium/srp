void __thiscall btSimulationIslandManager::~btSimulationIslandManager(btSimulationIslandManager *this)
{
  btCollisionObject **m_data; // eax
  btPersistentManifold **v3; // eax
  btElement *v4; // eax

  this->__vftable = (btSimulationIslandManager_vtbl *)&btSimulationIslandManager::`vftable';
  m_data = this->m_islandBodies.m_data;
  if ( m_data )
  {
    if ( this->m_islandBodies.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_islandBodies.m_data = 0;
  }
  this->m_islandBodies.m_ownsMemory = 1;
  this->m_islandBodies.m_data = 0;
  this->m_islandBodies.m_size = 0;
  this->m_islandBodies.m_capacity = 0;
  v3 = this->m_islandmanifold.m_data;
  if ( v3 )
  {
    if ( this->m_islandmanifold.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v3);
    }
    this->m_islandmanifold.m_data = 0;
  }
  this->m_islandmanifold.m_ownsMemory = 1;
  this->m_islandmanifold.m_data = 0;
  this->m_islandmanifold.m_size = 0;
  this->m_islandmanifold.m_capacity = 0;
  v4 = this->m_unionFind.m_elements.m_data;
  if ( v4 )
  {
    if ( this->m_unionFind.m_elements.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v4);
    }
    this->m_unionFind.m_elements.m_data = 0;
  }
  this->m_unionFind.m_elements.m_data = 0;
  this->m_unionFind.m_elements.m_size = 0;
  this->m_unionFind.m_elements.m_capacity = 0;
  this->m_unionFind.m_elements.m_ownsMemory = 1;
}
