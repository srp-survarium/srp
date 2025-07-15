void __thiscall survarium::network_client::on_new_input(survarium::network_client *this, unsigned int game_time_in_ms)
{
  unsigned int v3; // esi
  survarium::base_match_client *v4; // eax

  v3 = survarium::network_client::try_send_all(this, (int)this, game_time_in_ms, 1);
  if ( this->m_match_client->m_last_send_queed_packets_time_in_ms != v3 )
  {
    v4 = this->match_client(this);
    v4->send_queued_packets(v4, v3);
  }
}
