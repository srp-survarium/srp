void __thiscall btSoftRigidDynamicsWorld::~btSoftRigidDynamicsWorld(btSoftRigidDynamicsWorld *this)
{
  btSoftBodySolver *m_softBodySolver; // eax
  btSparseSdf<3>::Cell **m_data; // eax
  btSoftBody **v4; // eax

  this->__vftable = (btSoftRigidDynamicsWorld_vtbl *)&btSoftRigidDynamicsWorld::`vftable';
  if ( this->m_ownsSolver )
  {
    ((void (__thiscall *)(btSoftBodySolver *, _DWORD))this->m_softBodySolver->~btSoftBodySolver)(
      this->m_softBodySolver,
      0);
    m_softBodySolver = this->m_softBodySolver;
    if ( m_softBodySolver )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_softBodySolver);
    }
  }
  m_data = this->m_sbi.m_sparsesdf.cells.m_data;
  if ( m_data )
  {
    if ( this->m_sbi.m_sparsesdf.cells.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_sbi.m_sparsesdf.cells.m_data = 0;
  }
  this->m_sbi.m_sparsesdf.cells.m_ownsMemory = 1;
  this->m_sbi.m_sparsesdf.cells.m_data = 0;
  this->m_sbi.m_sparsesdf.cells.m_size = 0;
  this->m_sbi.m_sparsesdf.cells.m_capacity = 0;
  v4 = this->m_softBodies.m_data;
  if ( v4 )
  {
    if ( this->m_softBodies.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v4);
    }
    this->m_softBodies.m_data = 0;
  }
  this->m_softBodies.m_data = 0;
  this->m_softBodies.m_size = 0;
  this->m_softBodies.m_capacity = 0;
  this->m_softBodies.m_ownsMemory = 1;
  btDiscreteDynamicsWorld::~btDiscreteDynamicsWorld(this);
}
