void __thiscall vostok::network_core::udp_match_connection::fill_packet_header(
        vostok::network_core::udp_match_connection *this,
        vostok::network_core::udp_match_packet *packet)
{
  vostok::network_core::udp_match_packets_count_enum packet_type; // [esp+18h] [ebp-4h]

  packet_type = packet->m_buffer.elems[0];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&packet->m_buffer);
  *(_WORD *)packet->m_buffer.elems = packet->sequence_id.m_number;
  *(_WORD *)&packet->m_buffer.elems[2] = this->m_remote_sequence_id.m_number;
  *(_WORD *)&packet->m_buffer.elems[4] = (packet_type == udp_match_multiple_packets)
                                       | (unsigned __int16)(2 * this->m_remote_acknowledgement_bits);
}
