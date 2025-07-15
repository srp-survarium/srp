vostok::buffer_vector<vostok::resources::request> *__cdecl vostok::ai::planning::create_property(
        vostok::buffer_vector<vostok::resources::request> *result,
        unsigned int predicate_id,
        vostok::ai::planning::generalized_action *action,
        bool value,
        survarium::game_camera *parameters_source)
{
  survarium::game_camera *v5; // ecx
  vostok::variant<32> *v7; // [esp+18h] [ebp-44h] BYREF
  char v8; // [esp+22h] [ebp-3Ah]
  void *buffer; // [esp+24h] [ebp-38h]
  vostok::ai::planning::pddl_domain *m_domain; // [esp+28h] [ebp-34h]
  char v11; // [esp+2Eh] [ebp-2Eh]
  char v12; // [esp+2Fh] [ebp-2Dh]
  unsigned int i; // [esp+30h] [ebp-2Ch]
  vostok::ai::planning::pddl_world_state_property_impl new_property; // [esp+34h] [ebp-28h] BYREF
  unsigned int parameters_count; // [esp+54h] [ebp-8h]
  const vostok::ai::planning::pddl_predicate *target_predicate; // [esp+58h] [ebp-4h]

  m_domain = action->m_domain;
  target_predicate = (const vostok::ai::planning::pddl_predicate *)vostok::ai::planning::pddl_domain::operator[](
                                                                     m_domain,
                                                                     predicate_id);
  v12 = 0;
  survarium::weapon_user_dead_state::finalize(v5);
  parameters_count = (signed int)(LODWORD(parameters_source->m_inverted_view_matrix.i.x)
                                - (unsigned int)parameters_source->__vftable) >> 2;
  v11 = 0;
  survarium::weapon_user_dead_state::finalize(parameters_source);
  buffer = new_property.m_indices.m_buffer;
  vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
    &new_property.m_indices,
    (unsigned int *)new_property.m_indices.m_buffer,
    4u,
    0);
  new_property.m_predicate = target_predicate;
  new_property.m_result = value;
  for ( i = 0; i < parameters_count; ++i )
  {
    v8 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)i);
    v7 = (vostok::variant<32> *)*((_DWORD *)&parameters_source->get_projection_matrix + i);
    vostok::buffer_vector<unsigned int>::push_back(
      (vostok::buffer_vector<vostok::variant<32> const *> *)&new_property,
      (const vostok::variant<32> **)&v7);
  }
  vostok::fixed_vector<unsigned int,4>::fixed_vector<unsigned int,4>(
    (vostok::fixed_vector<unsigned int,4> *)result,
    &new_property.m_indices);
  result[3].m_begin = (vostok::resources::request *)new_property.m_predicate;
  LOBYTE(result[3].m_end) = new_property.m_result;
  vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(result, &new_property);
  return result;
}
