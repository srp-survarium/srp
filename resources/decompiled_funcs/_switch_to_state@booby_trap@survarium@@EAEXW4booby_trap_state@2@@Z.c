void __thiscall survarium::booby_trap::switch_to_state(survarium::booby_trap *this, survarium::game_camera *new_state)
{
  survarium::base_network_client *m_network_client; // ecx
  survarium::booby_trap_state m_trap_state; // edi
  survarium::booby_trap *v5; // ecx

  m_network_client = this->m_game_world->m_game->m_network_client;
  m_trap_state = this->m_trap_state;
  if ( m_network_client->has_bandwidth(m_network_client) )
    this->m_trap_state = (survarium::booby_trap_state)new_state;
  else
    survarium::booby_trap_core::switch_to_state(this, new_state);
  if ( this->m_trap_state != m_trap_state )
    survarium::booby_trap::on_new_state(v5, (int)this, m_trap_state);
}
