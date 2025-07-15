void __thiscall survarium::timelimit_rule::tick(
        survarium::timelimit_rule *this,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  survarium::base_network_client_vtbl *m_current_state; // eax

  survarium::timelimit_rule_core::tick(this, time_delta_ms, current_time_ms);
  if ( this->m_game->m_network_client->has_bandwidth(this->m_game->m_network_client)
    && current_time_ms > this->m_game_world_core->m_max_current_time_in_ms )
  {
    m_current_state = (survarium::base_network_client_vtbl *)this->m_current_state;
    if ( this->m_game->m_network_client[740].__vftable != m_current_state )
      survarium::network_client::set_game_status(
        (survarium::game_status)m_current_state,
        (const char *)this,
        (survarium::network_client *)this->m_game->m_network_client);
  }
}
