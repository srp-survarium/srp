void __thiscall survarium::game::commit_suicide(survarium::game *this)
{
  this->m_network_client->initiate_kill_current_player(this->m_network_client);
}
