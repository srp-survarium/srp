void __thiscall survarium::player::stand_up(survarium::player *this)
{
  vostok::physics::bullet_character_controller **v2; // eax
  vostok::physics::bullet_character_controller *v3; // esi
  stlp_std::list<btVector3,stlp_std::allocator<btVector3> > *p_m_positions; // edi
  stlp_std::list<btVector3,stlp_std::allocator<btVector3> > *M_next; // esi
  _STLP_atomic_freelist::item *v6; // eax
  vostok::physics::bt_character_controller *physics_controller; // ecx
  vostok::physics::bullet_character_controller *m_bt_controller; // esi
  stlp_std::list<btVector3,stlp_std::allocator<btVector3> > *v9; // edi
  stlp_std::list<btVector3,stlp_std::allocator<btVector3> > *v10; // esi
  _STLP_atomic_freelist::item *v11; // eax

  v2 = *(vostok::physics::bullet_character_controller ***)((char *)&dword_10DC8 + (_DWORD)this);
  v3 = *v2;
  if ( (*v2)->m_in_crouch )
  {
    vostok::physics::bullet_character_controller::setup_crouch_state(v3, 0, (int)v3);
    p_m_positions = &v3->m_positions;
    M_next = (stlp_std::list<btVector3,stlp_std::allocator<btVector3> > *)v3->m_positions._M_impl._M_node._M_data._M_next;
    while ( M_next != p_m_positions )
    {
      v6 = (_STLP_atomic_freelist::item *)M_next;
      M_next = (stlp_std::list<btVector3,stlp_std::allocator<btVector3> > *)M_next->_M_impl._M_node._M_data._M_next;
      stlp_std::__node_alloc::_M_deallocate(v6, 0x20u);
    }
    p_m_positions->_M_impl._M_node._M_data._M_next = (stlp_std::priv::_List_node_base *)p_m_positions;
    p_m_positions->_M_impl._M_node._M_data._M_prev = (stlp_std::priv::_List_node_base *)p_m_positions;
  }
  if ( byte_10F36[(_DWORD)this] )
  {
    physics_controller = this->m_current.physics_controller;
    m_bt_controller = physics_controller->m_bt_controller;
    if ( physics_controller->m_bt_controller->m_in_crouch )
    {
      vostok::physics::bullet_character_controller::setup_crouch_state(
        physics_controller->m_bt_controller,
        0,
        (int)m_bt_controller);
      v9 = &m_bt_controller->m_positions;
      v10 = (stlp_std::list<btVector3,stlp_std::allocator<btVector3> > *)m_bt_controller->m_positions._M_impl._M_node._M_data._M_next;
      while ( v10 != v9 )
      {
        v11 = (_STLP_atomic_freelist::item *)v10;
        v10 = (stlp_std::list<btVector3,stlp_std::allocator<btVector3> > *)v10->_M_impl._M_node._M_data._M_next;
        stlp_std::__node_alloc::_M_deallocate(v11, 0x20u);
      }
      v9->_M_impl._M_node._M_data._M_next = (stlp_std::priv::_List_node_base *)v9;
      v9->_M_impl._M_node._M_data._M_prev = (stlp_std::priv::_List_node_base *)v9;
    }
  }
}
