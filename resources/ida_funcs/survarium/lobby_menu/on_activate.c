void __thiscall survarium::lobby_menu::on_activate(survarium::lobby_menu *this)
{
  vostok::input::handler *v2; // edi
  vostok::input::world *v3; // eax
  survarium::lobby_menu *v4; // ecx

  survarium::base_game_scene::on_activate(this);
  if ( this )
    v2 = &this->vostok::input::handler;
  else
    v2 = 0;
  v3 = this->m_game->input_world(this->m_game);
  v3->add_handler(v3, v2);
  if ( this->m_game->m_network_client->lobby_client(this->m_game->m_network_client)->m_net_client_connected )
    survarium::lobby_menu::query_lobby_info(v4, (int)this);
  survarium::chat_handler::set_mode((survarium::chat_handler *)this->m_game, this->m_game->m_chat_handler, 0);
}
