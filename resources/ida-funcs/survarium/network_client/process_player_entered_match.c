void __thiscall survarium::network_client::process_player_entered_match(
        survarium::network_client *this,
        vostok::network_core::buffer_reader *reader)
{
  survarium::player *m_object; // esi
  unsigned __int8 player_id[4]; // [esp+Ch] [ebp-8h]
  unsigned int time_in_ms; // [esp+10h] [ebp-4h]

  m_object = this->m_current_player.m_object;
  player_id[0] = (unsigned __int8)m_object->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable;
  this->m_current_player.m_object = (survarium::player *)((char *)&m_object->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                                        + 1);
  m_object = (survarium::player *)((char *)m_object + 1);
  time_in_ms = (unsigned int)m_object->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable;
  this->m_current_player.m_object = (survarium::player *)&m_object->type;
  survarium::game_world_core::enter_match(
    (survarium::game_world_core *)this,
    *(_DWORD *)(reader[1724].m_buffer_size + 312),
    *(survarium::game_event_history_item::events_enum *)player_id,
    time_in_ms);
}
