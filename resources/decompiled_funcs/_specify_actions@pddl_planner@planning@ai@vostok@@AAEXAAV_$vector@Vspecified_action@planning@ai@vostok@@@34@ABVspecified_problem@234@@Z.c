void __thiscall vostok::ai::planning::pddl_planner::specify_actions(
        vostok::ai::planning::pddl_planner *this,
        vostok::ai::vector<vostok::ai::planning::specified_action> *destination,
        vostok::ai::planning::specified_problem *actual_problem)
{
  unsigned int j; // [esp+18h] [ebp-Ch]
  vostok::ai::planning::generalized_action *it; // [esp+20h] [ebp-4h]

  for ( it = actual_problem->m_domain->m_actions.m_first; it; it = it->next )
  {
    vostok::ai::planning::pddl_planner::specify_actions(this, it, destination, actual_problem);
    for ( j = 0; j < it->m_clones.m_end - it->m_clones.m_begin; ++j )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&it->m_clones);
      vostok::ai::planning::pddl_planner::specify_actions(this, it->m_clones.m_begin[j], destination, actual_problem);
    }
  }
}
