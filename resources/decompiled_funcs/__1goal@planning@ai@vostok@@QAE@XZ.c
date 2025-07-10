void __thiscall vostok::ai::planning::goal::~goal(vostok::ai::planning::goal *this)
{
  vostok::threading::mutex *v1; // ecx
  vostok::ai::planning::action_parameter **i; // [esp+8h] [ebp-34h]

  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::~_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>(&this->m_target_state._M_impl);
  vostok::threading::mutex::~mutex(v1, (_RTL_CRITICAL_SECTION *)&this->m_filters_set.vostok::threading::mutex);
  for ( i = this->m_parameters.m_begin; i != this->m_parameters.m_end; ++i )
    ;
  this->m_parameters.m_end = this->m_parameters.m_begin;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
