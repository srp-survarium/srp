void __thiscall vostok::network::login_client_impl::~login_client_impl(vostok::network::login_client_impl *this)
{
  const boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum)> *v1; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  const boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum)> *v3; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx
  vostok::network::login_client_impl::client_state_enum v5; // [esp+4h] [ebp-D0h]
  vostok::network::login_client_impl::client_state_enum m_client_state; // [esp+8h] [ebp-CCh]
  vostok::network::login_client_impl::connection_state_enum m_connection_state; // [esp+Ch] [ebp-C8h]
  int v9[8]; // [esp+94h] [ebp-40h] BYREF
  int v10[8]; // [esp+B4h] [ebp-20h] BYREF

  this->m_in_destructor = 1;
  do
  {
    m_connection_state = this->m_connection_state;
    if ( m_connection_state == connected )
      break;
    if ( m_connection_state == 4 )
    {
      m_client_state = this->m_client_state;
      if ( m_client_state != signed_in )
      {
        if ( m_client_state == 3 )
        {
          boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
            (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this->m_client_state,
            v10);
          vostok::network::login_client_impl::sign_out(this, v1);
          boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
            v2,
            v10);
        }
        goto LABEL_17;
      }
    }
    else
    {
      if ( m_connection_state != 6 )
        goto LABEL_17;
      v5 = this->m_client_state;
      if ( v5 != signed_in )
      {
        if ( v5 == 3 )
        {
          boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
            (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
            v9);
          vostok::network::login_client_impl::sign_out(this, v3);
          boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
            v4,
            v9);
        }
        goto LABEL_17;
      }
    }
    vostok::network::login_client_impl::close_connection(this, 1);
LABEL_17:
    boost::asio::io_service::run_one(this->m_io_service);
  }
  while ( this->m_connection_state );
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::~basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(&this->m_ping_timer);
  boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>::~basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>(&this->m_ping_socket);
  boost::asio::ssl::detail::stream_core::~stream_core(&this->m_ssl_stream.core_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(&this->m_ssl_stream.gap0 + 1));
  boost::asio::ssl::context::~context(&this->m_ssl_context);
  boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>::~basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>((boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp> > *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
