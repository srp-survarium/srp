void __userpurge survarium::game::set_network_client(
        survarium::game *this@<edi>,
        survarium::base_network_client *const network_client@<eax>,
        unsigned __int16 port@<cx>,
        char *host,
        const bool is_spectator)
{
  survarium::base_network_client *m_network_client; // ecx
  int v7; // ebx
  vostok::fixed_string<128> *v8; // ecx
  survarium::game *v9; // ecx
  vostok::fixed_string<128> *v10; // [esp-4h] [ebp-144h]
  vostok::buffer_string v11[12]; // [esp+8h] [ebp-138h] BYREF
  vostok::buffer_string v12[12]; // [esp+98h] [ebp-A8h] BYREF
  char *v13; // [esp+12Ch] [ebp-14h] BYREF
  unsigned __int16 v14; // [esp+130h] [ebp-10h]
  const char *v15; // [esp+134h] [ebp-Ch]
  const char *v16; // [esp+138h] [ebp-8h]
  char v17; // [esp+13Ch] [ebp-4h]

  this->m_network_client = network_client;
  if ( vostok::core::journal_usage() != replay_journal && this->m_network_client->has_bandwidth(this->m_network_client) )
  {
    m_network_client = this->m_network_client;
    if ( is_spectator )
    {
      v15 = uri;
      v16 = uri;
      v13 = host;
      v14 = port;
      v17 = 0;
      m_network_client->connect_to_login(m_network_client, (const vostok::sign_in_info *)&v13);
    }
    else
    {
      v7 = (int)m_network_client->login_client(m_network_client);
      vostok::strings::copy<64>((char (*)[64])(v7 + 340), host);
      *(_WORD *)(v7 + 404) = port;
      vostok::fixed_string<128>::fixed_string<128>(v10, v12, s_net_client_account_name);
      vostok::fixed_string<128>::fixed_string<128>(v8, v11, (char *)(v7 + 406));
      survarium::game::switch_to_login(v9, this, login_menu_status_disconnected);
    }
  }
}
