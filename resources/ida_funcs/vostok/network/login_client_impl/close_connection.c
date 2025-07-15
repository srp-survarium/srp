void __thiscall vostok::network::login_client_impl::close_connection(
        vostok::network::login_client_impl *this,
        bool stop_ping_timer)
{
  bool has_passed_filters; // al
  vostok::network::login_client_impl *thisa; // [esp+8h] [ebp-444h]
  char v4; // [esp+424h] [ebp-28h]
  boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > &> *v5; // [esp+428h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+42Ch] [ebp-20h] BYREF

  thisa = this;
  v4 = 0;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network:", info),
        (this = (vostok::network::login_client_impl *)has_passed_filters) != 0) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this);
    v4 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\login_client_impl.cpp",
      0x85u,
      "void __thiscall vostok::network::login_client_impl::close_connection(bool)",
      "network:",
      info,
      "[LOGIN] closed connection\r\n");
  }
  if ( (v4 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v4 & 1),
      (int *)&log_callback);
  if ( stop_ping_timer )
    boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::cancel(&thisa->m_ping_timer);
  boost::asio::ssl::detail::stream_core::~stream_core(&thisa->m_ssl_stream.core_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(&thisa->m_ssl_stream.gap0 + 1));
  v5 = (boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > &> *)operator new(0x98u, &thisa->m_ssl_stream);
  if ( v5 )
    boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>(
      v5,
      &thisa->m_socket,
      &thisa->m_ssl_context);
  boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::shutdown(
    &thisa->m_socket,
    shutdown_both);
  boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::close((boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *)thisa);
  thisa->m_connection_state = connected;
}
