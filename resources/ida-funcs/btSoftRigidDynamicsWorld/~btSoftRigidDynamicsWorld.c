void __thiscall btSoftRigidDynamicsWorld::~btSoftRigidDynamicsWorld(btSoftRigidDynamicsWorld *this)
{
  btSoftRigidDynamicsWorld *v1; // edi
  bool v2; // zf
  void **p_m_softBodySolver; // esi
  btAlignedObjectArray<GrahamVector2> *v4; // ecx
  btSoftRigidDynamicsWorld *v5; // [esp-4h] [ebp-Ch]

  v1 = this;
  v2 = !this->m_ownsSolver;
  this->__vftable = (btSoftRigidDynamicsWorld_vtbl *)&btSoftRigidDynamicsWorld::`vftable';
  if ( !v2 )
  {
    p_m_softBodySolver = (void **)&this->m_softBodySolver;
    ((void (__thiscall *)(btSoftBodySolver *, _DWORD))this->m_softBodySolver->~btSoftBodySolver)(
      this->m_softBodySolver,
      0);
    btAlignedFreeInternal(*p_m_softBodySolver);
    this = v5;
  }
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&v1->m_sbi.m_sparsesdf);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v4, (int)&v1->m_softBodies);
  btDiscreteDynamicsWorld::~btDiscreteDynamicsWorld(v1);
}
