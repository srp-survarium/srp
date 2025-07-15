void __thiscall vostok::network::login_client_impl::on_ping_sent(
        vostok::network::login_client_impl *this,
        unsigned int try_count,
        const boost::system::error_code *error_code,
        unsigned int bytes_transferred)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  BOOL v5; // ecx
  bool has_passed_filters; // al
  __int128 v7; // [esp-Ch] [ebp-200h]
  char v9; // [esp+184h] [ebp-70h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *> > > result; // [esp+188h] [ebp-6Ch] BYREF
  boost::posix_time::time_duration expiry_time; // [esp+194h] [ebp-60h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v12; // [esp+19Ch] [ebp-58h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+1BCh] [ebp-38h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v14; // [esp+1DCh] [ebp-18h] BYREF

  v9 = 0;
  v4 = error_code->m_val != 0
     ? (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
     : 0;
  if ( v4 )
  {
    vostok::network::login_client_impl::ping(this, try_count - 1);
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network:", error),
          v5 = has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v5);
      v9 = 3;
      error_code->m_cat->message(error_code->m_cat, &v14, error_code->m_val);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\login_client_impl_ping.cpp",
        0x14u,
        "void __thiscall vostok::network::login_client_impl::on_ping_sent(const unsigned int,const class boost::system::e"
        "rror_code &,const unsigned int)",
        "network:",
        error,
        "[LOGIN] ping: error during writing to socket: %s\r\n",
        v14._M_start_of_storage._M_data);
    }
    if ( (v9 & 2) != 0 )
    {
      v9 &= ~2u;
      stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v14);
    }
    if ( (v9 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v5,
        (int *)&log_callback);
  }
  else if ( bytes_transferred )
  {
    expiry_time.ticks_.value_ = boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count(
                                  0,
                                  0,
                                  1,
                                  0);
    boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::expires_from_now(
      &this->m_ping_timer,
      &expiry_time);
    *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > *)&v7 = *boost::bind<void,vostok::network::match_client,vostok::network_core::udp_network_flow_emulator_options const *,vostok::network::match_client *,vostok::network_core::udp_network_flow_emulator_options const *>((boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > *)&result, (void (__thiscall *)(vostok::sound::sound_voice *, void *))vostok::network::login_client_impl::ping, (vostok::sound::sound_voice *)this, (vostok::network_core::tcp_packet *)0xA);
    boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime>>::async_wait<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::login_client_impl,unsigned int>,boost::_bi::list2<boost::_bi::value<vostok::network::login_client_impl *>,boost::_bi::value<enum vostok::network::login_client_impl::_unnamed_tag_>>>>(
      &this->m_ping_timer.service->service_impl_,
      &this->m_ping_timer.implementation,
      v7);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network:", error) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v4);
      v9 = 4;
      vostok::logging::append(
        &v12,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\login_client_impl_ping.cpp",
        0x19u,
        "void __thiscall vostok::network::login_client_impl::on_ping_sent(const unsigned int,const class boost::system::e"
        "rror_code &,const unsigned int)",
        "network:",
        error,
        "[LOGIN] ping: unable to write to socket\r\n");
    }
    if ( (v9 & 4) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v4,
        (int *)&v12);
  }
}
