void __thiscall vostok::ai::planning::generalized_action::~generalized_action(
        vostok::ai::planning::generalized_action *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  vostok::ai::planning::generalized_action **m_begin; // ecx
  survarium::game_camera *v4; // [esp-4h] [ebp-B8h]
  vostok::ai::planning::generalized_action **j; // [esp+90h] [ebp-24h]
  unsigned int i; // [esp+B0h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    v1 = (survarium::game_camera *)(this->m_clones.m_end - this->m_clones.m_begin);
    if ( i >= (unsigned int)v1 )
      break;
    survarium::weapon_user_dead_state::finalize(v1);
    v4 = (survarium::game_camera *)&this->m_clones.m_begin[i];
    survarium::weapon_user_dead_state::finalize(v4);
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::generalized_action>(
      v2,
      (vostok::ai::planning::generalized_action **)v4);
  }
  for ( j = this->m_clones.m_begin; j != this->m_clones.m_end; ++j )
    ;
  m_begin = this->m_clones.m_begin;
  this->m_clones.m_end = m_begin;
  vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(
    (vostok::buffer_vector<vostok::resources::request> *)m_begin,
    &this->m_parameter_types.m_begin);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::~_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>(&this->m_effects._M_impl);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::~_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>(&this->m_preconditions._M_impl);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
