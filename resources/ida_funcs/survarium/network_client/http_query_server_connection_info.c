char __userpurge survarium::network_client::http_query_server_connection_info@<al>(
        survarium::network_client *this@<ecx>,
        survarium::network_client *a2@<esi>,
        unsigned __int8 type)
{
  char *v4; // ebp
  char *v5; // edi
  vostok::network::login_client *v6; // eax
  char *v7; // eax
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::network_client,char const *,unsigned char>,boost::_bi::list3<boost::_bi::value<survarium::network_client *>,boost::arg<1>,boost::_bi::value<unsigned char> > > v9; // [esp-10h] [ebp-458h]
  int v10; // [esp+0h] [ebp-448h]
  int v11; // [esp+10h] [ebp-438h]
  unsigned int v12; // [esp+14h] [ebp-434h]
  boost::function<void __cdecl(char const *)> callback; // [esp+18h] [ebp-430h] BYREF
  vostok::fixed_string<512> client_str; // [esp+38h] [ebp-410h] BYREF
  char v15; // [esp+244h] [ebp-204h] BYREF
  char request_str[512]; // [esp+248h] [ebp-200h] BYREF

  client_str.m_begin = client_str.m_buffer;
  client_str.m_end = client_str.m_buffer;
  client_str.m_max_end = &v15;
  client_str.m_buffer[0] = 0;
  if ( vostok::command_line::key::is_set_as_string(&s_net_login_client, (vostok::command_line::key *)&client_str) )
  {
    if ( a2->m_http_client.m_busy )
      return 0;
    v4 = vostok::network::login_client::server_browser_address(&a2->m_login_client);
    v5 = vostok::network::login_client::server_browser_initial_query(&a2->m_login_client);
    v11 = (int)a2->login_client(a2);
    v6 = a2->login_client(a2);
    v7 = vostok::network::login_client::host_ip_address(v6);
    sprintf_s<512>(
      (char (*)[512])request_str,
      "%s&type=%d&local_ip=%s&login_ip=%s",
      v5,
      type,
      (const char *)(v11 + 292),
      v7);
    callback.vtable = (boost::detail::function::vtable_base *)survarium::network_client::on_http_result_ready;
    LOBYTE(v12) = type;
    (&callback.vtable)[1] = 0;
    v9.f_.f_ = (void (__thiscall *__ptr64)(survarium::network_client *, const char *, unsigned __int8))(unsigned int)survarium::network_client::on_http_result_ready;
    *(_QWORD *)&callback.functor.obj_ptr = __PAIR64__(v12, (unsigned int)a2);
    v9.l_ = (boost::_bi::list3<boost::_bi::value<survarium::network_client *>,boost::arg<1>,boost::_bi::value<unsigned char> >)__PAIR64__(v12, (unsigned int)a2);
    boost::function1<void,char const *>::function1<void,char const *>(0, (int)&callback, (int)a2, v9, v10);
    vostok::network::http_client::get(&a2->m_http_client, v4, request_str, &callback);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v8 )
        {
          v8(&callback.functor, &callback.functor, 2);
          return 1;
        }
      }
    }
  }
  else if ( type == 2 )
  {
    survarium::network_client::on_http_result_ready(a2, "188.93.23.27:25101", 2u);
  }
  else if ( type == 4 )
  {
    survarium::network_client::on_http_result_ready(a2, "188.93.23.27:25102", 4u);
  }
  return 1;
}
