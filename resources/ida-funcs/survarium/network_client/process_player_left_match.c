void __thiscall survarium::network_client::process_player_left_match(
        survarium::network_client *this,
        vostok::network_core::buffer_reader *reader)
{
  vostok::network_core::buffer_reader *v2; // ebx
  survarium::player *m_object; // esi
  const unsigned __int8 *m_buffer; // eax
  unsigned int time_in_ms; // [esp+10h] [ebp-4h]

  v2 = reader;
  m_object = this->m_current_player.m_object;
  LOBYTE(reader) = m_object->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable;
  this->m_current_player.m_object = (survarium::player *)((char *)&m_object->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                                        + 1);
  time_in_ms = *(unsigned int *)((char *)&m_object->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                               + 1);
  this->m_current_player.m_object = (survarium::player *)((char *)&m_object->type + 1);
  survarium::game_world_core::leave_match(
    (survarium::game_world_core *)this,
    *(survarium::game_world_core **)(v2[1724].m_buffer_size + 312),
    (survarium::game_event_history_item::events_enum)reader,
    time_in_ms);
  m_buffer = v2[1725].m_buffer;
  if ( m_buffer
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && m_buffer[304] == (_BYTE)reader )
  {
    (*((void (__thiscall **)(vostok::network_core::buffer_reader *, int))v2->m_buffer + 21))(v2, 3);
    *(_BYTE *)((*((int (__thiscall **)(vostok::network_core::buffer_reader *))v2->m_buffer + 15))(v2) + 13180) = 1;
  }
}
