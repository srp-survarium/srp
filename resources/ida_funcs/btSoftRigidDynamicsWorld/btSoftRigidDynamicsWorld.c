void __userpurge btSoftRigidDynamicsWorld::btSoftRigidDynamicsWorld(
        btSoftRigidDynamicsWorld *this@<edi>,
        btConstraintSolver *constraintSolver@<ecx>,
        btCollisionConfiguration *collisionConfiguration@<eax>,
        btDispatcher *dispatcher,
        btBroadphaseInterface *pairCache,
        btSoftBodySolver *softBodySolver)
{
  btSoftBodySolver *v6; // eax
  btSparseSdf<3> *v7; // ecx
  btSparseSdf<3> *v8; // ecx
  btSparseSdf<3> *v9; // ecx

  btDiscreteDynamicsWorld::btDiscreteDynamicsWorld(this, constraintSolver, collisionConfiguration);
  ++gNumAlignedAllocs;
  this->__vftable = (btSoftRigidDynamicsWorld_vtbl *)&btSoftRigidDynamicsWorld::`vftable';
  this->m_softBodies.m_ownsMemory = 1;
  this->m_softBodies.m_data = 0;
  this->m_softBodies.m_size = 0;
  this->m_softBodies.m_capacity = 0;
  this->m_sbi.air_density = 1.2;
  this->m_sbi.water_density = 0.0;
  this->m_sbi.water_offset = 0.0;
  this->m_sbi.water_normal.mVec128.m128_u64[0] = 0;
  this->m_sbi.water_normal.mVec128.m128_u64[1] = 0;
  this->m_sbi.m_broadphase = 0;
  this->m_sbi.m_dispatcher = 0;
  this->m_sbi.m_gravity.mVec128.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)this->m_sbi.m_gravity.mVec128.m128_u64 + 4) = 3240099840LL;
  this->m_sbi.m_gravity.mVec128.m128_i32[3] = 0;
  this->m_sbi.m_sparsesdf.cells.m_ownsMemory = 1;
  this->m_sbi.m_sparsesdf.cells.m_data = 0;
  this->m_sbi.m_sparsesdf.cells.m_size = 0;
  this->m_sbi.m_sparsesdf.cells.m_capacity = 0;
  this->m_softBodySolver = 0;
  this->m_ownsSolver = 0;
  v6 = (btSoftBodySolver *)sAlignedAllocFunc(0x28u, 16);
  if ( v6 )
  {
    LODWORD(v6->m_timeScale) = clear_value;
    v6->m_numberOfVelocityIterations = 0;
    v6->m_numberOfPositionIterations = 5;
    v6->__vftable = (btSoftBodySolver_vtbl *)&btDefaultSoftBodySolver::`vftable';
    LOBYTE(v6[2].m_numberOfPositionIterations) = 1;
    v6[2].__vftable = 0;
    v6[1].m_numberOfVelocityIterations = 0;
    v6[1].m_timeScale = 0.0;
    LOBYTE(v6[1].__vftable) = 1;
  }
  else
  {
    v6 = 0;
  }
  this->m_sbi.m_broadphase = pairCache;
  this->m_softBodySolver = v6;
  this->m_ownsSolver = 1;
  this->m_drawFlags = 4302;
  this->m_drawNodeTree = 1;
  this->m_drawFaceTree = 0;
  this->m_drawClusterTree = 0;
  this->m_sbi.m_dispatcher = dispatcher;
  btSparseSdf<3>::Initialize(v7, (int)&this->m_sbi.m_sparsesdf);
  btSparseSdf<3>::Reset(v8, &this->m_sbi.m_sparsesdf);
  this->m_sbi.air_density = 1.2;
  this->m_sbi.water_normal.mVec128.m128_u64[0] = 0;
  this->m_sbi.water_density = 0.0;
  this->m_sbi.water_offset = 0.0;
  this->m_sbi.water_normal.mVec128.m128_u64[1] = 0;
  this->m_sbi.m_gravity.mVec128.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)this->m_sbi.m_gravity.mVec128.m128_u64 + 4) = 3240099840LL;
  this->m_sbi.m_gravity.mVec128.m128_i32[3] = 0;
  btSparseSdf<3>::Initialize(v9, (int)&this->m_sbi.m_sparsesdf);
}
