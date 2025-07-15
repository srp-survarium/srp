char __thiscall vostok::ai::planning::animation_filter::is_passing_filter(
        vostok::ai::planning::animation_filter *this,
        survarium::game_camera **object)
{
  vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *it_filter; // [esp+8h] [ebp-8h]
  survarium::game_camera *collection; // [esp+Ch] [ebp-4h]

  collection = *object;
  survarium::weapon_user_dead_state::finalize(*object);
  if ( !vostok::ai::planning::animation_filter::contains_item(
          this,
          (const vostok::fs_new::virtual_path_string *)&collection->m_inverted_view_matrix) )
    return 0;
  for ( it_filter = this->m_subfilters.m_first; it_filter; it_filter = it_filter->next )
  {
    if ( !vostok::ai::planning::base_filter::is_object_available(it_filter->list, (const void *const *)object) )
      return 0;
  }
  return 1;
}
