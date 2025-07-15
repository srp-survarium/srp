void __thiscall vostok::network::login_client_impl::login_client_impl(
        vostok::network::login_client_impl *this,
        boost::asio::io_service *io_service)
{
  survarium::game_options *v2; // eax
  boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,vostok::network::login_client_impl,bool,boost::asio::ssl::verify_context &>,boost::_bi::list3<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::arg<2> > > *v3; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+64h] [ebp-4Ch] BYREF
  char v6; // [esp+6Fh] [ebp-41h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > filename; // [esp+70h] [ebp-40h] BYREF
  boost::posix_time::time_duration expiry_time; // [esp+88h] [ebp-28h] BYREF
  int family; // [esp+90h] [ebp-20h]
  boost::asio::ip::detail::endpoint v10; // [esp+94h] [ebp-1Ch] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
    &this->m_socket,
    io_service);
  boost::asio::ssl::context::context(&this->m_ssl_context, sslv23);
  boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>(
    &this->m_ssl_stream,
    &this->m_socket,
    &this->m_ssl_context);
  family = 2;
  boost::asio::ip::detail::endpoint::endpoint(&v10, 2, 0);
  boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>(
    &this->m_ping_socket,
    io_service,
    (const boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *)&v10);
  boost::posix_time::time_duration::time_duration(&expiry_time, 0, 0, 1, 0);
  boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(
    &this->m_ping_timer,
    io_service,
    &expiry_time);
  this->m_io_service = io_service;
  this->m_client_state = signed_in;
  this->m_connection_state = connected;
  this->m_session_id = 0;
  this->m_host_port = -1;
  this->m_in_destructor = 0;
  this->m_server_browser_address[0] = 0;
  this->m_server_browser_initial_query[0] = 0;
  v2 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v6);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &filename,
    "../../resources/ssl/survarium_login_server.crt",
    (const stlp_std::allocator<char> *)v2);
  boost::asio::ssl::context::load_verify_file(&this->m_ssl_context, &filename);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&filename);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v6);
  boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>::set_verify_mode(
    &this->m_ssl_stream,
    1);
  v3 = (boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,vostok::network::login_client_impl,bool,boost::asio::ssl::verify_context &>,boost::_bi::list3<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::arg<2> > > *)boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::login_client_impl::verify_ssl_certificate, (vostok::sound::sound_debug_stats *)this);
  boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>::set_verify_callback<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,vostok::network::login_client_impl,bool,boost::asio::ssl::verify_context &>,boost::_bi::list3<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::arg<2>>>>(
    &this->m_ssl_stream,
    *v3);
  this->m_host[0] = 0;
  this->m_host_ip[0] = 0;
}
