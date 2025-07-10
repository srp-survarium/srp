btSimulationIslandManager::IslandCallback *__thiscall btSimulationIslandManager::IslandCallback::`scalar deleting destructor'(
        btSimulationIslandManager::IslandCallback *this,
        char a2)
{
  this->__vftable = (btSimulationIslandManager::IslandCallback_vtbl *)&btSimulationIslandManager::IslandCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
