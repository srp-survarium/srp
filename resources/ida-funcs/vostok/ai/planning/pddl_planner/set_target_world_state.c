void __thiscall vostok::ai::planning::pddl_planner::set_target_world_state(
        vostok::ai::planning::pddl_planner *this,
        vostok::ai::planning::specified_problem *actual_problem)
{
  const vostok::ai::planning::world_state_property *v2; // eax
  survarium::game_camera *v3; // ecx
  const vostok::ai::planning::world_state_property *v4; // eax
  survarium::game_camera *v5; // ecx
  unsigned int *v6; // eax
  vostok::ai::planning::world_state_property *v7; // [esp-4h] [ebp-154h]
  vostok::ai::planning::world_state_property *v8; // [esp-4h] [ebp-154h]
  vostok::ai::planning::world_state_property *v9; // [esp+0h] [ebp-150h]
  unsigned int v10; // [esp+4h] [ebp-14Ch]
  vostok::ai::planning::world_state_property *M_start; // [esp+98h] [ebp-B8h]
  bool m_result; // [esp+F3h] [ebp-5Dh] BYREF
  vostok::ai::planning::world_state_property v14; // [esp+F4h] [ebp-5Ch] BYREF
  bool value; // [esp+103h] [ebp-4Dh] BYREF
  vostok::ai::planning::world_state_property v16; // [esp+104h] [ebp-4Ch] BYREF
  unsigned int k; // [esp+110h] [ebp-40h]
  vostok::ai::planning::pddl_world_state_property_impl *v18; // [esp+114h] [ebp-3Ch]
  vostok::ai::planning::world_state_property *it_where; // [esp+118h] [ebp-38h]
  unsigned int id; // [esp+11Ch] [ebp-34h] BYREF
  unsigned int current_offset; // [esp+120h] [ebp-30h]
  unsigned int j; // [esp+124h] [ebp-2Ch]
  const vostok::ai::planning::pddl_world_state_property_impl *property; // [esp+128h] [ebp-28h]
  unsigned int property_index; // [esp+12Ch] [ebp-24h] BYREF
  unsigned int i; // [esp+130h] [ebp-20h]
  unsigned int world_state_size; // [esp+134h] [ebp-1Ch]
  vostok::ai::planning::dnf_world_state target; // [esp+138h] [ebp-18h] BYREF
  unsigned int current_index; // [esp+148h] [ebp-8h]
  unsigned int offsets_count; // [esp+14Ch] [ebp-4h]

  vostok::ai::vector<vostok::ai::planning::world_state_property>::vector<vostok::ai::planning::world_state_property>(&target.m_properties);
  target.m_hash = 0;
  offsets_count = actual_problem->m_target_offsets.m_end - actual_problem->m_target_offsets.m_begin;
  world_state_size = stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::size(&actual_problem->m_target_world_state._M_impl);
  current_index = 0;
  if ( offsets_count )
  {
    for ( j = 0; j <= offsets_count; ++j )
    {
      if ( j >= offsets_count )
        v10 = world_state_size;
      else
        v10 = *vostok::buffer_vector<unsigned int>::operator[](&actual_problem->m_target_offsets, j);
      current_offset = v10;
      while ( 1 )
      {
        v3 = (survarium::game_camera *)current_index;
        if ( current_index >= current_offset )
          break;
        if ( j )
        {
          M_start = target.m_properties._M_impl._M_start;
          survarium::weapon_user_dead_state::finalize((survarium::game_camera *)target.m_properties._M_impl._M_start);
          v3 = (survarium::game_camera *)&M_start[actual_problem->m_target_offsets.m_begin[j - 1]];
          v9 = (vostok::ai::planning::world_state_property *)v3;
        }
        else
        {
          v9 = target.m_properties._M_impl._M_start;
        }
        it_where = v9;
        survarium::weapon_user_dead_state::finalize(v3);
        v18 = &actual_problem->m_target_world_state._M_impl._M_start[current_index];
        id = (unsigned int)vostok::ai::planning::pddl_planner::calculate_property_index(
                             this,
                             (survarium::game_camera *)v18,
                             actual_problem);
        m_result = v18->m_result;
        v8 = it_where;
        vostok::ai::planning::world_state_property::world_state_property(&v14, &id, &m_result);
        vostok::ai::planning::dnf_world_state::add(&target, v4, v8);
        ++current_index;
      }
    }
  }
  else
  {
    for ( i = 0;
          i < actual_problem->m_target_world_state._M_impl._M_finish
            - actual_problem->m_target_world_state._M_impl._M_start;
          ++i )
    {
      property = vostok::ai::vector<vostok::ai::planning::pddl_world_state_property_impl>::operator[](
                   &actual_problem->m_target_world_state,
                   i);
      property_index = (unsigned int)vostok::ai::planning::pddl_planner::calculate_property_index(
                                       this,
                                       (survarium::game_camera *)property,
                                       actual_problem);
      value = property->m_result;
      v7 = target.m_properties._M_impl._M_start;
      vostok::ai::planning::world_state_property::world_state_property(&v16, &property_index, &value);
      vostok::ai::planning::dnf_world_state::add(&target, v2, v7);
    }
  }
  for ( k = 0; ; ++k )
  {
    v5 = (survarium::game_camera *)(actual_problem->m_target_offsets.m_end - actual_problem->m_target_offsets.m_begin);
    if ( k >= (unsigned int)v5 )
      break;
    survarium::weapon_user_dead_state::finalize(v5);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)actual_problem->m_target_offsets.m_begin[k]);
    stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::push_back(
      &this->m_planner.m_target_state_offsets._M_impl,
      v6);
  }
  vostok::ai::planning::propositional_planner::target(&this->m_planner, &target);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(&target.m_properties._M_impl);
}
