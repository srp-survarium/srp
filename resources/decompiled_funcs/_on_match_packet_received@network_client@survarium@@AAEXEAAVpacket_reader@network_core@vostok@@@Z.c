void __thiscall survarium::network_client::on_match_packet_received(
        survarium::network_client *this,
        unsigned __int8 message_type,
        vostok::network_core::packet_reader *packet)
{
  const unsigned __int8 *m_pointer; // eax
  survarium::player *v5; // ebx

  switch ( message_type )
  {
    case 0x81u:
      survarium::network_client::process_match_info(packet, this);
      break;
    case 0x82u:
      m_pointer = packet->m_pointer;
      v5 = *(survarium::player **)m_pointer;
      packet->m_pointer = m_pointer + 4;
      do
        survarium::network_client::process_player_action(this, packet, v5);
      while ( packet->m_pointer != &packet->m_packet->m_buffer[packet->m_packet->m_buffer_size] );
      break;
    case 0x83u:
      survarium::network_client::process_player_kill(this, packet);
      break;
    case 0x84u:
      survarium::network_client::process_player_respawn(packet, this);
      break;
    case 0x85u:
      survarium::network_client::process_base_capture_progress((survarium::network_client *)packet, this);
      break;
    case 0x86u:
      survarium::network_client::process_match_time((int)this, packet, this);
      break;
    case 0x87u:
      survarium::network_client::process_respawn_timer((int)this, packet, this);
      break;
    case 0x88u:
      survarium::network_client::process_player_kd_stats(packet, (unsigned int)this, this);
      break;
    case 0x89u:
      survarium::network_client::process_player_hit((survarium::network_client *)packet, (int)this, packet);
      break;
    case 0x8Au:
      survarium::network_client::process_affect_damage_model(this, packet);
      break;
    case 0x8Bu:
      survarium::network_client::process_sync_response(this, this, packet);
      break;
    case 0x8Cu:
      this->close_current_match(this, 0);
      break;
  }
}
