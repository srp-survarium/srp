void __thiscall vostok::ai::planning::predicate::add_to_target_world_state_as_predicate(
        vostok::ai::planning::predicate *this,
        vostok::ai::planning::specified_problem *problem,
        unsigned int *offset)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  const vostok::ai::planning::pddl_predicate *m_predicate; // [esp+Ch] [ebp-70h]
  unsigned int v10; // [esp+10h] [ebp-6Ch]
  vostok::variant<32> *value; // [esp+18h] [ebp-64h] BYREF
  unsigned int type; // [esp+24h] [ebp-58h]
  char v13; // [esp+2Bh] [ebp-51h]
  void **instance; // [esp+2Ch] [ebp-50h]
  char v15; // [esp+32h] [ebp-4Ah]
  bool m_value; // [esp+33h] [ebp-49h]
  void *buffer; // [esp+34h] [ebp-48h]
  survarium::game_camera *p_m_parameters; // [esp+38h] [ebp-44h]
  vostok::ai::planning::pddl_domain *m_domain; // [esp+3Ch] [ebp-40h]
  char v20; // [esp+40h] [ebp-3Ch]
  char v21; // [esp+41h] [ebp-3Bh]
  char v22; // [esp+42h] [ebp-3Ah]
  char v23; // [esp+43h] [ebp-39h]
  const vostok::ai::planning::object_instance *object; // [esp+44h] [ebp-38h]
  unsigned int j; // [esp+48h] [ebp-34h]
  unsigned int index; // [esp+4Ch] [ebp-30h]
  unsigned int i; // [esp+50h] [ebp-2Ch]
  vostok::ai::planning::pddl_world_state_property_impl property_to_be_added; // [esp+54h] [ebp-28h] BYREF
  unsigned int parameters_count; // [esp+74h] [ebp-8h]
  const vostok::ai::planning::pddl_predicate *target_predicate; // [esp+78h] [ebp-4h]

  m_domain = problem->m_domain;
  target_predicate = (const vostok::ai::planning::pddl_predicate *)vostok::ai::planning::pddl_domain::operator[](
                                                                     m_domain,
                                                                     this->m_predicate_id);
  v23 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  p_m_parameters = (survarium::game_camera *)&this->m_parameters;
  parameters_count = this->m_parameters.m_end - this->m_parameters.m_begin;
  v22 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_parameters);
  m_value = this->m_value;
  buffer = property_to_be_added.m_indices.m_buffer;
  vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
    &property_to_be_added.m_indices,
    (unsigned int *)property_to_be_added.m_indices.m_buffer,
    4u,
    0);
  property_to_be_added.m_predicate = target_predicate;
  property_to_be_added.m_result = m_value;
  for ( i = 0; i < parameters_count; ++i )
  {
    v15 = 0;
    survarium::weapon_user_dead_state::finalize(v4);
    instance = (void **)&this->m_parameters.m_begin[i];
    v13 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
    type = target_predicate->m_parameters.m_begin[i];
    index = vostok::ai::planning::specified_problem::get_object_index(problem, type, (const void *const *)instance);
    v21 = 0;
    survarium::weapon_user_dead_state::finalize(v5);
    value = (vostok::variant<32> *)index;
    vostok::buffer_vector<unsigned int>::push_back(
      (vostok::buffer_vector<vostok::variant<32> const *> *)&property_to_be_added,
      (const vostok::variant<32> **)&value);
    v4 = (survarium::game_camera *)(i + 1);
  }
  for ( j = 0; j < property_to_be_added.m_indices.m_end - property_to_be_added.m_indices.m_begin; ++j )
  {
    survarium::weapon_user_dead_state::finalize(v4);
    survarium::weapon_user_dead_state::finalize(v6);
    v10 = property_to_be_added.m_indices.m_begin[j];
    m_predicate = property_to_be_added.m_predicate;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)property_to_be_added.m_indices.m_begin);
    object = vostok::ai::planning::specified_problem::get_object_by_type_and_index(
               problem,
               m_predicate->m_parameters.m_begin[j],
               v10);
    v20 = 0;
    survarium::weapon_user_dead_state::finalize(v7);
  }
  vostok::ai::planning::specified_problem::add_target_property(problem, &property_to_be_added);
  ++*offset;
  vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(
    (vostok::buffer_vector<vostok::resources::request> *)offset,
    &property_to_be_added);
}
