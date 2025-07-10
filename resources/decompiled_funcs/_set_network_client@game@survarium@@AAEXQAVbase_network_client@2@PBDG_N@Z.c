void __userpurge survarium::game::set_network_client(
        survarium::base_network_client *const network_client@<ecx>,
        const char *host@<eax>,
        survarium::game *this,
        int port,
        bool is_spectator)
{
  survarium::base_network_client_vtbl *v6; // eax
  vostok::network::login_client *v7; // edi
  char *v8; // eax
  char *m_buffer; // ecx
  char *v10; // eax
  char *v11; // ecx
  vostok::fixed_string<128> name; // [esp+10h] [ebp-120h] BYREF
  char v13; // [esp+9Ch] [ebp-94h] BYREF
  vostok::fixed_string<128> password; // [esp+A0h] [ebp-90h] BYREF
  char v15; // [esp+12Ch] [ebp-4h] BYREF

  this->m_network_client = network_client;
  if ( network_client->has_bandwidth(network_client) )
  {
    v6 = this->m_network_client->__vftable;
    if ( is_spectator )
    {
      ((void (__stdcall *)(const char *, int, const survarium::flash_text *, const survarium::flash_text *))v6->connect_to_login)(
        host,
        port,
        &buf,
        &buf);
    }
    else
    {
      v7 = (vostok::network::login_client *)((int (*)(void))v6->login_client)();
      strcpy_s(v7->m_server_host, 0x40u, host);
      v7->m_server_port = port;
      v8 = vostok::network::login_client::account_name(v7);
      m_buffer = name.m_buffer;
      name.m_end = name.m_buffer;
      name.m_buffer[0] = 0;
      if ( v8 )
      {
        for ( ; *v8; ++name.m_end )
        {
          if ( m_buffer >= &v13 )
            break;
          *m_buffer = *v8;
          m_buffer = name.m_end + 1;
          ++v8;
        }
        *m_buffer = 0;
      }
      v10 = vostok::network::login_client::account_password(v7);
      v11 = password.m_buffer;
      password.m_begin = password.m_buffer;
      password.m_end = password.m_buffer;
      password.m_max_end = &v15;
      password.m_buffer[0] = 0;
      if ( v10 )
      {
        for ( ; *v10; ++password.m_end )
        {
          if ( v11 >= password.m_max_end )
            break;
          *v11 = *v10;
          v11 = password.m_end + 1;
          ++v10;
        }
        *v11 = 0;
      }
      survarium::game::switch_to_login((survarium::game *)v11, (int)this, login_menu_status_disconnected);
    }
  }
}
