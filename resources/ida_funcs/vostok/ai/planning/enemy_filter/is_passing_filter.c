char __thiscall vostok::ai::planning::enemy_filter::is_passing_filter(
        vostok::ai::planning::enemy_filter *this,
        survarium::game_camera **object)
{
  survarium::game_camera *m_filter_type; // ecx
  int v3; // eax
  vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *it_filter; // [esp+10h] [ebp-Ch]
  survarium::game_camera *object_npc; // [esp+14h] [ebp-8h]
  int object_id; // [esp+18h] [ebp-4h]

  object_id = -1;
  object_npc = *object;
  survarium::weapon_user_dead_state::finalize(*object);
  m_filter_type = (survarium::game_camera *)this->m_filter_type;
  switch ( (unsigned int)m_filter_type )
  {
    case 0u:
      object_id = ((int (__thiscall *)(survarium::game_camera *))object_npc->__vftable[2].get_projection_matrix)(object_npc);
      break;
    case 1u:
      v3 = ((int (__thiscall *)(survarium::game_camera *))object_npc->__vftable[1].on_activate)(object_npc);
      object_id = (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 4))(v3, v3);
      break;
    case 2u:
      object_id = ((int (__thiscall *)(survarium::game_camera *))object_npc->__vftable[2].on_activate)(object_npc);
      break;
    case 3u:
      object_id = ((int (__thiscall *)(survarium::game_camera *))object_npc->__vftable[2].on_deactivate)(object_npc);
      break;
    default:
      break;
  }
  survarium::weapon_user_dead_state::finalize(m_filter_type);
  if ( !vostok::ai::planning::enemy_filter::contains_object_id(this, object_id) )
    return 0;
  for ( it_filter = this->m_subfilters.m_first; it_filter; it_filter = it_filter->next )
  {
    if ( !vostok::ai::planning::base_filter::is_object_available(it_filter->list, (const void *const *)object) )
      return 0;
  }
  return 1;
}
