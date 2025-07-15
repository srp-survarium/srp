void __thiscall vostok::physics::bullet_character_controller::~bullet_character_controller(
        vostok::physics::bullet_character_controller *this,
        vostok::physics::bullet_character_controller *thisa)
{
  stlp_std::list<btVector3,stlp_std::allocator<btVector3> > *p_m_positions; // edi
  stlp_std::priv::_List_node_base *M_next; // esi
  _STLP_atomic_freelist::item *v4; // eax

  p_m_positions = &thisa->m_positions;
  thisa->__vftable = (vostok::physics::bullet_character_controller_vtbl *)&vostok::physics::bullet_character_controller::`vftable';
  M_next = thisa->m_positions._M_impl._M_node._M_data._M_next;
  if ( (stlp_std::list<btVector3,stlp_std::allocator<btVector3> > *)p_m_positions->_M_impl._M_node._M_data._M_next != p_m_positions )
  {
    do
    {
      v4 = (_STLP_atomic_freelist::item *)M_next;
      M_next = M_next->_M_next;
      stlp_std::__node_alloc::_M_deallocate(v4, 0x20u);
    }
    while ( M_next != (stlp_std::priv::_List_node_base *)p_m_positions );
  }
  p_m_positions->_M_impl._M_node._M_data._M_next = (stlp_std::priv::_List_node_base *)p_m_positions;
  thisa->m_positions._M_impl._M_node._M_data._M_prev = &thisa->m_positions._M_impl._M_node._M_data;
  thisa->m_shape.__vftable = (btCapsuleShape_vtbl *)&btCollisionShape::`vftable';
  thisa->__vftable = (vostok::physics::bullet_character_controller_vtbl *)&btActionInterface::`vftable';
}
