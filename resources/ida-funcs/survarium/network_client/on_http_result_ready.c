void __thiscall survarium::network_client::on_http_result_ready(
        survarium::network_client *this,
        char *content,
        unsigned __int8 type)
{
  survarium::network_client_vtbl *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // edi
  int v8; // eax
  survarium::lobby_client *v9; // eax
  unsigned int connection_error_count; // ebx
  survarium::messaging_client *v11; // eax
  survarium::messaging_client *v12; // ecx
  unsigned int *p_connection_error_count; // eax
  __int16 port; // [esp-4h] [ebp-9Ch]
  __int16 v15; // [esp+10h] [ebp-88h] BYREF
  _DWORD v16[32]; // [esp+18h] [ebp-80h] BYREF

  v16[0] = this->login_client(this)->m_client->m_session_id;
  v4 = this->__vftable;
  LOBYTE(v16[31]) = 0;
  v5 = (int)v4->login_client(this);
  strcpy_s((char *)&v16[17] + 2, 0x30u, (const char *)(v5 + 406));
  strchr(content, 0x3Au);
  v7 = v6;
  if ( v6
    && (strncpy_s((char *)&v16[1] + 2, 0x40u, content, v6 - (_DWORD)content),
        v8 = sscanf_s((const char *)(v7 + 1), "%d", &v15),
        strlen((const char *)&v16[1] + 2))
    && v8 == 1 )
  {
    LOWORD(v16[1]) = v15;
    if ( type == 2 )
    {
      v9 = this->lobby_client(this);
      connection_error_count = v9->m_connection_info.connection_error_count;
      qmemcpy(&v9->m_connection_info, v16, sizeof(v9->m_connection_info));
      port = v9->m_connection_info.port;
      v9->m_connection_info.connection_error_count = connection_error_count;
      vostok::network::tcp_packet_client::connect(
        (vostok::network::tcp_packet_client *)v9->m_connection_info.host,
        (const char *)&v9->m_packet_client,
        v9->m_connection_info.host,
        port);
    }
    else if ( type == 4 )
    {
      v11 = this->messaging_client(this);
      survarium::messaging_client::connect(v12, v11, v16);
    }
  }
  else
  {
    if ( type == 2 )
    {
      this->lobby_client(this)->m_connection_info.need_resolve = 1;
      p_connection_error_count = &this->lobby_client(this)->m_connection_info.connection_error_count;
    }
    else
    {
      if ( type != 4 )
        return;
      this->messaging_client(this)->m_connection_info.need_resolve = 1;
      p_connection_error_count = &this->messaging_client(this)->m_connection_info.connection_error_count;
    }
    ++*p_connection_error_count;
  }
}
