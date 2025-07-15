btSimulationIslandManager *__usercall btSimulationIslandManager::btSimulationIslandManager@<eax>(
        btSimulationIslandManager *this@<ecx>,
        btSimulationIslandManager *result@<eax>)
{
  result->__vftable = (btSimulationIslandManager_vtbl *)&btSimulationIslandManager::`vftable';
  result->m_unionFind.m_elements.m_data = 0;
  result->m_unionFind.m_elements.m_size = 0;
  result->m_unionFind.m_elements.m_capacity = 0;
  result->m_unionFind.m_elements.m_ownsMemory = 1;
  result->m_islandmanifold.m_ownsMemory = 1;
  result->m_islandmanifold.m_data = 0;
  result->m_islandmanifold.m_size = 0;
  result->m_islandmanifold.m_capacity = 0;
  result->m_islandBodies.m_ownsMemory = 1;
  result->m_islandBodies.m_data = 0;
  result->m_islandBodies.m_size = 0;
  result->m_islandBodies.m_capacity = 0;
  result->m_splitIslands = 1;
  return result;
}
