unsigned int __thiscall vostok::ai::planning::specified_problem::get_object_index(
        vostok::ai::planning::specified_problem *this,
        unsigned int type,
        const void *const *instance)
{
  stlp_std::priv::_Rb_tree_node_base *v5; // [esp+10h] [ebp-20h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v6; // [esp+1Ch] [ebp-14h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v7; // [esp+20h] [ebp-10h] BYREF
  unsigned int i; // [esp+24h] [ebp-Ch]
  unsigned int current_count; // [esp+28h] [ebp-8h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,vostok::fixed_vector<vostok::ai::planning::object_instance,16> >,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const ,vostok::fixed_vector<vostok::ai::planning::object_instance,16> > > > iter; // [esp+2Ch] [ebp-4h] BYREF

  v6 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>>::_M_find<unsigned int>(
                                                                     (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *)&this->m_objects,
                                                                     &type);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v6,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)&this->m_objects,
    &v7);
  if ( (boost::_bi::list1<vostok::network_core::packet_reader &> *)iter._M_node != v7 )
  {
    current_count = ((char *)iter._M_node[1]._M_left - (char *)iter._M_node[1]._M_parent) / 276;
    for ( i = 0; i < current_count; ++i )
    {
      v5 = iter._M_node + 1;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&iter._M_node[1]);
      if ( (const void *const)*((_DWORD *)&v5->_M_parent->_M_parent + 69 * i) == *instance )
        return i;
    }
  }
  return -1;
}
