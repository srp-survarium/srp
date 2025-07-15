void __thiscall vostok::ai::planning::propositional_planner::evaluate(
        vostok::ai::planning::propositional_planner *this,
        const vostok::ai::planning::world_state_property **iter,
        vostok::ai::planning::world_state_property **iter_end,
        unsigned int *property_id)
{
  survarium::game_camera *v4; // ecx
  const vostok::ai::planning::world_state_property *v5; // eax
  boost::_bi::list1<vostok::network_core::packet_reader &> *v7; // [esp+2Ch] [ebp-20h]
  bool value; // [esp+33h] [ebp-19h] BYREF
  vostok::ai::planning::world_state_property v9; // [esp+34h] [ebp-18h] BYREF
  char v10; // [esp+43h] [ebp-9h]
  unsigned int index; // [esp+44h] [ebp-8h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *> > > iter_oracles; // [esp+48h] [ebp-4h] BYREF

  v7 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>>::_M_find<unsigned int>(
                                                                     (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *)&this->m_oracles,
                                                                     property_id);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v7,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter_oracles);
  v10 = 0;
  survarium::weapon_user_dead_state::finalize(v4);
  index = *iter - this->m_current_state.m_properties._M_impl._M_start;
  value = (*(int (__thiscall **)(stlp_std::priv::_Rb_tree_node_base *, stlp_std::priv::_Rb_tree_node_base *))(*(_DWORD *)iter_oracles._M_node[1]._M_parent + 4))(
            iter_oracles._M_node[1]._M_parent,
            iter_oracles._M_node[1]._M_parent);
  vostok::ai::planning::world_state_property::world_state_property(&v9, property_id, &value);
  vostok::ai::planning::world_state::add(&this->m_current_state, iter, v5);
  *iter = &this->m_current_state.m_properties._M_impl._M_start[index];
  *iter_end = this->m_current_state.m_properties._M_impl._M_finish;
}
