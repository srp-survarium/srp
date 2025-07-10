unsigned int __thiscall vostok::ai::planning::specified_problem::get_world_state_size(
        vostok::ai::planning::specified_problem *this)
{
  survarium::game_camera *v1; // ecx
  int count_of_objects_by_type; // eax
  boost::_bi::list1<vostok::network_core::packet_reader &> *v5; // [esp+18h] [ebp-18h] BYREF
  unsigned int j; // [esp+1Ch] [ebp-14h]
  unsigned int combinations_count; // [esp+20h] [ebp-10h]
  const vostok::ai::planning::pddl_predicate *current_predicate; // [esp+24h] [ebp-Ch]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > iter; // [esp+28h] [ebp-8h] BYREF
  unsigned int world_state_size; // [esp+2Ch] [ebp-4h]

  world_state_size = 0;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)this->m_predicates._M_t._M_header._M_data._M_left,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter);
  while ( 1 )
  {
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)this,
      &v5);
    if ( (boost::_bi::list1<vostok::network_core::packet_reader &> *)iter._M_node == v5 )
      break;
    current_predicate = (const vostok::ai::planning::pddl_predicate *)iter._M_node[1]._M_parent;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)current_predicate);
    combinations_count = 1;
    for ( j = 0; ; ++j )
    {
      v1 = (survarium::game_camera *)(current_predicate->m_parameters.m_end - current_predicate->m_parameters.m_begin);
      if ( j >= (unsigned int)v1 )
        break;
      survarium::weapon_user_dead_state::finalize(v1);
      count_of_objects_by_type = vostok::ai::planning::specified_problem::get_count_of_objects_by_type(
                                   this,
                                   current_predicate->m_parameters.m_begin[j]);
      combinations_count *= count_of_objects_by_type;
    }
    world_state_size += combinations_count;
    iter._M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(iter._M_node);
  }
  return world_state_size;
}
