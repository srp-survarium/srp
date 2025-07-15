void __thiscall survarium::network_client::close_current_match(
        survarium::network_client *this,
        vostok::network_core::disconnect_event_types_enum disconnect_event_type)
{
  survarium::game_status *p_m_game_status; // ebx
  survarium::game_statistics_handler *v4; // ecx
  survarium::game_world *v5; // ecx
  survarium::lobby_menu *m_lobby_menu; // edi
  vostok::network_core::udp_match_packet *v7; // ebx
  vostok::timing::floating_timer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  survarium::base_match_client_vtbl *v10; // ebx
  vostok::timing::timer *v11; // ecx
  unsigned __int64 v12; // rax
  bool has_passed_filters; // al
  survarium::game_world *v14; // [esp-4h] [ebp-3Ch]
  const char *elapsed_msec; // [esp+10h] [ebp-28h] BYREF
  int v16; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v17; // [esp+18h] [ebp-20h] BYREF

  p_m_game_status = &this->m_game_status;
  v16 = 0;
  if ( this->m_game_status )
  {
    if ( !vostok::command_line::key::is_set(
            (vostok::command_line::key *)this,
            (int)&s_disable_game_statistics_gathering) )
      survarium::game_statistics_handler::finish_match(v4, (int)&this->m_game_statistics);
    *p_m_game_status = game_status_inactive;
    if ( vostok::core::journal_usage() == replay_journal )
      vostok::debug::terminate("No more records in the journal");
    if ( disconnect_event_type )
    {
      if ( disconnect_event_type != disconnected_by_connection_lost )
      {
        if ( disconnect_event_type != disconnected_by_initiator )
        {
          if ( disconnect_event_type == disconnected_on_match_finished )
          {
            survarium::game_world::on_finish_match(
              v5,
              (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)&this->m_game->m_game_world);
            m_lobby_menu = this->m_game->m_lobby_menu;
            Scaleform::GFx::Movie::Invoke(
              m_lobby_menu->m_lobby_menu_ui.m_object->movie->m_movie,
              "root.show_victory_screen",
              0,
              0,
              0);
            m_lobby_menu->m_match_stats_wnd_present = 1;
          }
          return;
        }
        v7 = this->m_match_client->new_packet(this->m_match_client, 72);
        elapsed_msec = (const char *)vostok::timing::floating_timer::get_elapsed_msec(v8, &this->m_game->m_timer);
        vostok::network_core::buffer_writer::w(
          v9,
          &v7->m_writer.serialization_operations_descriptors.m_size,
          (unsigned __int8 *)&elapsed_msec,
          4u);
        this->m_match_client->enqueue(this->m_match_client, v7);
        v10 = this->m_match_client->__vftable;
        v12 = vostok::timing::timer::get_elapsed_msec(v11, (int)&this->m_game->m_permanent_timer);
        ((void (__fastcall *)(survarium::base_match_client *, _DWORD, _DWORD))v10->send_queued_packets)(
          this->m_match_client,
          HIDWORD(v12),
          v12);
      }
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"game",
                                   (const char *)2),
            v5 = v14,
            has_passed_filters) )
      {
        elapsed_msec = "disconnected_by_connection_lost";
        if ( disconnect_event_type != disconnected_by_connection_lost )
          elapsed_msec = "disconnected_by_initiator";
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v5,
          &v17);
        v16 = 1;
        vostok::logging::append(
          &v17,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client_lobby.cpp",
          0x196u,
          "void __thiscall survarium::network_client::close_current_match(enum vostok::network_core::disconnect_event_types_enum)",
          "game",
          error,
          "network_client::close_current_match [%s]",
          elapsed_msec);
      }
      if ( (v16 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v5,
          (int *)&v17);
      this->lobby_client(this)->m_discard_playing_order_on_connected = 1;
    }
    survarium::game_world::on_finish_match(
      v5,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)&this->m_game->m_game_world);
  }
}
