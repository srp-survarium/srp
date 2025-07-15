void __thiscall survarium::messaging_client::connect(
        survarium::messaging_client *this,
        survarium::messaging_client *connection_info,
        const void *a3)
{
  unsigned int connection_error_count; // edx
  vostok::network::tcp_packet_client *v4; // ecx

  connection_error_count = connection_info->m_connection_info.connection_error_count;
  qmemcpy(&connection_info->m_connection_info, a3, sizeof(connection_info->m_connection_info));
  connection_info->m_connection_info.connection_error_count = connection_error_count;
  if ( *(_DWORD *)&connection_info->m_scheduler_identifier < 0 )
    survarium::scheduler::unregister(
      0,
      (int)&connection_info->m_game->m_scheduler,
      &connection_info->m_scheduler_identifier);
  if ( connection_info->m_connection_state != client_disconnected )
    survarium::messaging_client::disconnect(connection_info);
  if ( vostok::strings::compare(connection_info->m_connection_info.host, "x") )
  {
    if ( connection_info->m_connection_info.port )
      vostok::network::tcp_packet_client::connect(
        v4,
        (const char *)&connection_info->m_network_client,
        connection_info->m_connection_info.host,
        connection_info->m_connection_info.port);
  }
}
