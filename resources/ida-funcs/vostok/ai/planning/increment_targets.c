char __cdecl vostok::ai::planning::increment_targets(
        survarium::game_camera *offsets,
        const vostok::ai::planning::goal *const goal_for_specification,
        vostok::ai::planning::specified_problem *specific_problem)
{
  unsigned int *v3; // esi
  unsigned int *v5; // [esp+4h] [ebp-28h]
  unsigned int j; // [esp+10h] [ebp-1Ch]
  vostok::ai::planning::action_parameter *parameter; // [esp+14h] [ebp-18h]
  vostok::ai::selectors::target_selector_base *selector; // [esp+18h] [ebp-14h]
  unsigned int i; // [esp+1Ch] [ebp-10h]
  bool result; // [esp+23h] [ebp-9h]
  int index; // [esp+24h] [ebp-8h]
  unsigned int offsets_count; // [esp+28h] [ebp-4h]

  offsets_count = (signed int)(LODWORD(offsets->m_inverted_view_matrix.i.x) - (unsigned int)offsets->__vftable) >> 2;
  survarium::weapon_user_dead_state::finalize(offsets);
  result = 0;
  index = -1;
  for ( i = 0; i < offsets_count; ++i )
  {
    index = offsets_count - 1 - i;
    parameter = vostok::ai::planning::goal::get_parameter(goal_for_specification, index);
    selector = vostok::ai::planning::specified_problem::get_parameter_selector(specific_problem, parameter);
    if ( selector )
    {
      if ( !parameter->m_iterate_only_first )
      {
        v3 = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::operator[](
               (vostok::buffer_vector<unsigned int> *)offsets,
               index);
        if ( *v3 < (int)selector->get_targets_count(selector) - 1 )
        {
          v5 = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::operator[](
                 (vostok::buffer_vector<unsigned int> *)offsets,
                 index);
          ++*v5;
          result = 1;
          break;
        }
      }
    }
  }
  if ( !result || index == -1 )
    return 0;
  for ( j = index + 1; j < offsets_count; ++j )
    *stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::operator[](
       (vostok::buffer_vector<unsigned int> *)offsets,
       j) = 0;
  return 1;
}
