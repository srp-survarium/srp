void __thiscall survarium::network_client::process_sync_response(
        survarium::network_client *this,
        survarium::network_client *packet,
        vostok::network_core::packet_reader *packeta)
{
  unsigned __int64 v3; // rax
  vostok::network_core::udp_match_packet *v4; // eax
  survarium::player *v5; // ecx
  bool v6; // zf
  const vostok::network_core::base_packet *m_object; // eax
  survarium::base_network_client *v8; // ecx
  const unsigned __int8 *m_pointer; // eax
  int v10; // edi
  int v11; // ecx
  bool *p_is_connected; // eax
  int v13; // esi
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> v14; // [esp-4h] [ebp-18h] BYREF

  v3 = 1000 * vostok::timing::timer::get_elapsed_ticks(&packet->m_game->m_permanent_timer);
  v14.m_object = (survarium::player *)vostok::timing::g_qpc_per_second.HighPart;
  LODWORD(v3) = ((unsigned int)(v3 / vostok::timing::g_qpc_per_second.QuadPart) - packet->m_last_sync_request_time) >> 1;
  LOBYTE(v14.m_object) = 70;
  packet->m_server_latency = v3;
  v4 = vostok::network::match_client::new_packet(&packet->m_match_client.m_client, (unsigned __int8)v14.m_object);
  vostok::network::match_client::enqueue(&packet->m_match_client.m_client, v4);
  packet->m_match_client.m_are_there_any_packets_to_send = 1;
  v6 = packet->m_current_player.m_object == 0;
  packet->m_is_time_synchronized_first_time = 1;
  if ( v6 && packet->m_game_status == game_status_inprocess )
  {
    m_object = (const vostok::network_core::base_packet *)packet->m_local_player.m_object;
    if ( m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        && BYTE1(m_object[35].m_buffer) )
      {
        v14.m_object = v5;
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(
          &v14,
          &packet->m_local_player,
          (survarium::profile_player_character *)v5);
        survarium::base_network_client::attach_to_player(v8, v14);
      }
    }
  }
  m_pointer = packeta->m_pointer;
  v10 = *(_DWORD *)m_pointer;
  v11 = 0;
  packeta->m_pointer = m_pointer + 4;
  p_is_connected = &packet->m_net_players.elems[0].is_connected;
  v13 = 20;
  do
  {
    *p_is_connected = ((1 << v11++) & v10) != 0;
    p_is_connected += 8;
    --v13;
  }
  while ( v13 );
}
