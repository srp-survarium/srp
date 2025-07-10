void __thiscall survarium::booby_trap::defuse_completed(survarium::booby_trap *this)
{
  survarium::base_network_client *m_network_client; // ecx

  m_network_client = this->m_game_world->m_game->m_network_client;
  if ( !m_network_client->has_bandwidth(m_network_client) )
    survarium::booby_trap_core::defuse_completed(this);
}
