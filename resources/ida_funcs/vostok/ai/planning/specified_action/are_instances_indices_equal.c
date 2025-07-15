char __cdecl vostok::ai::planning::specified_action::are_instances_indices_equal(
        survarium::game_camera *first_property,
        const vostok::ai::planning::pddl_world_state_property_impl *second_property)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  unsigned int v5; // [esp+8h] [ebp-10h]
  unsigned int i; // [esp+14h] [ebp-4h]

  if ( (signed int)(LODWORD(first_property->m_inverted_view_matrix.i.x) - (unsigned int)first_property->__vftable) >> 2 != second_property->m_indices.m_end - second_property->m_indices.m_begin )
    return 0;
  for ( i = 0;
        i < (signed int)(LODWORD(first_property->m_inverted_view_matrix.i.x) - (unsigned int)first_property->__vftable) >> 2;
        ++i )
  {
    survarium::weapon_user_dead_state::finalize(first_property);
    survarium::weapon_user_dead_state::finalize(v3);
    v5 = *((_DWORD *)&first_property->get_projection_matrix + i);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)first_property->__vftable);
    survarium::weapon_user_dead_state::finalize(v4);
    if ( v5 != second_property->m_indices.m_begin[i] )
      return 0;
  }
  return 1;
}
