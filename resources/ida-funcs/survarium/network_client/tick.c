void __thiscall survarium::network_client::tick(
        survarium::network_client *this,
        unsigned int current_time_in_ms,
        const bool is_game_paused)
{
  bool v4; // zf
  survarium::network_client_vtbl *v5; // eax
  survarium::network_client_vtbl *v6; // eax
  const boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login::server::messages_enum)> *v7; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  survarium::game *v9; // ecx
  survarium::lobby_client *v10; // esi
  survarium::network_client *v11; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // ecx
  bool has_passed_filters; // al
  survarium::messaging_client *v14; // esi
  survarium::network_client *v15; // ecx
  survarium::base_match_client *v16; // eax
  bool v17; // al
  vostok::timing::timer *v18; // ecx
  vostok::timing::timer *p_m_permanent_timer; // esi
  unsigned int v20; // esi
  survarium::base_match_client *v21; // eax
  unsigned __int64 elapsed_msec; // rax
  unsigned int v23; // esi
  int v24; // eax
  survarium::game_world_ui *v25; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v26; // [esp-4h] [ebp-34h]
  char v27; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v28; // [esp+10h] [ebp-20h] BYREF

  v27 = 0;
  if ( this->login_client(this)->m_client_state == signed_in )
  {
    v4 = !this->lobby_client(this)->m_connection_info.need_resolve;
    v5 = this->__vftable;
    if ( v4 )
    {
      if ( v5->messaging_client(this)->m_connection_info.need_resolve
        && current_time_in_ms - messaging_resolve_time > 0xBB8 )
      {
        v14 = this->messaging_client(this);
        v14->m_connection_info.need_resolve = survarium::network_client::http_query_server_connection_info(
                                                v15,
                                                this,
                                                4u) == 0;
        messaging_resolve_time = current_time_in_ms;
      }
    }
    else if ( v5->lobby_client(this)->m_connection_info.connection_error_count <= 3 )
    {
      if ( current_time_in_ms - lobby_resolve_time > 0x1388 )
      {
        v10 = this->lobby_client(this);
        v10->m_connection_info.need_resolve = survarium::network_client::http_query_server_connection_info(
                                                v11,
                                                this,
                                                2u) == 0;
        lobby_resolve_time = current_time_in_ms;
        if ( !vostok::core::g_log_filter_tree
          || (has_passed_filters = vostok::logging::has_passed_filters(
                                     (vostok::logging::filter_tree *)"game",
                                     (const char *)4),
              v12 = v26,
              has_passed_filters) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v12,
            &v28);
          v27 = 1;
          vostok::logging::append(
            &v28,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\network_client_processing.cpp",
            0xFFu,
            "void __thiscall survarium::network_client::tick(const unsigned int,const bool)",
            "game",
            info,
            "LOBBY: try reconnect");
        }
        if ( (v27 & 1) != 0 )
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v12,
            (int *)&v28);
      }
    }
    else
    {
      this->lobby_client(this)->m_connection_info.connection_error_count = 0;
      v6 = this->__vftable;
      v28.vtable = 0;
      v7 = (const boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login::server::messages_enum)> *)v6->login_client(this);
      vostok::network::login_client::sign_out((vostok::network::login_client *)&v28, v7);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v8,
        (int *)&v28);
      survarium::game::switch_to_login(v9, this->m_game, login_menu_status_error_connection);
    }
  }
  v16 = this->match_client(this);
  v17 = v16->is_connected(v16);
  p_m_permanent_timer = &this->m_game->m_permanent_timer;
  if ( v17 )
  {
    elapsed_msec = vostok::timing::timer::get_elapsed_msec(v18, (int)p_m_permanent_timer);
    v23 = elapsed_msec;
    v24 = ((int (__fastcall *)(survarium::network_client *, _DWORD))this->match_client)(this, HIDWORD(elapsed_msec));
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v24 + 48))(v24) + 3000 <= v23
      && vostok::core::journal_usage() != replay_journal )
    {
      survarium::game_world_ui::set_broken_connection_message(v25, (const char *)&this->m_game->m_game_world.game_ui);
    }
    survarium::network_client::try_send_all((survarium::network_client *)v25, (int)this, current_time_in_ms, 1);
  }
  else
  {
    v20 = vostok::timing::timer::get_elapsed_msec(v18, (int)p_m_permanent_timer);
    if ( v20 >= this->m_last_send_queued_packets_time_in_ms + 33 )
    {
      this->m_last_send_queued_packets_time_in_ms = v20;
      v21 = this->match_client(this);
      v21->send_queued_packets(v21, v20);
    }
  }
}
