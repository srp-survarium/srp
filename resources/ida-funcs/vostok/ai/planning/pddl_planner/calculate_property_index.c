stlp_std::priv::_Rb_tree_node_base *__thiscall vostok::ai::planning::pddl_planner::calculate_property_index(
        vostok::ai::planning::pddl_planner *this,
        survarium::game_camera *property,
        vostok::ai::planning::specified_problem *actual_problem)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  const vostok::ai::planning::pddl_predicate *y_low; // [esp+Ch] [ebp-2Ch]
  unsigned int other_side_i; // [esp+24h] [ebp-14h]
  survarium::game_camera *i; // [esp+28h] [ebp-10h]
  unsigned int combinations_count; // [esp+2Ch] [ebp-Ch]
  unsigned int instances_count; // [esp+30h] [ebp-8h]
  stlp_std::priv::_Rb_tree_node_base *property_index; // [esp+34h] [ebp-4h]

  instances_count = (signed int)(LODWORD(property->m_inverted_view_matrix.i.x) - (unsigned int)property->__vftable) >> 2;
  property_index = vostok::ai::planning::specified_problem::get_predicate_offset(
                     actual_problem,
                     *(_DWORD *)LODWORD(property->m_inverted_view_matrix.j.y));
  survarium::weapon_user_dead_state::finalize(v3);
  combinations_count = 1;
  for ( i = 0; (unsigned int)i < instances_count; i = (survarium::game_camera *)((char *)i + 1) )
  {
    other_side_i = instances_count - 1 - (_DWORD)i;
    survarium::weapon_user_dead_state::finalize(i);
    survarium::weapon_user_dead_state::finalize(v4);
    property_index = (stlp_std::priv::_Rb_tree_node_base *)((char *)property_index
                                                          + combinations_count
                                                          * *((_DWORD *)&property->get_projection_matrix + other_side_i));
    y_low = (const vostok::ai::planning::pddl_predicate *)LODWORD(property->m_inverted_view_matrix.j.y);
    survarium::weapon_user_dead_state::finalize(property);
    combinations_count *= vostok::ai::planning::specified_problem::get_count_of_objects_by_type(
                            actual_problem,
                            y_low->m_parameters.m_begin[other_side_i]);
  }
  return property_index;
}
