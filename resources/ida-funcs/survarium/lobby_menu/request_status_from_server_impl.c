void __thiscall survarium::lobby_menu::request_status_from_server_impl(
        survarium::lobby_menu *this,
        const unsigned int frame_delta_ms,
        const unsigned int current_time_ms)
{
  survarium::scheduler *v4; // ecx
  survarium::lobby_client *v5; // eax
  survarium::lobby_client *v6; // ecx

  if ( survarium::lobby_menu::lobby_client(this, (int)this)->m_net_client_connected )
  {
    if ( *(_DWORD *)&this->m_update_status_handler < 0 )
      survarium::scheduler::unregister(v4, (int)&this->m_scheduler, &this->m_update_status_handler);
    v5 = survarium::lobby_menu::lobby_client((survarium::lobby_menu *)v4, (int)this);
    survarium::lobby_client::query_client_status(v6, (const vostok::network_core::tcp_packet *)v5, 0);
  }
}
