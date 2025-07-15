unsigned int __thiscall survarium::generic_anomaly_cook::seed(survarium::generic_anomaly_cook *this)
{
  survarium::base_network_client *m_network_client; // ecx

  m_network_client = this->m_game_world->m_game->m_network_client;
  return m_network_client->match_options(m_network_client)->match_id;
}
