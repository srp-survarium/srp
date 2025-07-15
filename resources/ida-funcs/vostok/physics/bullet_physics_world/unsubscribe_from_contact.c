void __thiscall vostok::physics::bullet_physics_world::unsubscribe_from_contact(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::base_physics_object *object,
        boost::function<void __cdecl(vostok::physics::contact_point const &)> *callback)
{
  stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl(vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > *p_m_contact_callbacks; // esi
  stlp_std::priv::_Rb_tree_node_base *M_node; // eax
  stlp_std::priv::_Rb_tree_node_base *v5; // edi
  _STLP_atomic_freelist::item *v6; // eax
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > >,stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > > result; // [esp+8h] [ebp-8h] BYREF

  p_m_contact_callbacks = &this->m_contact_callbacks;
  stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl (vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>>>::equal_range<vostok::physics::base_physics_object *>(
    (stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl(vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > *)this,
    &this->m_contact_callbacks._M_t._M_header._M_data,
    &result,
    &object);
  M_node = result.first._M_node;
  v5 = (stlp_std::priv::_Rb_tree_node_base *)p_m_contact_callbacks;
  while ( M_node != result.second._M_node )
  {
    if ( (boost::function<void __cdecl(vostok::physics::contact_point const &)> *)M_node[1]._M_parent == callback )
    {
      v5 = M_node;
      break;
    }
    M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(M_node);
  }
  v6 = (_STLP_atomic_freelist::item *)stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                                        v5,
                                        &p_m_contact_callbacks->_M_t._M_header._M_data._M_parent,
                                        &p_m_contact_callbacks->_M_t._M_header._M_data._M_left,
                                        &p_m_contact_callbacks->_M_t._M_header._M_data._M_right);
  if ( v6 )
    stlp_std::__node_alloc::deallocate(v6, 0x18u);
  --p_m_contact_callbacks->_M_t._M_node_count;
}
