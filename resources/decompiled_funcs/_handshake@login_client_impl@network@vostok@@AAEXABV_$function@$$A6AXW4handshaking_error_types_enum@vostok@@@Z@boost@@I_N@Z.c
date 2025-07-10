void __thiscall vostok::network::login_client_impl::handshake(
        vostok::network::login_client_impl *this,
        boost::function1<void,vostok::ai::sensors::sensed_object const &> *functor,
        unsigned int retry_count,
        bool stop_timer)
{
  vostok::network::login_client_impl *v4; // ecx
  boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> v5; // [esp-28h] [ebp-254h] BYREF
  unsigned int v6; // [esp-8h] [ebp-234h]
  BOOL v7; // [esp-4h] [ebp-230h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client_impl,boost::system::error_code const &,boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> const &,unsigned int,bool>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> >,boost::_bi::value<unsigned int>,boost::_bi::value<bool> > > *handler; // [esp+4h] [ebp-228h]
  vostok::network::login_client_impl *thisa; // [esp+8h] [ebp-224h]
  boost::function1<void,enum vostok::handshaking_error_types_enum> *v10; // [esp+8Ch] [ebp-1A0h]
  int v11; // [esp+1C0h] [ebp-6Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client_impl,boost::system::error_code const &,boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> const &,unsigned int,bool>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> >,boost::_bi::value<unsigned int>,boost::_bi::value<bool> > > result; // [esp+1C4h] [ebp-68h] BYREF
  char v13; // [esp+20Bh] [ebp-21h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20Ch] [ebp-20h] BYREF

  thisa = this;
  v11 = 0;
  if ( this->m_connection_state == 6 )
  {
    boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(functor, 0);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network:", info) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this);
      v11 |= 1u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\login_client_impl_handshake.cpp",
        0x40u,
        "void __thiscall vostok::network::login_client_impl::handshake(const class boost::function<void __cdecl(enum vost"
        "ok::handshaking_error_types_enum)> &,unsigned int,bool)",
        "network:",
        info,
        "[LOGIN] handshaking...\r\n");
    }
    if ( (v11 & 1) != 0 )
    {
      v11 &= ~1u;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)this,
        (int *)&log_callback);
    }
    v13 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    v4 = thisa;
    thisa->m_connection_state = 5;
    v7 = stop_timer;
    v6 = retry_count;
    v10 = &v5;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v4,
      &v5);
    boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
      v10,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)functor);
    handler = boost::bind<void,vostok::network::login_client_impl,boost::system::error_code const &,boost::function<void __cdecl (enum vostok::handshaking_error_types_enum)> const &,unsigned int,bool,vostok::network::login_client_impl *,boost::arg<1>,boost::function<void __cdecl (enum vostok::handshaking_error_types_enum)>,unsigned int,bool>(
                &result,
                (void (__thiscall *)(vostok::network::login_client_impl *, const boost::system::error_code *, const boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> *, unsigned int, bool))vostok::network::login_client_impl::on_handshaked,
                thisa,
                *(boost::arg<1> *)boost::asio::placeholders::`anonymous namespace'::error,
                v5,
                v6,
                v7);
    boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>::async_handshake<boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client_impl,boost::system::error_code const &,boost::function<void __cdecl (enum vostok::handshaking_error_types_enum)> const &,unsigned int,bool>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (enum vostok::handshaking_error_types_enum)>>,boost::_bi::value<unsigned int>,boost::_bi::value<bool>>>>(
      &thisa->m_ssl_stream,
      client,
      handler);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&result.l_.a3_);
  }
}
