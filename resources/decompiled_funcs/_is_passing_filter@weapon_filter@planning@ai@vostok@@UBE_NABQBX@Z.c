char __thiscall vostok::ai::planning::weapon_filter::is_passing_filter(
        vostok::ai::planning::weapon_filter *this,
        survarium::game_camera **object)
{
  int v2; // eax
  survarium::game_camera *v3; // ecx
  vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *it_filter; // [esp+Ch] [ebp-Ch]
  survarium::game_camera *object_weapon; // [esp+10h] [ebp-8h]
  unsigned int object_id; // [esp+14h] [ebp-4h]

  object_weapon = *object;
  survarium::weapon_user_dead_state::finalize(*object);
  v2 = ((int (__thiscall *)(survarium::game_camera *))object_weapon->get_projection_matrix)(object_weapon);
  object_id = (*(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 4))(v2, v2);
  survarium::weapon_user_dead_state::finalize(v3);
  if ( ((int (__thiscall *)(survarium::game_camera *))object_weapon->on_activate)(object_weapon) != this->m_filter_type )
    return 0;
  if ( !vostok::ai::planning::weapon_filter::contains_object_id(this, object_id) )
    return 0;
  for ( it_filter = this->m_subfilters.m_first; it_filter; it_filter = it_filter->next )
  {
    if ( !vostok::ai::planning::base_filter::is_object_available(it_filter->list, (const void *const *)object) )
      return 0;
  }
  return 1;
}
