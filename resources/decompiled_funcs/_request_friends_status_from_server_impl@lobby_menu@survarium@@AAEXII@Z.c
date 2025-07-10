void __thiscall survarium::lobby_menu::request_friends_status_from_server_impl(
        survarium::lobby_menu *this,
        unsigned int frame_delta_ms,
        unsigned int current_time_ms)
{
  survarium::messaging_client *v4; // eax
  survarium::messaging_client *v5; // ecx

  survarium::scheduler::unregister(&this->m_game->m_scheduler, &this->m_update_friends_status_handler);
  v4 = this->m_game->m_network_client->messaging_client(this->m_game->m_network_client);
  survarium::messaging_client::query_for_friends_status(v5, (int)v4);
}
