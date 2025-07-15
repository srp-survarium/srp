btSimulationIslandManager *__thiscall btSimulationIslandManager::`vector deleting destructor'(
        btSimulationIslandManager *this,
        char a2)
{
  btSimulationIslandManager::~btSimulationIslandManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
