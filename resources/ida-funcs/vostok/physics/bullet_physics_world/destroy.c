void __thiscall vostok::physics::bullet_physics_world::destroy(vostok::physics::bullet_physics_world *this)
{
  btOverlappingPairCache *v2; // eax
  vostok::memory::base_allocator *m_allocator; // edi
  _BYTE *v4; // ebp
  vostok::memory::base_allocator *v5; // edi
  _BYTE *v6; // ebp
  vostok::memory::base_allocator *v7; // edi
  _BYTE *v8; // ebp
  vostok::memory::base_allocator *v9; // edi
  _BYTE *v10; // ebp
  vostok::memory::base_allocator *v11; // edi
  _BYTE *v12; // ebp
  vostok::memory::base_allocator *v13; // edi
  _BYTE *v14; // ebp

  v2 = this->m_dynamicsWorld->m_broadphasePairCache->getOverlappingPairCache(this->m_dynamicsWorld->m_broadphasePairCache);
  v2->setInternalGhostPairCallback(v2, 0);
  m_allocator = this->m_allocator;
  if ( this->m_ghost_pair_callback )
  {
    v4 = __RTCastToVoid((void **)&this->m_ghost_pair_callback->__vftable);
    ((void (__thiscall *)(btGhostPairCallback *, _DWORD))this->m_ghost_pair_callback->~btGhostPairCallback)(
      this->m_ghost_pair_callback,
      0);
    m_allocator->call_free(m_allocator, v4);
    this->m_ghost_pair_callback = 0;
  }
  v5 = this->m_allocator;
  if ( this->m_dynamicsWorld )
  {
    v6 = __RTCastToVoid((void **)&this->m_dynamicsWorld->__vftable);
    ((void (__thiscall *)(btSoftRigidDynamicsWorld *, _DWORD))this->m_dynamicsWorld->~btSoftRigidDynamicsWorld)(
      this->m_dynamicsWorld,
      0);
    v5->call_free(v5, v6);
    this->m_dynamicsWorld = 0;
  }
  v7 = this->m_allocator;
  if ( this->m_constraintSolver )
  {
    v8 = __RTCastToVoid((void **)&this->m_constraintSolver->__vftable);
    ((void (__thiscall *)(btConstraintSolver *, _DWORD))this->m_constraintSolver->~btConstraintSolver)(
      this->m_constraintSolver,
      0);
    v7->call_free(v7, v8);
    this->m_constraintSolver = 0;
  }
  v9 = this->m_allocator;
  if ( this->m_overlappingPairCache )
  {
    v10 = __RTCastToVoid((void **)&this->m_overlappingPairCache->__vftable);
    ((void (__thiscall *)(btBroadphaseInterface *, _DWORD))this->m_overlappingPairCache->~btBroadphaseInterface)(
      this->m_overlappingPairCache,
      0);
    v9->call_free(v9, v10);
    this->m_overlappingPairCache = 0;
  }
  v11 = this->m_allocator;
  if ( this->m_dispatcher )
  {
    v12 = __RTCastToVoid((void **)&this->m_dispatcher->__vftable);
    ((void (__thiscall *)(btCollisionDispatcher *, _DWORD))this->m_dispatcher->~btCollisionDispatcher)(
      this->m_dispatcher,
      0);
    v11->call_free(v11, v12);
    this->m_dispatcher = 0;
  }
  v13 = this->m_allocator;
  if ( this->m_collisionConfiguration )
  {
    v14 = __RTCastToVoid((void **)&this->m_collisionConfiguration->__vftable);
    ((void (__thiscall *)(btCollisionConfiguration *, _DWORD))this->m_collisionConfiguration->~btCollisionConfiguration)(
      this->m_collisionConfiguration,
      0);
    v13->call_free(v13, v14);
    this->m_collisionConfiguration = 0;
  }
  vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,btSoftBodyWorldInfo,vostok::memory::detail::call_destructor_predicate>(
    this->m_allocator,
    &this->m_softBodyWorldInfo);
  this->m_last_frame_time = 0.0;
  this->m_last_frame_delta = 0.0;
}
