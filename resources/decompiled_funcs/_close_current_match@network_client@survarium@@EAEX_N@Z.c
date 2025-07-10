void __thiscall survarium::network_client::close_current_match(survarium::network_client *this, bool user_initiate)
{
  int (*match_client)(void); // edx
  vostok::network::match_client *v4; // eax
  survarium::game_world *v5; // ecx
  survarium::match_client *v6; // eax
  survarium::game *v7; // ecx

  match_client = (int (*)(void))this->match_client;
  this->m_game_status = game_status_inactive;
  v4 = (vostok::network::match_client *)match_client();
  if ( vostok::network::match_client::is_connected(v4) )
  {
    v6 = this->match_client(this);
    vostok::network::match_client::disconnect(&v6->m_client);
  }
  survarium::game_world::unload(v5);
  if ( user_initiate )
    this->lobby_client(this)->m_discard_playing_order_on_connected = 1;
  if ( !this->lobby_client(this)->m_net_client_connected )
    this->lobby_client(this)->m_connection_info.need_resolve = 1;
  if ( !this->m_game->m_game_world.m_is_loading )
    survarium::game::switch_to_lobby(v7);
}
