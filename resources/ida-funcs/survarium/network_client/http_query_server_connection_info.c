char __thiscall survarium::network_client::http_query_server_connection_info(
        survarium::network_client *this,
        survarium::network_client *type,
        unsigned __int8 a3)
{
  vostok::network::login_client_impl *m_client; // eax
  const char *m_server_browser_initial_query; // esi
  int v7; // edi
  int v8; // eax
  boost::function<void __cdecl(char const *)> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::network_client,char const *,unsigned char>,boost::_bi::list3<boost::_bi::value<survarium::network_client *>,boost::arg<1>,boost::_bi::value<unsigned char> > > v11; // [esp-14h] [ebp-45Ch]
  char path[512]; // [esp+10h] [ebp-438h] BYREF
  vostok::buffer_string v13; // [esp+210h] [ebp-238h] BYREF
  _BYTE v14[512]; // [esp+21Ch] [ebp-22Ch] BYREF
  char v15; // [esp+41Ch] [ebp-2Ch] BYREF
  unsigned int v16; // [esp+424h] [ebp-24h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+428h] [ebp-20h] BYREF
  char *server; // [esp+450h] [ebp+8h]

  v13.m_begin = v14;
  v13.m_end = v14;
  v13.m_max_end = &v15;
  v14[0] = 0;
  if ( vostok::command_line::key::is_set_as_string(
         (vostok::command_line::key *)this,
         &s_net_login_client.m_string_value,
         &v13) )
  {
    if ( type->m_http_client.m_busy )
      return 0;
    m_client = type->m_login_client.m_client;
    server = m_client->m_server_browser_address;
    m_server_browser_initial_query = m_client->m_server_browser_initial_query;
    v7 = (int)type->login_client(type);
    v8 = (int)type->login_client(type);
    vostok::sprintf<512>(
      (char (*)[512])path,
      "%s&type=%d&local_ip=%s&login_ip=%s&ver=%s",
      m_server_browser_initial_query,
      a3,
      (const char *)(v7 + 324),
      (const char *)(*(_DWORD *)(v8 + 316) + 583),
      "0.20e");
    LOBYTE(v9) = a3;
    f.functor.vostok_pointer_size_alignment[3] = 0;
    f.functor.vostok_pointer_size_alignment[2] = survarium::network_client::on_http_result_ready;
    LOBYTE(v16) = a3;
    *((_QWORD *)&f.functor.data + 2) = __PAIR64__(v16, (unsigned int)type);
    HIDWORD(v11.f_.f_) = survarium::network_client::on_http_result_ready;
    v11.l_.a1_.t_ = 0;
    *(_DWORD *)&v11.l_.a3_.t_ = type;
    LODWORD(v11.f_.f_) = &f;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(v9, v11, v16);
    vostok::network::http_client::get(&type->m_http_client, &f, server, path);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v10,
      (int *)&f);
  }
  else if ( a3 == 2 )
  {
    survarium::network_client::on_http_result_ready(type, "188.93.23.27:25101", 2u);
  }
  else if ( a3 == 4 )
  {
    survarium::network_client::on_http_result_ready(type, "188.93.23.27:25102", 4u);
  }
  return 1;
}
