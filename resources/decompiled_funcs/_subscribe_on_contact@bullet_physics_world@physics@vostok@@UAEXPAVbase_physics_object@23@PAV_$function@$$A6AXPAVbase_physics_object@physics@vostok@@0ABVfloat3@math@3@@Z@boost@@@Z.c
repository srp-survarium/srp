void __thiscall vostok::physics::bullet_physics_world::subscribe_on_contact(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::base_physics_object *object,
        boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *callback)
{
  stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> > > *p_m_contact_callbacks; // edi
  stlp_std::priv::_Rb_tree_node_base *M_node; // eax
  stlp_std::priv::_Rb_tree_node_base *i; // esi
  stlp_std::priv::_Rb_tree_node_base *M_parent; // eax
  int v7; // ecx
  vostok::physics::base_physics_object *const *v8; // [esp+0h] [ebp-18h]
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> > >,stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> > > > ret; // [esp+8h] [ebp-10h] BYREF
  stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> __val; // [esp+10h] [ebp-8h] BYREF

  p_m_contact_callbacks = &this->m_contact_callbacks;
  stlp_std::priv::_Rb_tree<vostok::physics::base_physics_object *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>>>::equal_range<vostok::physics::base_physics_object *>(
    (stlp_std::priv::_Rb_tree<vostok::physics::base_physics_object *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> >,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> >,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *> > > *)this,
    &ret,
    &this->m_contact_callbacks._M_t._M_header._M_data,
    &object,
    v8);
  M_node = ret.first._M_node;
  for ( i = ret.second._M_node; M_node != i; M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(M_node) )
    ;
  M_parent = p_m_contact_callbacks->_M_t._M_header._M_data._M_parent;
  __val.second = callback;
  __val.first = object;
  v7 = (int)p_m_contact_callbacks;
  while ( M_parent )
  {
    v7 = (int)M_parent;
    if ( (unsigned int)object >= *(_DWORD *)&M_parent[1]._M_color )
      M_parent = M_parent->_M_right;
    else
      M_parent = M_parent->_M_left;
  }
  stlp_std::priv::_Rb_tree<vostok::physics::base_physics_object *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,vostok::math::float3 const &)> *>>>::_M_insert(
    &p_m_contact_callbacks->_M_t,
    &__val,
    &ret.first,
    v7,
    M_parent);
}
