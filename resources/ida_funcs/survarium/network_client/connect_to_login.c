void __thiscall survarium::network_client::connect_to_login(
        survarium::network_client *this,
        const char *host,
        survarium::match_client *port,
        const char *account_name,
        const char *account_password)
{
  char v5; // bl
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  survarium::game *m_game; // esi
  survarium::base_game_scene *m_active_scene; // ecx
  survarium::game_world *p_m_game_world; // edi
  void (__cdecl *v14)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::network_client,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<survarium::network_client *>,boost::arg<1> > > v15; // [esp-10h] [ebp-40h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::network_client,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum>,boost::_bi::list5<boost::_bi::value<survarium::network_client *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > v16; // [esp-10h] [ebp-40h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::network_client,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum>,boost::_bi::list5<boost::_bi::value<survarium::network_client *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > v17; // [esp-10h] [ebp-40h]
  int v18; // [esp+0h] [ebp-30h]
  int v19; // [esp+0h] [ebp-30h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v5 = 0;
  if ( this->m_is_spectator )
  {
    this->m_last_tick_time_in_ms = this->m_game->m_current_time_in_ms;
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
    {
      v7 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v7 )
      {
        log_callback.functor.obj_ptr = v7;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v5 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\network_client.cpp",
        0x1AAu,
        "void __thiscall survarium::network_client::connect_to_login(const char *,const unsigned short,const char *,const char *)",
        "game:",
        info,
        "[R] connect_to_game_server: %s: %d game time is %d",
        host,
        (unsigned __int16)port,
        this->m_last_tick_time_in_ms);
    }
    if ( (v5 & 1) != 0 )
    {
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v8 )
            v8(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
    log_callback.vtable = (boost::detail::function::vtable_base *)survarium::network_client::on_match_disconnected;
    (&log_callback.vtable)[1] = 0;
    v15.f_.f_ = (void (__thiscall *__ptr64)(survarium::network_client *, vostok::network_core::disconnect_event_types_enum))(unsigned int)survarium::network_client::on_match_disconnected;
    log_callback.functor.obj_ptr = this;
    *(_QWORD *)&v15.l_.a1_.t_ = *(_QWORD *)&log_callback.functor.obj_ptr;
    boost::function1<void,enum vostok::network_core::disconnect_event_types_enum>::function1<void,enum vostok::network_core::disconnect_event_types_enum>(
      0,
      (int)&log_callback,
      (int)this,
      v15,
      v18);
    boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
      (boost::function<void __cdecl(unsigned int,unsigned int)> *)&log_callback,
      (boost::function2<void,unsigned int,unsigned int> *)&this->m_match_client.m_client.m_on_disconnected);
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v9 )
          v9(&log_callback.functor, &log_callback.functor, 2);
      }
    }
    log_callback.vtable = (boost::detail::function::vtable_base *)survarium::network_client::on_connected_to_match;
    (&log_callback.vtable)[1] = 0;
    v16.f_.f_ = (void (__thiscall *__ptr64)(survarium::network_client *, vostok::connection_error_types_enum, vostok::handshaking_error_types_enum, vostok::socket_error_types_enum, vostok::lobby_server_message_types_enum))(unsigned int)survarium::network_client::on_connected_to_match;
    log_callback.functor.obj_ptr = this;
    *(_QWORD *)&v16.l_.a1_.t_ = *(_QWORD *)&log_callback.functor.obj_ptr;
    boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum>::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum>(
      0,
      (int)&log_callback,
      (int)this,
      v16,
      v19);
    survarium::match_client::connect(
      port,
      &this->m_match_client,
      host,
      (unsigned __int16)port,
      0,
      (const boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum)> *)this->m_last_tick_time_in_ms,
      (const boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum)> *)&log_callback);
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v10 )
          v10(&log_callback.functor, &log_callback.functor, 2);
      }
    }
    m_game = this->m_game;
    m_active_scene = m_game->m_active_scene;
    p_m_game_world = &m_game->m_game_world;
    if ( m_active_scene != &m_game->m_game_world )
    {
      if ( m_active_scene )
        m_active_scene->on_deactivate(m_active_scene);
      m_game->m_active_scene = p_m_game_world;
      p_m_game_world->on_activate(&m_game->m_game_world);
    }
  }
  else
  {
    log_callback.vtable = (boost::detail::function::vtable_base *)survarium::network_client::on_connected_to_login;
    (&log_callback.vtable)[1] = 0;
    v17.f_.f_ = (void (__thiscall *__ptr64)(survarium::network_client *, vostok::connection_error_types_enum, vostok::handshaking_error_types_enum, vostok::socket_error_types_enum, vostok::login_server_message_types_enum))(unsigned int)survarium::network_client::on_connected_to_login;
    log_callback.functor.obj_ptr = this;
    *(_QWORD *)&v17.l_.a1_.t_ = *(_QWORD *)&log_callback.functor.obj_ptr;
    boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum>::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum>(
      0,
      (int)&log_callback,
      (int)this,
      v17,
      v18);
    vostok::network::login_client::sign_in(
      &this->m_login_client,
      host,
      (unsigned __int16)port,
      account_name,
      account_password,
      (boost::function<void __cdecl(unsigned int,unsigned int)> *)&log_callback);
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v14 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v14 )
          v14(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
}
