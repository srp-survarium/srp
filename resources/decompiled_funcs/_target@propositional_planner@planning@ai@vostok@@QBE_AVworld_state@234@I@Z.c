vostok::ai::planning::world_state *__thiscall vostok::ai::planning::propositional_planner::target(
        vostok::ai::planning::propositional_planner *this,
        vostok::ai::planning::world_state *result,
        unsigned int offset)
{
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  vostok::ai::planning::world_state_property *M_finish; // [esp+0h] [ebp-CCh]
  vostok::ai::planning::world_state_property *M_start; // [esp+4h] [ebp-C8h]
  survarium::game_camera *v9; // [esp+94h] [ebp-38h]
  vostok::ai::planning::world_state_property *v10; // [esp+A8h] [ebp-24h]
  vostok::ai::planning::world_state resulta; // [esp+B0h] [ebp-1Ch] BYREF
  unsigned int offsets_count; // [esp+C0h] [ebp-Ch]
  const vostok::ai::planning::world_state_property *it_target; // [esp+C4h] [ebp-8h]
  const vostok::ai::planning::world_state_property *it_target_end; // [esp+C8h] [ebp-4h]

  offsets_count = this->m_target_state_offsets._M_impl._M_finish - this->m_target_state_offsets._M_impl._M_start;
  if ( !offset || offset == -1 )
  {
    M_start = this->m_target_state.m_properties._M_impl._M_start;
  }
  else
  {
    v10 = this->m_target_state.m_properties._M_impl._M_start;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_target_state_offsets._M_impl._M_start);
    M_start = &v10[*v3];
  }
  it_target = M_start;
  if ( offset == -1 || offset == offsets_count )
  {
    M_finish = this->m_target_state.m_properties._M_impl._M_finish;
  }
  else
  {
    v9 = (survarium::game_camera *)this->m_target_state.m_properties._M_impl._M_start;
    survarium::weapon_user_dead_state::finalize(v9);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_target_state_offsets._M_impl._M_start);
    M_finish = (vostok::ai::planning::world_state_property *)((char *)v9 + 12 * *v4);
  }
  it_target_end = M_finish;
  memset(&resulta, 0, sizeof(resulta));
  while ( it_target != it_target_end )
    vostok::ai::planning::world_state::add(&resulta, it_target++);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(
    &result->m_properties._M_impl,
    &resulta.m_properties._M_impl);
  result->m_hash = resulta.m_hash;
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(&resulta.m_properties._M_impl);
  return result;
}
