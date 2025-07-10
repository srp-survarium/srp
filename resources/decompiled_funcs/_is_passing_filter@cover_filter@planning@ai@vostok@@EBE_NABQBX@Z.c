char __thiscall vostok::ai::planning::cover_filter::is_passing_filter(
        vostok::ai::planning::cover_filter *this,
        const void *const *object)
{
  survarium::game_camera *v2; // ecx
  vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *it_filter; // [esp+8h] [ebp-Ch]
  unsigned int object_id; // [esp+10h] [ebp-4h]

  object_id = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)object + 4))(*object);
  survarium::weapon_user_dead_state::finalize(v2);
  if ( !vostok::ai::planning::cover_filter::contains_object_id(this, object_id) )
    return 0;
  for ( it_filter = this->m_subfilters.m_first; it_filter; it_filter = it_filter->next )
  {
    if ( !vostok::ai::planning::base_filter::is_object_available(it_filter->list, object) )
      return 0;
  }
  return 1;
}
