void __fastcall survarium::messaging_client::connect(
        int a1,
        const vostok::server_connection_info *connection_info,
        survarium::messaging_client *this)
{
  bool v3; // zf
  unsigned int connection_error_count; // eax
  survarium::messaging_client *v5; // ecx

  v3 = *(_DWORD *)&this->m_scheduler_identifier >= 0;
  connection_error_count = this->m_connection_info.connection_error_count;
  qmemcpy(&this->m_connection_info, connection_info, sizeof(this->m_connection_info));
  v5 = 0;
  this->m_connection_info.connection_error_count = connection_error_count;
  if ( !v3 )
    survarium::scheduler::unregister(&this->m_game->m_scheduler, &this->m_scheduler_identifier);
  if ( this->m_connection_state != client_disconnected )
    survarium::messaging_client::disconnect(v5, (int)this);
  if ( strcmp(this->m_connection_info.host, "x") )
  {
    if ( this->m_connection_info.port )
      vostok::network::tcp_packet_client::connect(
        &this->m_network_client,
        this->m_connection_info.host,
        this->m_connection_info.port);
  }
}
