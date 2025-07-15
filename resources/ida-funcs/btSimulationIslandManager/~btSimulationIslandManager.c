void __thiscall btSimulationIslandManager::~btSimulationIslandManager(btSimulationIslandManager *this)
{
  btAlignedObjectArray<GrahamVector2> *v2; // ecx
  btUnionFind *v3; // ecx

  this->__vftable = (btSimulationIslandManager_vtbl *)&btSimulationIslandManager::`vftable';
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&this->m_islandBodies);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v2, (int)&this->m_islandmanifold);
  btUnionFind::~btUnionFind(v3, (int)&this->m_unionFind);
}
