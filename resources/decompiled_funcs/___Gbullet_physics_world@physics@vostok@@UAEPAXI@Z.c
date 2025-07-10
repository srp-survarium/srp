vostok::physics::bullet_physics_world *__thiscall vostok::physics::bullet_physics_world::`scalar deleting destructor'(
        vostok::physics::bullet_physics_world *this,
        char a2)
{
  stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> > > *p_m_contact_callbacks; // esi

  p_m_contact_callbacks = &this->m_contact_callbacks;
  if ( this->m_contact_callbacks._M_t._M_node_count )
  {
    stlp_std::priv::_Rb_tree<vostok::physics::base_physics_object *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>>>::_M_erase(
      &this->m_contact_callbacks._M_t,
      this->m_contact_callbacks._M_t._M_header._M_data._M_parent);
    p_m_contact_callbacks->_M_t._M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)p_m_contact_callbacks;
    p_m_contact_callbacks->_M_t._M_header._M_data._M_parent = 0;
    p_m_contact_callbacks->_M_t._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)p_m_contact_callbacks;
    p_m_contact_callbacks->_M_t._M_node_count = 0;
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
