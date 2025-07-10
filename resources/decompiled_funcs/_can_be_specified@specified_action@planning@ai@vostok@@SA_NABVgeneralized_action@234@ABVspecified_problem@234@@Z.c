char __cdecl vostok::ai::planning::specified_action::can_be_specified(
        const vostok::ai::planning::generalized_action *prototype,
        vostok::ai::planning::specified_problem *problem)
{
  survarium::game_camera *v2; // ecx
  unsigned int j; // [esp+Ch] [ebp-4h]

  for ( j = 0; ; ++j )
  {
    v2 = (survarium::game_camera *)(prototype->m_parameter_types.m_end - prototype->m_parameter_types.m_begin);
    if ( j >= (unsigned int)v2 )
      break;
    survarium::weapon_user_dead_state::finalize(v2);
    if ( !vostok::ai::planning::specified_problem::get_count_of_objects_by_type(
            problem,
            prototype->m_parameter_types.m_begin[j]) )
      return 0;
  }
  return 1;
}
