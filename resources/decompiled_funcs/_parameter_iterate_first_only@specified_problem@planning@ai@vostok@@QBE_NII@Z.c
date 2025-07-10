bool __thiscall vostok::ai::planning::specified_problem::parameter_iterate_first_only(
        vostok::ai::planning::specified_problem *this,
        unsigned int action_type,
        unsigned int parameter_index)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  const vostok::ai::planning::action_instance *action; // [esp+10h] [ebp-4h]

  action = vostok::ai::planning::pddl_problem::get_action_instance(
             (vostok::ai::planning::pddl_problem *)this->m_problem,
             action_type);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  return action->m_parameters.m_begin[parameter_index]->m_iterate_only_first;
}
