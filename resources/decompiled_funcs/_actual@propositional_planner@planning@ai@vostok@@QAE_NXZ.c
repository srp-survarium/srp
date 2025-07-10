char __thiscall vostok::ai::planning::propositional_planner::actual(vostok::ai::planning::propositional_planner *this)
{
  survarium::game_camera *v2; // ecx
  char v3; // al
  boost::_bi::list1<vostok::network_core::packet_reader &> *v5; // [esp+8h] [ebp-2Ch]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *> > > iter_oracles; // [esp+28h] [ebp-Ch] BYREF
  const vostok::ai::planning::world_state_property *iter_end; // [esp+2Ch] [ebp-8h]
  const vostok::ai::planning::world_state_property *iter; // [esp+30h] [ebp-4h]

  if ( !this->m_actual )
    return 0;
  iter = this->m_current_state.m_properties._M_impl._M_start;
  iter_end = this->m_current_state.m_properties._M_impl._M_finish;
  while ( iter != iter_end )
  {
    v5 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>>::_M_find<unsigned int>(
                                                                       (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *)&this->m_oracles,
                                                                       &iter->m_id);
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v5,
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter_oracles);
    survarium::weapon_user_dead_state::finalize(v2);
    v3 = (*(int (__thiscall **)(stlp_std::priv::_Rb_tree_node_base *, stlp_std::priv::_Rb_tree_node_base *))(*(_DWORD *)iter_oracles._M_node[1]._M_parent + 4))(
           iter_oracles._M_node[1]._M_parent,
           iter_oracles._M_node[1]._M_parent);
    if ( v3 != iter->m_value )
      return 0;
    ++iter;
  }
  return 1;
}
