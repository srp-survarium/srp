void __usercall `btDiscreteDynamicsWorld::solveConstraints'::`2'::InplaceSolverIslandCallback::~InplaceSolverIslandCallback(
        btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *this@<ecx>,
        _DWORD *a2@<edi>)
{
  btAlignedObjectArray<GrahamVector2> *v2; // ecx
  btAlignedObjectArray<GrahamVector2> *v3; // ecx

  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)(a2 + 18));
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v2, (int)(a2 + 13));
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v3, (int)(a2 + 8));
  *a2 = &btSimulationIslandManager::IslandCallback::`vftable';
}
