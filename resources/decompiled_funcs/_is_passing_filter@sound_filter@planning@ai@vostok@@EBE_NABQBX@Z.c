char __thiscall vostok::ai::planning::sound_filter::is_passing_filter(
        vostok::ai::planning::sound_filter *this,
        survarium::game_camera **object)
{
  vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *it_filter; // [esp+8h] [ebp-8h]
  survarium::game_camera *sound; // [esp+Ch] [ebp-4h]

  sound = *object;
  survarium::weapon_user_dead_state::finalize(*object);
  if ( !vostok::ai::planning::sound_filter::contains_object(
          this,
          (const vostok::fs_new::virtual_path_string *)&sound->m_inverted_view_matrix) )
    return 0;
  for ( it_filter = this->m_subfilters.m_first; it_filter; it_filter = it_filter->next )
  {
    if ( !vostok::ai::planning::base_filter::is_object_available(it_filter->list, (const void *const *)object) )
      return 0;
  }
  return 1;
}
