char __cdecl vostok::ai::planning::are_parameters_equal(
        survarium::game_camera *first,
        const vostok::fixed_vector<void const *,4> *second)
{
  const void **v3; // [esp+4h] [ebp-10h]
  unsigned int i; // [esp+10h] [ebp-4h]

  if ( (signed int)(LODWORD(first->m_inverted_view_matrix.i.x) - (unsigned int)first->__vftable) >> 2 != second->m_end - second->m_begin )
    return 0;
  for ( i = 0; i < (signed int)(LODWORD(first->m_inverted_view_matrix.i.x) - (unsigned int)first->__vftable) >> 2; ++i )
  {
    survarium::weapon_user_dead_state::finalize(first);
    v3 = (const void **)(&first->get_projection_matrix + i);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)i);
    if ( *v3 != second->m_begin[i] )
      return 0;
  }
  return 1;
}
