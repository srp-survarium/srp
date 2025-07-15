void __thiscall vostok::network_core::udp_match_connection::process_low_level_message(
        vostok::network_core::udp_match_connection *this,
        vostok::network_core::buffer_reader *reader,
        const unsigned __int8 *time_in_ms)
{
  char *v3; // esi
  const unsigned __int8 *m_buffer; // eax
  bool has_passed_filters; // al
  bool v6; // al
  vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v7; // eax
  vostok::network_core::udp_match_connection *v8; // [esp-4h] [ebp-5Ch]
  vostok::network_core::udp_match_connection *v9; // [esp-4h] [ebp-5Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v10; // [esp+10h] [ebp-48h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v11; // [esp+30h] [ebp-28h] BYREF
  int v12; // [esp+50h] [ebp-8h]
  char v13; // [esp+57h] [ebp-1h]

  v3 = (char *)this->m_random_generator.x[1];
  v13 = *v3;
  this->m_random_generator.x[1] = (unsigned int)(v3 + 1);
  v12 = 0;
  if ( v13 )
  {
    if ( v13 == 1 )
    {
      m_buffer = reader[235].m_buffer;
      if ( m_buffer )
      {
        if ( m_buffer == (const unsigned __int8 *)1 )
          vostok::network_core::udp_match_connection::instant_disconnect(
            this,
            (int)reader,
            (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)2);
      }
      else
      {
        if ( !vostok::core::g_log_filter_tree
          || (has_passed_filters = vostok::logging::has_passed_filters(
                                     (vostok::logging::filter_tree *)"network_core",
                                     (const char *)2),
              this = v8,
              has_passed_filters) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
            &v11);
          v12 = 2;
          vostok::logging::append(
            &v11,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\udp_match_connection.cpp",
            0x36Bu,
            "void __thiscall vostok::network_core::udp_match_connection::process_low_level_message(class vostok::network_"
            "core::buffer_reader &,const unsigned int)",
            "network_core",
            error,
            "[%s] processing low level packet: skip confirming disconnection - we didn't initiated it",
            uri);
        }
        if ( (v12 & 2) != 0 )
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
            (int *)&v11);
      }
    }
  }
  else if ( !reader[235].m_buffer )
  {
    reader[235].m_buffer = (const unsigned __int8 *)2;
    if ( !vostok::core::g_log_filter_tree
      || (v6 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"network_core", (const char *)2),
          this = v9,
          v6) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v10);
      v12 = 1;
      vostok::logging::append(
        &v10,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\udp_match_connection.cpp",
        0x362u,
        "void __thiscall vostok::network_core::udp_match_connection::process_low_level_message(class vostok::network_core"
        "::buffer_reader &,const unsigned int)",
        "network_core",
        error,
        "--confirming_disconnection");
    }
    if ( (v12 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&v10);
    reader[234].m_pointer = time_in_ms;
    v7 = (vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)vostok::network_core::udp_match_connection::new_low_level_packet(this, (int)reader, 1u);
    vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v7,
      &reader[219].m_buffer);
  }
}
