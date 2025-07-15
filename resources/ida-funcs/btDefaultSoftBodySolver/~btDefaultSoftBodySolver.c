void __thiscall btDefaultSoftBodySolver::~btDefaultSoftBodySolver(btDefaultSoftBodySolver *this)
{
  this->__vftable = (btDefaultSoftBodySolver_vtbl *)&btDefaultSoftBodySolver::`vftable';
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&this->m_softBodySet);
  this->__vftable = (btDefaultSoftBodySolver_vtbl *)&btSoftBodySolver::`vftable';
}
