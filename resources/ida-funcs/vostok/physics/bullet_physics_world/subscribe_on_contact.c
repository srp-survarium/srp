void __thiscall vostok::physics::bullet_physics_world::subscribe_on_contact(
        vostok::physics::bullet_physics_world *this,
        stlp_std::priv::_Rb_tree_node_base *object,
        stlp_std::priv::_Rb_tree_node_base *callback)
{
  stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl(vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > *p_m_contact_callbacks; // edi
  stlp_std::priv::_Rb_tree_node_base *i; // eax
  stlp_std::priv::_Rb_tree_node_base *M_parent; // eax
  stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl(vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > *v6; // ebx
  stlp_std::priv::_Rb_tree_node_base *node; // eax
  stlp_std::priv::_Rb_tree<vostok::physics::base_physics_object *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> >,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> >,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > *v8; // [esp+0h] [ebp-14h]
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > >,stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > > result; // [esp+Ch] [ebp-8h] BYREF

  result.second._M_node = 0;
  p_m_contact_callbacks = &this->m_contact_callbacks;
  stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl (vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>>>::equal_range<vostok::physics::base_physics_object *>(
    (stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl(vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > *)this,
    &this->m_contact_callbacks._M_t._M_header._M_data,
    &result,
    (vostok::physics::base_physics_object *const *)&object);
  for ( i = result.first._M_node; i != result.second._M_node; i = stlp_std::priv::_Rb_global<bool>::_M_increment(i) )
    ;
  result.second._M_node = callback;
  M_parent = p_m_contact_callbacks->_M_t._M_header._M_data._M_parent;
  result.first._M_node = object;
  v6 = p_m_contact_callbacks;
  if ( !M_parent )
    goto LABEL_10;
  do
  {
    v6 = (stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl(vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > *)M_parent;
    if ( (unsigned int)object >= *(_DWORD *)&M_parent[1]._M_color )
      M_parent = M_parent->_M_right;
    else
      M_parent = M_parent->_M_left;
  }
  while ( M_parent );
  if ( v6 == p_m_contact_callbacks )
  {
LABEL_10:
    node = stlp_std::priv::_Rb_tree<vostok::physics::base_physics_object *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>>>::_M_create_node(
             (const stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> *)&result,
             v8);
    v6->_M_t._M_header._M_data._M_left = node;
    p_m_contact_callbacks->_M_t._M_header._M_data._M_parent = node;
LABEL_15:
    p_m_contact_callbacks->_M_t._M_header._M_data._M_right = node;
    goto LABEL_16;
  }
  if ( (unsigned int)object >= v6->_M_t._M_node_count )
  {
    node = stlp_std::priv::_Rb_tree<vostok::physics::base_physics_object *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>>>::_M_create_node(
             (const stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> *)&result,
             v8);
    v6->_M_t._M_header._M_data._M_right = node;
    if ( v6 == (stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl(vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > *)p_m_contact_callbacks->_M_t._M_header._M_data._M_right )
      goto LABEL_15;
  }
  else
  {
    node = stlp_std::priv::_Rb_tree<vostok::physics::base_physics_object *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>>>::_M_create_node(
             (const stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> *)&result,
             v8);
    v6->_M_t._M_header._M_data._M_left = node;
    if ( v6 == (stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl(vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > *)p_m_contact_callbacks->_M_t._M_header._M_data._M_left )
      p_m_contact_callbacks->_M_t._M_header._M_data._M_left = node;
  }
LABEL_16:
  node->_M_parent = (stlp_std::priv::_Rb_tree_node_base *)v6;
  stlp_std::priv::_Rb_global<bool>::_Rebalance(node, &p_m_contact_callbacks->_M_t._M_header._M_data._M_parent);
  ++p_m_contact_callbacks->_M_t._M_node_count;
}
