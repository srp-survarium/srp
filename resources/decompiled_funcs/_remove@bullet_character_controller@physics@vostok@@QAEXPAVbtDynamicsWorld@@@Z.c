void __thiscall vostok::physics::bullet_character_controller::remove(
        vostok::physics::bullet_character_controller *this,
        vostok::physics::bullet_character_controller *world)
{
  void (__cdecl *M_next)(btDynamicsWorld *, float); // edi
  stlp_std::list<btVector3,stlp_std::allocator<btVector3> > *p_m_positions; // esi
  _STLP_atomic_freelist::item *v4; // eax
  float v5; // esi
  void *v6; // eax
  int v7; // esi

  world->m_collision_world->removeAction(world->m_collision_world, world);
  world->m_collision_world->removeCollisionObject(world->m_collision_world, world->m_ghost_object);
  M_next = (void (__cdecl *)(btDynamicsWorld *, float))world->m_positions._M_impl._M_node._M_data._M_next;
  p_m_positions = &world->m_positions;
  while ( (char *)M_next != (char *)p_m_positions )
  {
    v4 = (_STLP_atomic_freelist::item *)M_next;
    M_next = *(void (__cdecl **)(btDynamicsWorld *, float))M_next;
    stlp_std::__node_alloc::_M_deallocate(v4, 0x20u);
  }
  p_m_positions->_M_impl._M_node._M_data._M_next = (stlp_std::priv::_List_node_base *)p_m_positions;
  world->m_positions._M_impl._M_node._M_data._M_prev = &world->m_positions._M_impl._M_node._M_data;
  v5 = *(float *)&world->m_ghost_object;
  v6 = *(void **)(LODWORD(v5) + 284);
  v7 = LODWORD(v5) + 272;
  if ( v6 )
  {
    if ( *(_BYTE *)(v7 + 16) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v6);
    }
    *(_DWORD *)(v7 + 12) = 0;
  }
  *(_DWORD *)(v7 + 12) = 0;
  *(_DWORD *)(v7 + 4) = 0;
  *(_DWORD *)(v7 + 8) = 0;
  *(_BYTE *)(v7 + 16) = 1;
  world->m_collision_world = 0;
}
