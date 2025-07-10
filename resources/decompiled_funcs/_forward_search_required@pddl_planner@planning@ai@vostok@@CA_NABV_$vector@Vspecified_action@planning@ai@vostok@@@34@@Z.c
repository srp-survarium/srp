BOOL __cdecl vostok::ai::planning::pddl_planner::forward_search_required(
        const vostok::ai::vector<vostok::ai::planning::specified_action> *specified_actions)
{
  vostok::ai::planning::specified_action *v1; // ecx
  unsigned int i; // [esp+18h] [ebp-Ch]
  unsigned int preconditions_count; // [esp+1Ch] [ebp-8h]
  unsigned int effects_count; // [esp+20h] [ebp-4h]

  preconditions_count = 0;
  effects_count = 0;
  for ( i = 0; i < specified_actions->_M_impl._M_finish - specified_actions->_M_impl._M_start; ++i )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x34);
    v1 = &specified_actions->_M_impl._M_start[i];
    preconditions_count += v1->m_preconditions._M_impl._M_finish - v1->m_preconditions._M_impl._M_start;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v1);
    effects_count += specified_actions->_M_impl._M_start[i].m_effects._M_impl._M_finish
                   - specified_actions->_M_impl._M_start[i].m_effects._M_impl._M_start;
  }
  return preconditions_count < effects_count;
}
