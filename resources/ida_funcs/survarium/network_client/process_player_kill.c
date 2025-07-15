void __usercall survarium::network_client::process_player_kill(
        survarium::network_client *this@<esi>,
        vostok::network_core::packet_reader *packet@<eax>)
{
  const unsigned __int8 *m_pointer; // ecx
  char v3; // dl
  char v4; // dl
  survarium::player *m_object; // ebx
  char v6; // dl
  survarium::network_client_vtbl *v7; // eax
  survarium::player *v8; // edi
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player; // [esp+8h] [ebp-Ch] BYREF
  unsigned int item_dict_id; // [esp+Ch] [ebp-8h]
  survarium::game_world_ui *is_headshot; // [esp+10h] [ebp-4h]

  m_pointer = packet->m_pointer;
  v3 = *m_pointer++;
  packet->m_pointer = m_pointer;
  LOBYTE(player.m_object) = v3;
  v4 = *m_pointer++;
  packet->m_pointer = m_pointer++;
  m_object = player.m_object;
  LOBYTE(is_headshot) = v4;
  v6 = *(m_pointer - 1);
  packet->m_pointer = m_pointer;
  packet->m_pointer = m_pointer + 4;
  v7 = this->__vftable;
  LOBYTE(item_dict_id) = v6;
  v7->get_player(this, &player, (const unsigned __int8)m_object);
  survarium::game_world_ui::on_player_killed(
    is_headshot,
    (unsigned __int8)&this->m_game->m_fps_graph,
    (unsigned __int8)m_object,
    (bool)is_headshot,
    item_dict_id);
  v8 = player.m_object;
  if ( player.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && player.m_object->m_has_been_inserted
      && player.m_object->m_is_alive )
    {
      survarium::player::kill((survarium::player *)this->m_last_tick_time_in_ms, this->m_last_tick_time_in_ms);
      v8 = player.m_object;
    }
    if ( v8 && !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
    {
      if ( player.m_object )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &player.m_object->vostok::resources::unmanaged_intrusive_base,
          &player.m_object->vostok::resources::unmanaged_resource);
      else
        vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)0x1F0, 0);
    }
  }
}
