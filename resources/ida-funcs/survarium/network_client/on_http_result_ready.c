void __thiscall survarium::network_client::on_http_result_ready(
        survarium::network_client *this,
        char *content,
        unsigned __int8 type)
{
  vostok::network::login_client *v4; // eax
  vostok::network::login_client *(__thiscall *login_client)(struct survarium::network_client *); // edx
  vostok::network::login_client *v6; // eax
  char *v7; // eax
  survarium::lobby_client *v8; // eax
  survarium::lobby_client *v9; // ecx
  survarium::messaging_client *v10; // eax
  survarium::lobby_client *v11; // eax
  survarium::messaging_client *v12; // eax
  vostok::server_connection_info connection_info; // [esp+8h] [ebp-80h] BYREF

  v4 = this->login_client(this);
  connection_info.session_id = vostok::network::login_client::session_id(v4);
  login_client = this->login_client;
  connection_info.need_resolve = 0;
  v6 = login_client(this);
  v7 = vostok::network::login_client::account_password(v6);
  strcpy_s(connection_info.password, 0x30u, v7);
  if ( vostok::network_core::get_connection_info_from_string(content, connection_info.host, &connection_info.port) )
  {
    if ( type == 2 )
    {
      v8 = this->lobby_client(this);
      survarium::lobby_client::connect(v9, (int)v8, &connection_info);
    }
    else if ( type == 4 )
    {
      v10 = this->messaging_client(this);
      survarium::messaging_client::connect(v10, &connection_info);
    }
  }
  else if ( type == 2 )
  {
    this->lobby_client(this)->m_connection_info.need_resolve = 1;
    v11 = this->lobby_client(this);
    ++v11->m_connection_info.connection_error_count;
  }
  else if ( type == 4 )
  {
    this->messaging_client(this)->m_connection_info.need_resolve = 1;
    v12 = this->messaging_client(this);
    ++v12->m_connection_info.connection_error_count;
  }
}
