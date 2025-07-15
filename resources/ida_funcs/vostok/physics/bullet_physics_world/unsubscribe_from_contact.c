void __thiscall vostok::physics::bullet_physics_world::unsubscribe_from_contact(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::base_physics_object *object,
        boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *callback)
{
  stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> > > *p_m_contact_callbacks; // esi
  stlp_std::priv::_Rb_tree_node_base *M_node; // eax
  stlp_std::priv::_Rb_tree_node_base *v5; // edi
  stlp_std::priv::_Rb_tree_node_base *v6; // ebx
  _STLP_atomic_freelist::item *v7; // eax
  vostok::physics::base_physics_object *const *v8; // [esp+0h] [ebp-18h]
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> > >,stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> > > > ret; // [esp+10h] [ebp-8h] BYREF

  p_m_contact_callbacks = &this->m_contact_callbacks;
  stlp_std::priv::_Rb_tree<vostok::physics::base_physics_object *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>>>::equal_range<vostok::physics::base_physics_object *>(
    (stlp_std::priv::_Rb_tree<vostok::physics::base_physics_object *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> >,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> >,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> > > *)this,
    &ret,
    &this->m_contact_callbacks._M_t._M_header._M_data,
    &object,
    v8);
  M_node = ret.first._M_node;
  v5 = ret.second._M_node;
  v6 = (stlp_std::priv::_Rb_tree_node_base *)p_m_contact_callbacks;
  if ( ret.first._M_node != ret.second._M_node )
  {
    while ( (boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *)M_node[1]._M_parent != callback )
    {
      M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(M_node);
      if ( M_node == v5 )
        goto LABEL_6;
    }
    v6 = M_node;
  }
LABEL_6:
  v7 = (_STLP_atomic_freelist::item *)stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                                        v6,
                                        &p_m_contact_callbacks->_M_t._M_header._M_data._M_parent,
                                        &p_m_contact_callbacks->_M_t._M_header._M_data._M_left,
                                        &p_m_contact_callbacks->_M_t._M_header._M_data._M_right);
  if ( v7 )
    stlp_std::__node_alloc::_M_deallocate(v7, 0x18u);
  --p_m_contact_callbacks->_M_t._M_node_count;
}
