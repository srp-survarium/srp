void __thiscall vostok::physics::bullet_physics_world::initialize(vostok::physics::bullet_physics_world *this)
{
  vostok::memory::base_allocator *m_allocator; // esi
  char *v3; // eax
  btSoftBodyWorldInfo *v4; // eax
  btSoftBodyWorldInfo *v5; // ecx
  btSoftBodyWorldInfo *v6; // eax
  btSoftBodyWorldInfo *m_softBodyWorldInfo; // edi
  vostok::memory::base_allocator *v8; // esi
  btVector3 *p_m_gravity; // eax
  char *v10; // eax
  btSoftBodyRigidBodyCollisionConfiguration *v11; // eax
  btSoftBodyRigidBodyCollisionConfiguration *v12; // eax
  vostok::memory::base_allocator *v13; // esi
  char *v14; // eax
  btCollisionDispatcher *v15; // esi
  btCollisionDispatcher *v16; // eax
  btCollisionDispatcher *v17; // esi
  bool v18; // zf
  btCollisionAlgorithmCreateFunc **v19; // esi
  int v20; // ecx
  vostok::memory::base_allocator *v21; // esi
  char *v22; // eax
  btAxisSweep3Internal<unsigned short> *v23; // eax
  btBroadphaseInterface *v24; // eax
  btSoftBodyWorldInfo *v25; // ecx
  char *v26; // eax
  btSequentialImpulseConstraintSolver *v27; // eax
  btSequentialImpulseConstraintSolver *v28; // ecx
  btSequentialImpulseConstraintSolver *v29; // eax
  char *v30; // eax
  btSoftRigidDynamicsWorld *v31; // eax
  btSoftRigidDynamicsWorld *v32; // eax
  btSoftRigidDynamicsWorld *m_dynamicsWorld; // ecx
  btSoftBodyWorldInfo *v34; // eax
  btSparseSdf<3> *v35; // ecx
  btSparseSdf<3> *v36; // ecx
  vostok::memory::base_allocator *v37; // esi
  char *v38; // eax
  btGhostPairCallback *v39; // eax
  int v40; // eax
  btSoftBodySolver *v41; // [esp+58h] [ebp-50h]
  unsigned __int16 v42; // [esp+5Ch] [ebp-4Ch]
  btOverlappingPairCache *v43; // [esp+60h] [ebp-48h]
  btBroadphaseInterface *disableRaycastAccelerator; // [esp+64h] [ebp-44h]
  vostok::memory::base_allocator *disableRaycastAcceleratora; // [esp+64h] [ebp-44h]
  vostok::memory::base_allocator *disableRaycastAcceleratorb; // [esp+64h] [ebp-44h]
  btDefaultCollisionConstructionInfo constructionInfo; // [esp+68h] [ebp-40h] BYREF
  btVector3 handleMask; // [esp+88h] [ebp-20h] BYREF
  btVector3 worldAabbMax; // [esp+98h] [ebp-10h] BYREF

  sAllocFunc = bullet_alloc;
  if ( !bullet_alloc )
    sAllocFunc = _malloc_crt;
  sFreeFunc = bullet_free;
  if ( !bullet_free )
    sFreeFunc = btFreeDefault;
  m_allocator = this->m_allocator;
  worldAabbMax.mVec128.m128_f32[0] = FLOAT_N1000_0;
  worldAabbMax.mVec128.m128_f32[1] = FLOAT_N1000_0;
  worldAabbMax.mVec128.m128_u64[1] = LODWORD(FLOAT_N1000_0);
  handleMask.mVec128.m128_f32[0] = FLOAT_1000_0;
  handleMask.mVec128.m128_f32[1] = FLOAT_1000_0;
  handleMask.mVec128.m128_u64[1] = LODWORD(FLOAT_1000_0);
  v3 = type_info::raw_name(&btSoftBodyWorldInfo `RTTI Type Descriptor');
  v4 = (btSoftBodyWorldInfo *)m_allocator->call_malloc(
                                m_allocator,
                                112u,
                                v3,
                                "vostok::physics::bullet_physics_world::initialize",
                                ".\\bullet_physics_world.cpp",
                                141u);
  if ( v4 )
    v6 = btSoftBodyWorldInfo::btSoftBodyWorldInfo(v5, v4);
  else
    v6 = 0;
  v6->air_density = FLOAT_1_2;
  this->m_softBodyWorldInfo = v6;
  v6->water_density = 0.0;
  this->m_softBodyWorldInfo->water_offset = 0.0;
  m_softBodyWorldInfo = this->m_softBodyWorldInfo;
  memset(&constructionInfo, 0, 16);
  m_softBodyWorldInfo = (btSoftBodyWorldInfo *)((char *)m_softBodyWorldInfo + 16);
  m_softBodyWorldInfo->air_density = 0.0;
  m_softBodyWorldInfo = (btSoftBodyWorldInfo *)((char *)m_softBodyWorldInfo + 4);
  LODWORD(m_softBodyWorldInfo->air_density) = constructionInfo.m_persistentManifoldPool;
  m_softBodyWorldInfo = (btSoftBodyWorldInfo *)((char *)m_softBodyWorldInfo + 4);
  LODWORD(m_softBodyWorldInfo->air_density) = constructionInfo.m_collisionAlgorithmPool;
  LODWORD(m_softBodyWorldInfo->water_density) = constructionInfo.m_defaultMaxPersistentManifoldPoolSize;
  v8 = this->m_allocator;
  p_m_gravity = &this->m_softBodyWorldInfo->m_gravity;
  p_m_gravity->mVec128.m128_i32[0] = 0;
  p_m_gravity->mVec128.m128_f32[1] = FLOAT_N10_0;
  p_m_gravity->mVec128.m128_i32[2] = 0;
  p_m_gravity->mVec128.m128_i32[3] = 0;
  v10 = type_info::raw_name(&btSoftBodyRigidBodyCollisionConfiguration `RTTI Type Descriptor');
  v11 = (btSoftBodyRigidBodyCollisionConfiguration *)v8->call_malloc(
                                                       v8,
                                                       108u,
                                                       v10,
                                                       "vostok::physics::bullet_physics_world::initialize",
                                                       ".\\bullet_physics_world.cpp",
                                                       149u);
  if ( v11 )
  {
    constructionInfo.m_defaultMaxPersistentManifoldPoolSize = 4096;
    constructionInfo.m_defaultMaxCollisionAlgorithmPoolSize = 4096;
    memset(&constructionInfo, 0, 12);
    constructionInfo.m_customCollisionAlgorithmMaxElementSize = 0;
    constructionInfo.m_defaultStackAllocatorSize = 0;
    constructionInfo.m_useEpaPenetrationAlgorithm = 1;
    v12 = btSoftBodyRigidBodyCollisionConfiguration::btSoftBodyRigidBodyCollisionConfiguration(
            (btSoftBodyRigidBodyCollisionConfiguration *)&constructionInfo,
            v11,
            &constructionInfo);
  }
  else
  {
    v12 = 0;
  }
  v13 = this->m_allocator;
  this->m_collisionConfiguration = v12;
  v14 = type_info::raw_name(&btCollisionDispatcher `RTTI Type Descriptor');
  v15 = (btCollisionDispatcher *)v13->call_malloc(
                                   v13,
                                   5408u,
                                   v14,
                                   "vostok::physics::bullet_physics_world::initialize",
                                   ".\\bullet_physics_world.cpp",
                                   150u);
  if ( v15 )
  {
    btCollisionDispatcher::btCollisionDispatcher(v15, this->m_collisionConfiguration);
    v17 = v16;
  }
  else
  {
    v17 = 0;
  }
  v18 = (_S1_7 & 1) == 0;
  this->m_dispatcher = v17;
  if ( v18 )
  {
    _S1_7 |= 1u;
    byte_47EA3AC = 0;
    dword_47EA3A8 = (int)&btGImpactCollisionAlgorithm::CreateFunc::`vftable';
    atexit((int (__cdecl *)())btGImpactCollisionAlgorithm::registerAlgorithm_::_2_::_dynamic_atexit_destructor_for__s_gimpact_cf__);
  }
  memset32(v17->m_doubleDispatch[25], (int)&dword_47EA3A8, 0x24u);
  v19 = &v17->m_doubleDispatch[0][25];
  v20 = 36;
  do
  {
    *v19 = (btCollisionAlgorithmCreateFunc *)&dword_47EA3A8;
    v19 += 36;
    --v20;
  }
  while ( v20 );
  this->m_softBodyWorldInfo->m_dispatcher = this->m_dispatcher;
  v21 = this->m_allocator;
  v22 = type_info::raw_name(&btAxisSweep3 `RTTI Type Descriptor');
  v23 = (btAxisSweep3Internal<unsigned short> *)v21->call_malloc(
                                                  v21,
                                                  128u,
                                                  v22,
                                                  "vostok::physics::bullet_physics_world::initialize",
                                                  ".\\bullet_physics_world.cpp",
                                                  154u);
  if ( v23 )
  {
    btAxisSweep3Internal<unsigned short>::btAxisSweep3Internal<unsigned short>(
      (btAxisSweep3Internal<unsigned short> *)&worldAabbMax,
      v23,
      &worldAabbMax,
      &handleMask,
      (unsigned __int16)v41,
      v42,
      v43,
      (bool)v23);
    v24 = disableRaycastAccelerator;
    disableRaycastAccelerator->__vftable = (btBroadphaseInterface_vtbl *)&btAxisSweep3::`vftable';
  }
  else
  {
    v24 = 0;
  }
  v25 = this->m_softBodyWorldInfo;
  this->m_overlappingPairCache = v24;
  v25->m_broadphase = v24;
  disableRaycastAcceleratora = this->m_allocator;
  v26 = type_info::raw_name(&btSequentialImpulseConstraintSolver `RTTI Type Descriptor');
  v27 = (btSequentialImpulseConstraintSolver *)disableRaycastAcceleratora->call_malloc(
                                                 disableRaycastAcceleratora,
                                                 128u,
                                                 v26,
                                                 "vostok::physics::bullet_physics_world::initialize",
                                                 ".\\bullet_physics_world.cpp",
                                                 157u);
  if ( v27 )
    v29 = btSequentialImpulseConstraintSolver::btSequentialImpulseConstraintSolver(v28, v27);
  else
    v29 = 0;
  this->m_constraintSolver = v29;
  disableRaycastAcceleratorb = this->m_allocator;
  v30 = type_info::raw_name(&btSoftRigidDynamicsWorld `RTTI Type Descriptor');
  v31 = (btSoftRigidDynamicsWorld *)disableRaycastAcceleratorb->call_malloc(
                                      disableRaycastAcceleratorb,
                                      432u,
                                      v30,
                                      "vostok::physics::bullet_physics_world::initialize",
                                      ".\\bullet_physics_world.cpp",
                                      158u);
  if ( v31 )
    btSoftRigidDynamicsWorld::btSoftRigidDynamicsWorld(
      v31,
      this->m_dispatcher,
      this->m_overlappingPairCache,
      this->m_constraintSolver,
      v41);
  else
    v32 = 0;
  this->m_dynamicsWorld = v32;
  v32->m_dispatchInfo.m_enableSPU = 0;
  m_dynamicsWorld = this->m_dynamicsWorld;
  worldAabbMax.mVec128.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)worldAabbMax.mVec128.m128_u64 + 4) = LODWORD(FLOAT_N10_0);
  worldAabbMax.mVec128.m128_i32[3] = 0;
  ((void (__thiscall *)(btSoftRigidDynamicsWorld *, btVector3 *, btSoftBodySolver *))m_dynamicsWorld->setGravity)(
    m_dynamicsWorld,
    &worldAabbMax,
    v41);
  v34 = this->m_softBodyWorldInfo;
  v34->m_gravity.mVec128.m128_i32[0] = 0;
  v34->m_gravity.mVec128.m128_f32[1] = FLOAT_N10_0;
  v34->m_gravity.mVec128.m128_i32[2] = 0;
  v34->m_gravity.mVec128.m128_i32[3] = 0;
  btSparseSdf<3>::Initialize(v35, (int)&v34->m_sparsesdf);
  btSparseSdf<3>::Reset(v36, (int)&this->m_softBodyWorldInfo->m_sparsesdf);
  this->m_dynamicsWorld->m_solverInfo.m_numIterations = 2;
  this->m_dynamicsWorld->m_solverInfo.m_solverMode = 256;
  v37 = this->m_allocator;
  v38 = type_info::raw_name(&btGhostPairCallback `RTTI Type Descriptor');
  v39 = (btGhostPairCallback *)((int (__thiscall *)(vostok::memory::base_allocator *, int, char *, const char *, const char *))v37->call_malloc)(
                                 v37,
                                 4,
                                 v38,
                                 "vostok::physics::bullet_physics_world::initialize",
                                 ".\\bullet_physics_world.cpp");
  if ( v39 )
    v39->__vftable = (btGhostPairCallback_vtbl *)&btGhostPairCallback::`vftable';
  else
    v39 = 0;
  this->m_ghost_pair_callback = v39;
  v40 = ((int (__thiscall *)(btBroadphaseInterface *, int))this->m_dynamicsWorld->m_broadphasePairCache->getOverlappingPairCache)(
          this->m_dynamicsWorld->m_broadphasePairCache,
          172);
  (*(void (__thiscall **)(int, btGhostPairCallback *))(*(_DWORD *)v40 + 56))(v40, this->m_ghost_pair_callback);
  physics_log_fn = vostok::physics::log_cb;
}
