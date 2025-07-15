void __thiscall survarium::game::switch_to_login(
        survarium::game *this,
        survarium::game *status,
        survarium::login_menu_status_enum statusa)
{
  if ( status->m_network_client->has_bandwidth(status->m_network_client) )
  {
    survarium::login_menu::set_status(status->m_login_menu, statusa);
    survarium::game::switch_to_scene(status, status->m_login_menu);
  }
}
