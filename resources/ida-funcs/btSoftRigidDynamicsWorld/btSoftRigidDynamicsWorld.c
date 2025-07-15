void __userpurge btSoftRigidDynamicsWorld::btSoftRigidDynamicsWorld(
        btSoftRigidDynamicsWorld *this,
        btDispatcher *dispatcher,
        btBroadphaseInterface *pairCache,
        btConstraintSolver *constraintSolver,
        btSoftBodySolver *softBodySolver)
{
  btSoftBodyWorldInfo *v5; // ecx
  float *v6; // eax
  btSparseSdf<3> *v7; // ecx
  btSparseSdf<3> *v8; // ecx
  btSparseSdf<3> *v9; // [esp-4h] [ebp-24h]

  btDiscreteDynamicsWorld::btDiscreteDynamicsWorld(this, pairCache, constraintSolver);
  this->__vftable = (btSoftRigidDynamicsWorld_vtbl *)&btSoftRigidDynamicsWorld::`vftable';
  this->m_softBodies.m_ownsMemory = 1;
  this->m_softBodies.m_data = 0;
  this->m_softBodies.m_size = 0;
  this->m_softBodies.m_capacity = 0;
  btSoftBodyWorldInfo::btSoftBodyWorldInfo(v5, &this->m_sbi);
  this->m_softBodySolver = 0;
  this->m_ownsSolver = 0;
  v6 = (float *)btAlignedAllocInternal(0x28u);
  if ( v6 )
  {
    v6[3] = s_bm_current_air_resistance;
    v6[2] = 0.0;
    *((_DWORD *)v6 + 1) = 5;
    *(_DWORD *)v6 = &btDefaultSoftBodySolver::`vftable';
    *((_BYTE *)v6 + 36) = 1;
    v6[8] = 0.0;
    v6[6] = 0.0;
    v6[7] = 0.0;
    *((_BYTE *)v6 + 16) = 1;
  }
  else
  {
    v6 = 0;
  }
  this->m_softBodySolver = (btSoftBodySolver *)v6;
  this->m_sbi.m_broadphase = pairCache;
  this->m_sbi.m_dispatcher = dispatcher;
  this->m_ownsSolver = 1;
  this->m_drawFlags = 4302;
  this->m_drawNodeTree = 1;
  this->m_drawFaceTree = 0;
  this->m_drawClusterTree = 0;
  btSparseSdf<3>::Initialize(v9, (int)&this->m_sbi.m_sparsesdf);
  btSparseSdf<3>::Reset(v7, (int)&this->m_sbi.m_sparsesdf);
  this->m_sbi.air_density = FLOAT_1_2;
  this->m_sbi.water_normal.mVec128.m128_u64[0] = 0;
  this->m_sbi.water_normal.mVec128.m128_i32[2] = 0;
  this->m_sbi.water_density = 0.0;
  this->m_sbi.water_offset = 0.0;
  this->m_sbi.water_normal.mVec128.m128_i32[3] = 0;
  this->m_sbi.m_gravity.mVec128.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)this->m_sbi.m_gravity.mVec128.m128_u64 + 4) = LODWORD(FLOAT_N10_0);
  this->m_sbi.m_gravity.mVec128.m128_i32[3] = 0;
  btSparseSdf<3>::Initialize(v8, (int)&this->m_sbi.m_sparsesdf);
}
