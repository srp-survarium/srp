void __userpurge survarium::network_client::on_match_packet_received(
        survarium::network_client *this@<ecx>,
        const char *a2@<esi>,
        vostok::network_core::buffer_reader *message_type,
        vostok::network_core::buffer_reader *reader)
{
  vostok::journaling::journal *v5; // ecx
  int v7; // esi
  unsigned __int16 v8; // ax
  const unsigned __int8 *m_pointer; // esi
  bool has_passed_filters; // al
  const unsigned __int8 *v11; // esi
  unsigned __int16 v12; // ax
  void *v13; // esp
  unsigned __int8 *v14; // edi
  vostok::network_core::buffer_reader *v15; // ecx
  void *v16; // esp
  unsigned __int8 *v17; // esi
  vostok::network_core::buffer_reader *v18; // eax
  const unsigned __int8 *v19; // eax
  int v20; // edi
  void *v21; // esp
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v22; // eax
  survarium::game_world_core *v23; // ecx
  unsigned __int16 v24; // cx
  const unsigned __int8 *v25; // eax
  unsigned __int8 *v26; // esi
  bool v27; // al
  vostok::network_core::buffer_reader *v28; // [esp-4h] [ebp-7Ch]
  unsigned __int8 v29[16]; // [esp+0h] [ebp-78h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v30; // [esp+10h] [ebp-68h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v31; // [esp+30h] [ebp-48h] BYREF
  vostok::network_core::buffer_writer::serialization_operation_descriptor *descriptors_begin; // [esp+50h] [ebp-28h]
  unsigned __int8 *v33; // [esp+54h] [ebp-24h]
  vostok::network_core::buffer_writer::serialization_operation_descriptor *v34; // [esp+58h] [ebp-20h]
  const char *v35; // [esp+5Ch] [ebp-1Ch]
  const char *v36; // [esp+60h] [ebp-18h]
  const char *v37; // [esp+64h] [ebp-14h]
  const char *v38; // [esp+68h] [ebp-10h]
  unsigned __int8 *v39; // [esp+6Ch] [ebp-Ch]
  survarium::network_client *v40; // [esp+70h] [ebp-8h]
  int v41; // [esp+74h] [ebp-4h]
  int savedregs; // [esp+78h] [ebp+0h] BYREF
  int v43; // [esp+80h] [ebp+8h]
  unsigned __int8 *v44; // [esp+80h] [ebp+8h]
  vostok::network_core::buffer_reader *readera; // [esp+84h] [ebp+Ch]

  v41 = 0;
  v40 = this;
  if ( vostok::core::journal_usage() == record_journal )
  {
    a2 = (const char *)reader;
    vostok::journaling::match_client::write_packet(reader, v5, message_type);
    v5 = (vostok::journaling::journal *)v28;
  }
  switch ( (char)message_type )
  {
    case 'P':
      if ( this->m_match_state )
        goto LABEL_30;
      v7 = vostok::network_core::buffer_reader::r<unsigned short>(reader);
      v8 = vostok::network_core::buffer_reader::r<unsigned short>(reader);
      this->m_match_client->set_connection_ports(
        this->m_match_client,
        65u,
        this->m_lobby_client.m_connection_info.session_id,
        v7,
        v8);
      this->m_match_state = waiting_for_static_match_info;
      break;
    case 'Q':
      if ( this->m_match_state != waiting_for_static_match_info )
        goto LABEL_30;
      survarium::network_client::process_static_match_info(
        (survarium::network_client *)v5,
        (int)&savedregs,
        this,
        reader);
      this->m_match_state = playing_match;
      break;
    case 'R':
      if ( this->m_match_state != playing_match )
        goto LABEL_30;
      survarium::network_client::process_set_time_request(
        (survarium::network_client *)reader,
        (vostok::network_core::buffer_reader *)this);
      break;
    case 'S':
      if ( this->m_match_state != playing_match )
        goto LABEL_30;
      survarium::network_client::process_dynamic_match_info(
        (survarium::network_client *)v5,
        a2,
        (vostok::network_core::buffer_reader *)this,
        (vostok::particle::particle_system_instance_impl *)reader);
      break;
    case 'T':
      if ( this->m_match_state != playing_match )
        goto LABEL_30;
      survarium::network_client::process_player_input_change(
        (survarium::network_client *)v5,
        (vostok::network_core::buffer_reader *)this,
        reader);
      break;
    case 'U':
      if ( this->m_match_state != playing_match )
        goto LABEL_30;
      m_pointer = reader->m_pointer;
      LOWORD(message_type) = *(_WORD *)m_pointer;
      v28 = message_type;
      reader->m_pointer = m_pointer + 2;
      vostok::timing::floating_timer::set_offset(
        (vostok::timing::floating_timer *)v5,
        (int)&v40->m_game->m_timer,
        (const __int16)v28);
      break;
    case 'V':
      if ( this->m_match_state != playing_match )
        goto LABEL_30;
      survarium::network_client::process_player_entered_match(
        (survarium::network_client *)reader,
        (vostok::network_core::buffer_reader *)this);
      break;
    case 'W':
      if ( this->m_match_state != playing_match )
        goto LABEL_30;
      survarium::network_client::process_player_left_match(
        (survarium::network_client *)reader,
        (vostok::network_core::buffer_reader *)this);
      break;
    case 'X':
      if ( this->m_match_state != playing_match )
        goto LABEL_30;
      survarium::network_client::process_local_player_input_discard((survarium::network_client *)reader, (int)this);
      break;
    case 'Y':
      if ( this->m_match_state != playing_match )
        reader->m_pointer = &reader->m_buffer[reader->m_buffer_size];
      if ( vostok::network_core::g_debug_hash_mismatches )
      {
        v11 = reader->m_pointer;
        descriptors_begin = *(vostok::network_core::buffer_writer::serialization_operation_descriptor **)v11;
        reader->m_pointer = v11 + 4;
        v12 = vostok::network_core::buffer_reader::r<unsigned short>(reader);
        v13 = alloca(v12);
        v14 = v29;
        v43 = v12;
        v16 = alloca(4 * vostok::network_core::buffer_reader::r<unsigned short>(reader));
        v17 = v29;
        v39 = v29;
        readera = (vostok::network_core::buffer_reader *)v29;
        while ( v43 )
        {
          v18 = readera;
          readera = (vostok::network_core::buffer_reader *)((char *)readera + 4);
          v18->m_buffer = v14;
          v41 = (int)reader->m_pointer;
          vostok::network_core::buffer_reader::r_string(v15, (char *)reader, v14);
          v19 = reader->m_pointer;
          v15 = (vostok::network_core::buffer_reader *)(v41 - (_DWORD)v19);
          v43 += v41 - (_DWORD)v19;
          v14 = (unsigned __int8 *)&v19[(_DWORD)v14 - v41];
        }
        v20 = 32 * vostok::network_core::buffer_reader::r<unsigned short>(reader);
        v21 = alloca(v20);
        v22 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v29;
        v23 = (survarium::game_world_core *)&v29[v20];
        v33 = v29;
        v44 = v29;
        if ( v29 != &v29[v20] )
        {
          while ( 1 )
          {
            v37 = *(const char **)&v17[4 * vostok::network_core::buffer_reader::r<unsigned short>(reader)];
            v36 = *(const char **)&v17[4 * vostok::network_core::buffer_reader::r<unsigned short>(reader)];
            v34 = *(vostok::network_core::buffer_writer::serialization_operation_descriptor **)&v17[4 * vostok::network_core::buffer_reader::r<unsigned short>(reader)];
            v35 = *(const char **)&v17[4 * vostok::network_core::buffer_reader::r<unsigned short>(reader)];
            v38 = (const char *)vostok::network_core::buffer_reader::r<unsigned short>(reader);
            v24 = vostok::network_core::buffer_reader::r<unsigned short>(reader);
            v25 = reader->m_pointer;
            LOBYTE(v41) = *v25;
            v26 = v44;
            reader->m_pointer = v25 + 1;
            if ( v44 )
              vostok::network_core::buffer_writer::serialization_operation_descriptor::serialization_operation_descriptor(
                v34,
                (int)v44,
                v35,
                v36,
                v37,
                v38,
                v24,
                v41,
                v29[0]);
            *(_DWORD *)v44 = v44 + 32;
            v44 += 32;
            if ( v26 + 32 == &v29[v20] )
              break;
            v17 = v39;
          }
          v22 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v33;
          v23 = (survarium::game_world_core *)&v29[v20];
        }
        v23[-1].m_start_fixed_time_in_ms = 0;
        survarium::game_world_core::on_hash_mismatch(
          v23,
          v40->m_match.m_object->m_game_world_core,
          (unsigned int)descriptors_begin,
          v22,
          (int)reader);
      }
      else
      {
        if ( !vostok::core::g_log_filter_tree
          || (has_passed_filters = vostok::logging::has_passed_filters(
                                     (vostok::logging::filter_tree *)"game",
                                     (const char *)3),
              v5 = (vostok::journaling::journal *)v28,
              has_passed_filters) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v5,
            &v31);
          v41 = 1;
          vostok::logging::append(
            &v31,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\network_client_handler.cpp",
            0x83u,
            "void __thiscall survarium::network_client::on_match_packet_received(unsigned char,class vostok::network_core"
            "::buffer_reader &)",
            "game",
            warning,
            "run application with -debug_hash_mismatch command line key to process debug hash mismatch messages");
        }
        if ( (v41 & 1) != 0 )
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v5,
            (int *)&v31);
LABEL_30:
        reader->m_pointer = &reader->m_buffer[reader->m_buffer_size];
      }
      break;
    default:
      if ( !vostok::core::g_log_filter_tree
        || (v27 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2),
            v5 = (vostok::journaling::journal *)v28,
            v27) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v5,
          &v30);
        v41 = 2;
        vostok::logging::append(
          &v30,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client_handler.cpp",
          0xB3u,
          "void __thiscall survarium::network_client::on_match_packet_received(unsigned char,class vostok::network_core::"
          "buffer_reader &)",
          "game",
          error,
          "unknown message type : %d",
          (unsigned __int8)message_type);
      }
      if ( (v41 & 2) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v5,
          (int *)&v30);
      break;
  }
}
