void __thiscall vostok::ai::planning::oracle_holder::~oracle_holder(vostok::ai::planning::oracle_holder *this)
{
  stlp_std::priv::_Rb_tree_node_base *_M_node; // [esp+4h] [ebp-Ch]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v3[2]; // [esp+8h] [ebp-8h] BYREF

  while ( this->m_objects._M_t._M_node_count )
  {
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)this,
      v3);
    v3[1] = v3[0];
    _M_node = stlp_std::priv::_Rb_global<bool>::_M_decrement((stlp_std::priv::_Rb_tree_node_base *)v3[0]);
    vostok::ai::planning::oracle_holder::remove_impl(this, (const unsigned int *)&_M_node[1], 0);
  }
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::oracle *>>>::clear((stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_objects._M_t._M_key_compare);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
