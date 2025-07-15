void __thiscall survarium::lobby_menu::request_friends_status_from_server_impl(
        survarium::lobby_menu *this,
        const unsigned int frame_delta_ms,
        const unsigned int current_time_ms)
{
  survarium::messaging_client *v4; // eax
  survarium::messaging_client *v5; // ecx

  if ( *(_DWORD *)&this->m_update_friends_status_handler < 0 )
    survarium::scheduler::unregister(
      (survarium::scheduler *)this,
      (int)&this->m_scheduler,
      &this->m_update_friends_status_handler);
  v4 = survarium::lobby_menu::messaging_client(this, (int)this);
  survarium::messaging_client::query_for_friends_status(v5, (int)v4);
}
