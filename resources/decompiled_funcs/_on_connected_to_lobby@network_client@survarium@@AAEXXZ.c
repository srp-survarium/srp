void __thiscall survarium::network_client::on_connected_to_lobby(survarium::network_client *this)
{
  survarium::lobby_menu *m_lobby_menu; // esi
  survarium::lobby_menu *v2; // ecx

  m_lobby_menu = this->m_game->m_lobby_menu;
  survarium::lobby_menu::query_lobby_info((survarium::lobby_menu *)this);
  if ( !m_lobby_menu->m_is_connected_to_lobby )
  {
    m_lobby_menu->m_is_connected_to_lobby = 1;
    survarium::lobby_menu::show_disconnected_message(v2, (bool)m_lobby_menu);
  }
}
