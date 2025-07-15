void __userpurge survarium::network_client::process_player_profile(
        vostok::network_core::packet_reader *reader@<esi>,
        survarium::network_client *this)
{
  survarium::match_client *v2; // eax
  unsigned __int8 received_players_count; // cl
  survarium::match_options *p_m_match_options; // edi
  survarium::network_client *v5; // ecx

  v2 = this->match_client(this);
  received_players_count = v2->m_match_options.received_players_count;
  p_m_match_options = &v2->m_match_options;
  v2->m_match_options.received_players_count = received_players_count + 1;
  survarium::player_profile::deserialize(reader, &v2->m_match_options.player_profiles[received_players_count]);
  if ( p_m_match_options->received_players_count == p_m_match_options->players_count )
    survarium::network_client::query_players(v5, this);
}
