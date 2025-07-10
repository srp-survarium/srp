void __thiscall survarium::network_client::initiate_kill_current_player(survarium::network_client *this)
{
  survarium::match_client *p_m_match_client; // esi
  vostok::network_core::udp_match_packet *v2; // eax

  if ( this->m_local_player.m_object )
  {
    if ( this->m_current_player.m_object )
    {
      p_m_match_client = &this->m_match_client;
      v2 = vostok::network::match_client::new_packet(&this->m_match_client.m_client, 0x44u);
      vostok::network::match_client::enqueue(&p_m_match_client->m_client, v2);
      p_m_match_client->m_are_there_any_packets_to_send = 1;
    }
  }
}
