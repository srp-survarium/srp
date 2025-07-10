void __thiscall survarium::network_client::send_player_inputs(
        survarium::network_client *this,
        survarium::network_client *thisa)
{
  survarium::network_client *v2; // edi
  survarium::client_player_update *m_begin; // esi
  survarium::client_player_update *m_end; // ebx
  vostok::network::match_client *p_m_client; // edi
  vostok::network_core::udp_match_packet *v6; // ebp

  v2 = thisa;
  m_begin = thisa->m_player_inputs.m_begin;
  m_end = thisa->m_player_inputs.m_end;
  if ( m_begin != m_end )
  {
    p_m_client = &thisa->m_match_client.m_client;
    do
    {
      v6 = vostok::network::match_client::new_packet(p_m_client, 0x43u);
      survarium::client_player_update::serialize(m_begin, v6);
      vostok::network::match_client::enqueue(p_m_client, v6);
      ++m_begin;
      thisa->m_match_client.m_are_there_any_packets_to_send = 1;
    }
    while ( m_begin != m_end );
    v2 = thisa;
  }
  v2->m_player_inputs.m_end = v2->m_player_inputs.m_begin;
}
