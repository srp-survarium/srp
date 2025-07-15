void __thiscall survarium::network_client::on_disconnected_from_lobby(survarium::network_client *this)
{
  survarium::lobby_menu *m_lobby_menu; // eax

  m_lobby_menu = this->m_game->m_lobby_menu;
  if ( m_lobby_menu->m_is_connected_to_lobby )
  {
    m_lobby_menu->m_is_connected_to_lobby = 0;
    survarium::lobby_menu::show_disconnected_message((survarium::lobby_menu *)this, (bool)m_lobby_menu);
  }
}
