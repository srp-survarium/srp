void __thiscall btSequentialImpulseConstraintSolver::~btSequentialImpulseConstraintSolver(
        btSequentialImpulseConstraintSolver *this)
{
  btAlignedObjectArray<GrahamVector2> *v2; // ecx
  btAlignedObjectArray<GrahamVector2> *v3; // ecx
  btAlignedObjectArray<GrahamVector2> *v4; // ecx
  btAlignedObjectArray<GrahamVector2> *v5; // ecx
  btAlignedObjectArray<GrahamVector2> *v6; // ecx

  this->__vftable = (btSequentialImpulseConstraintSolver_vtbl *)&btSequentialImpulseConstraintSolver::`vftable';
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&this->m_tmpConstraintSizesPool);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    v2,
    (int)&this->m_orderFrictionConstraintPool);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v3, (int)&this->m_orderTmpConstraintPool);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    v4,
    (int)&this->m_tmpSolverContactFrictionConstraintPool);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    v5,
    (int)&this->m_tmpSolverNonContactConstraintPool);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    v6,
    (int)&this->m_tmpSolverContactConstraintPool);
  this->__vftable = (btSequentialImpulseConstraintSolver_vtbl *)&btConstraintSolver::`vftable';
}
