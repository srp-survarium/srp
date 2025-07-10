bool __thiscall vostok::ai::planning::pddl_predicate_redirector::value(
        vostok::ai::planning::pddl_predicate_redirector *this)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  const void **j; // [esp+4h] [ebp-74h]
  survarium::game_camera *m_instance; // [esp+Ch] [ebp-6Ch]
  bool v9; // [esp+2Eh] [ebp-4Ah]
  void *value; // [esp+30h] [ebp-48h] BYREF
  char v11; // [esp+36h] [ebp-42h]
  char v12; // [esp+37h] [ebp-41h]
  unsigned int other_side_i; // [esp+38h] [ebp-40h]
  const vostok::ai::planning::object_instance *object; // [esp+3Ch] [ebp-3Ch]
  unsigned int object_index; // [esp+40h] [ebp-38h]
  unsigned int count_of_type; // [esp+44h] [ebp-34h]
  unsigned int i; // [esp+48h] [ebp-30h]
  unsigned int combinations_count; // [esp+4Ch] [ebp-2Ch]
  unsigned int predicate_offset; // [esp+50h] [ebp-28h]
  const vostok::ai::planning::pddl_predicate *predicate; // [esp+54h] [ebp-24h]
  vostok::fixed_vector<void const *,4> values; // [esp+58h] [ebp-20h] BYREF
  unsigned int difference; // [esp+70h] [ebp-8h]
  unsigned int parameters_count; // [esp+74h] [ebp-4h]

  predicate = (const vostok::ai::planning::pddl_predicate *)vostok::ai::planning::specified_problem::get_lower_bound_predicate(
                                                              (vostok::ai::planning::specified_problem *)this->m_problem,
                                                              this->m_id);
  v12 = 0;
  survarium::weapon_user_dead_state::finalize(v1);
  predicate_offset = (unsigned int)vostok::ai::planning::specified_problem::get_predicate_offset(
                                     (vostok::ai::planning::specified_problem *)this->m_problem,
                                     predicate->m_type);
  v11 = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  difference = this->m_id - predicate_offset;
  parameters_count = predicate->m_parameters.m_end - predicate->m_parameters.m_begin;
  value = 0;
  values.m_begin = (const void **)values.m_buffer;
  values.m_end = (const void **)values.m_buffer;
  vostok::buffer_vector<void const *>::assign(
    &values.vostok::buffer_vector<void const *>,
    (survarium::game_camera *)parameters_count,
    (const void **)&value);
  combinations_count = 1;
  for ( i = 0; i < parameters_count; ++i )
  {
    other_side_i = parameters_count - i - 1;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)other_side_i);
    count_of_type = vostok::ai::planning::specified_problem::get_count_of_objects_by_type(
                      (vostok::ai::planning::specified_problem *)this->m_problem,
                      predicate->m_parameters.m_begin[other_side_i]);
    survarium::weapon_user_dead_state::finalize(v3);
    object_index = difference / combinations_count % count_of_type;
    survarium::weapon_user_dead_state::finalize(v4);
    object = vostok::ai::planning::specified_problem::get_object_by_type_and_index(
               (vostok::ai::planning::specified_problem *)this->m_problem,
               predicate->m_parameters.m_begin[other_side_i],
               object_index);
    m_instance = (survarium::game_camera *)object->m_instance;
    survarium::weapon_user_dead_state::finalize(m_instance);
    values.m_begin[other_side_i] = m_instance;
    combinations_count *= count_of_type;
  }
  v9 = predicate->m_predicate_binder(predicate, &values);
  for ( j = values.m_begin; j != values.m_end; ++j )
    ;
  return v9;
}
