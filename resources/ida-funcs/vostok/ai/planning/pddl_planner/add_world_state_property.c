void __thiscall vostok::ai::planning::pddl_planner::add_world_state_property(
        vostok::ai::planning::pddl_planner *this,
        survarium::game_camera *property,
        vostok::ai::planning::world_state *state,
        vostok::ai::planning::specified_problem *actual_problem)
{
  const vostok::ai::planning::world_state_property *v4; // eax
  bool value; // [esp+4Fh] [ebp-11h] BYREF
  vostok::ai::planning::world_state_property v6; // [esp+50h] [ebp-10h] BYREF
  unsigned int property_index; // [esp+5Ch] [ebp-4h] BYREF

  property_index = (unsigned int)vostok::ai::planning::pddl_planner::calculate_property_index(
                                   this,
                                   property,
                                   actual_problem);
  value = LOBYTE(property->m_inverted_view_matrix.lines[1].elements[2]);
  vostok::ai::planning::world_state_property::world_state_property(&v6, &property_index, &value);
  vostok::ai::planning::world_state::add(state, v4);
}
