bool __thiscall vostok::ai::planning::specified_problem::are_parameters_suitable(
        vostok::ai::planning::specified_problem *this,
        unsigned int action_type,
        survarium::game_camera *objects_indices)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  const void **j; // [esp+4h] [ebp-60h]
  unsigned int *v8; // [esp+28h] [ebp-3Ch]
  bool v9; // [esp+37h] [ebp-2Dh]
  void *value; // [esp+38h] [ebp-2Ch] BYREF
  char v11; // [esp+3Eh] [ebp-26h]
  char v12; // [esp+3Fh] [ebp-25h]
  const vostok::ai::planning::object_instance *object; // [esp+40h] [ebp-24h]
  unsigned int i; // [esp+44h] [ebp-20h]
  vostok::fixed_vector<void const *,4> object_instances; // [esp+48h] [ebp-1Ch] BYREF
  const vostok::ai::planning::action_instance *action; // [esp+60h] [ebp-4h]

  action = vostok::ai::planning::pddl_problem::get_action_instance(
             (vostok::ai::planning::pddl_problem *)this->m_problem,
             action_type);
  v12 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&object_instances);
  for ( i = 0;
        i < (signed int)(LODWORD(objects_indices->m_inverted_view_matrix.i.x) - (unsigned int)objects_indices->__vftable) >> 2;
        ++i )
  {
    survarium::weapon_user_dead_state::finalize(objects_indices);
    v8 = (unsigned int *)(&objects_indices->get_projection_matrix + i);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)i);
    object = vostok::ai::planning::specified_problem::get_object_by_type_and_index(
               this,
               action->m_parameters.m_begin[i]->m_type,
               *v8);
    v11 = 0;
    survarium::weapon_user_dead_state::finalize(v4);
    value = (void *)object->m_instance;
    vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
      &object_instances.vostok::buffer_vector<void const *>,
      (const void **)&value);
  }
  v9 = vostok::ai::planning::action_instance::are_parameters_suitable(
         (vostok::ai::planning::action_instance *)action,
         &object_instances);
  for ( j = object_instances.m_begin; j != object_instances.m_end; ++j )
    ;
  return v9;
}
