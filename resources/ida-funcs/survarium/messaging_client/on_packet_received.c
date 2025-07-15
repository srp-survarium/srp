void __thiscall survarium::messaging_client::on_packet_received(
        survarium::messaging_client *this,
        vostok::network_core::buffer_reader *reader)
{
  const unsigned __int8 *m_pointer; // esi
  survarium::messaging_client *v4; // ecx
  bool v5; // al
  unsigned int m_game_low; // esi
  unsigned __int8 *v7; // ecx
  unsigned __int8 *v8; // ecx
  bool v9; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // esi
  bool v11; // al
  bool v12; // al
  bool has_passed_filters; // al
  survarium::messaging_client *v14; // [esp-4h] [ebp-BCh]
  unsigned __int8 *v15; // [esp-4h] [ebp-BCh]
  unsigned __int8 *v16; // [esp-4h] [ebp-BCh]
  unsigned __int8 *v17; // [esp-4h] [ebp-BCh]
  unsigned __int8 *v18; // [esp-4h] [ebp-BCh]
  unsigned __int8 v19; // [esp+Eh] [ebp-AAh]
  unsigned __int8 v20; // [esp+Eh] [ebp-AAh]
  unsigned __int8 v21; // [esp+Eh] [ebp-AAh]
  unsigned __int8 v22; // [esp+Eh] [ebp-AAh]
  __int16 v23; // [esp+Fh] [ebp-A9h]
  unsigned __int8 m_game; // [esp+Fh] [ebp-A9h]
  survarium::lobby_menu **v25; // [esp+14h] [ebp-A4h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v26; // [esp+18h] [ebp-A0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v27; // [esp+38h] [ebp-80h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v28; // [esp+58h] [ebp-60h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v29; // [esp+78h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v30; // [esp+98h] [ebp-20h] BYREF

  m_pointer = reader->m_pointer;
  v23 = *m_pointer;
  v4 = (survarium::messaging_client *)(m_pointer + 1);
  v25 = (survarium::lobby_menu **)this;
  reader->m_pointer = m_pointer + 1;
  switch ( (unsigned __int8)v23 )
  {
    case 0xC9u:
      survarium::messaging_client::process_incoming_text_message(
        v4,
        (vostok::network_core::buffer_reader *)this,
        (unsigned int)reader);
      return;
    case 0xCBu:
      m_game = (unsigned __int8)v4->m_game;
      m_game_low = LOBYTE(v4->m_game);
      v7 = (unsigned __int8 *)&v4->m_game + 1;
      reader->m_pointer = v7;
      switch ( m_game_low )
      {
        case 7u:
          survarium::messaging_client::read_friend_list(
            (survarium::messaging_client *)v7,
            (vostok::network_core::buffer_reader *)this,
            reader);
LABEL_49:
          survarium::lobby_menu::on_friendship_status_recivied(
            (survarium::lobby_menu *)LODWORD((*v25)[8].m_inverted_view_matrix.i.y),
            (const vostok::messaging::friendship_actions_enum)m_game,
            *v25);
          return;
        case 9u:
          survarium::messaging_client::read_friend_status(
            (survarium::messaging_client *)v7,
            (vostok::network_core::buffer_reader *)this,
            reader);
          goto LABEL_49;
        case 8u:
          survarium::messaging_client::read_ignore_list(
            (survarium::messaging_client *)v7,
            (vostok::network_core::buffer_reader *)this,
            reader);
          goto LABEL_49;
        case 6u:
          survarium::messaging_client::read_found_players(
            (survarium::messaging_client *)v7,
            (vostok::network_core::buffer_reader *)this,
            reader);
          goto LABEL_49;
      }
      if ( m_game_low < 2 )
      {
        v22 = *v7;
        v8 = v7 + 1;
        reader->m_pointer = v8;
        if ( v22 == 52 )
          goto LABEL_42;
        if ( !vostok::core::g_log_filter_tree
          || (has_passed_filters = vostok::logging::has_passed_filters(
                                     (vostok::logging::filter_tree *)"game",
                                     (const char *)4),
              v8 = v18,
              has_passed_filters) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8,
            &v30);
          HIBYTE(v23) = 1;
          vostok::logging::append(
            &v30,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\messaging_client_process_messagess.cpp",
            0x3Eu,
            "void __thiscall survarium::messaging_client::on_packet_received(class vostok::network_core::buffer_reader &)",
            "game",
            info,
            "add_friend: operation denied ");
        }
        if ( (v23 & 0x100) == 0 )
          goto LABEL_49;
        v10 = &v30;
      }
      else
      {
        if ( m_game_low == 2 )
        {
          v19 = *v7;
          v8 = v7 + 1;
          reader->m_pointer = v8;
          if ( v19 != 52 )
          {
            if ( !vostok::core::g_log_filter_tree
              || (v9 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)4),
                  v8 = v15,
                  v9) )
            {
              boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
                (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8,
                &v29);
              HIBYTE(v23) = 2;
              vostok::logging::append(
                &v29,
                (void *const)vostok::core::g_log_flags,
                &vostok::core::g_log_format,
                ".\\messaging_client_process_messagess.cpp",
                0x48u,
                "void __thiscall survarium::messaging_client::on_packet_received(class vostok::network_core::buffer_reader &)",
                "game",
                info,
                "remove_friend: operation denied ");
            }
            if ( (v23 & 0x200) == 0 )
              goto LABEL_49;
            v10 = &v29;
            goto LABEL_48;
          }
LABEL_42:
          survarium::messaging_client::query_for_friend_list((survarium::messaging_client *)v8, (int)this);
          goto LABEL_49;
        }
        if ( m_game == 3 || m_game == 4 )
        {
          v21 = *v7;
          v8 = v7 + 1;
          reader->m_pointer = v8;
          if ( v21 == 52 )
            goto LABEL_29;
          if ( !vostok::core::g_log_filter_tree
            || (v12 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)4),
                v8 = v17,
                v12) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
              (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8,
              &v28);
            HIBYTE(v23) = 4;
            vostok::logging::append(
              &v28,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\messaging_client_process_messagess.cpp",
              0x52u,
              "void __thiscall survarium::messaging_client::on_packet_received(class vostok::network_core::buffer_reader &)",
              "game",
              info,
              "add_ignorable: operation denied ");
          }
          if ( (v23 & 0x400) == 0 )
            goto LABEL_49;
          v10 = &v28;
        }
        else
        {
          v20 = *v7;
          v8 = v7 + 1;
          reader->m_pointer = v8;
          if ( v20 == 52 )
          {
LABEL_29:
            survarium::messaging_client::query_for_ignore_list((survarium::messaging_client *)v8, (int)this);
            goto LABEL_49;
          }
          if ( !vostok::core::g_log_filter_tree
            || (v11 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)4),
                v8 = v16,
                v11) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
              (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8,
              &v27);
            HIBYTE(v23) = 8;
            vostok::logging::append(
              &v27,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\messaging_client_process_messagess.cpp",
              0x5Bu,
              "void __thiscall survarium::messaging_client::on_packet_received(class vostok::network_core::buffer_reader &)",
              "game",
              info,
              "remove_ignorable: operation denied ");
          }
          if ( (v23 & 0x800) == 0 )
            goto LABEL_49;
          v10 = &v27;
        }
      }
LABEL_48:
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v8,
        (int *)v10);
      goto LABEL_49;
    case 0xCCu:
      survarium::messaging_client::process_incoming_important_text_message(
        v4,
        (vostok::network_core::buffer_reader *)this,
        (int)reader);
      break;
    default:
      if ( !vostok::core::g_log_filter_tree
        || (v5 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2),
            v4 = v14,
            v5) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v4,
          &v26);
        HIBYTE(v23) = 16;
        vostok::logging::append(
          &v26,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\messaging_client_process_messagess.cpp",
          0x65u,
          "void __thiscall survarium::messaging_client::on_packet_received(class vostok::network_core::buffer_reader &)",
          "game",
          error,
          "messaging_client received unknown message:%d",
          (unsigned __int8)v23);
      }
      if ( (v23 & 0x1000) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v26);
      break;
  }
}
