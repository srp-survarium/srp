void __thiscall vostok::ai::planning::propositional_planner::~propositional_planner(
        vostok::ai::planning::propositional_planner *this)
{
  this->__vftable = (vostok::ai::planning::propositional_planner_vtbl *)&vostok::ai::planning::propositional_planner::`vftable';
  stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::~_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>(&this->m_target_state_offsets._M_impl);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(&this->m_target_state.m_properties._M_impl);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(&this->m_current_state.m_properties._M_impl);
  vostok::ai::planning::oracle_holder::~oracle_holder(&this->m_oracles);
  vostok::ai::planning::operator_holder::~operator_holder(&this->m_operators);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->vostok::ai::planning::propositional_planner_base);
}
