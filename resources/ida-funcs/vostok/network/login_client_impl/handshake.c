void __thiscall vostok::network::login_client_impl::handshake(
        vostok::network::login_client_impl *this,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *functor,
        vostok::network::login_client_impl *retry_count,
        boost::arg<1> stop_timer)
{
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client_impl,boost::system::error_code const &,boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> const &,unsigned int,bool>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> >,boost::_bi::value<unsigned int>,boost::_bi::value<bool> > > *v5; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v7; // [esp-20h] [ebp-68h] BYREF
  boost::asio::ssl::stream_base::handshake_type v8; // [esp+0h] [ebp-48h]
  _BYTE v9[16]; // [esp+8h] [ebp-40h] BYREF
  int v10[12]; // [esp+18h] [ebp-30h] BYREF

  if ( this->m_connection_state == handshaked )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)this,
      functor,
      0);
  }
  else
  {
    this->m_connection_state = handshaking;
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(functor, &v7);
    v5 = boost::bind<void,vostok::network::login_client_impl,boost::system::error_code const &,boost::function<void __cdecl (enum vostok::handshaking_error_types_enum)> const &,unsigned int,bool,vostok::network::login_client_impl *,boost::arg<1>,boost::function<void __cdecl (enum vostok::handshaking_error_types_enum)>,unsigned int,bool>(
           (int)v9,
           (boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client_impl,boost::system::error_code const &,boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> const &,unsigned int,bool>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> >,boost::_bi::value<unsigned int>,boost::_bi::value<bool> > > *)this,
           (void (__thiscall *)(vostok::network::login_client_impl *, const boost::system::error_code *, const boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> *, unsigned int, bool))*(unsigned __int8 *)boost::asio::placeholders::`anonymous namespace'::error,
           retry_count,
           stop_timer,
           v7);
    boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>::async_handshake<boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client_impl,boost::system::error_code const &,boost::function<void __cdecl (enum vostok::handshaking_error_types_enum)> const &,unsigned int,bool>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (enum vostok::handshaking_error_types_enum)>>,boost::_bi::value<unsigned int>,boost::_bi::value<bool>>>>(
      v5,
      &this->m_ssl_stream,
      v8);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, v10);
  }
}
