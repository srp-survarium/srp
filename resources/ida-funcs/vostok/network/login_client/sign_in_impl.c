void __thiscall vostok::network::login_client::sign_in_impl(
        vostok::network::login_client *this,
        const char *host,
        unsigned __int16 port,
        const char *account_name,
        const char *password,
        bool connect_from_eula_wnd)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login::server::messages_enum>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > v8; // [esp-8h] [ebp-48h]
  int v9; // [esp+0h] [ebp-40h]
  vostok::sign_in_info info; // [esp+Ch] [ebp-34h] BYREF
  boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login::server::messages_enum)> callback; // [esp+20h] [ebp-20h] BYREF

  info.host = host;
  info.port = port;
  info.account_email = account_name;
  info.password = password;
  info.connect_from_eula_wnd = connect_from_eula_wnd;
  v8.l_.a1_.t_ = this;
  v8.f_.f_ = (void (__thiscall *)(vostok::network::login_client *, vostok::connection_error_types_enum, vostok::handshaking_error_types_enum, vostok::socket_error_types_enum, vostok::login::server::messages_enum))vostok::network::login_client::on_signed_in;
  boost::function<void __cdecl (enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login::server::messages_enum)>::function<void __cdecl (enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login::server::messages_enum)>(
    (boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login::server::messages_enum)> *)this,
    (boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login::server::messages_enum>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > *)&callback,
    v8,
    v9);
  vostok::network::login_client_impl::sign_in(
    &info,
    this->m_client,
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&callback);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&callback);
}
