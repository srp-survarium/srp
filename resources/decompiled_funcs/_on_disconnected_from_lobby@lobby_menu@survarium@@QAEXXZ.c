void __usercall survarium::lobby_menu::on_disconnected_from_lobby(
        survarium::lobby_menu *this@<ecx>,
        survarium::lobby_menu *a2@<eax>)
{
  if ( a2->m_is_connected_to_lobby )
  {
    a2->m_is_connected_to_lobby = 0;
    survarium::lobby_menu::show_disconnected_message(this, a2, 1);
  }
}
