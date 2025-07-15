void __thiscall survarium::network_client::connect_to_login(
        survarium::network_client *this,
        const vostok::sign_in_info *info)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  bool has_passed_filters; // al
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::network_client,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<survarium::network_client *>,boost::arg<1> > > v8; // [esp-Ch] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::network_client,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby::server::messages_enum>,boost::_bi::list5<boost::_bi::value<survarium::network_client *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > v9; // [esp-Ch] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::network_client,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,unsigned int>,boost::_bi::list5<boost::_bi::value<survarium::network_client *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > v10; // [esp-Ch] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp+4h] [ebp-34h]
  char v12; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(vostok::network_core::buffer_reader &)> f; // [esp+18h] [ebp-20h] BYREF

  v3 = 0;
  v12 = 0;
  if ( this->m_is_spectator )
  {
    this->m_last_tick_time_in_ms = this->m_game->m_current_time_in_ms;
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)4),
          v3 = v11,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v3,
        &f);
      v12 = 1;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&f,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\network_client.cpp",
        0x19Eu,
        "void __thiscall survarium::network_client::connect_to_login(const struct vostok::sign_in_info &)",
        "game",
        info,
        "[R] connect_to_game_server: %s: %d game time is %d",
        info->host,
        info->port,
        this->m_last_tick_time_in_ms);
    }
    if ( (v12 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
        (int *)&f);
    f.functor.obj_ptr = this;
    f.vtable = (boost::detail::function::vtable_base *)survarium::network_client::on_match_disconnected;
    (&f.vtable)[1] = 0;
    HIDWORD(v8.f_.f_) = survarium::network_client::on_match_disconnected;
    *(_QWORD *)&v8.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
    LODWORD(v8.f_.f_) = &f;
    boost::function<void __cdecl (enum vostok::network_core::disconnect_event_types_enum)>::function<void __cdecl (enum vostok::network_core::disconnect_event_types_enum)>(
      0,
      v8,
      (int)f.functor.vostok_pointer_size_alignment[1]);
    this->m_match_client->set_on_disconnect(
      this->m_match_client,
      (const boost::function<void __cdecl(enum vostok::network_core::disconnect_event_types_enum)> *)&f);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&f);
    (&f.vtable)[1] = 0;
    f.functor.obj_ptr = this;
    f.vtable = (boost::detail::function::vtable_base *)survarium::network_client::on_connected_to_match;
    HIDWORD(v9.f_.f_) = survarium::network_client::on_connected_to_match;
    *(_QWORD *)&v9.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
    LODWORD(v9.f_.f_) = &f;
    this->m_match_state = waiting_for_connection_info;
    boost::function<void __cdecl (enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby::server::messages_enum)>::function<void __cdecl (enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby::server::messages_enum)>(
      0,
      v9,
      (int)f.functor.vostok_pointer_size_alignment[1]);
    this->m_match_client->connect(
      this->m_match_client,
      info->host,
      info->port,
      0,
      this->m_last_tick_time_in_ms,
      (const boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby::server::messages_enum)> *)&f);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&f);
    survarium::game::switch_to_scene(this->m_game, &this->m_game->m_game_world);
  }
  else
  {
    (&f.vtable)[1] = 0;
    f.functor.obj_ptr = this;
    f.vtable = (boost::detail::function::vtable_base *)survarium::network_client::on_connected_to_login;
    HIDWORD(v10.f_.f_) = survarium::network_client::on_connected_to_login;
    v10.l_.a1_.t_ = 0;
    *((_DWORD *)&v10.l_ + 1) = this;
    LODWORD(v10.f_.f_) = &f;
    boost::function<void __cdecl (enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login::server::messages_enum)>::function<void __cdecl (enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login::server::messages_enum)>(
      0,
      v10,
      (int)f.functor.vostok_pointer_size_alignment[1]);
    vostok::network::login_client::sign_in(info, &this->m_login_client, &f);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&f);
  }
}
