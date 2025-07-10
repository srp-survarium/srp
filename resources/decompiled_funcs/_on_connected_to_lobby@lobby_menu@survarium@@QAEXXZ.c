void __usercall survarium::lobby_menu::on_connected_to_lobby(
        survarium::lobby_menu *this@<ecx>,
        survarium::lobby_menu *a2@<eax>)
{
  survarium::lobby_menu *v3; // ecx

  survarium::lobby_menu::query_lobby_info(this, (int)a2);
  if ( !a2->m_is_connected_to_lobby )
  {
    a2->m_is_connected_to_lobby = 1;
    survarium::lobby_menu::show_disconnected_message(v3, a2, 0);
  }
}
