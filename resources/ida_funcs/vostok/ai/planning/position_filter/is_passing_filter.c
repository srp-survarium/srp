char __thiscall vostok::ai::planning::position_filter::is_passing_filter(
        vostok::ai::planning::position_filter *this,
        survarium::game_camera **object)
{
  vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *it_filter; // [esp+8h] [ebp-8h]
  const vostok::ai::movement_target *target; // [esp+Ch] [ebp-4h]

  target = (const vostok::ai::movement_target *)*object;
  survarium::weapon_user_dead_state::finalize(*object);
  if ( !vostok::ai::planning::position_filter::contains_item(this, target) )
    return 0;
  for ( it_filter = this->m_subfilters.m_first; it_filter; it_filter = it_filter->next )
  {
    if ( !vostok::ai::planning::base_filter::is_object_available(it_filter->list, (const void *const *)object) )
      return 0;
  }
  return 1;
}
