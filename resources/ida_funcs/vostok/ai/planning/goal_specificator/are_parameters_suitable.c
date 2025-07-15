bool __thiscall vostok::ai::planning::goal_specificator::are_parameters_suitable(
        vostok::ai::planning::goal_specificator *this,
        vostok::ai::planning::specified_problem *specific_problem,
        const vostok::ai::planning::goal *goal_for_specification,
        const vostok::fixed_vector<unsigned int,4> *targets_indices)
{
  survarium::game_camera *v4; // ecx
  const void **j; // [esp+4h] [ebp-5Ch]
  bool v7; // [esp+27h] [ebp-39h]
  _BYTE v8[8]; // [esp+28h] [ebp-38h] BYREF
  void *value; // [esp+30h] [ebp-30h] BYREF
  char v10; // [esp+37h] [ebp-29h]
  vostok::ai::planning::action_parameter *parameter; // [esp+38h] [ebp-28h]
  vostok::ai::selectors::target_selector_base *selector; // [esp+3Ch] [ebp-24h]
  unsigned int i; // [esp+40h] [ebp-20h]
  vostok::fixed_vector<void const *,4> objects; // [esp+44h] [ebp-1Ch] BYREF
  unsigned int parameters_count; // [esp+5Ch] [ebp-4h]

  parameters_count = goal_for_specification->m_parameters.m_end - goal_for_specification->m_parameters.m_begin;
  v10 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&goal_for_specification->m_parameters);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&objects);
  for ( i = 0; i < parameters_count; ++i )
  {
    parameter = vostok::ai::planning::goal::get_parameter(goal_for_specification, i);
    selector = vostok::ai::planning::specified_problem::get_parameter_selector(specific_problem, parameter);
    if ( selector )
    {
      survarium::weapon_user_dead_state::finalize(v4);
      value = (void *)selector->get_target(selector, v8, targets_indices->m_begin[i])->first;
      vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
        &objects.vostok::buffer_vector<void const *>,
        (const void **)&value);
    }
  }
  v7 = vostok::ai::planning::goal::are_parameters_suitable(goal_for_specification, &objects);
  for ( j = objects.m_begin; j != objects.m_end; ++j )
    ;
  return v7;
}
