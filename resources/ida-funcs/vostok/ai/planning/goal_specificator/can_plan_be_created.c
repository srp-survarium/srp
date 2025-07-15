char __thiscall vostok::ai::planning::goal_specificator::can_plan_be_created(
        vostok::ai::planning::goal_specificator *this,
        vostok::ai::planning::specified_problem *specific_problem,
        const vostok::ai::planning::goal *goal_for_specification,
        vostok::ai::planning::search *search_service)
{
  vostok::buffer_vector<vostok::resources::request> *v5; // ecx
  unsigned int *v6; // eax
  vostok::buffer_vector<vostok::resources::request> *v7; // ecx
  unsigned __int8 v8; // al
  vostok::buffer_vector<vostok::resources::request> *v9; // ecx
  unsigned int value; // [esp+24h] [ebp-48h] BYREF
  unsigned int j; // [esp+28h] [ebp-44h]
  vostok::fixed_vector<unsigned int,4> parameter_ids; // [esp+2Ch] [ebp-40h] BYREF
  const vostok::ai::planning::action_parameter *parameter; // [esp+44h] [ebp-28h]
  unsigned int i; // [esp+48h] [ebp-24h]
  bool offsets_incremented; // [esp+4Fh] [ebp-1Dh]
  vostok::fixed_vector<unsigned int,4> offsets; // [esp+50h] [ebp-1Ch] BYREF
  unsigned int parameters_count; // [esp+68h] [ebp-4h]

  parameters_count = goal_for_specification->m_parameters.m_end - goal_for_specification->m_parameters.m_begin;
  for ( i = 0; i < parameters_count; ++i )
  {
    parameter = vostok::ai::planning::goal::get_parameter(goal_for_specification, i);
    vostok::ai::planning::specified_problem::fill_parameter_targets(specific_problem, parameter);
    if ( parameter->m_type && vostok::ai::planning::specified_problem::has_no_targets(specific_problem, parameter) )
      return 0;
  }
  value = 0;
  offsets.m_begin = (unsigned int *)offsets.m_buffer;
  offsets.m_end = (unsigned int *)offsets.m_buffer;
  vostok::buffer_vector<unsigned int>::assign(&offsets, parameters_count, &value);
  offsets_incremented = 1;
  while ( offsets_incremented )
  {
    vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
      &parameter_ids,
      (unsigned int *)parameter_ids.m_buffer,
      4u,
      0);
    for ( j = 0; j < parameters_count; ++j )
    {
      v6 = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::operator[](&offsets, j);
      vostok::buffer_vector<unsigned int>::push_back(
        (vostok::buffer_vector<vostok::variant<32> const *> *)&parameter_ids,
        (const vostok::variant<32> **)v6);
      if ( j == parameters_count - 1 )
        offsets_incremented = vostok::ai::planning::increment_targets(
                                (survarium::game_camera *)&offsets,
                                goal_for_specification,
                                specific_problem);
    }
    if ( !parameters_count
      || vostok::ai::planning::goal_specificator::are_parameters_suitable(
           this,
           specific_problem,
           goal_for_specification,
           &parameter_ids) )
    {
      vostok::ai::planning::goal_specificator::fill_problem(
        this,
        specific_problem,
        goal_for_specification,
        &parameter_ids);
      v8 = vostok::ai::planning::pddl_planner::build_plan(
             this->m_planner,
             search_service,
             specific_problem,
             goals_captions_14[goal_for_specification->m_goal_type],
             1);
      v7 = (vostok::buffer_vector<vostok::resources::request> *)v8;
      if ( v8 )
      {
        vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(
          (vostok::buffer_vector<vostok::resources::request> *)v8,
          &parameter_ids);
        vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v9, &offsets);
        return 1;
      }
      if ( !parameters_count )
      {
        vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(
          (vostok::buffer_vector<vostok::resources::request> *)v8,
          &parameter_ids);
        break;
      }
    }
    vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v7, &parameter_ids);
  }
  vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v5, &offsets);
  return 0;
}
