void __usercall vostok::physics::bullet_character_controller::insert(
        vostok::physics::bullet_character_controller *this@<ecx>,
        btDynamicsWorld *world@<eax>)
{
  stlp_std::list<btVector3,stlp_std::allocator<btVector3> > *p_m_positions; // edi
  stlp_std::priv::_List_node_base *M_next; // esi
  _STLP_atomic_freelist::item *v5; // eax

  this->m_collision_world = world;
  vostok::physics::bullet_character_controller::setup_crouch_state(this, 0, (int)this);
  this->m_collision_world->addCollisionObject(
    this->m_collision_world,
    this->m_ghost_object,
    this->m_collision_filter_group,
    this->m_collision_filter_mask);
  this->m_collision_world->addAction(this->m_collision_world, this);
  p_m_positions = &this->m_positions;
  M_next = this->m_positions._M_impl._M_node._M_data._M_next;
  while ( M_next != (stlp_std::priv::_List_node_base *)p_m_positions )
  {
    v5 = (_STLP_atomic_freelist::item *)M_next;
    M_next = M_next->_M_next;
    stlp_std::__node_alloc::_M_deallocate(v5, 0x20u);
  }
  p_m_positions->_M_impl._M_node._M_data._M_prev = (stlp_std::priv::_List_node_base *)p_m_positions;
  p_m_positions->_M_impl._M_node._M_data._M_next = (stlp_std::priv::_List_node_base *)p_m_positions;
}
