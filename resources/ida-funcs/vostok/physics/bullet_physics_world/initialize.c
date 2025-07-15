void __thiscall vostok::physics::bullet_physics_world::initialize(vostok::physics::bullet_physics_world *this)
{
  vostok::memory::base_allocator *m_allocator; // ecx
  void *(__thiscall *call_malloc)(vostok::memory::base_allocator *, unsigned int); // eax
  int v4; // eax
  btCollisionDispatcher *v5; // esi
  btVector3 *p_water_normal; // eax
  btVector3 *p_m_gravity; // eax
  btSoftBodyRigidBodyCollisionConfiguration *v8; // eax
  vostok::memory::base_allocator *v9; // ecx
  btCollisionDispatcher *v10; // ecx
  btCollisionDispatcher *v11; // eax
  btAxisSweep3Internal<unsigned short> *v12; // esi
  btSoftBodyWorldInfo *m_softBodyWorldInfo; // edx
  btSequentialImpulseConstraintSolver *v14; // eax
  btSequentialImpulseConstraintSolver *v15; // ecx
  btSequentialImpulseConstraintSolver *v16; // eax
  vostok::memory::base_allocator *v17; // ecx
  btSoftRigidDynamicsWorld *v18; // edi
  btSoftRigidDynamicsWorld *v19; // eax
  btSoftRigidDynamicsWorld *m_dynamicsWorld; // ecx
  btVector3 *v21; // eax
  btSparseSdf<3> *v22; // ecx
  btSparseSdf<3> *v23; // ecx
  btGhostPairCallback *v24; // eax
  btOverlappingPairCache *v25; // eax
  btSoftBodySolver *v26; // [esp+30h] [ebp-50h]
  unsigned __int16 v27; // [esp+34h] [ebp-4Ch]
  btOverlappingPairCache *v28; // [esp+38h] [ebp-48h]
  btDefaultCollisionConstructionInfo constructionInfo; // [esp+3Ch] [ebp-44h] BYREF
  int v30; // [esp+5Ch] [ebp-24h]
  btVector3 handleMask; // [esp+60h] [ebp-20h] BYREF
  btVector3 worldAabbMax; // [esp+70h] [ebp-10h] BYREF

  sAllocFunc = bullet_alloc;
  if ( !bullet_alloc )
    sAllocFunc = btAllocDefault;
  sFreeFunc = bullet_free;
  if ( !bullet_free )
    sFreeFunc = btFreeDefault;
  m_allocator = this->m_allocator;
  call_malloc = m_allocator->call_malloc;
  worldAabbMax.mVec128.m128_u64[0] = 0xC47A0000C47A0000uLL;
  worldAabbMax.mVec128.m128_u64[1] = 3296329728LL;
  handleMask.mVec128.m128_u64[0] = 0x447A0000447A0000LL;
  handleMask.mVec128.m128_u64[1] = 1148846080;
  v4 = (int)call_malloc(m_allocator, 112u);
  v5 = 0;
  if ( v4 )
  {
    *(_DWORD *)v4 = 1067030938;
    *(_DWORD *)(v4 + 4) = 0;
    *(_DWORD *)(v4 + 8) = 0;
    *(_DWORD *)(v4 + 16) = 0;
    *(_DWORD *)(v4 + 20) = 0;
    *(_DWORD *)(v4 + 24) = 0;
    *(_DWORD *)(v4 + 28) = 0;
    *(_DWORD *)(v4 + 32) = 0;
    *(_DWORD *)(v4 + 36) = 0;
    *(_DWORD *)(v4 + 48) = 0;
    *(_DWORD *)(v4 + 52) = -1054867456;
    *(_DWORD *)(v4 + 56) = 0;
    *(_DWORD *)(v4 + 60) = 0;
    *(_BYTE *)(v4 + 80) = 1;
    *(_DWORD *)(v4 + 76) = 0;
    *(_DWORD *)(v4 + 68) = 0;
    *(_DWORD *)(v4 + 72) = 0;
  }
  else
  {
    v4 = 0;
  }
  this->m_softBodyWorldInfo = (btSoftBodyWorldInfo *)v4;
  *(_DWORD *)v4 = 1067030938;
  this->m_softBodyWorldInfo->water_density = 0.0;
  this->m_softBodyWorldInfo->water_offset = 0.0;
  p_water_normal = &this->m_softBodyWorldInfo->water_normal;
  *(_QWORD *)&constructionInfo.m_persistentManifoldPool = 0;
  p_water_normal->mVec128.m128_u64[0] = 0;
  *(_QWORD *)&constructionInfo.m_defaultMaxPersistentManifoldPoolSize = 0;
  p_water_normal->mVec128.m128_u64[1] = 0;
  p_m_gravity = &this->m_softBodyWorldInfo->m_gravity;
  p_m_gravity->mVec128.m128_i32[0] = 0;
  p_m_gravity->mVec128.m128_i32[1] = -1054867456;
  p_m_gravity->mVec128.m128_i32[2] = 0;
  p_m_gravity->mVec128.m128_i32[3] = 0;
  if ( this->m_allocator->call_malloc(this->m_allocator, 108) )
  {
    constructionInfo.m_defaultMaxCollisionAlgorithmPoolSize = 4096;
    constructionInfo.m_customCollisionAlgorithmMaxElementSize = 4096;
    memset(&constructionInfo.m_persistentManifoldPool, 0, 12);
    constructionInfo.m_defaultStackAllocatorSize = 0;
    constructionInfo.m_useEpaPenetrationAlgorithm = 0;
    v30 = 1;
    v8 = btSoftBodyRigidBodyCollisionConfiguration::btSoftBodyRigidBodyCollisionConfiguration(
           (btSoftBodyRigidBodyCollisionConfiguration *)&constructionInfo.m_persistentManifoldPool,
           (const btDefaultCollisionConstructionInfo *)&constructionInfo.m_persistentManifoldPool);
  }
  else
  {
    v8 = 0;
  }
  v9 = this->m_allocator;
  this->m_collisionConfiguration = v8;
  v10 = (btCollisionDispatcher *)v9->call_malloc(v9, 5408u);
  if ( v10 )
  {
    btCollisionDispatcher::btCollisionDispatcher(v10, this->m_collisionConfiguration);
    v5 = v11;
  }
  this->m_dispatcher = v5;
  btGImpactCollisionAlgorithm::registerAlgorithm(v5);
  this->m_softBodyWorldInfo->m_dispatcher = this->m_dispatcher;
  v12 = (btAxisSweep3Internal<unsigned short> *)this->m_allocator->call_malloc(this->m_allocator, 128);
  if ( v12 )
  {
    btAxisSweep3Internal<unsigned short>::btAxisSweep3Internal<unsigned short>(
      (btAxisSweep3Internal<unsigned short> *)&worldAabbMax,
      v12,
      &worldAabbMax,
      &handleMask,
      (unsigned __int16)v26,
      v27,
      v28,
      (bool)constructionInfo.m_stackAlloc);
    v12->__vftable = (btAxisSweep3Internal<unsigned short>_vtbl *)&btAxisSweep3::`vftable';
  }
  else
  {
    v12 = 0;
  }
  m_softBodyWorldInfo = this->m_softBodyWorldInfo;
  this->m_overlappingPairCache = v12;
  m_softBodyWorldInfo->m_broadphase = v12;
  v14 = (btSequentialImpulseConstraintSolver *)this->m_allocator->call_malloc(this->m_allocator, 128);
  if ( v14 )
    v16 = btSequentialImpulseConstraintSolver::btSequentialImpulseConstraintSolver(v15, v14);
  else
    v16 = 0;
  v17 = this->m_allocator;
  this->m_constraintSolver = v16;
  v18 = (btSoftRigidDynamicsWorld *)v17->call_malloc(v17, 432u);
  if ( v18 )
    btSoftRigidDynamicsWorld::btSoftRigidDynamicsWorld(
      v18,
      this->m_dispatcher,
      this->m_overlappingPairCache,
      this->m_constraintSolver,
      this->m_collisionConfiguration,
      v26);
  else
    v19 = 0;
  this->m_dynamicsWorld = v19;
  v19->m_dispatchInfo.m_enableSPU = 0;
  m_dynamicsWorld = this->m_dynamicsWorld;
  worldAabbMax.mVec128.m128_u64[0] = 0xC120000000000000uLL;
  worldAabbMax.mVec128.m128_u64[1] = 0;
  m_dynamicsWorld->setGravity(m_dynamicsWorld, &worldAabbMax);
  v21 = &this->m_softBodyWorldInfo->m_gravity;
  v21->mVec128.m128_i32[0] = 0;
  v21->mVec128.m128_i32[1] = -1054867456;
  v21->mVec128.m128_i32[2] = 0;
  v21->mVec128.m128_i32[3] = 0;
  btSparseSdf<3>::Initialize(v22, (int)&this->m_softBodyWorldInfo->m_sparsesdf);
  btSparseSdf<3>::Reset(v23, &this->m_softBodyWorldInfo->m_sparsesdf);
  v24 = (btGhostPairCallback *)this->m_allocator->call_malloc(this->m_allocator, 4);
  if ( v24 )
    v24->__vftable = (btGhostPairCallback_vtbl *)&btGhostPairCallback::`vftable';
  else
    v24 = 0;
  this->m_ghost_pair_callback = v24;
  v25 = this->m_dynamicsWorld->m_broadphasePairCache->getOverlappingPairCache(this->m_dynamicsWorld->m_broadphasePairCache);
  v25->setInternalGhostPairCallback(v25, this->m_ghost_pair_callback);
  this->m_last_frame_time = 0.0;
  this->m_last_frame_delta = 0.0;
  physics_log_fn = vostok::physics::log_cb;
}
