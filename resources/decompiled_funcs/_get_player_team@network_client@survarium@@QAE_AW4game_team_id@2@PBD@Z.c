survarium::game_team_id __usercall survarium::network_client::get_player_team@<eax>(
        survarium::network_client *this@<esi>,
        const char *player_profile_name@<edi>)
{
  unsigned __int8 v2; // bl

  v2 = 0;
  while ( strcmp(player_profile_name, this->m_match_client.m_match_options.player_profiles[v2].profile_name) )
  {
    if ( ++v2 >= 0x14u )
      return 3;
  }
  return this->m_match_client.m_match_options.player_profiles[v2].team;
}
