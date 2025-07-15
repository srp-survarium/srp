void __thiscall survarium::network_client::on_lobby_packet_received(
        survarium::network_client *this,
        vostok::network_core::buffer_reader *reader)
{
  unsigned __int8 *v3; // ecx
  survarium::lobby_client *v4; // eax
  survarium::lobby_client *v5; // ecx
  vostok::network_core::buffer_reader *v6; // eax
  unsigned int *v7; // edx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // ecx
  survarium::lobby_client *v9; // eax
  unsigned int m_match_id; // esi
  survarium::messaging_client *v11; // eax
  vostok::network_core::buffer_reader *v12; // eax
  survarium::lobby_client *v13; // ecx
  vostok::network_core::buffer_reader *v14; // eax
  survarium::lobby_client *v15; // ecx
  unsigned __int8 profile; // al
  survarium::lobby_client *v17; // ecx
  survarium::lobby_menu *v18; // ecx
  vostok::network_core::buffer_reader *v19; // eax
  survarium::lobby_client *v20; // ecx
  vostok::network_core::buffer_reader *v21; // eax
  survarium::lobby_client *v22; // ecx
  vostok::network_core::buffer_reader *v23; // eax
  survarium::lobby_client *v24; // ecx
  survarium::lobby_client *v25; // eax
  survarium::lobby_client *v26; // ecx
  survarium::lobby_menu *v27; // ecx
  survarium::lobby_client *v28; // eax
  survarium::lobby_client *v29; // eax
  survarium::lobby_menu *v30; // eax
  survarium::lobby_client *v31; // ecx
  vostok::network_core::buffer_reader *v32; // eax
  survarium::lobby_client *v33; // ecx
  vostok::network_core::buffer_reader *v34; // eax
  survarium::lobby_client *v35; // ecx
  vostok::network_core::buffer_reader *v36; // eax
  survarium::lobby_client *v37; // ecx
  survarium::lobby_client *v38; // eax
  vostok::render::stage_screen_space_reflections *v39; // eax
  survarium::lobby_client *v40; // ecx
  survarium::lobby_client *v41; // eax
  vostok::network_core::buffer_reader *v42; // eax
  survarium::lobby_client *v43; // ecx
  bool has_passed_filters; // al
  unsigned __int8 *v45; // esi
  unsigned __int8 *v46; // ecx
  survarium::lobby_menu *v47; // ecx
  vostok::lobby::client::messages_enum v48; // edx
  survarium::network_client *v49; // ecx
  const vostok::network_core::tcp_packet *v50; // eax
  survarium::lobby_client *v51; // ecx
  const vostok::network_core::tcp_packet *v52; // eax
  survarium::lobby_client *v53; // ecx
  bool v54; // zf
  const vostok::network_core::tcp_packet *v55; // eax
  survarium::lobby_client *v56; // ecx
  unsigned int profile_id; // esi
  const vostok::network_core::tcp_packet *v58; // eax
  survarium::lobby_client *v59; // ecx
  const vostok::network_core::tcp_packet *v60; // eax
  survarium::lobby_client *v61; // ecx
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v63; // eax
  survarium::game_team_id v64; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v65; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v66; // ecx
  survarium::lobby_client *v67; // esi
  survarium::lobby_client *v68; // edi
  survarium::messaging_client *v69; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::network_client,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby::server::messages_enum>,boost::_bi::list5<boost::_bi::value<survarium::network_client *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > v70; // [esp-18h] [ebp-8C8h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::network_client,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<survarium::network_client *>,boost::arg<1> > > v71; // [esp-14h] [ebp-8C4h]
  survarium::game_team_id m_team_id; // [esp-4h] [ebp-8B4h]
  unsigned int v73; // [esp-4h] [ebp-8B4h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v74; // [esp-4h] [ebp-8B4h]
  unsigned __int8 v75; // [esp+Eh] [ebp-8A2h]
  unsigned __int8 v76; // [esp+Eh] [ebp-8A2h]
  int v77; // [esp+Fh] [ebp-8A1h]
  unsigned __int8 v78; // [esp+Fh] [ebp-8A1h]
  unsigned __int8 price_items; // [esp+10h] [ebp-8A0h]
  unsigned int v80; // [esp+10h] [ebp-8A0h]
  int v81; // [esp+24h] [ebp-88Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v82; // [esp+28h] [ebp-888h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::network_client,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<survarium::network_client *>,boost::arg<1> > > f; // [esp+48h] [ebp-868h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::network_client,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby::server::messages_enum>,boost::_bi::list5<boost::_bi::value<survarium::network_client *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > v84; // [esp+64h] [ebp-84Ch] BYREF
  char v85[4]; // [esp+84h] [ebp-82Ch] BYREF
  vostok::network_core::buffer_reader __formal[5]; // [esp+88h] [ebp-828h] BYREF
  vostok::network_core::buffer_reader v87[42]; // [esp+C8h] [ebp-7E8h] BYREF
  survarium::lobby_player_profile v88; // [esp+2C8h] [ebp-5E8h] BYREF

  v77 = *reader->m_pointer;
  v3 = (unsigned __int8 *)(reader->m_pointer + 1);
  reader->m_pointer = v3;
  switch ( (unsigned __int8)v77 )
  {
    case '3':
      vostok::network_core::buffer_reader::r_string(__formal, (char *)reader, (unsigned __int8 *)__formal);
      vostok::network_core::buffer_reader::r<unsigned short>(reader);
      v80 = *(_DWORD *)reader->m_pointer;
      reader->m_pointer += 4;
      this->lobby_client(this)->m_match_id = v80;
      m_pointer = reader->m_pointer;
      v63 = m_pointer + 1;
      v64 = *m_pointer;
      reader->m_pointer = v63;
      this->lobby_client(this)->m_team_id = v64;
      this->lobby_client(this)->m_status = in_match;
      this->m_last_tick_time_in_ms = this->m_game->m_current_time_in_ms;
      HIDWORD(v71.f_.f_) = survarium::network_client::on_match_disconnected;
      *(_QWORD *)&v71.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
      LODWORD(v71.f_.f_) = &f;
      boost::function<void __cdecl (enum vostok::network_core::disconnect_event_types_enum)>::function<void __cdecl (enum vostok::network_core::disconnect_event_types_enum)>(
        0,
        v71,
        v81);
      ((void (__thiscall *)(survarium::base_match_client *))this->m_match_client->set_on_disconnect)(this->m_match_client);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v65,
        (int *)&v82.functor.vostok_pointer_size_alignment[5]);
      HIDWORD(v70.f_.f_) = survarium::network_client::on_connected_to_match;
      *(_QWORD *)&v70.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
      LODWORD(v70.f_.f_) = &v84;
      this->m_match_state = waiting_for_connection_info;
      boost::function<void __cdecl (enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby::server::messages_enum)>::function<void __cdecl (enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby::server::messages_enum)>(
        0,
        v70,
        (int)this);
      this->m_match_client->connect(
        this->m_match_client,
        v85,
        v80,
        this->m_lobby_client.m_connection_info.session_id,
        this->m_last_tick_time_in_ms,
        (const boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby::server::messages_enum)> *)&v84);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v66,
        (int *)&v84);
      v67 = this->lobby_client(this);
      v68 = this->lobby_client(this);
      v69 = (survarium::messaging_client *)((int (__thiscall *)(survarium::network_client *, survarium::game_team_id))this->messaging_client)(
                                             this,
                                             v67->m_team_id);
      survarium::messaging_client::assign_match_channel_order(v69, v68->m_match_id, (survarium::game_team_id)&f);
      break;
    case '4':
      v48 = *v3;
      v49 = (survarium::network_client *)(v3 + 1);
      reader->m_pointer = (const unsigned __int8 *)v49;
      switch ( v48 )
      {
        case shop_action:
          survarium::network_client::process_shop_action(v49, (vostok::network_core::buffer_reader *)this, reader);
          break;
        case skills_tree_action:
          v54 = LOBYTE(v49->__vftable) == 1;
          reader->m_pointer = (const unsigned __int8 *)&v49->__vftable + 1;
          if ( v54 )
          {
            v55 = (const vostok::network_core::tcp_packet *)this->lobby_client(this);
            survarium::lobby_client::query_client_status(v56, v55, 5u);
          }
          profile_id = this->m_lobby_client.m_profiles[this->m_game->m_lobby_menu->m_selected_profile_idx].profile_id;
          v58 = (const vostok::network_core::tcp_packet *)this->lobby_client(this);
          survarium::lobby_client::query_profile_leveling(v59, v58, profile_id);
          v60 = (const vostok::network_core::tcp_packet *)this->lobby_client(this);
          survarium::lobby_client::query_profile_contents(v61, v60, profile_id);
          break;
        case profiles_action:
          survarium::network_client::process_profiles_action(this, reader);
          break;
        case quest_action:
          if ( this->lobby_client(this)->m_net_client_connected )
          {
            v50 = (const vostok::network_core::tcp_packet *)this->lobby_client(this);
            survarium::lobby_client::query_client_status(v51, v50, 0xEu);
            v52 = (const vostok::network_core::tcp_packet *)this->lobby_client(this);
            survarium::lobby_client::query_client_status(v53, v52, 0x10u);
          }
          break;
        default:
          survarium::lobby_menu::on_operation_permitted_received(
            (survarium::lobby_menu *)v49,
            this->m_game->m_lobby_menu,
            v48);
          break;
      }
      break;
    case '5':
      v45 = v3;
      v46 = v3 + 1;
      v76 = *v45;
      reader->m_pointer = v46;
      reader->m_pointer = v46 + 1;
      vostok::network_core::buffer_reader::r_string(v87, (char *)reader, (unsigned __int8 *)v87);
      survarium::lobby_menu::on_operation_denied_received(
        v47,
        this->m_game->m_lobby_menu,
        (const char *)v76,
        (char *)v87);
      break;
    case '6':
      v78 = *v3;
      v7 = (unsigned int *)(v3 + 1);
      v8 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)*v3;
      reader->m_pointer = (const unsigned __int8 *)v7;
      if ( v8 )
      {
        if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)1 )
        {
          v12 = (vostok::network_core::buffer_reader *)this->lobby_client(this);
          survarium::lobby_client::read_enumerate_profiles_info(v13, v12, (int)reader);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)2 )
        {
          v14 = (vostok::network_core::buffer_reader *)this->lobby_client(this);
          profile = survarium::lobby_client::read_profile(v15, v14, reader);
          survarium::lobby_menu::on_profile_arrived(
            this->m_game->m_lobby_menu,
            profile,
            (survarium::flash_value *)this->m_game);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)17 )
        {
          survarium::lobby_player_profile::lobby_player_profile(&v88);
          this->lobby_client(this);
          survarium::lobby_client::read_squad_member_profile(v17, reader, (vostok::network_core::buffer_reader *)&v88);
          survarium::lobby_menu::on_squad_member_profile_arrived(v18, (int)this->m_game->m_lobby_menu, &v88);
          survarium::player_profile::~player_profile(&v88);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)3 )
        {
          v19 = (vostok::network_core::buffer_reader *)this->lobby_client(this);
          survarium::lobby_client::read_enumerate_inventory_info(v20, v19, (int)reader);
          this->lobby_client(this);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)6 )
        {
          v21 = (vostok::network_core::buffer_reader *)this->lobby_client(this);
          survarium::lobby_client::read_player_skills(v22, v21, (int)reader);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)9 )
        {
          v23 = (vostok::network_core::buffer_reader *)this->lobby_client(this);
          survarium::lobby_client::read_player_reputations(v24, v23, (int)reader);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)4 )
        {
          v25 = this->lobby_client(this);
          price_items = survarium::lobby_client::read_price_items(v26, (int)v25, reader);
          survarium::lobby_menu::on_price_items_arrived(
            v27,
            (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)this->m_game->m_lobby_menu,
            price_items);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)5 )
        {
          v28 = this->lobby_client(this);
          survarium::lobby_client::read_account_money(v28, reader);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)8 )
        {
          v29 = this->lobby_client(this);
          survarium::lobby_client::read_service_prices(v29, reader);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)11 )
        {
          v30 = (survarium::lobby_menu *)this->lobby_client(this);
          survarium::lobby_client::read_last_played_match_stats(v31, v30, reader);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)15 )
        {
          v32 = (vostok::network_core::buffer_reader *)this->lobby_client(this);
          survarium::lobby_client::read_player_match_stats(v33, v32, reader);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)12 )
        {
          v34 = (vostok::network_core::buffer_reader *)this->lobby_client(this);
          survarium::lobby_client::read_player_elo_rating(v35, v34, reader);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)13 )
        {
          v36 = (vostok::network_core::buffer_reader *)this->lobby_client(this);
          survarium::lobby_client::read_players_elo_list(v37, v36, reader);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)10 )
        {
          v73 = *v7;
          reader->m_pointer = (const unsigned __int8 *)(v7 + 1);
          survarium::lobby_menu::set_total_players_count(
            (survarium::lobby_menu *)0xA,
            (unsigned int)this->m_game->m_lobby_menu,
            v73);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)16 )
        {
          v38 = this->lobby_client(this);
          survarium::lobby_client::read_account_services(reader, v38);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)18 )
        {
          v39 = (vostok::render::stage_screen_space_reflections *)this->lobby_client(this);
          survarium::lobby_client::read_shop_items(v40, v39, (int)reader);
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)19 )
        {
          v75 = *(_BYTE *)v7;
          reader->m_pointer = (const unsigned __int8 *)v7 + 1;
          v41 = this->lobby_client(this);
          LOBYTE(v8) = v75;
          v41->m_unlocked_factions_mask = v75;
        }
        else if ( v8 == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)14 )
        {
          v42 = (vostok::network_core::buffer_reader *)this->lobby_client(this);
          survarium::lobby_client::read_quest_list(v43, v42, (int)reader);
        }
        else
        {
          if ( !vostok::core::g_log_filter_tree
            || (has_passed_filters = vostok::logging::has_passed_filters(
                                       (vostok::logging::filter_tree *)"game",
                                       (const char *)2),
                v8 = v74,
                has_passed_filters) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
              v8,
              &v82);
            BYTE1(v77) = 1;
            vostok::logging::append(
              &v82,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\network_client_lobby.cpp",
              0x8Du,
              "void __thiscall survarium::network_client::on_lobby_packet_received(class vostok::network_core::buffer_reader &)",
              "game",
              error,
              "Unknown client state received [%d]",
              v78);
          }
          if ( (v77 & 0x100) != 0 )
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v8,
              (int *)&v82);
        }
      }
      else
      {
        v9 = this->lobby_client(this);
        survarium::lobby_client::read_status_info(v9, reader);
        m_match_id = this->lobby_client(this)->m_match_id;
        m_team_id = this->lobby_client(this)->m_team_id;
        v11 = this->messaging_client(this);
        survarium::messaging_client::assign_match_channel_order(v11, m_match_id, m_team_id);
      }
      survarium::lobby_menu::on_client_status_received(
        (survarium::lobby_menu *)v8,
        this->m_game->m_lobby_menu,
        (vostok::lobby::query_info_types)v78);
      break;
    case '7':
      v6 = (vostok::network_core::buffer_reader *)this->lobby_client(this);
      survarium::lobby_client::read_ping_server_answer((survarium::lobby_client *)reader, v6);
      break;
    default:
      v4 = (survarium::lobby_client *)((int (__fastcall *)(survarium::network_client *))this->lobby_client)(this);
      if ( (unsigned __int8)v77 == 56 )
        survarium::lobby_client::read_online_stats(reader, v4);
      else
        survarium::lobby_client::read_squad_info(v5, (vostok::network_core::buffer_reader *)v4, (unsigned int)reader);
      break;
  }
}
