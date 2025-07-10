char __cdecl vostok::ai::planning::increment_offsets(
        survarium::game_camera *offsets,
        const vostok::ai::planning::generalized_action *prototype_action,
        vostok::ai::planning::specified_problem *problem)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  _DWORD *v5; // eax
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  survarium::game_camera *v8; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // [esp+1Ch] [ebp-28h]
  unsigned int j; // [esp+30h] [ebp-14h]
  unsigned int i; // [esp+34h] [ebp-10h]
  bool result; // [esp+3Bh] [ebp-9h]
  unsigned int index; // [esp+3Ch] [ebp-8h]
  unsigned int offsets_count; // [esp+40h] [ebp-4h]

  offsets_count = (signed int)(LODWORD(offsets->m_inverted_view_matrix.i.x) - (unsigned int)offsets->__vftable) >> 2;
  survarium::weapon_user_dead_state::finalize(offsets);
  result = 0;
  index = -1;
  for ( i = 0; i < offsets_count; ++i )
  {
    index = offsets_count - 1 - i;
    if ( !vostok::ai::planning::specified_problem::parameter_iterate_first_only(
            problem,
            prototype_action->m_type,
            index) )
    {
      survarium::weapon_user_dead_state::finalize(v4);
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)offsets->__vftable);
      v11 = v5;
      survarium::weapon_user_dead_state::finalize(v6);
      if ( *v11 < (unsigned int)(vostok::ai::planning::specified_problem::get_count_of_objects_by_type(
                                   problem,
                                   prototype_action->m_parameter_types.m_begin[index])
                               - 1) )
      {
        survarium::weapon_user_dead_state::finalize(v7);
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)offsets->__vftable);
        v3 = v8;
        ++v8->__vftable;
        result = 1;
        break;
      }
    }
    v3 = (survarium::game_camera *)(i + 1);
  }
  if ( !result || index == -1 )
    return 0;
  for ( j = index + 1; j < offsets_count; ++j )
  {
    survarium::weapon_user_dead_state::finalize(v3);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)offsets->__vftable);
    *v10 = 0;
    v3 = (survarium::game_camera *)(j + 1);
  }
  return 1;
}
