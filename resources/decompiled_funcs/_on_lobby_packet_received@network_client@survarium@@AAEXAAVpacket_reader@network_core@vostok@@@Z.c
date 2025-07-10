void __thiscall survarium::network_client::on_lobby_packet_received(
        survarium::network_client *this,
        vostok::network_core::packet_reader *reader)
{
  const unsigned __int8 *m_pointer; // eax
  int v4; // ecx
  const unsigned __int8 *v5; // eax
  const unsigned __int8 *v6; // esi
  __int16 v7; // cx
  const unsigned __int8 *v8; // eax
  unsigned int v9; // esi
  const unsigned __int8 *v10; // eax
  unsigned __int8 v11; // cl
  int p_log_callback; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v13; // ecx
  void (__cdecl *v14)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v15)(_BYTE *, _BYTE *, int); // eax
  survarium::lobby_client *v16; // esi
  survarium::lobby_client *v17; // eax
  survarium::game_team_id m_team_id; // edi
  unsigned int m_match_id; // esi
  survarium::messaging_client *v20; // eax
  survarium::messaging_client *v21; // ecx
  lobby::query_info_types v22; // esi
  survarium::lobby_client *v23; // eax
  unsigned int v24; // esi
  survarium::messaging_client *v25; // eax
  survarium::lobby_client *v26; // eax
  survarium::lobby_client *v27; // eax
  unsigned __int8 profile_content_info; // al
  survarium::lobby_client *v29; // eax
  survarium::lobby_client *v30; // ecx
  survarium::lobby_client *v31; // ecx
  survarium::lobby_client *v32; // eax
  survarium::lobby_client *v33; // ecx
  vostok::network_core::packet_reader *v34; // eax
  survarium::lobby_client *v35; // eax
  survarium::lobby_client *v36; // eax
  survarium::lobby_client *v37; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v38; // ecx
  void (__cdecl *v39)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  unsigned __int8 v40; // cl
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v41; // ecx
  void (__cdecl *v42)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  const unsigned __int8 *v43; // eax
  unsigned __int8 v44; // cl
  lobby::query_info_types v45; // eax
  survarium::lobby_client *v46; // ecx
  lobby::query_info_types v47; // eax
  survarium::lobby_client *v48; // ecx
  unsigned __int8 v49; // cl
  const unsigned __int8 *v50; // eax
  const unsigned __int8 *v51; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v52; // ecx
  void (__cdecl *v53)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  vostok::network_core::packet_reader *v54; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::network_client,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<survarium::network_client *>,boost::arg<1> > > v55; // [esp-10h] [ebp-338h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::network_client,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum>,boost::_bi::list5<boost::_bi::value<survarium::network_client *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > v56; // [esp-10h] [ebp-338h]
  unsigned int v57; // [esp-4h] [ebp-32Ch]
  survarium::game_team_id v58; // [esp-4h] [ebp-32Ch]
  int v59; // [esp+0h] [ebp-328h]
  int v60; // [esp+0h] [ebp-328h]
  vostok::lobby_client_message_types_enum op_id; // [esp+Ch] [ebp-31Ch]
  vostok::lobby_client_message_types_enum op_ida; // [esp+Ch] [ebp-31Ch]
  vostok::lobby_client_message_types_enum op_idb; // [esp+Ch] [ebp-31Ch]
  vostok::lobby_client_message_types_enum op_idc; // [esp+Ch] [ebp-31Ch]
  survarium::lobby_menu *faction_id; // [esp+10h] [ebp-318h]
  unsigned int v66; // [esp+14h] [ebp-314h]
  __int64 v67; // [esp+20h] [ebp-308h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v68; // [esp+28h] [ebp-300h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v69; // [esp+48h] [ebp-2E0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+68h] [ebp-2C0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v71; // [esp+88h] [ebp-2A0h] BYREF
  boost::function<void __cdecl(unsigned int,unsigned int)> v72; // [esp+A8h] [ebp-280h] BYREF
  int v73; // [esp+C8h] [ebp-260h] BYREF
  _BYTE v74[24]; // [esp+D0h] [ebp-258h] BYREF
  char host[64]; // [esp+E8h] [ebp-240h] BYREF
  char description[512]; // [esp+128h] [ebp-200h] BYREF

  m_pointer = reader->m_pointer;
  v4 = *m_pointer;
  v5 = m_pointer + 1;
  faction_id = 0;
  reader->m_pointer = v5;
  switch ( v4 )
  {
    case '3':
      v6 = v5 + 1;
      v57 = *v5;
      reader->m_pointer = v5 + 1;
      op_id = v57;
      memcpy((unsigned __int8 *)host, (unsigned __int8 *)v5 + 1, v57);
      reader->m_pointer = &v6[op_id];
      host[op_id] = 0;
      v7 = *(_WORD *)&v6[op_id];
      v8 = &v6[op_id + 2];
      reader->m_pointer = v8;
      v9 = *(_DWORD *)v8;
      reader->m_pointer = v8 + 4;
      LOWORD(op_id) = v7;
      this->lobby_client(this)->m_match_id = v9;
      v10 = reader->m_pointer;
      v11 = *v10;
      reader->m_pointer = v10 + 1;
      p_log_callback = v11;
      this->lobby_client(this)->m_team_id = v11;
      this->lobby_client(this)->m_status = in_match;
      this->m_last_tick_time_in_ms = this->m_game->m_current_time_in_ms;
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        p_log_callback = (int)vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( p_log_callback )
        {
          log_callback.functor.obj_ptr = (void *)p_log_callback;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        LOBYTE(faction_id) = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client_lobby.cpp",
          0x22u,
          "void __thiscall survarium::network_client::on_lobby_packet_received(class vostok::network_core::packet_reader &)",
          "game:",
          error,
          "[R] connect_to_game_server: %s: %d game time is %d",
          host,
          (unsigned __int16)op_id,
          this->m_last_tick_time_in_ms);
      }
      if ( ((unsigned __int8)faction_id & 1) != 0 )
      {
        p_log_callback = (int)&log_callback;
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v13,
          (int *)&log_callback);
      }
      v55.f_.f_ = (void (__thiscall *__ptr64)(survarium::network_client *, vostok::network_core::disconnect_event_types_enum))(unsigned int)survarium::network_client::on_match_disconnected;
      LODWORD(v67) = this;
      *(_QWORD *)&v55.l_.a1_.t_ = v67;
      boost::function1<void,enum vostok::network_core::disconnect_event_types_enum>::function1<void,enum vostok::network_core::disconnect_event_types_enum>(
        0,
        (int)&v72,
        p_log_callback,
        v55,
        v59);
      boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
        &v72,
        (boost::function2<void,unsigned int,unsigned int> *)&this->m_match_client.m_client.m_on_disconnected);
      if ( v72.vtable )
      {
        if ( ((int)v72.vtable & 1) == 0 )
        {
          v14 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v72.vtable & 0xFFFFFFFE);
          if ( v14 )
            v14(&v72.functor, &v72.functor, 2);
        }
        v72.vtable = 0;
      }
      v56.f_.f_ = (void (__thiscall *__ptr64)(survarium::network_client *, vostok::connection_error_types_enum, vostok::handshaking_error_types_enum, vostok::socket_error_types_enum, vostok::lobby_server_message_types_enum))(unsigned int)survarium::network_client::on_connected_to_match;
      LODWORD(v67) = this;
      *(_QWORD *)&v56.l_.a1_.t_ = v67;
      boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum>::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum>(
        0,
        (int)&v73,
        0,
        v56,
        v60);
      survarium::match_client::connect(
        (survarium::match_client *)host,
        (const char *)&this->m_match_client,
        (unsigned __int16)host,
        op_id,
        this->m_lobby_client.m_connection_info.session_id,
        (const boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum)> *)this->m_last_tick_time_in_ms);
      if ( v73 )
      {
        if ( (v73 & 1) == 0 )
        {
          v15 = *(void (__cdecl **)(_BYTE *, _BYTE *, int))(v73 & 0xFFFFFFFE);
          if ( v15 )
            v15(v74, v74, 2);
        }
        v73 = 0;
      }
      v16 = this->lobby_client(this);
      v17 = this->lobby_client(this);
      m_team_id = v16->m_team_id;
      m_match_id = v17->m_match_id;
      v20 = this->messaging_client(this);
      if ( v20->m_match_channel_id_ != m_match_id && m_match_id != -1 )
      {
        v20->m_match_channel_id_ = m_match_id;
        v20->m_game_team_id = m_team_id;
        survarium::messaging_client::update_channel_subscriptions(v21);
      }
      survarium::lobby_menu::switch_to_level_loading((survarium::lobby_menu *)v21);
      return;
    case '4':
      v40 = *v5;
      reader->m_pointer = v5 + 1;
      op_idb = v40;
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v42 = vostok::core::g_log_callback;
        v69.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v69.functor,
            &v69.functor,
            destroy_functor_tag);
        if ( v42 )
        {
          v69.functor.obj_ptr = v42;
          v69.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v69.vtable = 0;
        }
        LOBYTE(faction_id) = 4;
        vostok::logging::append(
          &v69,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client_lobby.cpp",
          0x75u,
          "void __thiscall survarium::network_client::on_lobby_packet_received(class vostok::network_core::packet_reader &)",
          "game:",
          info,
          "[R] operation_permitted: %d",
          op_idb);
      }
      if ( ((unsigned __int8)faction_id & 4) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v41,
          (int *)&v69);
      if ( op_idb == shop_action )
      {
        survarium::network_client::process_shop_action((survarium::network_client *)reader, this);
      }
      else if ( op_idb == skills_tree_action )
      {
        v43 = reader->m_pointer;
        v44 = *v43;
        reader->m_pointer = v43 + 1;
        if ( v44 == 1 )
        {
          v45 = ((int (__thiscall *)(survarium::network_client *, int))this->lobby_client)(this, 7);
          survarium::lobby_client::query_client_status(v46, v45);
        }
        v47 = ((int (__thiscall *)(survarium::network_client *, int))this->lobby_client)(this, 8);
        survarium::lobby_client::query_client_status(v48, v47);
      }
      else
      {
        survarium::lobby_menu::on_operation_permitted_received(this->m_game->m_lobby_menu, op_idb);
      }
      return;
    case '5':
      v49 = *v5;
      v50 = v5 + 1;
      reader->m_pointer = v50++;
      reader->m_pointer = v50;
      v51 = v50 + 1;
      op_idc = v49;
      v66 = *v50;
      reader->m_pointer = v50 + 1;
      memcpy((unsigned __int8 *)description, (unsigned __int8 *)v50 + 1, v66);
      reader->m_pointer = &v51[v66];
      description[v66] = 0;
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v53 = vostok::core::g_log_callback;
        v71.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v71.functor,
            &v71.functor,
            destroy_functor_tag);
        if ( v53 )
        {
          v71.functor.obj_ptr = v53;
          v71.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v71.vtable = 0;
        }
        LOBYTE(faction_id) = 8;
        vostok::logging::append(
          &v71,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client_lobby.cpp",
          0xA0u,
          "void __thiscall survarium::network_client::on_lobby_packet_received(class vostok::network_core::packet_reader &)",
          "game:",
          info,
          "[R] operation_denied: %d",
          op_idc);
      }
      if ( ((unsigned __int8)faction_id & 8) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v52,
          (int *)&v71);
      survarium::lobby_menu::on_operation_denied_received(this->m_game->m_lobby_menu, op_idc, description);
      return;
    case '6':
      v22 = *v5;
      reader->m_pointer = v5 + 1;
      op_ida = v22;
      if ( v22 )
      {
        if ( v22 != q_enumerate_profiles )
        {
          switch ( v22 )
          {
            case q_profile_contents:
              v27 = this->lobby_client(this);
              profile_content_info = survarium::lobby_client::read_profile_content_info(v27, reader);
              survarium::lobby_menu::on_profile_arrived(this->m_game->m_lobby_menu, profile_content_info);
              break;
            case q_enumerate_inventory:
              v29 = this->lobby_client(this);
              survarium::lobby_client::read_enumerate_inventory_info(v29, reader);
              break;
            case q_profile_slots_restrictions:
              this->lobby_client(this);
              survarium::lobby_client::read_profile_slots_restrictions(v30, reader);
              break;
            case q_items_compatibility:
              this->lobby_client(this);
              survarium::lobby_client::read_items_compatibility(v31, reader);
              break;
            case q_player_skills:
              v32 = this->lobby_client(this);
              survarium::lobby_client::read_player_skills(v32, reader);
              break;
            case q_player_reputations:
              this->lobby_client(this);
              survarium::lobby_client::read_player_reputations(v33, reader);
              break;
            case q_player_skills_tree:
              v34 = (vostok::network_core::packet_reader *)this->lobby_client(this);
              survarium::lobby_client::read_player_skills_tree((survarium::lobby_client *)reader, v34);
              break;
            case q_price_items:
              v35 = this->lobby_client(this);
              LOBYTE(faction_id) = survarium::lobby_client::read_price_items(v35, reader);
              survarium::lobby_menu::on_price_items_arrived(faction_id, (unsigned __int8)this->m_game->m_lobby_menu);
              goto LABEL_60;
            case q_account_money:
              v36 = this->lobby_client(this);
              survarium::lobby_client::read_account_money(v36, reader);
              goto LABEL_60;
            case q_service_prices:
              v37 = this->lobby_client(this);
              survarium::lobby_client::read_service_prices(v37, reader);
              break;
            default:
              if ( !vostok::core::g_log_filter_tree
                || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
              {
                v39 = vostok::core::g_log_callback;
                v68.vtable = 0;
                if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
                  `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                    &v68.functor,
                    &v68.functor,
                    destroy_functor_tag);
                if ( v39 )
                {
                  v68.functor.obj_ptr = v39;
                  v68.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                      + 1);
                }
                else
                {
                  v68.vtable = 0;
                }
                LOBYTE(faction_id) = 2;
                vostok::logging::append(
                  &v68,
                  (void *const)vostok::core::g_log_flags,
                  &vostok::core::g_log_format,
                  ".\\network_client_lobby.cpp",
                  0x6Bu,
                  "void __thiscall survarium::network_client::on_lobby_packet_received(class vostok::network_core::packet_reader &)",
                  "game:",
                  error,
                  "Unknown client state received [%d]",
                  v22);
              }
              if ( ((unsigned __int8)faction_id & 2) == 0 )
                break;
              boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
                v38,
                (int *)&v68);
              goto LABEL_60;
          }
LABEL_61:
          survarium::lobby_menu::on_client_status_received(this->m_game->m_lobby_menu, v22);
          return;
        }
        v26 = this->lobby_client(this);
        survarium::lobby_client::read_enumerate_profiles_info(v26, reader);
      }
      else
      {
        v23 = this->lobby_client(this);
        survarium::lobby_client::read_status_info(v23, reader);
        v24 = this->lobby_client(this)->m_match_id;
        v58 = this->lobby_client(this)->m_team_id;
        v25 = this->messaging_client(this);
        survarium::messaging_client::assign_match_channel_order(v25, v24, v58);
      }
LABEL_60:
      v22 = op_ida;
      goto LABEL_61;
    case '7':
      v54 = (vostok::network_core::packet_reader *)this->lobby_client(this);
      survarium::lobby_client::read_ping_server_answer((survarium::lobby_client *)reader, v54);
      return;
  }
}
