void __thiscall vostok::physics::bullet_physics_world::destroy(vostok::physics::bullet_physics_world *this)
{
  btOverlappingPairCache *v2; // eax
  btAlignedObjectArray<GrahamVector2> *v3; // ecx
  btSoftBodyWorldInfo *m_softBodyWorldInfo; // eax
  vostok::memory::base_allocator *m_allocator; // [esp+7Ch] [ebp-8h]
  _BYTE *v6; // [esp+7Ch] [ebp-8h]
  _BYTE *v7; // [esp+7Ch] [ebp-8h]
  _BYTE *v8; // [esp+7Ch] [ebp-8h]
  _BYTE *v9; // [esp+7Ch] [ebp-8h]
  _BYTE *v10; // [esp+7Ch] [ebp-8h]
  btSoftBodyWorldInfo *v11; // [esp+7Ch] [ebp-8h]
  _BYTE *v12; // [esp+80h] [ebp-4h]
  vostok::memory::base_allocator *v13; // [esp+80h] [ebp-4h]
  vostok::memory::base_allocator *v14; // [esp+80h] [ebp-4h]
  vostok::memory::base_allocator *v15; // [esp+80h] [ebp-4h]
  vostok::memory::base_allocator *v16; // [esp+80h] [ebp-4h]
  vostok::memory::base_allocator *v17; // [esp+80h] [ebp-4h]
  vostok::memory::base_allocator *v18; // [esp+80h] [ebp-4h]

  v2 = this->m_dynamicsWorld->m_broadphasePairCache->getOverlappingPairCache(this->m_dynamicsWorld->m_broadphasePairCache);
  v2->setInternalGhostPairCallback(v2, 0);
  m_allocator = this->m_allocator;
  if ( this->m_ghost_pair_callback )
  {
    v12 = __RTCastToVoid((void **)&this->m_ghost_pair_callback->__vftable);
    ((void (__thiscall *)(btGhostPairCallback *, _DWORD))this->m_ghost_pair_callback->~btGhostPairCallback)(
      this->m_ghost_pair_callback,
      0);
    m_allocator->call_free(
      m_allocator,
      v12,
      "vostok::physics::bullet_physics_world::destroy",
      ".\\bullet_physics_world.cpp",
      182u);
    this->m_ghost_pair_callback = 0;
  }
  v13 = this->m_allocator;
  if ( this->m_dynamicsWorld )
  {
    v6 = __RTCastToVoid((void **)&this->m_dynamicsWorld->__vftable);
    ((void (__thiscall *)(btSoftRigidDynamicsWorld *, _DWORD))this->m_dynamicsWorld->~btSoftRigidDynamicsWorld)(
      this->m_dynamicsWorld,
      0);
    v13->call_free(v13, v6, "vostok::physics::bullet_physics_world::destroy", ".\\bullet_physics_world.cpp", 183u);
    this->m_dynamicsWorld = 0;
  }
  v14 = this->m_allocator;
  if ( this->m_constraintSolver )
  {
    v7 = __RTCastToVoid((void **)&this->m_constraintSolver->__vftable);
    ((void (__thiscall *)(btConstraintSolver *, _DWORD))this->m_constraintSolver->~btConstraintSolver)(
      this->m_constraintSolver,
      0);
    v14->call_free(v14, v7, "vostok::physics::bullet_physics_world::destroy", ".\\bullet_physics_world.cpp", 184u);
    this->m_constraintSolver = 0;
  }
  v15 = this->m_allocator;
  if ( this->m_overlappingPairCache )
  {
    v8 = __RTCastToVoid((void **)&this->m_overlappingPairCache->__vftable);
    ((void (__thiscall *)(btBroadphaseInterface *, _DWORD))this->m_overlappingPairCache->~btBroadphaseInterface)(
      this->m_overlappingPairCache,
      0);
    v15->call_free(v15, v8, "vostok::physics::bullet_physics_world::destroy", ".\\bullet_physics_world.cpp", 185u);
    this->m_overlappingPairCache = 0;
  }
  v16 = this->m_allocator;
  if ( this->m_dispatcher )
  {
    v9 = __RTCastToVoid((void **)&this->m_dispatcher->__vftable);
    ((void (__thiscall *)(btCollisionDispatcher *, _DWORD))this->m_dispatcher->~btCollisionDispatcher)(
      this->m_dispatcher,
      0);
    v16->call_free(v16, v9, "vostok::physics::bullet_physics_world::destroy", ".\\bullet_physics_world.cpp", 186u);
    this->m_dispatcher = 0;
  }
  v17 = this->m_allocator;
  if ( this->m_collisionConfiguration )
  {
    v10 = __RTCastToVoid((void **)&this->m_collisionConfiguration->__vftable);
    ((void (__thiscall *)(btCollisionConfiguration *, _DWORD))this->m_collisionConfiguration->~btCollisionConfiguration)(
      this->m_collisionConfiguration,
      0);
    v17->call_free(v17, v10, "vostok::physics::bullet_physics_world::destroy", ".\\bullet_physics_world.cpp", 187u);
    this->m_collisionConfiguration = 0;
  }
  v18 = this->m_allocator;
  m_softBodyWorldInfo = this->m_softBodyWorldInfo;
  v11 = m_softBodyWorldInfo;
  if ( m_softBodyWorldInfo )
  {
    btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
      v3,
      (int)&m_softBodyWorldInfo->m_sparsesdf);
    v18->call_free(v18, v11, "vostok::physics::bullet_physics_world::destroy", ".\\bullet_physics_world.cpp", 188u);
    this->m_softBodyWorldInfo = 0;
  }
}
