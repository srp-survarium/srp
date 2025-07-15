void __thiscall survarium::lobby_menu::request_squad_status_from_server_impl(
        survarium::lobby_menu *this,
        const unsigned int frame_delta_ms,
        const unsigned int current_time_ms)
{
  survarium::lobby_menu *v4; // ecx
  survarium::lobby_client *v5; // eax
  survarium::lobby_client *v6; // ecx

  if ( *(_DWORD *)&this->m_update_squad_status_handler < 0 )
    survarium::scheduler::unregister(
      (survarium::scheduler *)this,
      (int)&this->m_scheduler,
      &this->m_update_squad_status_handler);
  if ( survarium::lobby_menu::lobby_client(this, (int)this)->m_net_client_connected )
  {
    v5 = survarium::lobby_menu::lobby_client(v4, (int)this);
    survarium::lobby_client::query_squad_info(v6, (int)v5);
    survarium::lobby_menu::request_squad_status_from_server(this, 0x1388u);
  }
}
